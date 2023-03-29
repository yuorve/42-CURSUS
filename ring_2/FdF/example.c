#include "lib/minilibx/mlx.h"

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "MiniLibX Example");
    mlx_loop(mlx);
    return 0;
}