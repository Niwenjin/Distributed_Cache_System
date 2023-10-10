#include "cache_service.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <iostream>
#include <string>
#include <unordered_map>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using std::string;
using std::unordered_map;

class CacheServiceImpl final : public CacheService::Service {
  public:
    Status Get(ServerContext *context, const GetRequest *request,
               GetReply *reply) override {
        reply->set_value(map[request->key()]);
        return Status::OK;
    }

    Status Set(ServerContext *context, const SetRequest *request,
               SetReply *reply) override {
        map[request->key()] = request->value();
        return Status::OK;
    }

    Status Delete(ServerContext *context, const DelRequest *request,
                  DelReply *reply) override {
        int n = map.erase(request->key());
        reply->set_num(n);
        return Status::OK;
    }

  private:
    unordered_map<string, string> map;
};

int main() {
    string server_address("0.0.0.0:50051");
    CacheServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();

    return 0;
}
