int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buf;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buf);
	if (ret < 0)
		return (-1);
	*line = ft_strdup(str);
	str = ft_substr(str, ft_strchr(str, '\n') + 1);
	return (ret == 0 ? 0 : 1);
}
