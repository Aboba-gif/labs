# корневой CMakeLists.txt

cmake_minimum_required(VERSION 3.15)
project(NumericalMethodsLabs CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === Секция 1: Подключаем чертежи наших модулей ===

# "Сходи в папку common и выполни инструкции из ее CMakeLists.txt"
# Это автоматически создаст цель 'common' со всеми ее файлами и настройками.
add_subdirectory(common)

# === Секция 2: Подключаем чертежи лабораторных ===
add_subdirectory(labs/lab_01_integration)
add_subdirectory(labs/lab_02_heat_equation)
add_subdirectory(labs/lab_03_matrix_multiplication)