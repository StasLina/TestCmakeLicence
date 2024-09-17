#include <iostream>

#ifdef __linux__
#include <dlfcn.h>  // Для Linux и macOS
#elif _WIN32
#include <windows.h>  // Для Windows
#else
#error "Unsupported platform"
#endif

typedef int (*func_ptr)(int, int);
typedef double (*cos_func)(double);
typedef void (*FuncType)();


void * GetProcAddr(const char * lib_name, const char* name_func) {
#ifdef __linux__
    void* handle = dlopen(lib_name, RTLD_LAZY);
    if (!handle) {
        // Обработка ошибки
        return 0;
    }
    return dlsym(handle, name_func);
#elif _WIN32
    HMODULE handle = LoadLibrary(lib_name);
    if (!handle) {
        return 0;
    }
    return GetProcAddress(handle, name_func);
#else

#endif
}

int main() {
    // Загрузка библиотеки
    const char *lib_name;
#ifdef __linux__
    lib_name = "my_library.so";
#elif _WIN32
    lib_name = "my_library.dll";
#else
#endif
    const char* func_name1 = "add";
    const char* func_name2 = "subtract";

    void* add_func = GetProcAddr(lib_name, func_name1);
    void* subtract_func = GetProcAddr(lib_name, func_name2);
    // Вывод адресов функций
    std::cout << "Адрес функции add: " << (void*)add_func << std::endl;
    std::cout << "Адрес функции subtract: " << (void*)subtract_func << std::endl;
    std::cout << "Diff: " << (int)((int)subtract_func - (int)add_func) << std::endl;

    //// Вызов функций
    //int result = add_func(5, 3);
    //std::cout << "add(5, 3) = " << result << std::endl;

    //result = subtract_func(5, 3);
    //std::cout << "subtract(5, 3) = " << result << std::endl;

    // Закрытие библиотеки
    //dlclose(handle);  
    
    return 0;
}
