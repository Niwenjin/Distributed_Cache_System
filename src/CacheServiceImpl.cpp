#include "CacheServiceImpl.h"

CacheServiceImpl::CacheServiceImpl(size_t no) : server_NO(no) {}

CacheServiceImpl::~CacheServiceImpl() {}

Status CacheServiceImpl::Get(ServerContext *context, const GetRequest *request,
                             GetReply *reply) {
    reply->set_value(getCache(request->key()));
    return Status::OK;
}

Status CacheServiceImpl::Set(ServerContext *context, const SetRequest *request,
                             SetReply *reply) {
    map[request->key()] = request->value();
    return Status::OK;
}

Status CacheServiceImpl::Delete(ServerContext *context,
                                const DelRequest *request, DelReply *reply) {
    int n = delCache(request->key());
    reply->set_num(n);
    return Status::OK;
}

bool CacheServiceImpl::inthis(string key) {
    size_t no = hash(key);
    return no == server_NO;
}

string CacheServiceImpl::getCache(const string key) {
    if (inthis(key))
        return map[key];
    else
        // 访问其他节点
        return
}

void CacheServiceImpl::setCache(const string key, const string value) {
    if (inthis(key))
        map[key] = value;
    else
    // 访问其他节点
}

int CacheServiceImpl::delCache(const string key) {
    if (inthis(key))
        return map.erase(key);
    else
    // 访问其他节点
}

size_t CacheServiceImpl::hash(string str) {
    size_t hash = 0;
    for (char c : str) {
        hash = hash * 31 + static_cast<size_t>(c);
    }
    return hash % 3;
}