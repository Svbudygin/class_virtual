cmake_minimum_required(VERSION 3.8)
project(123 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
include(FetchContent)
FetchContent_Declare(fmt GIT_REPOSITORY https://github.com/fmtlib/fmt.git GIT_TAG master)
FetchContent_MakeAvailable(fmt)



add_executable(123 main.cpp)
target_link_libraries(123 PRIVATE fmt::fmt)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
