cmake_minimum_required(VERSION 3.10)

# �������� �������
project(my_library)

# �������� ����������
add_library(my_library SHARED my_library.cpp)

# ����������� ����������
target_include_directories(my_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
