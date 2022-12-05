#ifndef OBJECTS_H_INCLUDE
#define OBJECTS_H_INCLUDE
#include <stdbool.h>
#include <math.h>
#include <SDL.h>
#include <stdarg.h>


typedef struct color_s
{
    Uint8 R, G, B, A;
}color_t;


typedef struct vec2
{
    float x, y;
} vec2;

typedef struct ball_s
{
    vec2 pos, vel, acc;
    float mass;
    float radius;
    color_t col;
} ball_t;

typedef struct sCollidedBallPairs
{
    ball_t * a;
    ball_t * b;
} collidedBallPairs;

typedef struct line_s
{
    vec2 start, ending;
    color_t col;
    float radius;
}line_t;

float distance(vec2 a, vec2 b);

float dotProd(vec2 a, vec2 b);

float module(vec2 a);

float crossProd(vec2 a, vec2 b);

vec2 vectorize(float x, float y);

vec2 vectorAdd(vec2 a, vec2 b);

vec2 vectorSub(vec2 a, vec2 b);

vec2 multiple_vectorSum(int amount, ...);

vec2 scalar(float e, vec2 vec);

vec2 divScalar(float e, vec2 vec);

color_t colorize(Uint8 R, Uint8 G, Uint8 B, Uint8 A);

bool Ball2Line(ball_t ball, line_t line);

bool Ball2Ball(ball_t a, ball_t b);

#endif // OBJECTS_H_INCLUDE
