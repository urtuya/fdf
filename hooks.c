#include "head.h"

int     mouse_press(int btn, int x, int y, t_fdf *fdf)
{
    double prev_siz;

    if (x < 0 || x > HEI || y < 0 || y > WID)
        return (1);
    if (!fdf->key.h_release && (btn == 4 || btn == 5))
    {
        prev_siz = fdf->siz;
        fdf->siz *= btn == 5 ? 0.9 : 1.1;
        fdf->siz = fdf->siz < 1 ? prev_siz : fdf->siz;
    }
    if (fdf->key.h_release && (btn == 4 || btn == 5))
    {
        fdf->h_zarr += btn == 4 ? 1.0 : -1.0;
        if (fdf->h_zarr < 1.0)
            fdf->h_zarr = 1.1;
    }
    mlx_clear_window(fdf->full->mlx, fdf->full->win);
    draw(fdf);
    // if (btn == 1)
    //     fdf->ms.btn = 1;
    return (0);
}

int     mouse_release(int btn, int x, int y, t_fdf *fdf)
{
    if (btn == 1)
    {
        fdf->ms.left = 1;
    }
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
    if (fdf->ms.left)
    {
        fdf->ang.a_x = (y - prev_y) * 0.2;
        fdf->ang.a_y = (x - prev_x) * 0.2;
        fdf->ang.a_z = (prev_x - x) * 0.1;
        mlx_clear_window(fdf->full->mlx, fdf->full->win);
        draw(fdf);
    }

    return (0);
}

int     key_release(int keykode, t_fdf *fdf)
{
    if (keykode == 4)
    {
        fdf->key.h_release = 1;
        printf("KEY RELEASE: %d\n", keykode);
    }

    return (0);
}