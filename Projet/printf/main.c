/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 13:49:20 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 13:13:07 by qmoricea    ###    #+. /#+    ###.fr     */
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

	// Test h (d i // u o x X)
	ft_printf("%hX", 10);
	write(1, "\n", 1);
	printf("h %hX%s\n", (short)10, "->printf");

	// Test hh (d i // u o x X)
	ft_printf("%hhd", 18);
	write(1, "\n", 1);
	printf("hh %hhd%s\n", (signed char)18, "->printf");

	// Test l (d i // u o x X)
	ft_printf("%ld", (long)21474836471);
	write(1, "\n", 1);
	printf("l %ld%s\n", (long)21474836471, "->printf");

	// Test ll (d i // u o x X)
	ft_printf("%lld", (long long)9223372036854775807);
	write(1, "\n", 1);
	printf("ll %lld%s\n", (long long)9223372036854775807, "->printf");

	// Test j (d i // u o x X)
	ft_printf("%jX", (unsigned long)238);
	write(1, "\n", 1);
	printf("j %jX%s\n", (unsigned long)238, "->printf");

	// Test z (d i // u o x X)
	ft_printf("%zd", 21474836471);
	write(1, "\n", 1);
	printf("z %zd%s\n", 21474836471, "->printf");

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
	ft_printf("%#5X", 15);
	write(1, "\n", 1);
	printf("0 %#5X%s\n", 15, "->printf");

	//Test p
	ft_printf("%p", p);
	write(1, "\n", 1);
	printf("p %p%s\n", p, "->printf");

	printf("%s \n", "----------------------------------------");
	printf("%p\n", p);
	printf("%01d", 5);
}
