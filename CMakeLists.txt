cmake_minimum_required(VERSION 3.10) 

project(CPP CXX)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(test_1 test_1.cpp)
add_executable(test_2 test_2.cpp)

add_custom_command(
   TARGET test_1
   POST_BUILD
   COMMAND ${CMAKE_COMMAND}
       -D "EXE=$<TARGET_FILE:test_1>"  # Полный путь к test_1.exe (не меняем)
       -D "OUT=${CMAKE_CURRENT_SOURCE_DIR}/test_1_output.txt"  # Теперь файл в корне C:\CPP
       -P ${CMAKE_CURRENT_LIST_DIR}/run_and_capture.cmake
   VERBATIM
)

add_custom_command(
   TARGET test_2
   POST_BUILD
   COMMAND ${CMAKE_COMMAND}
       -D "EXE=$<TARGET_FILE:test_2>"  # Полный путь к test_1.exe (не меняем)
       -D "OUT=${CMAKE_CURRENT_SOURCE_DIR}/test_2_output.txt"  # Теперь файл в корне C:\CPP
       -P ${CMAKE_CURRENT_LIST_DIR}/run_and_capture.cmake
   VERBATIM
)