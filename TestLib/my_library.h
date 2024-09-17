#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#ifdef _WIN32
#define MY_LIBRARY_API __declspec(dllexport)
#else
#define MY_LIBRARY_API
#endif

extern "C" {
    MY_LIBRARY_API int add(int a, int b);
    MY_LIBRARY_API int subtract(int a, int b);
}

#endif // MY_LIBRARY_H
