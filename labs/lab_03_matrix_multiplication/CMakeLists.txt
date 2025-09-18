# Создаем исполняемый файл для третьей лабы
add_executable(lab_03 main.cpp)

# Говорим, что lab_03 для своей работы нужен код
# и заголовочные файлы из нашей общей библиотеки 'common'
target_link_libraries(lab_03 PRIVATE common)