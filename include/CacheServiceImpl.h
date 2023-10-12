#ifndef CACHESERVICEIMPL_H
#define CACHESERVICEIMPL_H
#include "CacheClient.h"
#include "cache_service.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using grpc::ServerContext;
using grpc::Status;
using std::string;
using std::unordered_map;
using std::vector;
using std::unique_ptr;

class CacheServiceImpl final : public CacheService::Service {
  public:
    CacheServiceImpl(size_t no);
    ~CacheServiceImpl();

    Status Get(ServerContext *context, const GetRequest *request,
               GetReply *reply) override;

    Status Set(ServerContext *context, const SetRequest *request,
               SetReply *reply) override;

    Status Delete(ServerContext *context, const DelRequest *request,
                  DelReply *reply) override;

  private:
    size_t m_no;
    vector<unique_ptr<CacheClient>> client;
    unordered_map<string, string> map;
    string getCache(const string key);
    void setCache(const string key, const string value);
    int delCache(const string key);
    size_t hash(string);
};
#endif