cmake_minimum_required(VERSION 3.28)
project(CMyArray)

set(CMAKE_CXX_STANDARD 26)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}Test
        Test/Tests.cpp
        Classes/CMyArray.cpp
        Classes/CMyArray.h
        Classes/CMyArray.cpp
        Classes/CMyArrayException.cpp
        Classes/CMyArrayException.h
        Classes/CMyArrayIterator.cpp
        Classes/CMyArrayIterator.h
)

target_link_libraries(${PROJECT_NAME}Test gtest_main)
enable_testing()
add_test(NAME ${PROJECT_NAME}Test COMMAND ${PROJECT_NAME}Test)

add_executable(${PROJECT_NAME} main.cpp
        Classes/CMyArray.cpp
        Classes/CMyArray.h
        Classes/CMyArray.cpp
        Classes/CMyArrayException.cpp
        Classes/CMyArrayException.h
        Classes/CMyArrayIterator.cpp
        Classes/CMyArrayIterator.h
)
