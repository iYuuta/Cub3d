#include "include/Cupid.h"

int print(void *ptr)
{
    int x = *((int *)ptr);
    int y = *((int *)(ptr + 1));

    printf("%d, %d\n", x, y);
}

int main()
{
    int xy[2];
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 100, 100, "test mouse hooks");
    mlx_mouse_hook(win, print, xy);
    while (1)
    {
        
    }
}