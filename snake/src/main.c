#include <raylib.h>

#define SNAKE_LENGTH   256
#define SQUARE_SIZE     31
#define FOODHEAD_SIZE 7
#define GAME_LABEL "SNAKE GAME by EV"

typedef struct Snake {
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    Color color;
} Snake;

typedef struct Food {
    Vector2 position;
    Vector2 size;
    bool active;
    Color color;
} Food;

typedef struct GameState {
    bool pve;
    int diff;
    bool over;
    bool pause;
} GameState;

static const int screenWidth = 800;
static const int screenHeight = 600;
static int framesCounter = 0;
static GameState game = {.diff = 1,
                        .over = true,
                        .pause = false,
                        .pve = false
                        };
static Food fruit = { 0 };
static Snake snake[SNAKE_LENGTH] = { 0 };
static Vector2 snakePosition[SNAKE_LENGTH] = { 0 };
static bool allowMove = false;
static Vector2 offset = { 0 };
static int counterTail = 0;


static void InitGame(void);
static void UpdateGame(void);
static void DrawGame(void);
static void UpdateDrawFrame(void);
static void DrawGameplaySignle(void);
static void DrawMenu(void);
static void DrawPauseMenu(void);
static void HandleMenuKeys(void);
static void HandleGameplayKeys(void);
static void ProcessPlayer(void);
static void ProcessFruit(void);
static void DrawGameplayPve(void);
static void HandlePauseMenuKeys(void);

int main(void){
    InitWindow(screenWidth, screenHeight, "Snake Game");
    InitGame();
    SetTargetFPS(60);
    while (!WindowShouldClose()){
        UpdateDrawFrame();
    }
    CloseWindow();
    return 0;
}

void UpdateDrawFrame(void){
    UpdateGame();
    DrawGame();
}

void UpdateGame(void){
    if (!game.over && !game.pve){
        if (!game.pause){
            HandleGameplayKeys();
            ProcessPlayer();
            ProcessFruit();
            framesCounter++;
        }
        if(game.pause){
            HandlePauseMenuKeys();
        }
    } else if (!game.over && game.pve){
        // TODO
    } else {
        HandleMenuKeys();
    }
    if (IsKeyPressed('P')){
        game.pause = !game.pause;
    }
}

void DrawGame(void){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (!game.over && !game.pve){
        DrawGameplaySignle();
        if (game.pause){
            DrawPauseMenu();
        }
    } else if(!game.over && game.pve){
        DrawGameplayPve();
        if (game.pause){
            DrawPauseMenu();
        }
    } else {
        DrawMenu();
    }
    EndDrawing();
}


