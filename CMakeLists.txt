cmake_minimum_required(VERSION 3.10.0)
project(cpp_regex)

link_directories(C:/Lua/16_dynamic)

add_executable(cpp cpp.cpp)

add_executable(lua lua.cpp)

target_include_directories(lua PRIVATE C:/Lua/16_dynamic/include)
target_link_libraries(lua PRIVATE lua54)

file(COPY C:/Lua/16_dynamic/lua54.dll DESTINATION ./)

