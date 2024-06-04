#include "drawUtilities.h"

void ClearTexture(gameData * game, color_t backgroundColor){
    int i;
    for(i = 0; i < WINDOWSIZE_X * WINDOWSIZE_Y; i++){
        *((Uint32*)((Uint8*)game->buffer )+ i) = ((backgroundColor.R<<24)|
                                                  (backgroundColor.G<<16)|
                                                  (backgroundColor.B<< 8)|
                                                  (backgroundColor.A    ));
    }
}

void putPixel(gameData * game, int x, int y, color_t col){
    //sets color in the texture buffer
    if(x > 0 && x < WINDOWSIZE_X && y > 0 && y < WINDOWSIZE_Y){
        *(((Uint32*)(((Uint8*)game->buffer) + ((y * game->pitch))) + x)) = ((col.R<<24)|
                                                                            (col.G<<16)|
                                                                            (col.B<< 8)|
                                                                            (col.A    ));
    }
}



void drawLine(gameData * game, vec2 start, vec2 end, color_t col){
    float temp = 0;
    int x, y, x0, x1, y0, y1, dx, dy, incline, D;

    if(fabs(end.y - start.y) < fabs(end.x - start.x)){
        if(start.x > end.x){
            x0=floor(end.x);
            y0=floor(end.y);
            x1=floor(start.x);
            y1=floor(start.y);

        }else{
            x0=floor(start.x);
            y0=floor(start.y);
            x1=floor(end.x);
            y1=floor(end.y);
        }

        dx = x1 - x0;
        dy = y1 - y0;
        incline = 1;
        if(dy < 0){
            incline = -1;
            dy = -dy;
        }
        D = 2*dy - dx;
        y = y0;
        for(x = x0; x <= x1; x++){
            putPixel(game, x, y, col);
            if(D>0){
                y += incline;
                D += 2 * (dy - dx);
            } else {
                D += 2*dy;
            }
        }
    }else{
        if(start.y < end.y){
            x0=floor(start.x);
            y0=floor(start.y);
            x1=floor(end.x);
            y1=floor(end.y);

        }else{
            x0=floor(end.x);
            y0=floor(end.y);
            x1=floor(start.x);
            y1=floor(start.y);
        }
        dx = x1 - x0;
        dy = y1 - y0;
        incline = 1;
        if(dx < 0){
            incline = -1;
            dx = -dx;
        }
        D = 2*dx - dy;
        x = x0;
        for(y = y0; y <= y1; y++){
            putPixel(game, x, y, col);
            if(D>0){
                x += incline;
                D += 2 * (dx - dy);
            } else {
                D += 2*dx;
            }
        }
    }
}

void drawBall(gameData * game, vec2 pos, float radius, color_t col){
    int i, j;
    for(i = pos.x - radius; i < pos.x + radius; i++){
        for(j = pos.y - radius; j < pos.y + radius; j++){
            if((pos.x - i)*(pos.x - i)+(pos.y - j)*(pos.y - j) <= radius * radius){
                putPixel(game, i, j, col);
            }
        }
    }
}

