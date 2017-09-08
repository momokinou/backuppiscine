/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:07:36 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/08 09:52:41 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void ft_print_reverse_alphabet(void)
{
	 int i;

	 i = 0;
	 while(i < 26)
	 {
	 	ft_putchar('z' - i);
	 	i++;
	 }

}
