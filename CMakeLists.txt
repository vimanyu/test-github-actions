cmake_minimum_required(VERSION 3.1)

project(test-github-action
        VERSION 1.0
        LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MT")

include(ExternalProject)

set(version v1.33.1)

ExternalProject_Add(
  libuv

  DOWNLOAD_DIR external/downloads
  DOWNLOAD_NAME libuv-${version}.tar.gz
  URL https://github.com/libuv/libuv/archive/${version}.tar.gz

  PREFIX external/bin

  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
  TEST_COMMAND ""
)


find_package(tinyxml REQUIRED)


add_executable(myapp src/main.cpp)
target_link_libraries(myapp unofficial-tinyxml::unofficial-tinyxml)

