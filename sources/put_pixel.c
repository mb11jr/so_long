 void ft_put_pixel(t_img *img, int x, int y, int color)
{
    char *pxl;
    
    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
    {
        pxl = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}