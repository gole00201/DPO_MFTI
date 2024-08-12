#include <raylib.h>
#include <stdio.h> // For sprintf

#define SNAKE_LENGTH   256
#define SQUARE_SIZE     31
#define FOODHEAD_SIZE 7
#define GAME_LABEL "SNAKE GAME by EV"

// Структуры данных
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
    bool pvp;
    int difficulty;
    bool over;
    bool pause;
} GameState;

// Глобальные переменные
static const int screenWidth = 800;
static const int screenHeight = 600;
static int framesCounter = 0;
static GameState game = {.difficulty = 1, .over = true, .pause = false, .pvp = false};
static Food fruit1 = { 0 }, fruit2 = { 0 };
static Snake snake1[SNAKE_LENGTH] = { 0 }, snake2[SNAKE_LENGTH] = { 0 };
static Vector2 snakePosition1[SNAKE_LENGTH] = { 0 }, snakePosition2[SNAKE_LENGTH] = { 0 };
static bool allowMove1 = false;
static bool allowMove2 = false;
static Vector2 offset = { 0 };
static int counterTail1 = 0;
static int counterTail2 = 0;

// Прототипы функций
static void InitGame(void);
static void UpdateGame(void);
static void DrawGame(void);
static void UpdateDrawFrame(void);
static void DrawGameplay(bool isPvP);
static void DrawMenu(void);
static void DrawPauseMenu(void);
static void HandleMenuKeys(void);
static void HandleGameplayKeys(bool isPvP);
static void ProcessPlayerMovement(bool isPvP);
static void HandlePauseMenuKeys(void);
static void ProcessFruit(bool isPvP);
static void DrawFruit(Food *fruit);

// Главная функция
int main(void) {
    InitWindow(screenWidth, screenHeight, "Snake Game");
    InitGame();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }

    CloseWindow();
    return 0;
}

// Функции обновления и рисования кадров
void UpdateDrawFrame(void) {
    UpdateGame();
    DrawGame();
}

// Обновление состояния игры
void UpdateGame(void) {
    if (!game.over) {
        if (!game.pause) {
            HandleGameplayKeys(game.pvp);
            ProcessPlayerMovement(game.pvp);
            ProcessFruit(game.pvp);
            framesCounter++;
        } else {
            HandlePauseMenuKeys();
        }
    } else {
        HandleMenuKeys();
    }

    if (IsKeyPressed('P')) {
        game.pause = !game.pause;
    }
}

// Рисование игры
void DrawGame(void) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (!game.over) {
        DrawGameplay(game.pvp);
        if (game.pause) {
            DrawPauseMenu();
        }
    } else {
        DrawMenu();
    }

    EndDrawing();
}

