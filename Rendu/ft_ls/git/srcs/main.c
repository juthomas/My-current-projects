/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:12:02 by juthomas          #+#    #+#             */
/*   Updated: 2018/07/10 11:38:13 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
void	test(int argc, char **argv);


// static void		keskese(int type)
// {
// 	if (type == DT_BLK)
// 		ft_putstr("C'est un périphérique de blocs.\n");
// 	else if (type == DT_CHR)
// 		ft_putstr("C'est un périphérique de caractères.\n");
// 	else if (type == DT_DIR)
// 		ft_putstr("C'est un répertoire.\n");
// 	else if (type == DT_FIFO)
// 		ft_putstr("C'est un tube nommé (FIFO).\n");
// 	else if (type == DT_LNK)
// 		ft_putstr("C'est un lien symbolique.\n");
// 	else if (type == DT_REG)
// 		ft_putstr("C'est un fichier ordinaire.\n");
// 	else if (type == DT_SOCK)
// 		ft_putstr("C'est une socket de domaine Unix.\n");
// 	else if (type == DT_UNKNOWN)
// 		ft_putstr("Le type de fichier est inconnu.\n");
// }

// static void	test_lib(char *s1, char *s2)
// {
// 	char *cpy;

// 	cpy = ft_strjoin(s1, s2);
// 	ft_putstr(cpy);
// 	ft_putstr("ah\n\n\n");
// }

int		main(int argc, char **argv)
{
	(void)argv;
	(void)argc;

	test(argc, argv);
	
	// char *ret;
	// DIR	*dir;
	// struct dirent *dp;
	// if (argc != 2)
	// 	return (0);


	// if ((dir = opendir(argv[1])) == NULL)
	// {
	// 	ft_putstr("Ca pue\n");
	// }
	// while ((dp = readdir(dir)) != NULL)
	// {
	// 		(void) printf("\nname: %s\n", dp->d_name);
	// 		keskese(dp->d_type);
	// 		if (dp->d_type == DT_DIR && ft_strcmp(dp->d_name, ".") && ft_strcmp(dp->d_name, ".."))
	// 		{
	// 			ret = ft_strjoin("./", dp->d_name);
	// 			printf("retour | %s\n", ret);
	// 		}
	// 	//	return (0);
	// }
	// (void) printf("fin\n");
	// (void) closedir(dir);




	// ft_putstr("cc cv?\n");
	// if (errno)
	// 	ft_putstr(strerror(errno));
	// test_lib("cccccwecwe  s", " cvcccccccb");
}