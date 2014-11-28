#include "ft_ls.h"
int g_sargs;
int g_pargs;
int g_oargs;
int g_hargs;

char	*ft_memconcat(char *s1, char *s2)
{
	char *ret_str;

	ret_str = NULL;
	ret_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1)
	{
		ft_strcpy(ret_str, s1);
		free(s1);
	}
	if (s2)
		ft_strcat(ret_str, s2);
	if (!s1 && !s2)
		return (NULL);
	else
		return (ret_str);
}
void ft_new_r(t_lista **n, t_lista **list, t_lista **first, struct dirent *dp)
{
	t_lista *aux;

	aux = (*list);
	while ((*list))
	{
		if (ft_strcmp(dp->d_name, (*list)->content) > 0)
		{
			if (aux == (*list))
			{
				(*n)->next = (*list);
				(*first) = (*n);
			}
			else
			{
				(*n)->next = aux->next;
				aux->next = (*n);
			}
			break ;
		}
		aux = (*list);
		(*list) = (*list)->next;
	}
	if (!(*list))
	{
		(*n)->next = 0;
		aux->next = (*n);
	}
}
void ft_new(t_lista **n, t_lista **list, t_lista **first, struct dirent *dp)
{
	t_lista *aux;

	aux = (*list);
	while ((*list))
	{
		if (ft_strcmp(dp->d_name, (*list)->content) < 0)
		{
			if (aux == (*list))
			{
				(*n)->next = (*list);
				(*first) = (*n);
			}
			else
			{
				(*n)->next = aux->next;
				aux->next = (*n);
			}
			break ;
		}
		aux = (*list);
		(*list) = (*list)->next;
	}
	if (!(*list))
	{
		(*n)->next = 0;
		aux->next = (*n);
	}
}
void lst_add(t_lista **list, struct dirent *dp)
{
	t_lista *new;
	t_lista *first;

	if (!(*list))
	{
		(*list) = (t_lista *)ft_memalloc(sizeof(t_lista));
		(*list)->content = ft_strdup(dp->d_name);
		(*list)->content_size = dp->d_reclen;
		(*list)->content_type = dp->d_type;
	}
	else
	{
		new = (t_lista *)ft_memalloc(sizeof(t_lista));
		first = (*list);
		new->content = ft_strdup(dp->d_name);
		new->content_size = dp->d_reclen;
		new->content_type = dp->d_type;
		if (g_oargs == 0)//here is decided the printing order
			ft_new(&new, list, &first, dp);
		if (g_oargs == 1)
			ft_new_r(&new, list, &first, dp);
		(*list) = first;
	}
}
t_len *ft_build_print_data(t_lista *lst, char *path)
{
	size_t	max;
	char *temp_path;
	t_len *lens;

	max = 0;
	lens = (t_len *)ft_memalloc(sizeof(t_len));
	temp_path = path;
	path = ft_strjoin(path, "/");
	free(temp_path);
	while (lst)
	{
		temp_path = ft_strjoin(path, lst->content);	
		lst->infos = grab_infos(temp_path);
		if (ft_strlen(lst->infos->filename) > lens->filename_len)
			lens->filename_len = ft_strlen(lst->infos->filename);
		if (ft_strlen(lst->infos->links) > lens->links_len)
			lens->links_len = ft_strlen(lst->infos->links);
		if (ft_strlen(lst->infos->usrname) > lens->username_len)
			lens->username_len = ft_strlen(lst->infos->usrname);
		if (ft_strlen(lst->infos->usrgrp) > lens->usrgrp_len)
			lens->usrgrp_len = ft_strlen(lst->infos->usrgrp);
		if (ft_strlen(lst->infos->bytesize) > lens->bytesize_len)
			lens->bytesize_len = ft_strlen(lst->infos->bytesize);
		lst = lst->next;
		free(temp_path);
	}
	return (lens);
}
void ft_add_spaces(size_t max_len, char **string)//adds spaces for printing
{
	char *free_help;

	while (ft_strlen(*string) < max_len)
	{
		free_help = *string;
		*string = ft_strjoin(" ", *string);
		free(free_help);
	}
}
char *assemble_string(t_lista *elem,  t_len *lens)
{
	char *ret_val;

	ret_val = ft_strjoin(elem->infos->acces, "  ");
	ft_add_spaces(lens->links_len, &(elem->infos->links));
	ret_val = ft_memconcat(ret_val, elem->infos->links);
	ret_val = ft_memconcat(ret_val, " ");
	ft_add_spaces(lens->username_len, &(elem->infos->usrname));
	ret_val = ft_memconcat(ret_val, elem->infos->usrname);
	ret_val = ft_memconcat(ret_val, "  ");
	ft_add_spaces(lens->usrgrp_len, &(elem->infos->usrgrp));
	ret_val = ft_memconcat(ret_val, elem->infos->usrgrp);
	ret_val = ft_memconcat(ret_val, "  ");
	ft_add_spaces(lens->bytesize_len, &(elem->infos->bytesize));
	ret_val = ft_memconcat(ret_val, elem->infos->bytesize);
	ret_val = ft_memconcat(ret_val, " ");
	ret_val = ft_memconcat(ret_val, elem->infos->date_formated);
	ret_val = ft_memconcat(ret_val, " ");
	ret_val = ft_memconcat(ret_val, elem->content);
	return (ret_val);
	//posibil un free la lens aici
}
int ft_add_blocksize(t_lista *list, char hidden)
{
	int ret;

	ret = 0;
	while (list)
	{
		if (*((char *)list->content) != hidden)
			ret = ret + (int)list->infos->blksize;
		list = list->next;
	}
	return (ret);
}
void ft_print(t_lista *list, t_len *lens)
{
	char	hidden;

	hidden = 0;
	if (!g_hargs)
		hidden = '.';
	if (g_pargs)
	{
		ft_putstr("total ");
		ft_putnbr(ft_add_blocksize(list, hidden));
		ft_putendl("");
	}
	while (list)
	{
		if (*((char *)list->content) != hidden)
		{
			if (!g_pargs)
				ft_putendl(list->content);
			else
			{
				ft_putendl(assemble_string(list, lens));
			}
		}
		list = list->next;
	}
}
void print_dir(DIR *directory, char *dir_path)
{
	t_lista			*list;
	struct dirent	*temp;

	list = NULL;
	while ((temp = readdir(directory)) != NULL)
		lst_add(&list, temp);
	ft_print(list, ft_build_print_data(list, dir_path));
}

