#include "CacheClient.h"

CacheClient::CacheClient(std::shared_ptr<Channel> channel)
    : stub(CacheService::NewStub(channel)) {}

CacheClient::~CacheClient() {}

string CacheClient::Get(const string &key) {
    GetRequest request;

    request.set_key(key);

    GetReply reply;
    ClientContext context;

    stub->Get(&context, request, &reply);
    return reply.value();
}

void CacheClient::Set(const string &key, const string &value) {
    SetRequest request;
    request.set_key(key);
    request.set_value(value);

    SetReply reply;
    ClientContext context;

    stub->Set(&context, request, &reply);
}

int CacheClient::Delete(const string &key) {
    DelRequest request;
    request.set_key(key);

    DelReply reply;
    ClientContext context;

    stub->Delete(&context, request, &reply);

    return reply.num();
}