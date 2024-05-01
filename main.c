/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:25:28 by omartela          #+#    #+#             */
/*   Updated: 2024/05/01 16:25:30 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
int main(void) {
    char c = 'A';
    char *s = "Hello, world!";
    int d = -42;
    int i = 123;
    unsigned int u = 4294967295; // Maximum value of unsigned int
    void *p = &c; // Address of variable c
    printf("Testing ft_printf:\n");

    // Test cases
    ft_printf("%%c: %c\n", c);
    ft_printf("%%s: %s\n", s);
    ft_printf("%%p: %p\n", p);
    ft_printf("%%d: %d\n", d);
    ft_printf("%%i: %i\n", i);
    ft_printf("%%u: %u\n", u);
    ft_printf("%%x: %x\n", u);
    ft_printf("%%X: %X\n", u);

    // Compare with original printf
    printf("\nTesting original printf:\n");
    printf("%%c: %c\n", c);
    printf("%%s: %s\n", s);
    printf("%%p: %p\n", p);
    printf("%%d: %d\n", d);
    printf("%%i: %i\n", i);
    printf("%%u: %u\n", u);
    printf("%%x: %x\n", u);
    printf("%%X: %X\n", u);

    return 0;
}