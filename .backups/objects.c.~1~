#include "objects.h"

//calcula distancia entre dois vetores
float distance(vec2 v1, vec2 v2){
    return sqrtf((v1.x - v2.x)*(v1.x - v2.x) + (v1.y - v2.y)*(v1.y - v2.y));
}

vec2 vectorize(float x, float y){
    vec2 vect = { x , y };
    return vect;
}

color_t colorize(Uint8 R, Uint8 G, Uint8 B, Uint8 A){
    color_t color;
    color.R = R;
    color.G = G;
    color.B = B;
    color.A = A;
    return color;
}

float module(vec2 a){
    return sqrtf((a.x * a.x) + (a.y *a.y));
}

float dotProd(vec2 a, vec2 b){
    return a.x * b.x + a.y * b.y;
}

float crossProd(vec2 a, vec2 b){
    return fabs((a.x * b.y)- (a.y * b.x));
}

vec2 vectorAdd(vec2 a, vec2 b){
    vec2 sum;
    sum.x = a.x + b.x;
    sum.y = a.y + b.y;
    return sum;
}

vec2 vectorSub(vec2 a, vec2 b){
    vec2 sub;
    sub.x = a.x - b.x;
    sub.y = a.y - b.y;
    return sub;
}

vec2 multiple_vectorAdd(int amount, ...){
    va_list vList;
    vec2 sum;
    vec2 temp;
    int i;
    va_start(vList, amount);

    for(i=0;i<amount;i++){
        temp = va_arg(vList, vec2);
        sum.x += temp.x;
        sum.y += temp.y;
    }

    va_end(vList);
    return sum;

}

vec2 multiple_vectorSub(int amount, ...){
    va_list vList;
    vec2 sub;
    vec2 temp;
    int i;
    va_start(vList, amount);

    for(i=0;i<amount;i++){
        temp = va_arg(vList, vec2);
        sub.x -= temp.x;
        sub.y -= temp.y;
    }

    va_end(vList);
    return sub;
}

vec2 scalar(float e, vec2 vec){
    vec.x *= e;
    vec.y *= e;
    return vec;
}

vec2 divScalar(float e, vec2 vec){
    vec.x /= e;
    vec.y /= e;
    return vec;
}

//verifica se dois circulos estao colidindo
bool Ball2Ball(ball_t a, ball_t b){
    return (a.pos.x - b.pos.x)*(a.pos.x - b.pos.x) + (a.pos.y - b.pos.y)*(a.pos.y - b.pos.y) < (a.radius + b.radius) * (a.radius + b.radius);
}

bool Ball2Line(ball_t ball, line_t line){

}
