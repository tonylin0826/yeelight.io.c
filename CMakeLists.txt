cmake_minimum_required(VERSION 3.15)
project(yeelight_io_c C)

set(CMAKE_C_STANDARD 11)

#add_library(yeelight_io_c SHARED yeelight.c yeelight.h)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(yeelight yeelight.c yeelight.h)