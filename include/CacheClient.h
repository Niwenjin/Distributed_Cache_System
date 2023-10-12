#ifndef CACHECLIENT_H
#define CACHECLIENT_H
#include "cache_service.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <string>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using std::string;

class CacheClient {
  public:
    CacheClient(std::shared_ptr<Channel> channel);
    ~CacheClient();

    string Get(const string &key);

    void Set(const string &key, const string &value);

    int Delete(const string &key);

  private:
    std::unique_ptr<CacheService::Stub> stub;
};
#endif