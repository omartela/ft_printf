/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:25:28 by omartela          #+#    #+#             */
/*   Updated: 2024/05/07 18:02:40 by omartela         ###   ########.fr       */
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
    int ret_ft_printf, ret_printf;

    printf("Testing ft_printf:\n");

    // Test cases
    ret_ft_printf = ft_printf("%%c: %c\n", c);
    ret_printf = printf("%%c: %c\n", c);
    printf("Return value of ft_printf: %d\n", ret_ft_printf);
    printf("Return value of printf: %d\n", ret_printf);

	printf("##########################\n");
    ret_ft_printf = ft_printf("%%s: %s\n", s);
    ret_printf = printf("%%s: %s\n", s);
    printf("Return value of ft_printf: %d\n", ret_ft_printf);
    printf("Return value of printf: %d\n", ret_printf);

	printf("##########################\n");
    ret_ft_printf = ft_printf("%%p: %p\n", p);
    ret_printf = printf("%%p: %p\n", p);
    printf("Return value of ft_printf: %d\n", ret_ft_printf);
    printf("Return value of printf: %d\n", ret_printf);


	 printf("##########################\n");
	 ret_ft_printf = ft_printf("%%p: %p\n", NULL);
	 ret_printf = printf("%%p: %p\n", NULL);
	 printf("Return value of ft_printf: %d\n", ret_ft_printf);
	 printf("Return value of printf: %d\n", ret_printf);

	printf("##########################\n");
    ret_ft_printf = ft_printf("%%d: %d\n", d);
    ret_printf = printf("%%d: %d\n", d);
    printf("Return value of ft_printf: %d\n", ret_ft_printf);
    printf("Return value of printf: %d\n", ret_printf);


	printf("##########################\n");
    ret_ft_printf = ft_printf("%%i: %i\n", i);
    ret_printf = printf("%%i: %i\n", i);
    printf("Return value of ft_printf: %d\n", ret_ft_printf);
    printf("Return value of printf: %d\n", ret_printf);

	printf("##########################\n");
    ret_ft_printf = ft_printf("%%u: %u\n", u);
    ret_printf = printf("%%u: %u\n", u);
    printf("Return value of ft_printf: %d\n", ret_ft_printf);
    printf("Return value of printf: %d\n", ret_printf);

	printf("##########################\n");
    ret_ft_printf = ft_printf("%%x: %x\n", u);
    ret_printf = printf("%%x: %x\n", u);
    printf("Return value of ft_printf: %d\n", ret_ft_printf);
    printf("Return value of printf: %d\n", ret_printf);

	printf("##########################\n");
    ret_ft_printf = ft_printf("%%X: %X\n", u);
    ret_printf = printf("%%X: %X\n", u);
    printf("Return value of ft_printf: %d\n", ret_ft_printf);
    printf("Return value of printf: %d\n", ret_printf);

    return 0;
}
