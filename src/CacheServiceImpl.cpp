#include "CacheServiceImpl.h"
#include "CacheClient.h"
#include <cstddef>
#include <memory>

using grpc::CreateChannel;
using grpc::InsecureChannelCredentials;
using std::make_unique;

CacheServiceImpl::CacheServiceImpl(size_t no) : m_no(no) {
    string server_address[3] = {"0.0.0.0:8080", "0.0.0.0:8081", "0.0.0.0:8082"};
    for (string addr : server_address) {
        client.push_back(make_unique<CacheClient>(
            CreateChannel(addr, InsecureChannelCredentials())));
    }
}

CacheServiceImpl::~CacheServiceImpl() {}

Status CacheServiceImpl::Get(ServerContext *context, const GetRequest *request,
                             GetReply *reply) {
    string value = map[request->key()];
    reply->set_value(value);
    return Status::OK;
}

Status CacheServiceImpl::Set(ServerContext *context, const SetRequest *request,
                             SetReply *reply) {
    map[request->key()] = request->value();
    return Status::OK;
}

Status CacheServiceImpl::Delete(ServerContext *context,
                                const DelRequest *request, DelReply *reply) {
    reply->set_num(map.erase(request->key()));
    return Status::OK;
}

string CacheServiceImpl::getCache(const string key) {
    size_t no = hash(key);
    if (no == m_no)
        return map[key];
    else
        return client[no]->Get(key);
}

void CacheServiceImpl::setCache(const string key, const string value) {
    size_t no = hash(key);
    if (no == m_no)
        map[key] = value;
    else
        client[no]->Set(key, value);
}

int CacheServiceImpl::delCache(const string key) {
    size_t no = hash(key);
    if (no == m_no)
        return map.erase(key);
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