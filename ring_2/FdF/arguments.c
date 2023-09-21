//Función para comprobar los argumentos
void check_arguments(t_Data *data, char **argv, int argc)
{
	//t_Map *map;
	int		fd;
	int		x;
	int		y;
	char	*str;	

	//map = createMap();

	if (argc != 2)
		exit(EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	str = get_next_line(fd);
	while (str != NULL)
	{
		str = get_next_line(fd);
		ft_printf("%s",str);
	}
	close(fd);
	//data->map = map;
}

int32_t	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	char	**matrix;
	int		x;
	int		i;
	int		j;

	if (argc != 2)
		exit(EXIT_FAILURE);

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	x = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		ft_printf("%s", str);
		matrix = ft_split(str, ' ');
		i = 0;
		while (matrix[i])
		{
			j = 0;
			while (matrix[i][j] && matrix[i][j] != '\n')
			{
				if (!ft_isdigit(matrix[i][j++]))
					exit(EXIT_FAILURE);
			}			
			//ft_printf("x:%i y:%i z:%i ", x, i, ft_atoi(matrix[i]));
			//ft_printf("\n");
			i++;
		}
		//ft_printf("\n");
		x++;
		str = get_next_line(fd);
	}
	close(fd);
    //x` = (x - y) * cos(angle)
    //y` = (x + y) * sin(angle) - z
	return (EXIT_SUCCESS);
}
