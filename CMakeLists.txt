cmake_minimum_required (VERSION 3.16)
project (Myproject LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_library(iniParser STATIC "includes/iniparcer.h" "src/iniparcer.cpp")
target_include_directories(iniParser PUBLIC includes)

add_executable(ini_parser "src/main.cpp")
target_link_libraries(ini_parser iniParser)

