 void ft_put_pixel(t_obj *img, int x, int y, int color)
{
    char *pxl;
    
    if ()
    {
        pxl = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}