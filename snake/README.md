# Snake Game

> [!WARNING]
> Под Windows тестировалось только под **x86 wine**

Этот проект представляет собой простую игру «Змейка», использующую библиотеку Raylib.

## Структура проекта

```css
├── build
│   └── snake_game
├── inc
│   ├── raylib.h
│   ├── raymath.h
│   └── rlgl.h
├── lib_unix
│   └── libraylib.a
├── lib_win
│   ├── x64
│   │   └── libraylib.a
│   └── x86
│       └── libraylib.a
├── Makefile
├── README.md
└── src
    └── main.c
```

## Требования

**Linux**
- GCC(**!!x64!!**)
- make

**Windows**
- MinGW(64/32)
- make

## Установка
Склонируйте репозиторий:

```bash
git clone https://github.com/gole00201/DPO_MFTI.git
```

Перейдите в папку проекта:

```bash
cd ./DPO_MFTI/snake
```

## Компиляция и запуск
### Linux

Компиляция:

```bash
make
```
Запуск:

```bash
./build/snake_game
```
### Windows

Компиляция:

```bash
make
```
Запуск:
``` bash
build\snake_game.exe
```
## Управление

```
Стрелки: движение змейки
P: пауза
Enter: начать заново после окончания игры
```

### Зависимости

Raylib 5.0

### Очистка

Чтобы удалить скомпилированные файлы:

``` bash
make clean
```