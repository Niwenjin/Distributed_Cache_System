#include "CacheClient.h"

CacheClient::CacheClient(std::shared_ptr<Channel> channel)
    : stub_(CacheService::NewStub(channel)) {}

CacheClient::~CacheClient() {}

string CacheClient::Get(const string &key) {
    GetRequest request;
    request.set_key(key);

    GetReply reply;
    ClientContext context;

    Status status = stub_->Get(&context, request, &reply);

    if (status.ok()) {
        return reply.value();
    } else {
        std::cerr << "Error: " << status.error_message() << std::endl;
        return "";
    }
}

void CacheClient::Set(const string &key, const string &value) {
    SetRequest request;
    request.set_key(key);
    request.set_value(value);

    SetReply reply;
    ClientContext context;

    Status status = stub_->Set(&context, request, &reply);

    if (!status.ok()) {
        std::cerr << "Error: " << status.error_message() << std::endl;
    }
}

void CacheClient::Delete(const string &key) {
    DelRequest request;
    request.set_key(key);

    DelReply reply;
    ClientContext context;

    Status status = stub_->Delete(&context, request, &reply);

    if (!status.ok()) {
        std::cerr << "Error: " << status.error_message() << std::endl;
    }
}