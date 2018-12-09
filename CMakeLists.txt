cmake_minimum_required(VERSION 3.13)
project(nnxor)
#set(EXECUTABLE_OUTPUT_PATH nnxor/)

#The includes
include_directories(include/)

file(GLOB SOURCES src/*.cpp)

#remove from glob
#list(REMOVE_ITEM SOURCES nnxor/badcode.cpp)

add_executable(nnxor ${SOURCES})