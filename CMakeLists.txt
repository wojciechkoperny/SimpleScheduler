cmake_minimum_required(VERSION 3.10)
project(test_proj VERSION 1.0)

SET(CMAKE_MAKE_PROGRAM make)

add_executable(test_proj1   SchM.c
                            main.c)
                            
target_link_libraries(test_proj1 pthread)