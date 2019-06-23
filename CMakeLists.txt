cmake_minimum_required(VERSION 3.12)
project(agf LANGUAGES CXX)

file(GLOB agf-src src/*.h src/*.cpp)
file(GLOB agf-heads src/*.h)

add_library(agf ${agf-src})

target_include_directories(src)

set_target_properties(agf CXX_STANDARD 17)

install(TARGETS agf DESTINATION lib)
install(FILES ${agf-heads} DESTINATION include/agf)