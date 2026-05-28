#include <stdio.h>
#include <math.h>
#include <raylib.h>

#define WIDTH 900
#define HEIGHT 600
#define SIDE 80.0f
#define SPRING_ELEM_LEN 53.0f
#define NO_OF_SPRING_ELEM 16
#define SPRING_THICC 2
#define VELOCITY 0
#define SPRING_CONSTANT 10.0f
#define FRICTION 0.4
#define MASS_INITIAL_POSI 40
#define RESTING_LEN 400

void drawSpring(float massX);

typedef struct Line{
    float startX;
    float startY;
    float endX;
    float endY;
    float thickness;
}LinePosition;

LinePosition line = {
    .startX = 0,
    .startY = 400,
    .endX = 900,
    .endY = 400,
    .thickness = 20
};

int main(){
    InitWindow(WIDTH, HEIGHT, "Spring Simulation");
    SetTargetFPS(300);

    float massX = MASS_INITIAL_POSI;
    float velocity = VELOCITY;
    float force = 0;
    int friction = 0;
    // void EnableCursor();

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);
        float dt = GetFrameTime();

        force = -SPRING_CONSTANT * (massX - RESTING_LEN) - (velocity * FRICTION);
        velocity += force * dt;

        if(IsMouseButtonDown(0))
        {
            massX = GetMouseX();
            velocity = 0;
        }

        if(massX + SIDE > WIDTH) massX = WIDTH - SIDE;
        else if(massX < 25) massX = 25;
        else massX += velocity * dt;
        printf("velocity : %f\n", velocity);

        DrawLineEx((Vector2){line.startX, line.startY}, (Vector2){line.endX, line.endY}, line.thickness, WHITE);
        DrawRectangleV((Vector2){massX, line.startY - SIDE - line.thickness/2}, (Vector2){SIDE, SIDE}, RED);
        drawSpring(massX);

        EndDrawing();
    }

    CloseWindow();
}

void drawSpring(float massX)
{
    float spingDelta = massX / NO_OF_SPRING_ELEM;
    float height = sqrt(pow(SPRING_ELEM_LEN, 2) - pow(spingDelta, 2));

    for(int i = 0; i < NO_OF_SPRING_ELEM; i++){
        if( i % 2 == 0)
        {
            Vector2 start = {i * spingDelta, line.startY  - line.thickness/2 - SIDE/2 + height/2};
            Vector2 end = {((i+1) * spingDelta), start.y - height};
            DrawLineEx(start, end, SPRING_THICC, LIGHTGRAY);
        }
        else
        {
            Vector2 start = {(i * spingDelta), start.y - height};
            Vector2 end = {(i+1) * spingDelta, line.startY - line.thickness/2 - SIDE/2 + height/2};
            DrawLineEx(start, end, SPRING_THICC, LIGHTGRAY);
        }
    }
}
