/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <nibouniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:53:37 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/24 20:37:40 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_H
# define FT_H

typedef struct file_param
{
	int		size_file;
	char	*file_name;
}	t_file_param;

typedef struct dictio
{
	char	**dictio_parsed;
	char	*dictio;
}	t_dictio;

typedef struct number
{
	char	*number_array;
	char	*number_word;
	int		number_length;
}	t_number;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				check_error(char *argv);
int				ft_strlen(char *src);
int				getsign(char c, int *s);
char			*ft_atoi_char(char *str);
int				ft_strcmp(char *s1, char *s2);
void			setup_struct(char *file_name);
int				length_file(char *file_name);
t_dictio		*get_dictio(t_file_param *file_p);
t_dictio		*ft_check_dict(t_dictio *dictio);
t_dictio		*corr_dictio(t_dictio *dictio_p);
char			*ft_strdup(char *src);
char			*f_snc(char *dest, char *src, unsigned int b1, unsigned int b2);
int				check_charset(char c, char *charset);
int				check_word(char *str, char *charset);
char			**ft_split(char *str, char *charset);
char			*ft_strcat(char *dest, char *src);
char			*ft_strjoin(int size, char **strs, char *sep);
t_number		*setup_nbstruct(char *argv);
int				ft_charcmp(char c, char *s2);
void			print_u(char c, t_dictio *dictio);
int				getindex_10(char *number, t_dictio *dictio, int start_pos);
int				getindex_20(char *number, t_dictio *dictio, int start_pos);
int				print_d(t_dictio *dictio, char *number, int start_pos);
void			print_h(t_dictio *dictio, char *number, int start_pos);
void			print_th(t_dictio *dictio, char *number, int start_pos);
void			write_nb(t_dictio *dictio, t_number *number);
int				check_error(char *argv);
int				rush(char *argv);
int				rush_w_dict(char *argv1, char *argv2);

#endif
