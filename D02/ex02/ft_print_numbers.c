/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:15:40 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/07 20:44:20 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void ft_print_number(void)
{
	 int i;

	 i = 0;
	 while(i < 10)
	 {
		 ft_putchar('0' + i);
		 i++;
	 }

}

