# 使用基础镜像
# FROM ubuntu:20.04

# 使用基于Ubuntu 20.04的Docker镜像
FROM shuiyihang0981/ubuntu20.04_grpc:latest

# 设置环境变量
# ENV DEBIAN_FRONTEND=noninteractive

# 安装依赖
# RUN apt-get update && apt-get install -y \
#     libjsoncpp-dev \
#     build-essential \
#     tzdata \
#     g++ \
#     cmake \
#     protobuf-compiler \
#     libprotobuf-dev \
#     libgrpc++-dev \
#     && rm -rf /var/lib/apt/lists/*

# 复制相关文件到容器中
COPY . /app

# 设置工作目录
WORKDIR /app

# 编译可执行文件
RUN cd protos && \
    protoc -I=. --cpp_out=. --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` cache_service.proto && \
    cd .. && \
    rm -rf build && \
    mkdir build && \
    cd build && \
    cmake .. \
    && make

# 启动 gRPC 服务器
# CMD ["./build/server", "--config=config.conf"]