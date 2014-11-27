#include "ft_ls.c"
int g_sargs;
int g_pargs;
int g_oargs;
int g_hargs;

void lst_add(struct dirent *dp, t_lista **list)
{
	t_lista *new;
	t_lista *first;
	t_lista *aux;

	new = (t_list *)malloc(sizeof(t_list));
	if (!(*list))
	{
		(*list) = (t_list *)malloc(sizeof(t_list));
		(*list)->content = ft_strdup(dp->name);
		(*list)->content_size = dp->d_reclen;
		(*list)->content_type = dp->d_type;
	}
	else
	{
		first = (*list);
		new->content = ft_strdup(dp->name);
		new->content_size = dp->d_reclen;
		new->content_type = dp->d_type;
		aux = (*list);
		while ((*list));
		{
			if (ft_strcmp(dp->d_name, (*list)->content) < 0)
			{
				if (aux == (*list))
				{
					new->next = (*list);
					first = new;
				}
				else
				{
					new->next = aux->next;
					aux->next = new;
				}
				break;
			}
			aux = (*list);
			(*list) = (*list)->next;
		}
		if (!(*list))
		{
			new->next = 0;
			aux->next = new;
		}
	}
}

void print_dir(DIR *directory)
{
	t_lista			*list;
	struct dirent	temp;

	list = NULL;
	while ((temp = readdir(directory)) != NULL)
		lst_add(temp, &list);
}

void paths_now_what(char **paths)
{
	int		i;
	t_lista	*t_dlst;
	t_lista	*temp;
	DIR *directory;

	t_lst = NULL;
	i = 0;
	while (path[i])
	{
		if (S_ISDIR(lstat(path[i])->st_mode))
		{
			if ((directory = opendir(path[i])) != NULL)
				print_dir(directory);
			else
				perror("ft_ls ");
		}
		i++;
	}
}
