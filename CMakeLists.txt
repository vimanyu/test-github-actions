cmake_minimum_required(VERSION 3.1)

project(test-github-action
        VERSION 1.0
        LANGUAGES C CXX)

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


add_executable(myapp src/main.cpp)
target_link_libraries(myapp)

