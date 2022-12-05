#include "doUpdate.h"

#define TIME_SUB_SAMPLES 5

void doUpdate(gameData * game){
    //update delta tempo
    static float segundo;
    updateClock(game);
    unsigned int i, j;
    float dist;
    float overlap;
    int g;

    float simElapsedTime = game->deltaTime / TIME_SUB_SAMPLES;

    for(g = 0; g < TIME_SUB_SAMPLES; g++){
        //atualiza velocidade e posicao da bola
        for(i = 0; i < game->ballAmout; i++){
            game->balls[i].acc.y = 1200;
            game->balls[i].vel = vectorAdd(divScalar( 1+simElapsedTime*0.8, game->balls[i].vel), scalar(simElapsedTime, game->balls[i].acc));
            game->balls[i].pos = vectorAdd(game->balls[i].pos, scalar(simElapsedTime, game->balls[i].vel));
            if(fabs(game->balls[i].vel.x * game->balls[i].vel.x + game->balls[i].vel.y * game->balls[i].vel.y)< 0.01)
                game->balls[i].vel = vectorize(0,0);
        }

        //move bola selecionada com botao direito
        if(game->selectedBall != NULL){
            vec2 temp = game->selectedBall->pos;
            game->selectedBall->pos = game->mousePos;
            game->selectedBall->vel = divScalar(simElapsedTime * 2, (vectorSub(game->selectedBall->pos, temp)));

        }

        //nao deixa aconntecer intersecao das bolas e tambem salva cada colisao para ser resolvida depois
        for(i = 0; i < game->ballAmout; i++){
            for(j = 0; j< game->ballAmout; j++){
                if(i != j){
                    if(Ball2Ball(game->balls[i], game->balls[j])){

                        dist = distance(game->balls[i].pos, game->balls[j].pos);
                        overlap = 0.5 * (dist - game->balls[i].radius - game->balls[j].radius);

                        //displace ball j
                        if(dist == 0) dist = 1;
                        game->balls[j].pos.x -= overlap * (game->balls[j].pos.x - game->balls[i].pos.x) / dist;
                        game->balls[j].pos.y -= overlap * (game->balls[j].pos.y - game->balls[i].pos.y) / dist;

                        pushCollidedBalls(game, &game->balls[i], &game->balls[j]);
                    }
                }
            }
        }


        //cuida da colisao dinamica
        for(i = 0; i < game->ammoutOfCollisions; i++){
            ball_t * b1 = game->collidedBalls[i].a;
            ball_t * b2 = game->collidedBalls[i].b;

            dist = distance(b1->pos, b2->pos);

            float nx = (b2->pos.x - b1->pos.x) / dist;
            float ny = (b2->pos.y - b1->pos.y) / dist;

            float tx = -ny;
            float ty = nx;

            float dpTan1 = b1->vel.x * tx + b1->vel.y * ty;
            float dpTan2 = b2->vel.x * tx + b2->vel.y * ty;

            float dpNorm1 = b1->vel.x * nx + b1->vel.y * ny;
            float dpNorm2 = b2->vel.x * nx + b2->vel.y * ny;

            float m1 = (dpNorm1 * (b1->mass - b2->mass) + 2 * b2->mass * dpNorm2) / (b1->mass + b2->mass);
            float m2 = (dpNorm2 * (b2->mass - b1->mass) + 2 * b1->mass * dpNorm1) / (b1->mass + b2->mass);

            b1->vel.x = (tx * dpTan1 + nx * m1);
            b1->vel.y = (ty * dpTan1 + ny * m1);
            b2->vel.x = (tx * dpTan2 + nx * m2);
            b2->vel.y = (ty * dpTan2 + ny * m2);

        }


        //clamp balls to the screen
        for(i = 0; i < game->ballAmout; i++){
            if(game->balls[i].pos.y + game->balls[i].radius >= WINDOWSIZE_Y){
                game->balls[i].pos.y = WINDOWSIZE_Y - game->balls[i].radius;
                game->balls[i].vel.y = -game->balls[i].vel.y * 0.9;
            } else if(game->balls[i].pos.y - game->balls[i].radius <= 0){
                game->balls[i].pos.y = game->balls[i].radius;
                game->balls[i].vel.y = -game->balls[i].vel.y * 0.9;
            }
            if(game->balls[i].pos.x + game->balls[i].radius >= WINDOWSIZE_X){
                game->balls[i].pos.x = WINDOWSIZE_X - game->balls[i].radius;
                game->balls[i].vel.x = -game->balls[i].vel.x * 0.9;
            } else if(game->balls[i].pos.x - game->balls[i].radius <= 0){
                game->balls[i].pos.x = game->balls[i].radius;
                game->balls[i].vel.x = -game->balls[i].vel.x * 0.9;
            }


        }

    }

    game->fps++;
    segundo += game->deltaTime;
    if(segundo >= 1){
        segundo = 0;
        system("cls");
        printf("fps: %d\n", game->fps);
        game->fps = 0;

    }
}

