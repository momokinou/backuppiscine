/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/15 09:17:58 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/15 09:43:11 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*Partie Includes necessaires*/
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"

/*Define Keymap Options*/

/*Gestion de la 3D*/
typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point;

#endif
