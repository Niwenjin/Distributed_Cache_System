#include "CacheClient.h"
#include <json/value.h>

CacheClient::CacheClient(std::shared_ptr<Channel> channel)
    : stub(CacheService::NewStub(channel)) {}

CacheClient::~CacheClient() {}

Json::Value CacheClient::Get(const string &key) {
    Request request;

    request.set_req(key);

    Reply reply;
    ClientContext context;

    stub->Get(&context, request, &reply);

    if (reply.reply().empty())
        return Json::Value();

    // 将 std::string 转换为 Json::Value
    Json::CharReaderBuilder reader;
    Json::Value jsonValue;
    std::istringstream jsonStream(reply.reply());
    JSONCPP_STRING errs;
    Json::parseFromStream(reader, jsonStream, &jsonValue, &errs);

    return jsonValue;
}

void CacheClient::Set(const string &key, const Json::Value &value) {
    Request request;

    // 将 Json::Value 转换为 Json::String
    Json::Value jsonValue;
    jsonValue[key] = value;
    Json::StreamWriterBuilder writer;
    std::string json_str = Json::writeString(writer, jsonValue);

    request.set_req(json_str);

    Reply reply;
    ClientContext context;
    stub->Set(&context, request, &reply);
}

int CacheClient::Delete(const string &key) {
    Request request;
    request.set_req(key);

    Reply reply;
    ClientContext context;

    stub->Delete(&context, request, &reply);

    return stoi(reply.reply());
}