// Инициализация игры
void InitGame(void) {
    framesCounter = 0;
    game.pause = false;
    counterTail1 = 1;
    allowMove1 = false;
    counterTail2 = 1;
    allowMove2 = false;

    offset.x = screenWidth % SQUARE_SIZE;
    offset.y = screenHeight % SQUARE_SIZE;

    for (int i = 0; i < SNAKE_LENGTH; i++) {
        snake1[i].position = (Vector2){ offset.x / 2, offset.y / 2 };
        snake1[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
        snake1[i].speed = (Vector2){ SQUARE_SIZE, 0 };
        snake1[i].color = (i == 0) ? DARKBLUE : BLUE;
        snakePosition1[i] = (Vector2){ 0.0f, 0.0f };
    }

    for (int i = 0; i < SNAKE_LENGTH; i++) {
        snake2[i].position = (Vector2){screenWidth / 2 + SQUARE_SIZE / 2, offset.y / 2 };
        snake2[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
        snake2[i].speed = (Vector2){ SQUARE_SIZE, 0 };
        snake2[i].color = (i == 0) ? RED : PINK;
        snakePosition2[i] = (Vector2){ 0.0f, 0.0f };
    }

    fruit1.size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    fruit1.color = LIME;
    fruit1.active = false;

    fruit2.size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    fruit2.color = LIME;
    fruit2.active = false;
}

// Обработка движений игрока и компьютера
void ProcessPlayerMovement(bool isPvP) {
    // Первая змейка
    for (int i = 0; i < counterTail1; i++) {
        snakePosition1[i] = snake1[i].position;
    }

    if ((framesCounter % (7 - game.difficulty)) == 0) {
        for (int i = 0; i < counterTail1; i++) {
            if (i == 0) {
                snake1[0].position.x += snake1[0].speed.x;
                snake1[0].position.y += snake1[0].speed.y;
                allowMove1 = true;
            } else {
                snake1[i].position = snakePosition1[i - 1];
            }
        }
    }
    float border_x = (isPvP ? screenWidth / 2 - offset.x : screenWidth - offset.x);
    float border_y = screenHeight - offset.y;
    bool outOfBounds = (snake1[0].position.x > border_x) ||
                       (snake1[0].position.y > border_y) ||
                       (snake1[0].position.x < 0) ||
                       (snake1[0].position.y < 0);

    if (outOfBounds) {
        game.over = true;
        game.pvp = false;
    }

    for (int i = 1; i < counterTail1; i++) {
        bool collisionWithItself = (snake1[0].position.x == snake1[i].position.x) &&
                                   (snake1[0].position.y == snake1[i].position.y);
        if (collisionWithItself) {
            game.over = true;
            game.pvp = false;
        }
    }
    if(!isPvP){
        return;
    }
    // Вторая змейка
    for(int i = 0; i < counterTail2; i++){
        snakePosition2[i] = snake2[i].position;
    }
    if((framesCounter % (7 - game.difficulty)) == 0){
        for(int i = 0; i < counterTail2; i++){
            if(i == 0){
                snake2[i].position.x += snake2[0].speed.x;
                snake2[i].position.y += snake2[0].speed.y;
                allowMove2 = true;
            } else {
                snake2[i].position = snakePosition2[i - 1];
            }
        }
    }
    border_x = screenWidth - offset.x;
    border_y = screenHeight - offset.y;
    outOfBounds = (snake2[0].position.x > border_x) ||
                  (snake2[0].position.y > border_y) ||
                  (snake2[0].position.x < screenWidth / 2) ||
                  (snake2[0].position.y < 0);
    if (outOfBounds) {
        game.over = true;
        game.pvp = false;
    }
    for (int i = 1; i < counterTail2; i++) {
        bool collisionWithItself = (snake2[0].position.x == snake2[i].position.x) &&
                                   (snake2[0].position.y == snake2[i].position.y);
        if (collisionWithItself) {
            game.over = true;
            game.pvp = false;
        }
    }
}

// Обработка фруктов
void ProcessFruit(bool isPvP) {
    if (!fruit1.active) {
        fruit1.active = true;
        float border_x = isPvP ? (screenWidth / 2 / SQUARE_SIZE - 1) : ((screenWidth / SQUARE_SIZE) - 1);
        float border_y = ((screenHeight / SQUARE_SIZE) - 1);
        float x = GetRandomValue(0, border_x) * SQUARE_SIZE + offset.x / 2;
        float y = GetRandomValue(0, border_y) * SQUARE_SIZE + offset.y / 2;
        fruit1.position = (Vector2){ x, y};

        for (int i = 0; i < counterTail1; i++) {
            while ((fruit1.position.x == snake1[i].position.x) && (fruit1.position.y == snake1[i].position.y)) {
                float x = GetRandomValue(0, border_x) * SQUARE_SIZE + offset.x / 2;
                float y = GetRandomValue(0, border_y) * SQUARE_SIZE + offset.y / 2;
                fruit1.position = (Vector2){x, y};
                i = 0;
            }
        }
    }
    bool getFood =(snake1[0].position.x < (fruit1.position.x + fruit1.size.x) &&
                  (snake1[0].position.x + snake1[0].size.x) > fruit1.position.x) &&
                  (snake1[0].position.y < (fruit1.position.y + fruit1.size.y) &&
                  (snake1[0].position.y + snake1[0].size.y) > fruit1.position.y);
    if (getFood) {
        snake1[counterTail1].position = snakePosition1[counterTail1 - 1];
        counterTail1 += 1;
        fruit1.active = false;
    }

    if(!fruit2.active && isPvP){
        fruit2.active = true;
        float border_x = (screenWidth / 2 / SQUARE_SIZE - 1) + offset.x / 2;
        float border_y = (screenHeight / SQUARE_SIZE) - 1;
        float x = GetRandomValue(border_x, screenWidth / SQUARE_SIZE - 1) * SQUARE_SIZE + offset.x / 2;
        float y = GetRandomValue(0, border_y) * SQUARE_SIZE + offset.y / 2;
        fruit2.position = (Vector2){x, y};
        for(int i = 0; i < counterTail2; i++){
            while((fruit2.position.x == snake2[i].position.x) && (fruit2.position.y == snake2[i].position.y)){
                float x = GetRandomValue(border_x, screenWidth / SQUARE_SIZE - 1) * SQUARE_SIZE + offset.x / 2;
                float y = GetRandomValue(0, border_y) * SQUARE_SIZE + offset.y / 2;
                fruit2.position = (Vector2){x, y};
                i = 0;
            }
        }
    }
    if(isPvP){
        getFood =(snake2[0].position.x < (fruit2.position.x + fruit2.size.x) &&
                 (snake2[0].position.y < (fruit2.position.y + fruit2.size.y) &&
                 (snake2[0].position.x + snake2[0].size.x) > fruit2.position.x) &&
                 (snake2[0].position.y + snake2[0].size.y) > fruit2.position.y);
        if (getFood) {
            snake2[counterTail2].position = snakePosition2[counterTail2 - 1];
            counterTail2 += 1;
            fruit2.active = false;
        }
    }
}

// Обработка нажатий клавиш в меню
void HandleMenuKeys(void) {
    if (IsKeyPressed(KEY_ONE)) {
        game.difficulty = 1;
        InitGame();
        game.over = false;
    }
    if (IsKeyPressed(KEY_TWO)) {
        game.difficulty = 3;
        InitGame();
        game.over = false;
    }
    if (IsKeyPressed(KEY_THREE)) {
        game.difficulty = 5;
        InitGame();
        game.over = false;
    }
    if (IsKeyPressed(KEY_FOUR)) {
        game.difficulty = 0;
        game.pvp = true;
        InitGame();
        game.over = false;
    }
}

// Обработка нажатий клавиш в игровом процессе
void HandleGameplayKeys(bool isPvP) {
    // Первая змейка
    if (IsKeyPressed(KEY_RIGHT) && (snake1[0].speed.x == 0) && allowMove1) {
        snake1[0].speed = (Vector2){ SQUARE_SIZE, 0 };
        allowMove1 = false;
    }
    if (IsKeyPressed(KEY_LEFT) && (snake1[0].speed.x == 0) && allowMove1) {
        snake1[0].speed = (Vector2){ -SQUARE_SIZE, 0 };
        allowMove1 = false;
    }
    if (IsKeyPressed(KEY_UP) && (snake1[0].speed.y == 0) && allowMove1) {
        snake1[0].speed = (Vector2){ 0, -SQUARE_SIZE };
        allowMove1 = false;
    }
    if (IsKeyPressed(KEY_DOWN) && (snake1[0].speed.y == 0) && allowMove1) {
        snake1[0].speed = (Vector2){ 0, SQUARE_SIZE };
        allowMove1 = false;
    }
    if(!isPvP){
        return;
    }
    // Вторая змейка
    if (IsKeyPressed(KEY_D) && (snake2[0].speed.x == 0) && allowMove2) {
        snake2[0].speed = (Vector2){ SQUARE_SIZE, 0 };
        allowMove2 = false;
    }
    if (IsKeyPressed(KEY_A) && (snake2[0].speed.x == 0) && allowMove2) {
        snake2[0].speed = (Vector2){ -SQUARE_SIZE, 0 };
        allowMove2 = false;
    }
    if (IsKeyPressed(KEY_W) && (snake2[0].speed.y == 0) && allowMove2) {
        snake2[0].speed = (Vector2){ 0, -SQUARE_SIZE };
        allowMove2 = false;
    }
    if (IsKeyPressed(KEY_S) && (snake2[0].speed.y == 0) && allowMove2) {
        snake2[0].speed = (Vector2){ 0, SQUARE_SIZE };
        allowMove2 = false;
    }
}

// Обработка нажатий клавиш в паузе
void HandlePauseMenuKeys(void) {
    if (IsKeyPressed(KEY_ONE)) {
        game.over = true;
        game.pvp = false;
    }
    if (IsKeyPressed(KEY_TWO)) {
        game.pause = false;
    }
}

// Рисование игрового процесса
void DrawGameplay(bool isPvP) {
    for (int i = 0; i < screenWidth / SQUARE_SIZE + 1; i++) {
        DrawLineV((Vector2){SQUARE_SIZE * i + offset.x / 2, offset.y / 2}, (Vector2){SQUARE_SIZE * i + offset.x / 2, screenHeight - offset.y / 2}, LIGHTGRAY);
    }
    for (int i = 0; i < screenHeight / SQUARE_SIZE + 1; i++) {
        DrawLineV((Vector2){offset.x / 2, SQUARE_SIZE * i + offset.y / 2}, (Vector2){screenWidth - offset.x / 2, SQUARE_SIZE * i + offset.y / 2}, LIGHTGRAY);
    }
    // Рисовать первую змейку
    for (int i = 0; i < counterTail1; i++) {
        DrawRectangleV(snake1[i].position, snake1[i].size, snake1[i].color);
    }
    DrawFruit(&fruit1);
    if(isPvP){
        DrawText("You", screenWidth / 2 - 80, 0, 30, BLUE);
        DrawText("Him", screenWidth / 2 + 31, 0, 30, RED);
        DrawRectangle(screenWidth / 2 - SQUARE_SIZE / 2 - 1 , 0, SQUARE_SIZE, screenHeight, BROWN);
        DrawFruit(&fruit2);
        // Рисовать вторую змейку
        for (int i = 0; i < counterTail2; i++) {
            DrawRectangleV(snake2[i].position, snake2[i].size, snake2[i].color);
        }
    } else {
        char cnt[10];
        sprintf(cnt, "%d", counterTail1);
        DrawText(cnt, screenWidth - MeasureText(cnt, 40) - 15, 5, 40, GRAY);
    }
}

void DrawFruit(Food *fruit){
    float fruitPosX = fruit->position.x + SQUARE_SIZE / 2 - FOODHEAD_SIZE / 2;
    float fruitPosY = fruit->position.y + SQUARE_SIZE / 2 - FOODHEAD_SIZE / 2;
    DrawCircle(fruit->position.x + SQUARE_SIZE/ 2 + 1, fruit->position.y + SQUARE_SIZE / 2 + 1, 16, RED);
    DrawRectangleV((Vector2){fruitPosX, fruitPosY}, (Vector2){FOODHEAD_SIZE, FOODHEAD_SIZE}, GOLD);
}

// Рисование меню
void DrawMenu(void) {
    DrawText(GAME_LABEL, screenWidth / 2 - MeasureText(GAME_LABEL, 40) / 2, screenHeight / 2 - 130, 40, PINK);
    DrawText("1 - Easy", screenWidth / 2 - MeasureText("1 - Easy", 20) / 2, screenHeight / 2 - 60, 20, GRAY);
    DrawText("2 - Normal", screenWidth / 2 - MeasureText("2 - Normal", 20) / 2, screenHeight / 2 - 20, 20, GRAY);
    DrawText("3 - Hard", screenWidth / 2 - MeasureText("3 - Hard", 20) / 2, screenHeight / 2 + 20, 20, GRAY);
    DrawText("4 - PvP Mode", screenWidth / 2 - MeasureText("4 - PvP Mode", 20) / 2, screenHeight / 2 + 60, 20, GRAY);
}

// Рисование паузного меню
void DrawPauseMenu(void) {
    DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 60, 40, GRAY);
    DrawText("1 - MENU", screenWidth / 2 - MeasureText("1 - MENU", 20) / 2, screenHeight / 2, 20, GRAY);
    DrawText("2 - BACK TO GAME", screenWidth / 2 - MeasureText("2 - BACK TO GAME", 20) / 2, screenHeight / 2 + 40, 20, GRAY);
}
