cmake_minimum_required(VERSION 3.5.0)
project(ebpf_collector VERSION 0.1.0 LANGUAGES C CXX)

find_package(prometheus-cpp CONFIG REQUIRED)

if(NOT DEFINED prometheus-cpp_VERSION)
  message(FATAL_ERROR "prometheus-cpp_VERSION is not defined")
endif()

# 查找所有源文件
file(GLOB_RECURSE SOURCES "src/*.cpp")

if(PROMETHEUS_CPP_ENABLE_PUSH)
  add_executable(ebpf_collector ${SOURCES})
  target_link_libraries(ebpf_collector PRIVATE prometheus-cpp::push $<$<BOOL:${WIN32}>:Ws2_32>)
endif()

if(PROMETHEUS_CPP_ENABLE_PULL)
  add_executable(ebpf_collector ${SOURCES})
  target_link_libraries(ebpf_collector PRIVATE prometheus-cpp::pull)
endif()