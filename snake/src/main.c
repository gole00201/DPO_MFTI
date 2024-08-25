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
    bool controls;
    bool himLose;
    bool youLose;
} GameState;

// Глобальные переменные
static const int screenWidth = 800;
static const int screenHeight = 600;
static int framesCounter = 0;

static GameState game = {
                         .difficulty = 1,
                         .over = true,
                         .pause = false,
                         .pvp = false,
                         .himLose = false,
                         .youLose = false
                        };

static Food    fruit1 = { 0 },                       fruit2 = { 0 };
static Snake   snake1[SNAKE_LENGTH] = { 0 },         snake2[SNAKE_LENGTH] = { 0 };
static Vector2 snakePosition1[SNAKE_LENGTH] = { 0 }, snakePosition2[SNAKE_LENGTH] = { 0 };

static bool allowMove1 = false;
static bool allowMove2 = false;
static Vector2 offset = { 0 };
static int counterTail1 = 0;
static int counterTail2 = 0;
// Прототипы функций
static void InitGame(void);
static void UpdateGame(Sound ping);
static void DrawGame(Texture2D cntrlsTexturePvp, Texture2D cntrlsTextureSingle);
static void UpdateDrawFrame(Texture2D cntrlsTexture, Texture2D cntrlsTextureSingle, Sound ping);
static void DrawGameplay();
static void DrawMenu(void);
static void DrawPauseMenu(void);
static void HandleMenuKeys(void);
static void HandleGameplayKeys();
static void ProcessPlayerMovement();
static void HandlePauseMenuKeys(void);
static void ProcessFruit(Sound ping);
static void DrawFruit(Food *fruit);
static void DrawControlsPvP(Texture2D cntrlsTexture);
static void DrawControlsSingle(Texture2D cntrlsTextureSingle);
static void DrawBustedScore(int num);
static void InitFruit(Food *fruit);
static void InitSnake(Snake *snake, Vector2 snakePos, Color colorHead, Color colorBody);
static void DrawPvpPlay(void);
static void DrawSingePlay(void);
static void DrawSnakeGrid(void);

// Главная функция
int main(void) {
    InitWindow(screenWidth, screenHeight, "Snake Game");
    InitGame();
    InitAudioDevice();
    SetTargetFPS(60);
    Image cntrls = LoadImage("./res/img/controls.png");
    Image cntrlsSingle = LoadImage("./res/img/controls.png");
    ImageCrop(&cntrlsSingle, (Rectangle){0, 0, cntrlsSingle.width/2, cntrlsSingle.height});
    Sound ping = LoadSound("./res/sound/ping.wav");
    Texture2D cntrlsTexture = LoadTextureFromImage(cntrls);
    Texture2D cntrlsTextureSingle = LoadTextureFromImage(cntrlsSingle);
    while (!WindowShouldClose()) {
        UpdateDrawFrame(cntrlsTexture, cntrlsTextureSingle, ping);
    }

    UnloadImage(cntrls);
    UnloadTexture(cntrlsTexture);
    UnloadImage(cntrlsSingle);
    UnloadTexture(cntrlsTextureSingle);
    UnloadSound(ping);
    CloseWindow();
    return 0;
}

// Функции обновления и рисования кадров
void UpdateDrawFrame(Texture2D cntrlsTexture, Texture2D cntrlsTextureSingle, Sound ping) {
    UpdateGame(ping);
    DrawGame(cntrlsTexture, cntrlsTextureSingle);
}

// Обновление состояния игры
void UpdateGame(Sound ping) {
    /*
        * Тут прежде всего важен приоритет хэндлеров. Приоритет в моем случае
        * отоборажается порядком исполнения. Тот что первеее, тот и приоритетней.
        * Перым идет хэндлер клавиш меню, потому что он меняет состоянией всей игры.
        * Далее идет хэндлер клавиш паузы, потому что он меняет состояние конкретно
        * исполняемой игры. Соответсвенно далее идет сам геймпей. Потому что он не
        * влияет на состояние игры.
    */
    if(game.over && !game.controls) {
        HandleMenuKeys();
    }

    if (!game.over && game.pause){
        HandlePauseMenuKeys();
    }

    if (!game.over && !game.pause){
        HandleGameplayKeys();
        ProcessPlayerMovement();
        ProcessFruit(ping);
        framesCounter++;
    }

    if(game.over && game.controls){
        if(IsKeyPressed(KEY_ENTER)){
            game.controls = false;
            game.over = false;
            InitGame();
        }
    }

    if (IsKeyPressed('P')) {
        game.pause = !game.pause;
    }
}

