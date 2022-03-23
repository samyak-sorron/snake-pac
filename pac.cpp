#include <bits/stdc++.h>
#include <time.h>
#include "raylib.h"

int main(){
    srand(time(0));
    const int windowWidth=600, windowHeight=400;
    
    int snakex=windowWidth/2,snakey=windowHeight/2;

    bool collision=false,ate=true, collision_with_barrier1=false, collision_with_barrier2=false;
    bool in_barrier1=false,in_barrier2=false;

    int randomx{windowWidth/4}, randomy{windowHeight/4};
    
    int barrier1x{windowWidth-50},barrier2x{windowWidth-200},barrier1y{windowHeight-300},barrier2y{windowHeight-50};


    int score=0;

    InitWindow(windowWidth,windowHeight,"snake as pac");
    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(TextFormat("Score:- %d", score), 10, 10, 20, WHITE);
        
        collision=(snakex+30>windowWidth)||((snakey+30)>windowHeight)
                ||(snakex<0)||(snakey<0);

        collision_with_barrier1=(snakey+30>=barrier1y)&&(snakey<=barrier1y+200)
                                && (snakex+30>=barrier1x) && (snakex<=barrier1x+50);

        collision_with_barrier2=(snakey+30>=barrier2y)&&(snakey<=barrier2y+50)
                                && (snakex+30>=barrier2x) && (snakex<=barrier2x+300);
        in_barrier1=(randomy+30>=barrier1y)&&(randomy<=barrier1y+200)
                                && (randomx+30>=barrier1x) && (randomx<=barrier1x+50);
        in_barrier2=(randomy+30>=barrier2y)&&(randomy<=barrier2y+50)
                                && (randomx+30>=barrier2x) && (randomx<=barrier2x+300);

        if(collision || collision_with_barrier1 || collision_with_barrier2){
            DrawText("Game Over!",(windowWidth/2-100),windowHeight/2,40,RED);
        }
        else
        {

            ate=(snakex+30>=randomx) && (snakex<=randomx+30)
                && (snakey<=randomy+30) && (snakey+30>=randomy);

            if(ate || in_barrier1 || in_barrier2){
                // DrawText("go ahead",windowWidth/2,windowHeight/2,20,BLUE);
                score+=10;
                randomx=rand()%(windowWidth-40)+10;
                randomy=rand()%(windowHeight-40)+10;
                barrier1x=rand()%(windowWidth-300);
                barrier1y=rand()%(windowHeight-50);
                barrier2x=rand()%(windowWidth-50);
                barrier2y=rand()%(windowHeight-200);

                // while (collision_with_barrier1 || collision_with_barrier2)
                // {
                //     barrier1x=rand()%(windowWidth-300);
                //     barrier1y=rand()%(windowHeight-50);
                //     barrier2x=rand()%(windowWidth-50);
                //     barrier2y=rand()%(windowHeight-200);
                // }
                
            }

            DrawRectangle(randomx,randomy,30,30,BLUE);
            DrawRectangle(snakex,snakey,30,30,RED);
            DrawRectangle(barrier1x,barrier1y,50,200,RED);
            DrawRectangle(barrier2x,barrier2y,300,50,RED);

            if(IsKeyDown(KEY_D))    snakex+=10;
            if(IsKeyDown(KEY_S))    snakey+=10;
            if(IsKeyDown(KEY_A))    snakex-=10;
            if(IsKeyDown(KEY_W))    snakey-=10;

            if(score>=100){
                DrawText("Good Job! if wish to can go ahead",windowWidth/2-100,windowHeight/2,30,BLUE);
            }
            while (collision_with_barrier1 || collision_with_barrier2)
                {
                    barrier1x=rand()%(windowWidth-300);
                    barrier1y=rand()%(windowHeight-50);
                    barrier2x=rand()%(windowWidth-50);
                    barrier2y=rand()%(windowHeight-200);
                }
        }
        EndDrawing();
    }
    CloseWindow();
    
}