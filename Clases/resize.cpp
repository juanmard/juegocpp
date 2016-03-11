#include <allegro.h>
 
 
/**************** CONFIG *******************************/
 
// define this to 15, 16 or 32
#define USE_COLOR_DEPTH 32
 
 
// UNCOMMENT ONLY ONE OF THESE TWO DEFINES !!!
 
// optimized for magnifying
//#define ALGO1
 
// optimized for reducing
#define ALGO3
 
/********************************************************/
 
 
#if (USE_COLOR_DEPTH == 15 || USE_COLOR_DEPTH == 16)
#define COLOR_DEPTH_TYPE short
#elif (USE_COLOR_DEPTH == 24 || USE_COLOR_DEPTH == 32)
#define COLOR_DEPTH_TYPE long
#endif
 
 
#if (USE_COLOR_DEPTH == 15)
 
#define GETR(c)    (((unsigned short)(c)) >> 10)
#define GETG(c)    (((c) & 0x03E0)>>5)
#define GETB(c)    ((c) & 0x1F)
#define MAKECOL(r, g, b)    ( ((r)<<10) | ((g)<<5) | (b))
 
#elif (USE_COLOR_DEPTH == 16)
 
#define GETR(c)    (((unsigned short)(c)) >> 11)
#define GETG(c)    (((c) & 0x07E0)>>5)
#define GETB(c)    ((c) & 0x1F)
#define MAKECOL(r, g, b)    ( ((r)<<11) | ((g)<<5) | (b))
 
#elif (USE_COLOR_DEPTH == 24 || USE_COLOR_DEPTH == 32)
 
#define GETR(c)    ((c & 0xFF0000) >> 16)
#define GETG(c)    (((c) & 0xFF00)>>8)
#define GETB(c)    ((c) & 0xFF)
#define MAKECOL(r, g, b)    ( ((r)<<16) | ((g)<<8) | (b))
 
