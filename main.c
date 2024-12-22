#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    // Testing %c
    ft_printf("ft_printf: %c\n", 'A');
    printf("printf: %c\n\n", 'A');

    // Testing %s
    ft_printf("ft_printf: %s\n", "Hello, World!");
    printf("printf: %s\n\n", "Hello, World!");

    // Testing %p
    int x = 42;
    ft_printf("ft_printf: %p\n", &x);
    printf("printf: %p\n\n", &x);

    // Testing %d and %i
    ft_printf("ft_printf: %d\n", -12345);
    printf("printf: %d\n\n", -12345);

    ft_printf("ft_printf: %i\n", -67890);
    printf("printf: %i\n\n", -67890);

    // Testing %u
    ft_printf("ft_printf: %u\n", 12345);
    printf("printf: %u\n\n", 12345);

    // Testing %x
    ft_printf("ft_printf: %x\n", 255);
    printf("printf: %x\n\n", 255);

    // Testing %X
    ft_printf("ft_printf: %X\n", 255);
    printf("printf: %X\n\n", 255);

    // Testing %%
    ft_printf("ft_printf: %%\n");
    printf("printf: %%\n\n");

    return 0;
}
