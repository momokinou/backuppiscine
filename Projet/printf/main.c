/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 13:49:20 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 08:43:30 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include "stdio.h"

int		main(void)
{
	char *p;

	p = "test";
	// Test d
	ft_printf("%d", 545665);
	write(1, "\n", 1);
	printf("d %d%s\n", 545665, "->printf");

	// Test c
	ft_printf("%c", 'c');
	write(1, "\n", 1);
	printf("c %c%s\n", 'c', "->printf");

	// Test i
	ft_printf("%i", 0);
	write(1, "\n", 1);
	printf("i %i%s\n", 0, "->printf");

	// Test o
	ft_printf("%o", 95);
	write(1, "\n", 1);
	printf("o %o%s\n", 95, "->printf");

	// Test x
	ft_printf("%x", 101);
	write(1, "\n", 1);
	printf("x %x%s\n", 101, "->printf");

	// Test X
	ft_printf("%X", 42);
	write(1, "\n", 1);
	printf("X %X%s\n", 42, "->printf");

	// Test s
	ft_printf("%s", "test string");
	write(1, "\n", 1);
	printf("s %s%s\n", "test string", "->printf");

	// Test u
	ft_printf("%u", 101);
	write(1, "\n", 1);
	printf("u %u%s\n", 101, "->printf");

	// Test %%
	ft_printf("%%");
	write(1, "\n", 1);
	printf("%%");
	printf("%s\n", "->printf");

	// Partie Test des Flags - + ' ' et #
	// Test - (MINUS)
	ft_printf("%-d", 95);
	write(1, "\n", 1);
	printf("- %-d%s\n", 95, "->printf");

	// Test + (PLUS)
	ft_printf("%+d", 58);
	write(1, "\n", 1);
	printf("+ %+d%s\n", 58, "->printf");

	// Test ' ' (Space)
	ft_printf("% d", 18);
	write(1, "\n", 1);
	printf("% d%s\n", 18, "->printf");

	// Test # (Hashtag)
	ft_printf("%#x", 36);
	write(1, "\n", 1);
	printf("%#x%s\n", 36, "->printf");

	//Test 0 (Zero)
	ft_printf("%05d", 15);
	write(1, "\n", 1);
	printf("%05d%s\n", 15, "->printf");

	printf("%s \n", "----------------------------------------");
	printf("%p\n", p);
	printf("%01d", 5);
}
