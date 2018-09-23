/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:39:07 by juthomas          #+#    #+#             */
/*   Updated: 2018/07/11 15:57:02 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

// static void		keskese(int type)
// {
// 	if (type == DT_BLK)
// 		ft_putstr("b");
// 	else if (type == DT_CHR)
// 		ft_putstr("c");
// 	else if (type == DT_DIR)
// 		ft_putstr("d");
// 	else if (type == DT_FIFO)
// 		ft_putstr("p");
// 	else if (type == DT_LNK)
// 		ft_putstr("l");
// 	else if (type == DT_REG)
// 		ft_putstr("-");
// 	else if (type == DT_SOCK)
// 		ft_putstr("s");
// 	else if (type == DT_UNKNOWN)
// 		ft_putstr("d");
// }

char *modifpath(const char *s1, const char *s2)
{
	char *ret;

	ret = NULL;
	if (!(ret = ft_stralloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ret = ft_strcpy(ret, s1);
	ret = ft_strcat(ret, "/");
	ret = ft_strcat(ret, s2);
	
	return (ret);
}

static void		putmode(int mode)
{
	if ((mode & S_IFMT) == S_IFBLK)
		ft_putchar('b');
	else if ((mode & S_IFMT) == S_IFCHR)
		ft_putchar('c');
	else if ((mode & S_IFMT) == S_IFDIR)
		ft_putchar('d');
	else if ((mode & S_IFMT) == S_IFLNK)
		ft_putchar('l');
	else if ((mode & S_IFMT) == S_IFSOCK)
		ft_putchar('s');
	else if ((mode & S_IFMT) == S_IFIFO)
		ft_putchar('p');
	else if ((mode & S_IFMT) == S_IFREG)
		ft_putchar('-');
	else
		ft_putchar('?');

	if (mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');

	if (mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');

	if (mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');




}

static int			get_parttime(char *str, int part)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i] != '\0' && word < part)
	{
		while (str[i] && (str[i] == '\t' || str[i] == ' '))
			i++;
		while (str[i] && str[i] != '\t' && str[i] != ' ')
			i++;
		while (str[i] && (str[i] == '\t' || str[i] == ' '))
			i++;
		word++;
	}
	return (i);
}

void			put_time(char *str, int max)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && i < max)
		ft_putchar(str[i++]);
}


void			get_info(const char *path)
{
	struct stat buf;

	int value;
	char *date;
	time_t	our_date;
	struct passwd *pwd;
	struct group *grd;

	/*
	** Recuperer la structure stat qui contient toutes les infos du document en question
	*/

	value = lstat(path, &buf);
	
	/*
	** Le noeud st_mode contient le type de fichier et les droits de RWX associes sous
	** un int, on peut recuperer les valeurs voulues grace a des flags binaires S_
	*/
	
	putmode((int)buf.st_mode);
	ft_putchar('\t');
	
	/*
	** Le noeud st_nlink contient le nombre de liens materiels associes au document
	*/
	
	ft_putnbr_fd((int)buf.st_nlink, 1);
	ft_putchar('\t');	

	/*
	** Le noeud st_uid est un int qui correspond a l'uid du proprietaire
	** grace a la fonction getpwuid on recupere une structure psswd qui
	** contient la string du nom du proprietaire correspondant a l'uid
	*/

	pwd = getpwuid(buf.st_uid);
	if (pwd)
		ft_putstr(pwd->pw_name);
	ft_putchar('\t');	

	/*
	** Le noeud st_gid a le meme fonctionnement que le noeud st_uid mais il
	** doit passer par la fonction getgrgid pour recuper une structure group
	** qui a le meme fonctionnement que la structure psswd, elle contient donc
	** le nom du groupe associe a l'utilisateur
	*/

	grd = getgrgid(buf.st_gid);
	if (grd)
		ft_putstr(grd->gr_name);
	ft_putchar('\t');	

	/*
	** le noeud st_size contient tout simplement un int qui correspond
	** a la taille du fichier en bytes
	*/

	ft_putnbr_fd((int)buf.st_size, 1);
	ft_putchar('\t');

	/*
	** L'appel de ctime transforme un time_t en string sous le format :
	** "Day Month DD HH/MM/SS YYYY\n"
	*/

	date = ctime(&buf.st_mtime);
	
	// On imprime le Month
	put_time(&date[get_parttime(date, 1)], 10);
	ft_putchar('\t');
	
	// On imprime le Day
	put_time(&date[get_parttime(date, 2)], 10);
	ft_putchar('\t');		
	our_date = time(NULL);
	
	/*
	** Si le fichier a ete modifie il y a plus de 6 mois ou si il sera modifie
	** dans plus de 6 mois on imprime juste l'annee sinon on imprime HH/MM
	*/
	if (our_date + 15768000 < buf.st_mtime || our_date - 15768000 > buf.st_mtime)
		put_time(&date[get_parttime(date, 4)], 10);
	else
		put_time(&date[get_parttime(date, 3)], 5);
	ft_putchar('\t');		

}

void	test(int argc, char **argv)
{
	char *ret;
	DIR	*dir;
	struct dirent *dp;
	char *path;

	if (argc != 2)
		return ;
	path = argv[1];
	if ((dir = opendir(path)) == NULL)
	{
		ft_putstr("Ca pue\n");
	}
	while ((dp = readdir(dir)) != NULL)
	{
	//		keskese(dp->d_type);
			ret = modifpath(path, dp->d_name);
			get_info(ret);
			ft_putstr("\t");
			ft_putstr(dp->d_name);
			ft_putstr("\t");
			ft_putstr(ret);			
			ft_putstr("\n");
			if (dp->d_type == DT_DIR && ft_strcmp(dp->d_name, ".") && ft_strcmp(dp->d_name, ".."))
			{
				// ret = ft_strjoin("./", dp->d_name);
				printf("retour | %s\n", ret);
			}
		//	return (0);
	}
	(void) printf("fin\n");
	(void) closedir(dir);




	ft_putstr("cc cv?\n");
	if (errno)
		ft_putstr(strerror(errno));


}