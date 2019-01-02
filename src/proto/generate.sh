protoc -I ./ --grpc_out=./ --plugin=protoc-gen-grpc=/Users/fenglin/project/self/kvstore/third_party/grpc/bins/opt/grpc_cpp_plugin ./server.proto
protoc -I ./ --cpp_out=. ./server.proto
mv server.pb.cc server.pb.cpp
mv server.grpc.pb.cc server.grpc.pb.cpp
protoc -I ./ --cpp_out=. ./message.proto
mv message.pb.cc message.pb.cpp
