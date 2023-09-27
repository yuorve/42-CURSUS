/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:30:41 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/27 16:01:56 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// Función para crear un punto
t_Point2D	*createPoint()
{
	t_Point2D *point;

	point = (t_Point2D *)malloc(sizeof(t_Point2D));
    if (point == NULL)
		exit(EXIT_FAILURE);
	point->x = 0;
	point->y = 0;
	return point;
}

// Función para crear un punto 3D
t_Point3D	*createPoint3D()
{
	t_Point3D *point;

	point = (t_Point3D *)malloc(sizeof(t_Point3D));
    if (point == NULL)
		exit(EXIT_FAILURE);
	point->x = 0;
	point->y = 0;
	point->z = 0;
	return point;
}

// Ajustar la proyección según la profundidad que da el ángulo de visión
t_Point2D	*transformTo2D(t_Point3D point, int depth) {
    t_Point2D 	*transformTo2D;
	double		angle;
	
	transformTo2D = createPoint();
	angle = depth *(M_PI / 180.0);
	//Proyección Isometrica
    //transformTo2D->x = (point.x - point.y) * cos(angle);
    //transformTo2D->y = (point.x + point.y) * sin(angle) - point.z * sin(angle);
	//transformTo2D->x = point.x + cos(angle) * point.z;
	//transformTo2D->y = point.y + sin(angle) * point.z;	
	transformTo2D->x = point.x + cos(angle) * point.z - cos(angle) * point.y;
	transformTo2D->y = -point.y * sin(angle) - point.z * sin(angle);
	printf("Point2D x: %f y: %f \n",transformTo2D->x, transformTo2D->y);
    return transformTo2D;
}

void	 	isometricView(t_Point2D *point, t_Point2D *projected, int offset, int scale)
{
	projected->x = (point->x * scale) + offset;
	projected->y = (point->y * scale) + offset;
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

    point = createPoint();
    direction = createPoint();
    distance = createPoint();
	distance->x = fabs(line->end->x - line->start->x);
	distance->y = fabs(line->end->y - line->start->y);
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
				printf("Point x: %f y: %f \n",point->x, point->y + i++);
		}
		else
			printf("Point x: %f y: %f \n",point->x, point->y);
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
    point = createPoint3D();
    // Inicializar la estructura projected
    projected = createPoint();
    point->x = 0;
    point->y = 0;
	point->z = 0;
	isometricView(transformTo2D(*point, 45), projected, 100, 10);	
    line->start = projected;
	//line->start = point;
	// Crear otro punto y asignarlo como el final de la línea
    point = createPoint3D();
    // Inicializar la estructura projected para el final de la línea
    projected = createPoint();
    point->x = 1;
    point->y = 0;
	point->z = 0;
	isometricView(transformTo2D(*point, 45), projected, 100, 10);	
    line->end = projected;
	//line->end = point;
	// Dibujar la línea proyectada entre los dos puntos	
	printf("Start x: %f y: %f \n",line->start->x, line->start->y);
	printf("End   x: %f y: %f \n",line->end->x, line->end->y);
	//draw_line(line, 1);
    // Liberar la memoria
    free(line);
    free(point);
	free(projected);
	return (EXIT_SUCCESS);
}
