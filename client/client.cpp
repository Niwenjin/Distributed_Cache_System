#include "cache_service.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <iostream>
#include <memory>
#include <string>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

class CacheClient {
public:
    CacheClient(std::shared_ptr<Channel> channel)
        : stub_(CacheService::NewStub(channel)) {}

    std::string Get(const std::string& key) {
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

    void Set(const std::string& key, const std::string& value) {
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

    void Delete(const std::string& key) {
        DelRequest request;
        request.set_key(key);

        DelReply reply;
        ClientContext context;

        Status status = stub_->Delete(&context, request, &reply);

        if (!status.ok()) {
            std::cerr << "Error: " << status.error_message() << std::endl;
        }
    }

private:
    std::unique_ptr<CacheService::Stub> stub_;
};

int main() {
    std::string server_address("localhost:50051");
    CacheClient client(grpc::CreateChannel(
        server_address, grpc::InsecureChannelCredentials()));

    // Example usage of the client:
    client.Set("key1", "value1");
    std::cout << "Get key1: " << client.Get("key1") << std::endl;
    client.Delete("key1");

    return 0;
}
