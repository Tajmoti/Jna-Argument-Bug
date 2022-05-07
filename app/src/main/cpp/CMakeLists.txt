cmake_minimum_required(VERSION 3.18.1)

project("JnaArgumentBug")
add_library(JnaArgumentBug SHARED bug.c)
find_library(log-lib log)
target_link_libraries(JnaArgumentBug ${log-lib})

target_compile_options(JnaArgumentBug PUBLIC
        "$<$<CONFIG:DEBUG>:-O1>"
        "$<$<CONFIG:RELEASE>:-O1>")