#include "CacheServiceImpl.h"
#include <memory>

using grpc::InsecureServerCredentials;
using grpc::Server;
using grpc::ServerBuilder;
using std::stoi;
using std::unique_ptr;

int main(int argc, char *argv[]) {
    string server_address[3] = {"0.0.0.0:8080", "0.0.0.0:8081", "0.0.0.0:8082"};
    size_t no = stoi(argv[1]);
    
    CacheServiceImpl service(no);

    ServerBuilder builder;
    builder.AddListeningPort(server_address[no], InsecureServerCredentials());
    builder.RegisterService(&service);

    unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address[no] << std::endl;

    server->Wait();

    return 0;
}
