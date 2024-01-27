/*
Разработать программу src/pong.c, представляющую из себя игру для двух игроков, схожую с игрой «Pong». 
Для отображения графики использовать только символьную (ASCII) графику (с выводом в терминал). 
Тебе необходимо реализовать пошаговый вариант исключительно в рамках уже изученного материала и 
стандартной библиотеки.

A/Z и K/M для перемещения ракеток.
Space Bar для пропуска действия на очередном шаге игры в пошаговом режиме.
Поле — прямоугольник 80 на 25 символов.
Размер ракетки — 3 символа.
размер мяча — 1 символ.
После достижения одним из игроков счета в 21 очко, игра выводит поздравление победителя и завершается.==
*/

#include <stdio.h>

*char table();

int main() {
    table();
    char comand;
    while (1) {
        scanf();
        if (comand == ' ' || comand == 'Z' || comand == 'A' || comand == 'K' || comand == 'M') {
            // действия при правильной активации
        } else {
            continue;
        }
    }
    return 0;
}

// вывод игрового поля
*char table() {
    char background [25][80]; // создание массива с фоном
    for (int line = 0; line < 25; line++){ //формирование базового изображения
        for (int column = 0; column < 80; column++){
            if (line == 12 && column == 39) { // координата начальная шарика -> 14,40
                background [line][column] = 'O';
            } else if ((column == 0 || column == 79 || column == 39) && (line > 0 && line < 24)) {
                background [line][column] = '|';
            } else if ((line == 0 || line == 24) && (column % 2 == 0)) {
                background [line][column] = '-';
            } else if ((line == 11 || line == 12 || line == 13) && (column == 6 || column == 73)) {
                background [line][column] = '|';
            } else {
                background [line][column] = ' ';
            }
        }
    }
    return background;
    // for (int i = 0; i < 25; i++) {
    //     for (int j = 0; j < 80; j++) {
    //         printf("%c", background[i][j]);
    //     }
    //     printf("\n");
    // }
}

// функция передвижения ракеток
int rocket (char input) {
    if (input == 'A' || input == 'Z' || input == 'K' || input == 'M') {
        int high, low;
        if (input == 'A' || input == 'Z') {
            // нахождение координат левой ракетки
                
            if (input == 'A') { //вверх
                if 
            } else if (input == 'Z') { //вниз

            }
        } else {
            // нахождение координат правой ракетки

            if (input == 'K') { //вверх

            } else { //вниз

            }
        }
    } else {
        // прописать действия в случае иной команды
    }
}

// функция передвижения мяча