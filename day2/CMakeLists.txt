cmake_minimum_required(VERSION 3.0.0)
project(day2 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(day2 main.cpp)

set_target_properties(day2 PROPERTIES CXX_STANDARD 17 CXX_EXTENSIONS OFF)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