void paths_now_what(char **paths, int put_dirnames)
{
	int			i;
	struct stat	*s_stat;
	DIR 		*directory;

	s_stat = (struct stat *)malloc(sizeof(struct stat));
	i = 0;
	//first print files then print directories
	while (paths[i])
	{
		if (lstat(paths[i], s_stat) == 0)
		{
			if(!(S_ISDIR(s_stat->st_mode)))
			{
				ft_putendl(paths[i]);
				free(s_stat);
				s_stat = (struct stat *)malloc(sizeof(struct stat));
			}
		}
		else
			perror("ft_ls: ");
		i++;
	}
	i = 0;
	while (paths[i])
	{
		if (lstat(paths[i], s_stat) == 0)
		{
			if (S_ISDIR(s_stat->st_mode))
			{
				free(s_stat);
				s_stat = (struct stat *)malloc(sizeof(struct stat));
				if ((directory = opendir(paths[i])) != NULL)
				{
					if (put_dirnames)
					{
						ft_putstr(paths[i]);
						ft_putendl(":");
					}
					print_dir(directory, ft_strdup(paths[i]));
					if (paths[i + 1])
						ft_putendl("");
					closedir(directory);
				}
				else
					perror("ft_ls ");
			}
		}
		else
			perror("ft_ls ");
		i++;
	}
	ft_putchar(8);
}
