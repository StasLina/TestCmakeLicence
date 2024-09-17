cmake_minimum_required(VERSION 3.10)

# Название проекта
project(my_library)

# Создание библиотеки
add_library(my_library SHARED my_library.cpp)

# Определение заголовков
target_include_directories(my_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
