#include "head.h"

int     key_press(int keykode, t_fdf *fdf)
{
    if (keykode == 4)
        fdf->key.h_key = 1;
    fdf->key.anykey_ispressed = fdf->key.h_key != 0 ? 1 : 0;
    return (0);
}

int     key_release(int keykode, t_fdf *fdf)
{
    if (keykode == 4)
    {
        fdf->key.h_key = 0;
        printf("KEY RELEASE: %d\n", keykode);
    }
    fdf->key.anykey_ispressed = fdf->key.h_key != 0 ? 1 : 0;
    return (0);
}

int     mouse_press(int btn, int x, int y, t_fdf *fdf)
{
    if (x < 0 || x > HEI || y < 0 || y > WID)
        return (1);
    if (btn == 1)
        fdf->ms.left = 1;
    else if (fdf->key.h_key == 1 && (btn == 4 || btn == 5))
    {
        fdf->h_zarr *= btn == 4 ? 1.1 : 0.9;
        printf("h_zarr = %.f\n", fdf->h_zarr);
        mlx_clear_window(fdf->full->mlx, fdf->full->win);
        draw(fdf);
    }
    else if (!fdf->key.anykey_ispressed && (btn == 4 || btn == 5))
    {
        fdf->ms.left = 0;
        fdf->siz *= btn == 4 ? 1.1 : 0.9;
        mlx_clear_window(fdf->full->mlx, fdf->full->win);
        draw(fdf);
    }
    return (0);
}

int     mouse_release(int btn, int x, int y, t_fdf *fdf)
{
    if (btn == 1)
        fdf->ms.left = 0;
    // printf("release %d: [%d:%d]\n", btn, x, y);
    return (0);
}

int     mouse_move(int x, int y, t_fdf *fdf)
{
    int prev_x;
    int prev_y;

    if (x < 0 || x > HEI || y < 0 || y > WID)
        return (1);
    prev_x = fdf->ms.x;
    prev_y = fdf->ms.y;
    fdf->ms.x = x;
    fdf->ms.y = y;
    if (fdf->ms.left == 1)
    {
        // fdf->ang.a_x = (prev_y - y) * 0.2;
        // fdf->ang.a_y = (y - prev_y) * 0.2;
        // fdf->ang.a_x = (x - prev_x) * 0.2;
        fdf->ang.a_y = (y - prev_y) * 0.2;
        fdf->ang.a_x = (x - prev_x) * 0.2;


        mlx_clear_window(fdf->full->mlx, fdf->full->win);
        draw(fdf);
    }

    return (0);
}
