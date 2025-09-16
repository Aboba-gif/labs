cmake_minimum_required(VERSION 3.10)

project(CPP CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(test_1 test_1.cpp)
add_executable(test_2 test_2.cpp)
add_executable(test_3 test_3.cpp)
add_executable(test_4 test_4.cpp)

# test_1-3: простой запуск с выводом в файлы
foreach(i RANGE 1 3)
    add_custom_command(
        TARGET test_${i}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Launching test_${i}.exe -> Output to test_${i}_output.txt"
        COMMAND $<TARGET_FILE:test_${i}> > ${CMAKE_CURRENT_SOURCE_DIR}/test_${i}_output.txt 2>&1
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        VERBATIM
    )
endforeach()

# Для test_4 используем batch файл (надежнее чем PowerShell)
if(WIN32)
    add_custom_command(
        TARGET test_4
        POST_BUILD
        COMMAND cmd /c "${CMAKE_CURRENT_SOURCE_DIR}/run_test_4.bat"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Запуск test_4 через batch файл"
        VERBATIM
    )
endif()