# 设置cmake最小版本
cmake_minimum_required(VERSION 3.6)

# 设置项目名称
project(Distributed_Cache_System)

# 设置C++标准11
set(CMAKE_CXX_STANDARD 17)

# 设置输出compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

find_package(protobuf REQUIRED)
set(protobuf_LIBRARIES
    protobuf::libprotobuf
    protobuf::libprotoc
)

find_package(gRPC CONFIG REQUIRED)
set(grpc_LIBRARIES
    gRPC::grpc++_reflection
)

find_package(absl REQUIRED)
set(absl_LIBRARIES
    absl::flags
    absl::flags_parse
)

# file(GLOB_RECURSE LIB_ABSL /usr/lib/libabsl_*.so)
# find_library(LIB_ABSL libabsl_*.* /usr/lib)
# find_package(grpc CONFIG REQUIRED)

include_directories(include protos http)

# link_directories(/app/json /app/lib)

add_executable(server main.cpp src/CacheClient.cpp src/CacheServiceImpl.cpp protos/cache_service.pb.cc protos/cache_service.grpc.pb.cc)

target_link_libraries(server ${grpc_LIBRARIES} ${absl_LIBRARIES} ${protobuf_LIBRARIES} jsoncpp)

# target_link_libraries(server ${grpc_LIBS})