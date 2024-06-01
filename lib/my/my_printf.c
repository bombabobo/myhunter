/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_mini_printf
*/
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

int printpercent3(const char *format, va_list arr, int *ptr, int i)
{
    int precision = 6;

    if (format[i] == 'p')
        my_put_ptr(va_arg(arr, unsigned long), ptr);
    if (format[i] == 'u')
        my_put_unsigned_int(va_arg(arr, int), ptr);
    if (format[i] == 'c')
        my_putcharptr((char) va_arg(arr, int), ptr);
    if (format[i] == 's')
        my_putstrptr(va_arg(arr, char *), ptr);
    if (format[i] == '%')
        my_putcharptr('%', ptr);
    if (format[i] == '.'){
        precision = format[i + 1] - '0';
        i += 2;
    }
    if (format[i] == 'f' || format[i] == 'F')
        my_put_float(va_arg(arr, double), ptr, precision);
    return i    ;
}

int printpercent2(const char *format, va_list arr, int *ptr, int i)
{
    if (format[i] == '#')
        i++;
    if (format[i - 1] == '#' && format[i] == 'o')
        my_putcharptr('0', ptr);
    if (format[i] == 'o')
        decimal_to_octal(va_arg(arr, int), ptr);
    if (format[i - 1] == '#' && format[i] == 'x')
        my_putstrptr("0x", ptr);
    if (format[i] == 'x')
        decimal_to_hexa(va_arg(arr, int), ptr, 1);
    if (format[i - 1] == '#' && format[i] == 'X')
        my_putstrptr("0X", ptr);
    if (format[i] == 'X')
        decimal_to_hexa(va_arg(arr, int), ptr, 0);
    i = printpercent3(format, arr, ptr, i);
    return i;
}

int printpercent(const char *format, va_list arr, int *ptr, int i)
{
    int *tempptr;

    if (format[i] == ' ')
        i = printpercent(format, arr, ptr, i + 1);
    if (format[i] == '\0')
        my_putcharptr('%', ptr);
    if (format[i] == 'd' || format[i] == 'i')
        my_put_int(va_arg(arr, int), ptr);
    if (format[i] == 'n'){
        (tempptr) = va_arg(arr, int *);
        (*tempptr) = *ptr;
    }
    printpercent2(format, arr, ptr, i);
}

int my_printf(const char *format, ...)
{
    va_list arr;
    int count = 0;
    int *ptr = &count;

    va_start(arr, format);
    for (int i = 0; format[i] != '\0'; i++){
        if (format[i] == '%'){
            i = printpercent(format, arr, ptr, i + 1);
            continue;
        }
        my_putcharptr(format[i], ptr);
    }
    va_end(arr);
    return count;
}
