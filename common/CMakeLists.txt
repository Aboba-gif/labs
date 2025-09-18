# common/CMakeLists.txt

# Создаем библиотеку 'common' и перечисляем ВСЕ ее исходные файлы
# объект по имени 'common'. Это будет не программа, а библиотека (add_library)."
# "Для ее создания используй кирпичи из файла common/src/integration.cpp".
add_library(common 
    src/integration.cpp
    src/heat.cpp
)

# Указываем, где лежат заголовочные файлы для этой библиотеки
# "Очень важно! Любой, кто будет использовать 'common', должен знать,
# где искать ее заголовочные файлы. Скажи им, что они лежат в папке common/include".
# PUBLIC означает, что это знание передается дальше по цепочке зависимостей.
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)