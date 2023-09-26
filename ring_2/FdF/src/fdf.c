/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:30:41 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/26 11:44:15 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// Ajustar la proyección según la profundidad que da el ángulo de visión
t_Point2D	transformTo2D(t_Point3D point, int depth) {
    t_Point2D 	transformTo2D;
	double		angle;
	//Proyección Lineal
    //transformTo2D.x = point.x;
    //transformTo2D.y = point.y - (point.z / depth);
	//Proyección Isometrica
	angle = depth *(M_PI / 180.0);
	transformTo2D.x = point.x + cos(angle) * point.z - cos(angle) * point.y;
	transformTo2D.y = -point.y * sin(angle) - point.z * sin(angle);
    return transformTo2D;
}

void	 	isometricView(t_Point2D point, t_Point2D *projected, int offset, int scale)
{
	//projected->x = point.x - point.y;
	//projected->y = (point.x + point.y) / 2;
	projected->x = (point.x * scale) + offset;
	projected->y = (point.y * scale) + offset;
}

// Función para dibujar la línea utilizando el algoritmo de Bresenham
void		draw_line(t_Line *line, int width)
{
	t_Point2D 	*point;
	t_Point2D 	*direction;
	t_Point2D 	*distance;
	int			correction;
	int			tracker;
	int			i;

    point = (t_Point2D *)malloc(sizeof(t_Point2D));
    if (point == NULL)
		exit(EXIT_FAILURE);
    direction = (t_Point2D *)malloc(sizeof(t_Point2D));
    if (direction == NULL)
		exit(EXIT_FAILURE);	
    distance = (t_Point2D *)malloc(sizeof(t_Point2D));
    if (distance == NULL)
		exit(EXIT_FAILURE);
	distance->x = abs(line->end->x - line->start->x);
	distance->y = abs(line->end->y - line->start->y);
	if (line->start->x < line->end->x)
		direction->x = 1;
	else
		direction->x = -1;
	if (line->start->y < line->end->y)
		direction->y = 1;
	else
		direction->y = -1;
	correction = distance->x - distance->y;
	point = line->start;
	while (1)
	{
		if (width > 1)
		{
			i = -(width/2);
			while (i < (width/2))
				ft_printf("Point x: %i y: %i \n",point->x, point->y + i++);
		}
		else
			ft_printf("Point x: %i y: %i \n",point->x, point->y);
		if (point->x == line->end->x && point->y == line->end->y)
			break ;		
		tracker =  2 * correction;
		if (tracker > -distance->y)
		{
			correction -= distance->y;
			point->x += direction->x;
		}
		if (tracker < distance->x)
		{
			correction += distance->x;
			point->y += direction->y;
		}
	}
}

void	ft_void(void)
{
	system("leaks -q 'push_swap'");
}

int32_t		main(int argc, char **argv)
{
	atexit(ft_void);
	int			fd;
	char		*str;
	t_Line		*line;
	t_Point3D 	*point;
	t_Point2D 	*projected;
	
	if (argc != 2)
		exit(EXIT_FAILURE);
 	// Leer el fichero fdf
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	str = get_next_line(fd);
	while (str != NULL)
	{
		ft_printf("%s",str);
		str = get_next_line(fd);		
	}
	close(fd);
	ft_printf("\n");
    // Inicializar la estructura line
    line = (t_Line *)malloc(sizeof(t_Line));
    if (line == NULL)
        exit(EXIT_FAILURE);
    // Inicializar la estructura point3D
    point = (t_Point3D *)malloc(sizeof(t_Point3D));
    if (point == NULL)
        exit(EXIT_FAILURE);
    // Inicializar la estructura projected
    projected = (t_Point2D *)malloc(sizeof(t_Point2D));
    if (projected == NULL)
        exit(EXIT_FAILURE);	
    point->x = 1;
    point->y = 1;
	point->z = 0;
	isometricView(transformTo2D(*point, 10), projected, 100, 10);	
    line->start = projected;
	//line->start = point;
	// Crear otro punto y asignarlo como el final de la línea
    point = (t_Point3D *)malloc(sizeof(t_Point3D));
    if (point == NULL)
        exit(EXIT_FAILURE);
    // Inicializar la estructura projected para el final de la línea
    projected = (t_Point2D *)malloc(sizeof(t_Point2D));
    if (projected == NULL)
        exit(EXIT_FAILURE);	
    point->x = 2;
    point->y = 2;
	point->z = 5;
	isometricView(transformTo2D(*point, 10), projected, 100, 10);	
    line->end = projected;
	//line->end = point;
	// Dibujar la línea proyectada entre los dos puntos	
	draw_line(line, 1);
    // Liberar la memoria
    free(line);
    free(point);
	free(projected);
	return (EXIT_SUCCESS);
}
