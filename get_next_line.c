/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:00:39 by krwongwa          #+#    #+#             */
/*   Updated: 2024/02/18 22:44:26 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *clearline(char *file,size_t pos)
{
	char *temp;
	size_t num;
	size_t n;

	num = ft_strlen(file) - pos;
	if (num == 0)
	{
		free(file);
		file = ft_strdup("");
	}
	else
	{
		n = 0;
		temp =malloc(sizeof(char)  * (num));
		if (!temp)
		temp[num] = '\0';
		num = 0;
		// printf("%ld\n",pos);
		while (file[pos - 1 +num])
		{
			temp[num] = file[pos+num];
			num++;
		}
		// printf("TEMP IS [%s]\n",temp);
		free(file);
		file = temp;
	}
	return(file);
}

char *readline(char *file,char *buffer,int fd)
{
	ssize_t len;

	len = 1;
	while (len > 0 && ft_strrchr(file,'\n') == NULL)
	{
		len = read(fd,buffer,BUFFER_SIZE);
		if (len == -1)
		{
			free(file);
			free(buffer);
			return (NULL);
		}
		buffer[len] = '\0';
		file = ft_strjoin(file,buffer);
		if (!file)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (file);
}

char *makebuff(char **file,int fd)
{
	char *buffer;

	if (BUFFER_SIZE <= 0 && fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer[BUFFER_SIZE] = '\0';
	if (!buffer)
	{
		free(file[fd]);
		file[fd] = NULL;
		return(NULL);
	}
	if (file[fd] == NULL)
		file[fd] = ft_strdup("");
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char * file[FD_MAX + 1];
	char *ans;
	char	*buffer;
	size_t count;

	count = 0;
	ans = NULL;
	file[FD_MAX] = NULL;
	buffer = makebuff(file,fd);
	if (!buffer)
		return (NULL);
	file[fd] = readline(file[fd],buffer,fd);
	while(file[fd][count] != '\0' && file[fd][count++] != '\n');
	// printf("indext in count is %c\n",file[fd][count]);
	ans = malloc(sizeof(char) * count + 1);
	ans[count] = '\0';
	ft_memcpy(ans,file[fd],count);
	if (!ans)
	{
		free(file[fd]);
		file[fd] = NULL;
	}
	file[fd] = clearline(file[fd],count);
	return (ans);
}

int main()
{
	int fd = open("test.txt",O_RDONLY);
	char *ans;
	while ((ans =  get_next_line(fd)))
	{
		printf("%s",ans);
		free(ans);
	}

	// ans = get_next_line(fd);
	// 	printf("%s",ans);
	// 	free(ans);
	// printf("-------------------\n");
	// ans = get_next_line(fd);
	// 	printf("%s",ans);
	// 	free(ans);
}
