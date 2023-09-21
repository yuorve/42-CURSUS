#include <stdio.h>
#include <math.h>

// Estructura para representar un punto en 2D
struct Point2D {
    double x;
    double y;
};

// Estructura para representar un punto en 3D
struct Point3D {
    double x;
    double y;
    double z;
};

// Función para realizar la proyección isométrica de un punto en 3D a 2D
struct Point2D projectPointTo2D(struct Point3D point3D) {
    struct Point2D point2D;

    double angle = 45.0 * M_PI / 180.0; // Ángulo de vista en radianes

    printf("***%f***\n", angle);
    //point2D.x = (point3D.x - point3D.y) * cos(0.785);
    //point2D.y = (point3D.x + point3D.y - 2 * point3D.z) * sin(0.785);
    point2D.x = point3D.x + cos(0.785398) * point3D.z - cos(0.785398) * point3D.y;
    point2D.y = -point3D.y * sin(0.785398) - point3D.z * sin(0.785398);

    return point2D;
}

int main() {
    // Coordenadas de los puntos en 3D
    struct Point3D startPoint = {1.0, 1.0, 1.0};
    struct Point3D endPoint = {4.0, 4.0, 4.0};

    // Coordenadas proyectadas de los puntos
    struct Point2D start2D, end2D;
    
    // Proyectar la línea en 3D a 2D
    start2D = projectPointTo2D(startPoint);
    end2D = projectPointTo2D(endPoint);

    // Aquí puedes utilizar las coordenadas proyectadas para dibujar la línea en un sistema 2D

    printf("Punto inicial proyectado: (%.2f, %.2f)\n", start2D.x, start2D.y);
    printf("Punto final proyectado: (%.2f, %.2f)\n", end2D.x, end2D.y);

    return 0;
}
