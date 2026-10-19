cmake_minimum_required(VERSION 3.28)
project(OptymalizacjaPomiarow LANGUAGES CXX)

add_executable(program main.cpp statystyki.cpp)
target_compile_features(program PRIVATE cxx_std_20)
target_sources(program PRIVATE
    FILE_SET CXX_MODULES FILES statystyki.cppm
)