void InitGame(void){
    framesCounter = 0;
    game.pause = false;

    counterTail = 1;
    allowMove = false;

    offset.x = screenWidth % SQUARE_SIZE;
    offset.y = screenHeight % SQUARE_SIZE;

    for (int i = 0; i < SNAKE_LENGTH; i++){
        snake[i].position = (Vector2){ offset.x/2, offset.y/2 };
        snake[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
        snake[i].speed = (Vector2){ SQUARE_SIZE, 0 };
        if (i == 0){
            snake[i].color = DARKBLUE;
        } else {
            snake[i].color = BLUE;
        }
    }

    for (int i = 0; i < SNAKE_LENGTH; i++){
        snakePosition[i] = (Vector2){ 0.0f, 0.0f };
    }

    fruit.size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    fruit.color = LIME;
    fruit.active = false;
}

void ProcessFruit(void){
    if (!fruit.active){
        fruit.active = true;
        fruit.position = (Vector2){ GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };
        for (int i = 0; i < counterTail; i++){
            while ((fruit.position.x == snake[i].position.x) && (fruit.position.y == snake[i].position.y)){
                fruit.position = (Vector2){ GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };
                i = 0;
            }
        }
    }

    if ((snake[0].position.x < (fruit.position.x + fruit.size.x) && (snake[0].position.x + snake[0].size.x) > fruit.position.x) &&
        (snake[0].position.y < (fruit.position.y + fruit.size.y) && (snake[0].position.y + snake[0].size.y) > fruit.position.y))
    {
        snake[counterTail].position = snakePosition[counterTail - 1];
        counterTail += 1;
        fruit.active = false;
    }
}

void ProcessPlayer(void){
    for (int i = 0; i < counterTail; i++){
        snakePosition[i] = snake[i].position;
    }
    if ((framesCounter% (7 - game.diff)) == 0){
        for (int i = 0; i < counterTail; i++){
            if (i == 0){
                snake[0].position.x += snake[0].speed.x;
                snake[0].position.y += snake[0].speed.y;
                allowMove = true;
            }
            else snake[i].position = snakePosition[i-1];
        }
    }

    if (((snake[0].position.x) > (screenWidth - offset.x)) ||
        ((snake[0].position.y) > (screenHeight - offset.y)) ||
        (snake[0].position.x < 0) || (snake[0].position.y < 0))
    {
        game.over = true;
    }

    for (int i = 1; i < counterTail; i++){
        if ((snake[0].position.x == snake[i].position.x) && (snake[0].position.y == snake[i].position.y)){
            game.over = true;
        }
    }
}

void HandleMenuKeys(void){
    if (IsKeyPressed(KEY_ONE)){
        game.diff = 1;
        InitGame();
        game.over = false;
    }
    if (IsKeyPressed(KEY_TWO)){
        game.diff = 3;
        InitGame();
        game.over = false;
    }
    if (IsKeyPressed(KEY_THREE)){
        game.diff = 5;
        InitGame();
        game.over = false;
    }
    if (IsKeyPressed(KEY_FOUR)){
        game.diff = 2;
        game.pve = true;
        InitGame();
        game.over = false;
    }
}

void HandlePauseMenuKeys(void){
    if (IsKeyPressed(KEY_ONE)){
        game.over = true;
    }
    if (IsKeyPressed(KEY_TWO)){
        game.pause = false;
    }
}

void HandleGameplayKeys(void){
    if (IsKeyPressed(KEY_RIGHT) && (snake[0].speed.x == 0) && allowMove){
        snake[0].speed = (Vector2){ SQUARE_SIZE, 0 };
        allowMove = false;
    }
    if (IsKeyPressed(KEY_LEFT) && (snake[0].speed.x == 0) && allowMove){
        snake[0].speed = (Vector2){ -SQUARE_SIZE, 0 };
        allowMove = false;
    }
    if (IsKeyPressed(KEY_UP) && (snake[0].speed.y == 0) && allowMove){
        snake[0].speed = (Vector2){ 0, -SQUARE_SIZE };
        allowMove = false;
    }
    if (IsKeyPressed(KEY_DOWN) && (snake[0].speed.y == 0) && allowMove){
        snake[0].speed = (Vector2){ 0, SQUARE_SIZE };
        allowMove = false;
    }
}

void DrawPauseMenu(void){
    DrawRectangle(GetScreenWidth()/2 - MeasureText(GAME_LABEL, 25)/2 - 5, GetScreenHeight()/2 - 120, MeasureText(GAME_LABEL, 25) + 10, 300, SKYBLUE);
    DrawText("QUIT?", screenWidth/2 - MeasureText("QUIT?", 40)/2, screenHeight/2 - 40, 40, BLACK);
    DrawText(" \t\t\t[1]\t\t YES", GetScreenWidth()/2 - MeasureText(GAME_LABEL, 20)/2, GetScreenHeight()/2 + 20, 20, RED);
    DrawText(" \t\t\t[2]\t\t NO", GetScreenWidth()/2 - MeasureText(GAME_LABEL, 20)/2, GetScreenHeight()/2 + 40, 20, BLUE);
}

void DrawGameplaySignle(void){
    for (int i = 0; i < screenWidth/SQUARE_SIZE + 1; i++){
        DrawLineV((Vector2){SQUARE_SIZE*i + offset.x/2, offset.y/2}, (Vector2){SQUARE_SIZE*i + offset.x/2, screenHeight - offset.y/2}, LIGHTGRAY);
    }
    for (int i = 0; i < screenHeight/SQUARE_SIZE + 1; i++){
        DrawLineV((Vector2){offset.x/2, SQUARE_SIZE*i + offset.y/2}, (Vector2){screenWidth - offset.x/2, SQUARE_SIZE*i + offset.y/2}, LIGHTGRAY);
    }
    for (int i = 0; i < counterTail; i++){
        DrawRectangleV(snake[i].position, snake[i].size, snake[i].color);
    }
    DrawCircle(fruit.position.x + SQUARE_SIZE/ 2 + 1, fruit.position.y + SQUARE_SIZE / 2 + 1, 16, RED);
    DrawRectangleV((Vector2){fruit.position.x + SQUARE_SIZE / 2 - FOODHEAD_SIZE / 2, fruit.position.y + SQUARE_SIZE / 2 - FOODHEAD_SIZE / 2}, (Vector2){FOODHEAD_SIZE, FOODHEAD_SIZE}, GOLD);
}

void DrawGameplayPve(void){
    for (int i = 0; i < screenWidth/SQUARE_SIZE + 1; i++){
        DrawLineV((Vector2){SQUARE_SIZE*i + offset.x/2, offset.y/2}, (Vector2){SQUARE_SIZE*i + offset.x/2, screenHeight - offset.y/2}, LIGHTGRAY);
    }
    for (int i = 0; i < screenHeight/SQUARE_SIZE + 1; i++){
        DrawLineV((Vector2){offset.x/2, SQUARE_SIZE*i + offset.y/2}, (Vector2){screenWidth - offset.x/2, SQUARE_SIZE*i + offset.y/2}, LIGHTGRAY);
    }
    DrawText("You", screenWidth / 2 - 80, 0, 30, BLUE);
    DrawText("AI", screenWidth / 2 + 31, 0, 30, RED);
    DrawRectangle(screenWidth / 2 - 15 , 0, 31, screenHeight, BROWN);
    DrawText("NOT READY", screenWidth/2 - MeasureText("NOT READY", 40)/2, screenHeight/2 - 40, 40, RED);
}

void DrawMenu(void){
    ClearBackground(RAYWHITE);
    for (int i = 0; i < screenWidth/SQUARE_SIZE + 1; i++){
        DrawLineV((Vector2){SQUARE_SIZE*i + offset.x/2, offset.y/2}, (Vector2){SQUARE_SIZE*i + offset.x/2, screenHeight - offset.y/2}, LIGHTGRAY);
    }
    for (int i = 0; i < screenHeight/SQUARE_SIZE + 1; i++){
        DrawLineV((Vector2){offset.x/2, SQUARE_SIZE*i + offset.y/2}, (Vector2){screenWidth - offset.x/2, SQUARE_SIZE*i + offset.y/2}, LIGHTGRAY);
    }
    /*
    TODO: FIXME
    */
    DrawRectangle(GetScreenWidth()/2 - MeasureText(GAME_LABEL, 25)/2 - 5, GetScreenHeight()/2 - 120, MeasureText(GAME_LABEL, 25) + 10, 300, SKYBLUE);
    DrawText(GAME_LABEL, GetScreenWidth()/2 - MeasureText(GAME_LABEL, 25)/2, GetScreenHeight()/2 - 60, 25, PINK);
    DrawText(" Select gamemode by\ngpressing num button.", GetScreenWidth()/2 - MeasureText(GAME_LABEL, 20)/2, GetScreenHeight()/2 + 20, 20, WHITE);
    DrawText(" \t\t\t[1] \t\tEasy", GetScreenWidth()/2 - MeasureText(GAME_LABEL, 20)/2, GetScreenHeight()/2 + 80, 20, GREEN);
    DrawText(" \t\t\t[2] \tMedium", GetScreenWidth()/2 - MeasureText(GAME_LABEL, 20)/2, GetScreenHeight()/2 + 100, 20, BLUE);
    DrawText(" \t\t\t[3]  Ass pain", GetScreenWidth()/2 - MeasureText(GAME_LABEL, 20)/2, GetScreenHeight()/2 + 120, 20, RED);
    DrawText(" \t\t\t[4]\t\t PvE", GetScreenWidth()/2 - MeasureText(GAME_LABEL, 20)/2, GetScreenHeight()/2 + 140, 20, YELLOW);
    DrawText(" \t\t\t[5]\t\t PvP", GetScreenWidth()/2 - MeasureText(GAME_LABEL, 20)/2, GetScreenHeight()/2 + 160, 20, BLACK);
}