/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/14 11:10:23 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/14 11:18:14 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char *argv[])
{
	Personnes user;

	printf("Nom? ");
	scanf("%s", user.Nom);
	printf("Prenom? ");
	scanf("%s", user.Prenom);

	printf("Nom: %s / Prenom: %s", user.Nom, user.Prenom);
	return (0);
}
