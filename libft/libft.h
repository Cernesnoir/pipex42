/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:36:05 by anmuller          #+#    #+#             */
/*   Updated: 2026/01/21 11:36:09 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

size_t	ft_strlen(const char *str);
int		ft_isalnum(int c);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dest, char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_putchar_printf(char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memset(void *zone_vide, int valeur, size_t nombre);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *stash, char *s2);
void	str_fill(char **result, char **str1, char **str2);
int		ft_strchr_gnl(char *str, char c);
char	*ft_strdup_gnl(char *src);
char	*get_next_line(int fd);
char	*clear_all(char **buffer, char **stash);
char	*extract_remain(char *stash);
char	*extract_line(char *stash);
void	line_manager(char **stash, char *line);
int		ft_printf(const char *str, ...);
int		ft_putstr_printf(char *s);
int		ft_putchar_printf(char c);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putptr_printf(void *ptr);
int		ft_putnbr_int(long nbr);
int		ft_putnbr_un(unsigned int nbr);
int		ft_putnbr_uint(uintptr_t nbr, char *base);

#endif
