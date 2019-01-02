cmake_minimum_required(VERSION 3.11)
project(kvstore)

set(CMAKE_CXX_STANDARD 11)

unset(GRPC_INCLUDE_DIRS)
set(GRPC_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/third_party/grpc/include)
unset(GRPC_LIBRARY)
find_library(GRPC_LIBRARY libgrpc++.a PATHS  ${PROJECT_SOURCE_DIR}/third_party/grpc/libs/opt)
file(GLOB GRPC_ALL_LIBS "${PROJECT_SOURCE_DIR}/third_party/grpc/libs/opt/libgrpc*.a")

if(NOT GRPC_INCLUDE_DIRS)
    message("grpc include not found, test will not succeed!")
endif()

if(NOT GRPC_LIBRARY)
    message("grpc not found, test will not succeed!")
endif()

unset(PROTOBUFFER_LIBRARY)
find_library(PROTOBUFFER_LIBRARY libprotobuf.a PATHS ${PROJECT_SOURCE_DIR}/third_party/grpc/libs/opt)

unset(ROCKSDB_LIBRARY)
find_library(ROCKSDB_LIBRARY librocksdb.a PATHS /usr/local/lib)

find_package(ZLIB)
if(NOT ZLIB_FOUND)
    message(FATAL_ERROR "ZLIB not found, test will not succeed!")
endif()

find_package(BZip2)
if(NOT BZIP2_FOUND)
    message(FATAL_ERROR "BZIP2 not found, test will not succeed!")
endif()

unset(LIBLZ4_LIBRARY)
unset(LIBSNAPPY_LIBRARY)
find_library(LIBLZ4_LIBRARY liblz4.a  PATHS /usr/lib /usr/lib64 /usr/local/lib)
find_library(LIBSNAPPY_LIBRARY libsnappy.a PATHS /usr/lib /usr/local/lib)

unset(GTEST_INCLUDEDIR)
set(GTEST_INCLUDEDIR ${PROJECT_SOURCE_DIR}/third_party/googletest/googletest/include)
unset(GTEST_LIBRARY)
find_library(GTEST_LIBRARY libgtest.a PATHS ${PROJECT_SOURCE_DIR}/third_party/googletest/googletest/libs)

if(NOT GTEST_INCLUDEDIR)
    message("gtest include not found, test will not succeed!")
endif()

if(NOT GTEST_LIBRARY)
    message("gtest lib not found, test will not succeed!")
endif()

FILE(GLOB_RECURSE SRC_LIST RELATIVE ${PROJECT_SOURCE_DIR} "src/*.c*")
FILE(GLOB_RECURSE INC_LIST RELATIVE ${PROJECT_SOURCE_DIR} "src/*.h*")
FILE(GLOB_RECURSE CLIENT_SRC_LIST RELATIVE ${PROJECT_SOURCE_DIR} "client/*.c*")
FILE(GLOB_RECURSE CLIENT_INC_LIST RELATIVE ${PROJECT_SOURCE_DIR} "client/*.h*")
FILE(GLOB_RECURSE TEST_SRC_LIST RELATIVE ${PROJECT_SOURCE_DIR} "test/*.c*")
FILE(GLOB_RECURSE TEST_INC_LIST RELATIVE ${PROJECT_SOURCE_DIR} "test/*.h*")

include_directories(${PROJECT_SOURCE_DIR} ${GRPC_INCLUDE_DIRS} ${GTEST_INCLUDEDIR})

add_executable(kvstore main.cpp ${GRPC_INCLUDE_DIRS} ${SRC_LIST} ${INC_LIST} )
target_link_libraries(kvstore ${GRPC_ALL_LIBS} ${PROTOBUFFER_LIBRARY} ${ROCKSDB_LIBRARY} ${LIBLZ4_LIBRARY} ${LIBSNAPPY_LIBRARY} ${BZIP2_LIBRARIES} ${ZLIB_LIBRARIES})

add_executable(kvstoreclient client/main.cpp ${GRPC_INCLUDE_DIRS} ${CLIENT_SRC_LIST} ${CLIENT_INC_LIST} )
target_link_libraries(kvstoreclient ${GRPC_ALL_LIBS} ${PROTOBUFFER_LIBRARY} ${ROCKSDB_LIBRARY} ${LIBLZ4_LIBRARY} ${LIBSNAPPY_LIBRARY} ${BZIP2_LIBRARIES} ${ZLIB_LIBRARIES})

add_executable(kvTest test/test-main.cpp ${GRPC_INCLUDE_DIRS} ${SRC_LIST} ${INC_LIST} ${TEST_SRC_LIST} ${TEST_INC_LIST} ${GTEST_INCLUDEDIR})
target_link_libraries(kvTest ${GRPC_ALL_LIBS} ${PROTOBUFFER_LIBRARY} ${ROCKSDB_LIBRARY} ${LIBLZ4_LIBRARY} ${LIBSNAPPY_LIBRARY} ${BZIP2_LIBRARIES} ${ZLIB_LIBRARIES} ${GTEST_LIBRARY})

if ( CMAKE_SYSTEM_NAME MATCHES "Linux" )
    target_link_libraries(kvstore rt pthread)
    target_link_libraries(kvstoreclient rt pthread)
endif()