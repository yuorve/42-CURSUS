/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:46:54 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/23 20:29:11 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

int		ft_toupper(int c);
int		ft_toupper(int c);
int		ft_atoi(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);

size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, char *scr, size_t size);
size_t	ft_strlcat(char *dest, char *scr, size_t size);

char	*ft_strdup(char *src);
char	*strrchr(const char *s, int c);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero(void *s, size_t n);

#endif
