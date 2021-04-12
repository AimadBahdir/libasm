/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 08:11:00 by abahdir           #+#    #+#             */
/*   Updated: 2021/04/12 14:17:41 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

size_t		ft_strlen(const char *str);
char		*ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char		*ft_strdup(const char *s1);


void ft_strlen_test(void)
{
	char	*str;

	printf("\n\033[0;34m::::::::::::::::::::| ft_strlen |::::::::::::::::::::\033[0m\n");
	printf("\n\033[0;33m++++ TEST(1) ++++\033[0m\n");
	str = strdup("Le Lorem Ipsum est simplement du faux texte employé dans la composition et la mise en page avant impression. Le Lorem Ipsum est le faux texte standard de l'imprimerie depuis les années 1500, quand un imprimeur anonyme assembla ensemble des morceaux de texte pour réaliser un livre spécimen de polices de texte. Il n'a pas fait que survivre cinq siècles, mais s'est aussi adapté à la bureautique informatique, sans que son contenu n'en soit modifié. Il a été popularisé dans les années 1960 grâce à la vente de feuilles Letraset contenant des passages du Lorem Ipsum, et, plus récemment, par son inclusion dans des applications de mise en page de texte, comme Aldus PageMaker.");
	printf("\n   - length of '%s'\n\n", str);
	printf("     \033[0;32mMINE: %zu\033[0m\n", ft_strlen(str));
	printf("     \033[0;31mSYST: %zu\033[0m\n", strlen(str));
	printf("\n\033[0;33m++++ TEST(2) ++++\033[0m\n");
	str = strdup("");
	printf("\n   - length of '%s'\n\n", str);
	printf("     \033[0;32mMINE: %zu\033[0m\n", ft_strlen(str));
	printf("     \033[0;31mSYST: %zu\033[0m\n", strlen(str));
	printf("\n\033[0;33m++++ TEST(3) ++++\033[0m\n");
	printf("\n   - length of 'libasm'\n\n");
	printf("     \033[0;32mMINE: %zu\033[0m\n", ft_strlen("libasm"));
	printf("     \033[0;31mSYST: %zu\n\033[0m", strlen("libasm"));
}

void ft_strcpy_test(void)
{
	char	*src;
	char	*dst;
	char	*src1;
	char	*dst1;

	printf("\n\033[0;34m::::::::::::::::::::| ft_strcpy |::::::::::::::::::::\033[0m\n");
	src = strdup("Le Lorem Ipsum est simplement du faux texte employé dans la composition et la mise en page avant impression. Le Lorem Ipsum est le faux texte standard de l'imprimerie depuis les années 1500, quand un imprimeur anonyme assembla ensemble des morceaux de texte pour réaliser un livre spécimen de polices de texte. Il n'a pas fait que survivre cinq siècles, mais s'est aussi adapté à la bureautique informatique, sans que son contenu n'en soit modifié. Il a été popularisé dans les années 1960 grâce à la vente de feuilles Letraset contenant des passages du Lorem Ipsum, et, plus récemment, par son inclusion dans des applications de mise en page de texte, comme Aldus PageMaker.");
	dst = strdup("On sait depuis longtemps que travailler avec du texte lisible et contenant du sens est source de distractions, et empêche de se concentrer sur la mise en page elle-même. L'avantage du Lorem Ipsum sur un texte générique comme 'Du texte. Du texte. Du texte.' est qu'il possède une distribution de lettres plus ou moins normale, et en tout cas comparable avec celle du français standard. De nombreuses suites logicielles de mise en page ou éditeurs de sites Web ont fait du Lorem Ipsum leur faux texte par défaut, et une recherche pour 'Lorem Ipsum' vous conduira vers de nombreux sites qui n'en sont encore qu'à leur phase de construction. Plusieurs versions sont apparues avec le temps, parfois par accident, souvent intentionnellement (histoire d'y rajouter de petits clins d'oeil, voire des phrases embarassantes).");
	src1 = strdup(src);
	dst1 = strdup(dst);
	printf("\n\033[0;33m++++ TEST(1) ++++\033[0m\n");
	printf("\n   - src : '%s'\n\n", src);
	printf("\n   - dest : '%s'\n\n", dst);
	printf("     \033[0;32mMINE: \n\t- src: '%s', \n\t- dst: '%s', \n\t- res: '%s'\033[0m\n", src, dst, ft_strcpy(dst, src));
	printf("     \033[0;31mSYST: \n\t- src: '%s', \n\t- dst: '%s', \n\t- res: '%s'\033[0m\n", src1, dst1, strcpy(dst1, src1));
	printf("\n\033[0;33m++++ TEST(2) ++++\033[0m\n");
	src = strdup("");
	dst = strdup("");
	src1 = strdup("");
	dst1 = strdup("");
	printf("\n   - src : '%s'\n\n", src);
	printf("\n   - dest : '%s'\n\n", dst);
	printf("     \033[0;32mMINE: \n\t- src: '%s', \n\t- dst: '%s', \n\t- res: '%s'\033[0m\n", src, dst, ft_strcpy(dst, src));
	printf("     \033[0;31mSYST: \n\t- src: '%s', \n\t- dst: '%s', \n\t- res: '%s'\033[0m\n", src1, dst1, strcpy(dst1, src1));
	printf("\n\033[0;33m++++ TEST(3) ++++\033[0m\n");
	src = strdup("Libasm");
	dst = strdup("Hello World!");
	src1 = strdup("Libasm");
	dst1 = strdup("Hello World!");
	printf("\n   - src : '%s'\n\n", src);
	printf("\n   - dest : '%s'\n\n", dst);
	printf("     \033[0;32mMINE: \n\t- src: '%s', \n\t- dst: '%s', \n\t- res: '%s'\033[0m\n", src, dst, ft_strcpy(dst, src));
	printf("     \033[0;31mSYST: \n\t- src: '%s', \n\t- dst: '%s', \n\t- res: '%s'\033[0m\n", src1, dst1, strcpy(dst1, src1));
}

void ft_strcmp_test(void)
{
	char *str1;
	char *str2;

	printf("\n\033[0;34m::::::::::::::::::::| ft_strcmp |::::::::::::::::::::\033[0m\n");
	printf("\n\033[0;33m++++ TEST(1) ++++\033[0m\n");
	str1 = strdup("Le Lorem Ipsum est simplement du faux texte employé dans la composition et la mise en page avant impression. Le Lorem Ipsum est le faux texte standard de l'imprimerie depuis les années 1500, quand un imprimeur anonyme assembla ensemble des morceaux de texte pour réaliser un livre spécimen de polices de texte. Il n'a pas fait que survivre cinq siècles, mais s'est aussi adapté à la bureautique informatique, sans que son contenu n'en soit modifié. Il a été popularisé dans les années 1960 grâce à la vente de feuilles Letraset contenant des passages du Lorem Ipsum, et, plus récemment, par son inclusion dans des applications de mise en page de texte, comme Aldus PageMaker.");
	str2 = strdup("On sait depuis longtemps que travailler avec du texte lisible et contenant du sens est source de distractions, et empêche de se concentrer sur la mise en page elle-même. L'avantage du Lorem Ipsum sur un texte générique comme 'Du texte. Du texte. Du texte.' est qu'il possède une distribution de lettres plus ou moins normale, et en tout cas comparable avec celle du français standard. De nombreuses suites logicielles de mise en page ou éditeurs de sites Web ont fait du Lorem Ipsum leur faux texte par défaut, et une recherche pour 'Lorem Ipsum' vous conduira vers de nombreux sites qui n'en sont encore qu'à leur phase de construction. Plusieurs versions sont apparues avec le temps, parfois par accident, souvent intentionnellement (histoire d'y rajouter de petits clins d'oeil, voire des phrases embarassantes).");
	printf("\n	- str1 : '%s'\n", str1);
	printf("\n	- str2 : '%s'\n", str2);
	printf("     \033[0;32mMINE: %d\033[0m\n", ft_strcmp(str1, str2));
	printf("     \033[0;31mSYST: %d\033[0m\n", strcmp(str1, str2));
	printf("\n\033[0;33m++++ TEST(2) ++++\033[0m\n");
	str1 = strdup("");
	str2 = strdup("");
	printf("\n	- str1 : '%s'\n", str1);
	printf("\n	- str2 : '%s'\n", str2);
	printf("     \033[0;32mMINE: %d\033[0m\n", ft_strcmp(str1, str2));
	printf("     \033[0;31mSYST: %d\033[0m\n", strcmp(str1, str2));
	printf("\n\033[0;33m++++ TEST(3) ++++\033[0m\n");
	str1 = strdup("HELLO");
	str2 = strdup("HELLO");
	printf("\n	- str1 : '%s'\n", str1);
	printf("\n	- str2 : '%s'\n", str2);
	printf("     \033[0;32mMINE: %d\033[0m\n", ft_strcmp(str1, str2));
	printf("     \033[0;31mSYST: %d\033[0m\n", strcmp(str1, str2));
}

void ft_write_test(void)
{
	char	*str;
	int		fd1, fd2;

	printf("\n\033[0;34m::::::::::::::::::::| ft_write |::::::::::::::::::::\033[0m\n");
	printf("\n\033[0;33m++++ TEST(1) ++++\033[0m\n");
	str = strdup("Le Lorem Ipsum est simplement du faux texte employé dans la composition et la mise en page avant impression. Le Lorem Ipsum est le faux texte standard de l'imprimerie depuis les années 1500, quand un imprimeur anonyme assembla ensemble des morceaux de texte pour réaliser un livre spécimen de polices de texte. Il n'a pas fait que survivre cinq siècles, mais s'est aussi adapté à la bureautique informatique, sans que son contenu n'en soit modifié. Il a été popularisé dans les années 1960 grâce à la vente de feuilles Letraset contenant des passages du Lorem Ipsum, et, plus récemment, par son inclusion dans des applications de mise en page de texte, comme Aldus PageMaker.");
	printf("\n   - WRITE IN STDOUT '%s'\n\n", str);
	printf("     \033[0;32mMINE: %zu\033[0m\n", ft_write(1, str, ft_strlen(str)));
	printf("     \033[0;31mSYST: %zu\033[0m\n", write(1, str, strlen(str)));
	printf("\n\033[0;33m++++ TEST(2) ++++\033[0m\n");
	fd1 = open("MINE", O_RDWR | O_CREAT, 0644);
	fd2 = open("SYST", O_RDWR | O_CREAT, 0644);
	printf("\n   - WRITE in EXIST file : \n\n");
	printf("     \033[0;32mMINE: %zu\033[0m\n", ft_write(fd1, str, ft_strlen(str)));
	printf("     \033[0;31mSYST: %zu\033[0m\n", write(fd2, str, strlen(str)));
	printf("\n\033[0;33m++++ TEST(3) ++++\033[0m\n");
	printf("\n   - WRITE in ERROR file : \n\n");
	printf("     \033[0;32mMINE: %zu\033[0m\n", ft_write(-5, str, ft_strlen(str)));
	printf("     \033[0;31mSYST: %zu\033[0m\n", write(-5, str, strlen(str)));
}

void ft_read_test(void)
{
	char	*str;
	int		fd1, fd2;

	printf("\n\033[0;34m::::::::::::::::::::| ft_read |::::::::::::::::::::\033[0m\n");
	printf("\n\033[0;33m++++ TEST(1) ++++\033[0m\n");
	fd1 = open("MINE", O_RDWR | O_CREAT, 0644);
	fd2 = open("SYST", O_RDWR | O_CREAT, 0644);
	str = malloc(500);
	printf("\n   - READ 500 Characters FROM 'MINE & SYST' FILES\n\n");
	printf("     \033[0;32mMINE: %zu\033[0m\n", ft_read(fd1, str, 500));
	printf("READ : '%s'\n", str);
	printf("     \033[0;31mSYST: %zu\033[0m\n", read(fd2, str, 500));
	printf("READ : '%s'\n", str);
	free(str);
	str = NULL;
	printf("\n\033[0;33m++++ TEST(2) ++++\033[0m\n");
	printf("\n   - READ FROM NO EXIST file :\n\n");
	printf("     \033[0;32mMINE: %zu\033[0m\n", ft_read(-5, str, 500));
	printf("READ : '%s'\n", str);
	printf("     \033[0;31mSYST: %zu\033[0m\n", read(-5, str, 500));
	printf("READ : '%s'\n", str);
	printf("\n\033[0;33m++++ TEST(3) ++++\033[0m\n");
	free(str);
	str = NULL;
	str = malloc(30);
	printf("\n   - READ 30 chars FROM STDIN :\n\n");
	printf("     \033[0;32mMINE: %zu\033[0m\n", ft_read(0, str, 30));
	printf("READ : '%s'\n", str);
	printf("     \033[0;31mSYST: %zu\033[0m\n", read(0, str, 30));
	printf("READ : '%s'\n", str);
}

void ft_strdup_test(void)
{
	printf("\n\033[0;34m::::::::::::::::::::| ft_strdup |::::::::::::::::::::\033[0m\n");
	printf("\n\033[0;33m++++ TEST(1) ++++\033[0m\n");
	printf("\n	- DUP : 'Le Lorem Ipsum est simplement du faux texte employé dans la composition et la mise en page avant impression. Le Lorem Ipsum est le faux texte standard de l'imprimerie depuis les années 1500, quand un imprimeur anonyme assembla ensemble des morceaux de texte pour réaliser un livre spécimen de polices de texte. Il n'a pas fait que survivre cinq siècles, mais s'est aussi adapté à la bureautique informatique, sans que son contenu n'en soit modifié. Il a été popularisé dans les années 1960 grâce à la vente de feuilles Letraset contenant des passages du Lorem Ipsum, et, plus récemment, par son inclusion dans des applications de mise en page de texte, comme Aldus PageMaker.'\n");
	printf("     \033[0;32mMINE: '%s'\033[0m\n", ft_strdup("Le Lorem Ipsum est simplement du faux texte employé dans la composition et la mise en page avant impression. Le Lorem Ipsum est le faux texte standard de l'imprimerie depuis les années 1500, quand un imprimeur anonyme assembla ensemble des morceaux de texte pour réaliser un livre spécimen de polices de texte. Il n'a pas fait que survivre cinq siècles, mais s'est aussi adapté à la bureautique informatique, sans que son contenu n'en soit modifié. Il a été popularisé dans les années 1960 grâce à la vente de feuilles Letraset contenant des passages du Lorem Ipsum, et, plus récemment, par son inclusion dans des applications de mise en page de texte, comme Aldus PageMaker."));
	printf("     \033[0;31mSYST: '%s'\033[0m\n", strdup("Le Lorem Ipsum est simplement du faux texte employé dans la composition et la mise en page avant impression. Le Lorem Ipsum est le faux texte standard de l'imprimerie depuis les années 1500, quand un imprimeur anonyme assembla ensemble des morceaux de texte pour réaliser un livre spécimen de polices de texte. Il n'a pas fait que survivre cinq siècles, mais s'est aussi adapté à la bureautique informatique, sans que son contenu n'en soit modifié. Il a été popularisé dans les années 1960 grâce à la vente de feuilles Letraset contenant des passages du Lorem Ipsum, et, plus récemment, par son inclusion dans des applications de mise en page de texte, comme Aldus PageMaker."));
	printf("\n\033[0;33m++++ TEST(2) ++++\033[0m\n");
	printf("\n	- DUP : ''\n");
	printf("     \033[0;32mMINE: '%s'\033[0m\n", ft_strdup(""));
	printf("     \033[0;31mSYST: '%s'\033[0m\n", strdup(""));
}


int main(int argc, char **argv)
{
	ft_strlen_test();
	ft_strcpy_test();
	ft_strcmp_test();
	ft_write_test();
	ft_read_test();
	ft_strdup_test();
}