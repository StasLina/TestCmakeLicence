# CMakeList.txt: проект CMake для TestCmakeLicence; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

include_directories(${CMAKE_SOURCE_DIR}/TestLib)



# Добавьте источник в исполняемый файл этого проекта.
add_executable (TestCmakeLicence "TestCmakeLicence.cpp" "TestCmakeLicence.h")

if (WIN32)
    target_compile_definitions(TestCmakeLicence PRIVATE _WIN32)
elseif (UNIX)
    target_compile_definitions(TestCmakeLicence PRIVATE __linux__)
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

target_link_libraries(TestCmakeLicence my_library)

install (TARGETS TestCmakeLicence my_library EXPORT DESTINATION bin)

#target_link_libraries(TestCmakeLicence ${CMAKE_SOURCE_DIR}/../my_library/libmy_library.so)
# Для Windows: target_link_libraries(my_application ${CMAKE_SOURCE_DIR}/../my_library/my_library.dll)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TestCmakeLicence PROPERTY CXX_STANDARD 20)
endif()