#endif
 
 
#if (USE_COLOR_DEPTH != 15 && USE_COLOR_DEPTH != 16 && USE_COLOR_DEPTH != 32)
#if (USE_COLOR_DEPTH == 24)
//#warning 'USE_COLOR_DEPTH' = 24: 24bpp is not currently supported. Graphics will be corrupt.
#else
#error USE_COLOR_DEPTH must be either 15, 16 or 32
#endif
#endif
 
 
void resize_bitmap(BITMAP *src, BITMAP *dest)
{
    int srcw = src->w;
    int srch = src->h;
    int destw = dest->w;
    int desth = dest->h;
    int i, j;
    double src_dest_w = (double)(src->w-1)/(double)(dest->w-1);
    double src_dest_h = (double)(src->h-1)/(double)(dest->h-1);
    double ci, cj;
    int x1, y1, x2, y2;
    double xoff, yoff;
    unsigned c1_rgb[3], c2_rgb[3], c3_rgb[3], c4_rgb[3];
    unsigned r, g, b;
#ifdef ALGO1
    unsigned c;
    int index, index2;
#endif
#ifdef ALGO3
    COLOR_DEPTH_TYPE *line1, *line2;
#endif
    COLOR_DEPTH_TYPE *dest_line;
 
#ifdef ALGO1
    RGB *inbitmap_1;
 
    inbitmap_1 = (RGB *)malloc(sizeof(RGB) * (srcw+1) * (srch+1));
 
    index = 0;
    for (i=0; i<srch-1; i++)
    {
        for(j=0; j<srcw-1; j++)
        {
            c = ((COLOR_DEPTH_TYPE *)src->line[i])[j];
            inbitmap_1[index].r = GETR(c);
            inbitmap_1[index].g = GETG(c);
            inbitmap_1[index].b = GETB(c);
            index++;
        }
        inbitmap_1[index].r = inbitmap_1[index-1].r;
        inbitmap_1[index].g = inbitmap_1[index-1].g;
        inbitmap_1[index].b = inbitmap_1[index-1].b;
        index++;
    }
    for(j=0; j<srcw; j++)
    {
        inbitmap_1[index].r = inbitmap_1[index-srcw].r;
        inbitmap_1[index].g = inbitmap_1[index-srcw].g;
        inbitmap_1[index].b = inbitmap_1[index-srcw].b;
        index++;
    }
#endif
 
#ifdef ALGO1
    index=0;
#endif
    cj = 0;
    for (j=0; j<desth; j++)
    {
        y1 = cj;
#ifdef ALGO3
        y2 = y1 < srch-1 ? y1+1 : srch-1;
#else
        y2 = y1+1;
#endif
        yoff = cj-y1;
 
#ifdef ALGO3
        line1 = (COLOR_DEPTH_TYPE *)src->line[y1];
        line2 = (COLOR_DEPTH_TYPE *)src->line[y2];
#endif
        dest_line = (COLOR_DEPTH_TYPE *)dest->line[j];
 
#ifdef ALGO1
        index=y1*(srcw);
        index2=y2*(srcw);
#endif
 
        ci = 0;
        for(i=0; i<destw; i++)
        {
            x1 = ci;
#ifdef ALGO3
            x2 = x1<srcw-1 ? x1+1 : srcw-1;
#else
            x2 = x1+1;
#endif
 
#ifdef ALGO1
            c1_rgb[0] = inbitmap_1[index+x1].r;
            c1_rgb[1] = inbitmap_1[index+x1].g;
            c1_rgb[2] = inbitmap_1[index+x1].b;
            c2_rgb[0] = inbitmap_1[index+x2].r;
            c2_rgb[1] = inbitmap_1[index+x2].g;
            c2_rgb[2] = inbitmap_1[index+x2].b;
            c3_rgb[0] = inbitmap_1[index2+x1].r;
            c3_rgb[1] = inbitmap_1[index2+x1].g;
            c3_rgb[2] = inbitmap_1[index2+x1].b;
            c4_rgb[0] = inbitmap_1[index2+x2].r;
            c4_rgb[1] = inbitmap_1[index2+x2].g;
            c4_rgb[2] = inbitmap_1[index2+x2].b;
#endif
 
#ifdef ALGO3
            c1_rgb[0] = GETR(line1[x1]);
            c1_rgb[1] = GETG(line1[x1]);
            c1_rgb[2] = GETB(line1[x1]);
            c2_rgb[0] = GETR(line1[x2]);
            c2_rgb[1] = GETG(line1[x2]);
            c2_rgb[2] = GETB(line1[x2]);
            c3_rgb[0] = GETR(line2[x1]);
            c3_rgb[1] = GETG(line2[x1]);
            c3_rgb[2] = GETB(line2[x1]);
            c4_rgb[0] = GETR(line2[x2]);
            c4_rgb[1] = GETG(line2[x2]);
            c4_rgb[2] = GETB(line2[x2]);
#endif
 
            xoff = ci-x1;
 
            r = (c1_rgb[0]*(1-xoff)+(c2_rgb[0]*xoff))*(1-yoff)+(c3_rgb[0]*(1-xoff)+(c4_rgb[0]*xoff))*yoff;
            g = (c1_rgb[1]*(1-xoff)+(c2_rgb[1]*xoff))*(1-yoff)+(c3_rgb[1]*(1-xoff)+(c4_rgb[1]*xoff))*yoff;
            b = (c1_rgb[2]*(1-xoff)+(c2_rgb[2]*xoff))*(1-yoff)+(c3_rgb[2]*(1-xoff)+(c4_rgb[2]*xoff))*yoff;
 
            dest_line[i] = MAKECOL(r, g, b);
 
            ci+=src_dest_w;
        }
        cj+=src_dest_h;
    }
 
#ifdef ALGO1
    free(inbitmap_1);
#endif
}
 
BITMAP * reduce_mipmap (BITMAP *src, int factorx, int factory)
{
    int w, h;
    int div = factorx * factory;
    int divrx, divry, divrxy;
    int i, j, x, y;
    int rx, ry;
    COLOR_DEPTH_TYPE *line;
    COLOR_DEPTH_TYPE *dest_line;
    BITMAP *dest;
 
    w = (src->w / factorx);
    rx = src->w - w*factory;
    divrx = rx*factory;
    if (rx > 0) w++;
    h = (src->h / factory);
    ry = src->h - h*factory;
    divry = ry*factorx;
    if (ry > 0) h++;
    divrxy = rx*ry;
 
    dest = create_bitmap_ex(USE_COLOR_DEPTH, w, h);
 
    for(j=0; j<src->h; j+=factory)
    {
        dest_line = (COLOR_DEPTH_TYPE *)dest->line[j/factory];
        for(i=0; i<src->w; i+=factorx)
        {
            int r, g, b;
            r=g=b=0;
            div=0;
            for(y=0; y<factory && j+y<src->h; y++)
            {
                line = (COLOR_DEPTH_TYPE *)src->line[j+y];
                for(x=0; x<factorx && i+x<src->w; x++)
                {
                    r += GETR(line[i+x]);
                    g += GETG(line[i+x]);
                    b += GETB(line[i+x]);
                    div++;
                }
            }
            r /= div;
            g /= div;
            b /= div;
 
            dest_line[i/factorx] = MAKECOL(r, g, b);
        }
    }
    return dest;
}