// Рисование игры
void DrawGame(Texture2D cntrlsTexture, Texture2D cntrlsTextureSingle) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (!game.over && !game.pause) {
        DrawGameplay();
    }

    if (!game.over && game.pause){
        DrawPauseMenu();
    }

    if(game.controls && game.pvp && game.over){
        DrawControlsPvP(cntrlsTexture);
    }

    if (game.controls && !game.pvp && game.over){
        DrawControlsSingle(cntrlsTextureSingle);
    }

    if(game.over && !game.controls){
        DrawMenu();
    }

    EndDrawing();
}

void InitGame(void) {
    framesCounter = 0;
    game.pause = false;
    counterTail1 = 1;
    allowMove1 = false;
    counterTail2 = 1;
    allowMove2 = false;
    offset.x = screenWidth % SQUARE_SIZE;
    offset.y = screenHeight % SQUARE_SIZE;
    Vector2 snake1Pos = (Vector2){ offset.x / 2, offset.y / 2 };
    Vector2 snake2Pos = (Vector2){screenWidth / 2 + SQUARE_SIZE / 2, offset.y / 2 };
    InitSnake(snake1, snake1Pos, BLUE, SKYBLUE);
    InitSnake(snake2, snake2Pos, PURPLE, PINK);
    InitFruit(&fruit1);
    InitFruit(&fruit2);
}

void InitFruit(Food *fruit){
    fruit->size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    fruit->active = false;
}

