#include "CacheServiceImpl.h"
#include "CacheClient.h"
#include <cstddef>
#include <memory>

using grpc::CreateChannel;
using grpc::InsecureChannelCredentials;
using std::make_unique;

CacheServiceImpl::CacheServiceImpl(size_t no) : m_no(no) {
    string server_address[3] = {"server1:8000", "server2:8001", "server3:8002"};
    for (string addr : server_address) {
        client.push_back(make_unique<CacheClient>(
            CreateChannel(addr, InsecureChannelCredentials())));
    }
}

CacheServiceImpl::~CacheServiceImpl() {}

Status CacheServiceImpl::Get(ServerContext *context, const Request *request,
                             Reply *reply) {
    string key = request->req();
    if (json_data.isMember(key)) {
        Json::Value jsonValue = json_data[key];
        Json::StreamWriterBuilder writer;
        string json_str = Json::writeString(writer, jsonValue);

        reply->set_reply(json_str);
    } else
        reply->set_reply("");
    return Status::OK;
}

Status CacheServiceImpl::Set(ServerContext *context, const Request *request,
                             Reply *reply) {
    Json::CharReaderBuilder reader;
    Json::Value jsonValue;
    std::istringstream jsonStream(request->req());
    JSONCPP_STRING errs;
    Json::parseFromStream(reader, jsonStream, &jsonValue, &errs);

    string key = jsonValue.getMemberNames()[0];
    Json::Value value = jsonValue[key];

    json_data[key] = value;

    return Status::OK;
}

Status CacheServiceImpl::Delete(ServerContext *context, const Request *request,
                                Reply *reply) {
    string key = request->req();
    if (json_data.isMember(key)) {
        json_data.removeMember(key);
        reply->set_reply("1");
    } else
        reply->set_reply("0");
    return Status::OK;
}

Json::Value CacheServiceImpl::getCache(const string key) {
    size_t no = hash(key);
    if (no == m_no)
        if (json_data.isMember(key)) {
            return json_data[key];
        } else
            return Json::Value();
    else
        return client[no]->Get(key);
}

void CacheServiceImpl::setCache(const string key, const Json::Value value) {
    size_t no = hash(key);
    if (no == m_no)
        json_data[key] = value;
    else
        client[no]->Set(key, value);
}

int CacheServiceImpl::delCache(const string key) {
    size_t no = hash(key);
    if (no == m_no)
        if (json_data.isMember(key)) {
            json_data.removeMember(key);
            return 1;
        } else
            return 0;
    else
        return client[no]->Delete(key);
}

size_t CacheServiceImpl::hash(string str) {
    size_t hash = 0;
    for (char c : str) {
        hash = hash * 31 + static_cast<size_t>(c);
    }
    return hash % 3;
}

void CacheServiceImpl::print() { std::cout << json_data << std::endl; }