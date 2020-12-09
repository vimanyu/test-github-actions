cmake_minimum_required(VERSION 3.1)

project(test-github-action
        VERSION 1.0
        LANGUAGES C CXX)

message(STATUS "Before: ${CMAKE_GENERATOR}")
message(STATUS "Before: ${CMAKE_C_FLAGS}")
message(STATUS "Before: ${CMAKE_CXX_FLAGS}")
message(STATUS "Before: ${CMAKE_BUILD_TYPE}")
message(STATUS "Before: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "Before: ${CMAKE_GENERATOR_PLATFORM}")
if(APPLE)
message(STATUS "Before: ${CMAKE_OSX_ARCHITECTURES}")
endif()

if (MSVC)
  if (MSVC_RUNTIME_LIBRARY_STATIC)
    add_compile_options(
      $<$<CONFIG:>:/MT>
      $<$<CONFIG:Debug>:/MTd>
      $<$<CONFIG:Release>:/MT>
  )
  else()
    add_compile_options(
      $<$<CONFIG:>:/MD>
      $<$<CONFIG:Debug>:/MDd>
      $<$<CONFIG:Release>:/MD>
  )
  endif()
endif()


message(STATUS "After: ${CMAKE_GENERATOR}")
message(STATUS "After: ${CMAKE_C_FLAGS}")
message(STATUS "After: ${CMAKE_CXX_FLAGS}")
message(STATUS "After: ${CMAKE_BUILD_TYPE}")
message(STATUS "After: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "After: ${CMAKE_GENERATOR_PLATFORM}")
if(APPLE)
message(STATUS "After: ${CMAKE_OSX_ARCHITECTURES}")
endif()


include(ExternalProject)
ExternalProject_Add(
  boringssl

  DOWNLOAD_DIR ${FIREBASE_DOWNLOAD_DIR}
  DOWNLOAD_NAME boringssl-${commit}.tar.gz
  URL https://github.com/google/boringssl/archive/${commit}.tar.gz

  PREFIX ${PROJECT_BINARY_DIR}

  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
) 


add_executable(myapp src/main.cpp)
target_link_libraries(myapp unofficial-tinyxml::unofficial-tinyxml)