void InitSnake(Snake *snake, Vector2 snakePos, Color colorHead, Color colorBody){
    for (int i = 0; i < SNAKE_LENGTH; i++) {
        snake[i].position = snakePos;
        snake[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
        snake[i].speed = (Vector2){ SQUARE_SIZE, 0 };
        snake[i].color = (i == 0) ? colorHead : colorBody;
        snakePosition2[i] = (Vector2){ 0.0f, 0.0f };
    }
}

// Обработка движений игрока и противника
void ProcessPlayerMovement() {
    // Первая змейка
    if(!game.youLose){
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
        float border_x = (game.pvp ? screenWidth / 2 - offset.x : screenWidth - offset.x);
        float border_y = screenHeight - offset.y;
        bool outOfBounds = (snake1[0].position.x > border_x) ||
                           (snake1[0].position.y > border_y) ||
                           (snake1[0].position.x < 0) ||
                           (snake1[0].position.y < 0);

        if (outOfBounds) {
            game.youLose = true;
        }

        for (int i = 1; i < counterTail1; i++) {
            bool collisionWithItself = (snake1[0].position.x == snake1[i].position.x) &&
                                    (snake1[0].position.y == snake1[i].position.y);
            if (collisionWithItself) {
                game.youLose = true;
            }
        }
    }
    if(game.youLose && !game.pvp){
        game.over = true;
        game.youLose = false;
    }
    if(!game.pvp){
        return;
    }
    // Вторая змейка
    if(!game.himLose){
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
        float border_x = screenWidth - offset.x;
        float border_y = screenHeight - offset.y;
        bool outOfBounds = (snake2[0].position.x > border_x) ||
                           (snake2[0].position.y > border_y) ||
                           (snake2[0].position.x < screenWidth / 2) ||
                           (snake2[0].position.y < 0);
        if (outOfBounds) {
            game.himLose = true;
        }
        for (int i = 1; i < counterTail2; i++) {
            bool collisionWithItself = (snake2[0].position.x == snake2[i].position.x) &&
                                    (snake2[0].position.y == snake2[i].position.y);
            if (collisionWithItself) {
                game.himLose = true;
            }
        }

    }
    if(game.youLose && game.himLose && game.pvp){
        game.over = true;
        game.himLose = false;
        game.youLose = false;
        game.pvp = false;
    }
}

// Обработка фруктов
void ProcessFruit(Sound ping) {
    if (!fruit1.active) {
        fruit1.active = true;
        float border_x = game.pvp ? (screenWidth / 2 / SQUARE_SIZE - 1) : ((screenWidth / SQUARE_SIZE) - 1);
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
        PlaySound(ping);
        fruit1.active = false;
    }

    if (!fruit2.active && game.pvp) {
        fruit2.active = true;
        float border_x_start = (screenWidth / 2 + SQUARE_SIZE) / SQUARE_SIZE;
        float border_x_end = screenWidth / SQUARE_SIZE - 1;
        float border_y = (screenHeight / SQUARE_SIZE) - 1;
        float x = GetRandomValue(border_x_start, border_x_end) * SQUARE_SIZE + offset.x / 2;
        float y = GetRandomValue(0, border_y) * SQUARE_SIZE + offset.y / 2;
        fruit2.position = (Vector2){x, y};

        for (int i = 0; i < counterTail2; i++) {
            while ((fruit2.position.x == snake2[i].position.x) && (fruit2.position.y == snake2[i].position.y)) {
                x = GetRandomValue(border_x_start, border_x_end) * SQUARE_SIZE + offset.x / 2;
                y = GetRandomValue(0, border_y) * SQUARE_SIZE + offset.y / 2;
                fruit2.position = (Vector2){x, y};
                i = 0;  // Начинаем проверку заново после генерации новых координат
            }
        }
    }
    if(game.pvp){
        getFood =(snake2[0].position.x < (fruit2.position.x + fruit2.size.x) &&
                 (snake2[0].position.y < (fruit2.position.y + fruit2.size.y) &&
                 (snake2[0].position.x + snake2[0].size.x) > fruit2.position.x) &&
                 (snake2[0].position.y + snake2[0].size.y) > fruit2.position.y);
        if (getFood) {
            PlaySound(ping);
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
        game.controls = true;
    }
    if (IsKeyPressed(KEY_TWO)) {
        game.difficulty = 3;
        game.controls = true;
    }
    if (IsKeyPressed(KEY_THREE)) {
        game.difficulty = 5;
        game.controls = true;
    }
    if (IsKeyPressed(KEY_FOUR)) {
        game.difficulty = 0;
        game.pvp = true;
        game.controls = true;
    }
}

// Обработка нажатий клавиш в игровом процессе
void HandleGameplayKeys() {
    // Первая змейка
    if (IsKeyPressed(KEY_D) && (snake1[0].speed.x == 0) && allowMove1) {
        snake1[0].speed = (Vector2){ SQUARE_SIZE, 0 };
        allowMove1 = false;
    }
    if (IsKeyPressed(KEY_A) && (snake1[0].speed.x == 0) && allowMove1) {
        snake1[0].speed = (Vector2){ -SQUARE_SIZE, 0 };
        allowMove1 = false;
    }
    if (IsKeyPressed(KEY_W) && (snake1[0].speed.y == 0) && allowMove1) {
        snake1[0].speed = (Vector2){ 0, -SQUARE_SIZE };
        allowMove1 = false;
    }
    if (IsKeyPressed(KEY_S) && (snake1[0].speed.y == 0) && allowMove1) {
        snake1[0].speed = (Vector2){ 0, SQUARE_SIZE };
        allowMove1 = false;
    }
    // Вторая змейка
    if (IsKeyPressed(KEY_RIGHT) && (snake2[0].speed.x == 0) && allowMove2 && game.pvp) {
        snake2[0].speed = (Vector2){ SQUARE_SIZE, 0 };
        allowMove2 = false;
    }
    if (IsKeyPressed(KEY_LEFT) && (snake2[0].speed.x == 0) && allowMove2 && game.pvp) {
        snake2[0].speed = (Vector2){ -SQUARE_SIZE, 0 };
        allowMove2 = false;
    }
    if (IsKeyPressed(KEY_UP) && (snake2[0].speed.y == 0) && allowMove2 && game.pvp) {
        snake2[0].speed = (Vector2){ 0, -SQUARE_SIZE };
        allowMove2 = false;
    }
    if (IsKeyPressed(KEY_DOWN) && (snake2[0].speed.y == 0) && allowMove2 && game.pvp) {
        snake2[0].speed = (Vector2){ 0, SQUARE_SIZE };
        allowMove2 = false;
    }
}

// Обработка нажатий клавиш в паузе
void HandlePauseMenuKeys(void) {
    if (IsKeyPressed(KEY_ONE)) {
        game.over = true;
        game.pvp = false;
        game.himLose = false;
        game.youLose = false;
    }
    if (IsKeyPressed(KEY_TWO)) {
        game.pause = false;
    }
}

// Рисование игрового процесса
void DrawGameplay() {
    /* Игровая сетка */
    DrawSnakeGrid();
    /* Интерактивные объекты первой половины */
    DrawSingePlay();
    if(game.pvp){
        /* Интерактивные объекты второй половины */
        DrawPvpPlay();
    }

    /* Надпись для первого умершего */
    if (game.pvp && game.youLose){
        DrawBustedScore(1);
    }
    if (game.pvp && game.himLose){
        DrawBustedScore(2);
    }
}

void DrawSnakeGrid(void){
    for (int i = 0; i < screenWidth / SQUARE_SIZE + 1; i++) {
        DrawLineV((Vector2){SQUARE_SIZE * i + offset.x / 2, offset.y / 2}, (Vector2){SQUARE_SIZE * i + offset.x / 2, screenHeight - offset.y / 2}, LIGHTGRAY);
    }
    for (int i = 0; i < screenHeight / SQUARE_SIZE + 1; i++) {
        DrawLineV((Vector2){offset.x / 2, SQUARE_SIZE * i + offset.y / 2}, (Vector2){screenWidth - offset.x / 2, SQUARE_SIZE * i + offset.y / 2}, LIGHTGRAY);
    }
}

void DrawSingePlay(){
    /* Первая змейка */
    if(!game.youLose){
        for (int i = 0; i < counterTail1; i++) {
            DrawRectangleV(snake1[i].position, snake1[i].size, snake1[i].color);
        }
    }
    DrawFruit(&fruit1);
    /* Счетчик игрока */
    char cnt[10];
    sprintf(cnt, "%d", counterTail1);
    DrawText(cnt, 15, 5, 40, GRAY);
}

void DrawPvpPlay(){
    /* Лейблы для игроков */
    DrawText("You", screenWidth / 2 - 80, 0, 30, BLUE);
    DrawText("Him", screenWidth / 2 + 31, 0, 30, RED);
    /* Центральный барьер */
    DrawRectangle(screenWidth / 2 - SQUARE_SIZE / 2 - 1 , 0, SQUARE_SIZE, screenHeight, BROWN);
    DrawFruit(&fruit2);
    /* Вторая змейка */
    if(!game.himLose){
        for (int i = 0; i < counterTail2; i++) {
            DrawRectangleV(snake2[i].position, snake2[i].size, snake2[i].color);
        }
    }
    char cnt[10];
    sprintf(cnt, "%d", counterTail2);
    DrawText(cnt, screenWidth - MeasureText(cnt, 40) - 15, 5, 40, GRAY);
}

void DrawBustedScore(int num){
    if(num == 1){
        char score[1024];
        sprintf(score, "%d", counterTail1);
        DrawText("BUSTED", screenWidth / 2 - screenWidth / 4 - MeasureText("BUSTED", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
        DrawText(score, screenWidth / 2 - screenWidth / 4 - MeasureText(score, 50) / 2, screenHeight / 2 + 70, 50, BLACK);
    }
    if(num == 2){
        char score[1024];
            sprintf(score, "%d", counterTail2);
            DrawText("BUSTED", screenWidth / 2 + screenWidth / 4 - MeasureText("BUSTED", 50) / 2, screenHeight / 2 - 50, 50, BLACK);
            DrawText(score, screenWidth / 2 + screenWidth / 4 - MeasureText(score, 50) / 2, screenHeight / 2 + 70, 50, BLACK);
    }
}

void DrawFruit(Food *fruit){
    float fruitPosX = fruit->position.x + SQUARE_SIZE / 2 - FOODHEAD_SIZE / 2;
    float fruitPosY = fruit->position.y + SQUARE_SIZE / 2 - FOODHEAD_SIZE / 2;
    DrawCircle(fruit->position.x + SQUARE_SIZE/ 2 + 1, fruit->position.y + SQUARE_SIZE / 2 + 1, 16, RED);
    DrawRectangleV((Vector2){fruitPosX, fruitPosY}, (Vector2){FOODHEAD_SIZE, FOODHEAD_SIZE}, GOLD);
}

/* Всякие менюшки */
void DrawMenu(void) {
    DrawText(GAME_LABEL, screenWidth / 2 - MeasureText(GAME_LABEL, 40) / 2, screenHeight / 2 - 130, 40, PINK);
    DrawText("1 - Easy", screenWidth / 2 - MeasureText("1 - Easy", 20) / 2, screenHeight / 2 - 60, 20, BLACK);
    DrawText("2 - Normal", screenWidth / 2 - MeasureText("2 - Normal", 20) / 2, screenHeight / 2 - 20, 20, BLACK);
    DrawText("3 - Hard", screenWidth / 2 - MeasureText("3 - Hard", 20) / 2, screenHeight / 2 + 20, 20, BLACK);
    DrawText("4 - PvP Mode", screenWidth / 2 - MeasureText("4 - PvP Mode", 20) / 2, screenHeight / 2 + 60, 20, BLACK);
}

void DrawPauseMenu(void) {
    DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 60, 40, BLACK);
    DrawText("1 - MENU", screenWidth / 2 - MeasureText("1 - MENU", 20) / 2, screenHeight / 2, 20, BLACK);
    DrawText("2 - BACK TO GAME", screenWidth / 2 - MeasureText("2 - BACK TO GAME", 20) / 2, screenHeight / 2 + 40, 20, BLACK);
}

void DrawControlsPvP(Texture2D cntrlsTexture){
    DrawText("CONTROLS", screenWidth / 2 - MeasureText("CONTROLS", 30) / 2, screenHeight / 2 - 150, 30, BLACK);
    DrawTexture(cntrlsTexture, screenWidth/2 - cntrlsTexture.width/2, screenHeight/2 - cntrlsTexture.height/2, RAYWHITE);
    DrawText("YOU", screenWidth/2 - 90 - MeasureText("YOU", 30) / 2, screenHeight - screenHeight/3, 30, BLUE);
    DrawText("HIM", screenWidth/2 + 90 - MeasureText("HIM", 30) / 2, screenHeight - screenHeight/3, 30, RED);
    DrawText("[P] - PAUSE", screenWidth / 2 - MeasureText("[P] - PAUSE", 20) / 2, screenHeight - screenHeight/5, 20, BLACK);
    DrawText("[ENTER] - START", screenWidth / 2 - MeasureText("[ENTER] TO START", 20) / 2, screenHeight - screenHeight/6, 20, BLACK);
}

void DrawControlsSingle(Texture2D cntrlsTexture){
    DrawText("CONTROLS", screenWidth / 2 - MeasureText("CONTROLS", 30) / 2, screenHeight / 2 - 150, 30, BLACK);
    DrawTexture(cntrlsTexture, screenWidth/2 - cntrlsTexture.width/2, screenHeight/2 - cntrlsTexture.height/2, RAYWHITE);
    DrawText("[P] - PAUSE", screenWidth / 2 - MeasureText("[P] - PAUSE", 20) / 2, screenHeight - screenHeight/5, 20, BLACK);
    DrawText("[ENTER] - START", screenWidth / 2 - MeasureText("[ENTER] TO START", 20) / 2, screenHeight - screenHeight/6, 20, BLACK);
}