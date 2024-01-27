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

void table();

int main() {
    table();
    // char table [] = table();
    // for (int i = 0; i < 28; i++) {
    //     for (int j = 0; j < 82; j++) {
    //         printf("%c", table[i][j]);
    //     }
    // }
    return 0;
}

// вывод игрового поля
void table() {
    char background [25][80]; // создание массива с фоном
    for (int line = 0; line < 25; line++){ //формирование базового изображения
        for (int column = 0; column < 80; column++){
            if (line == 12 && column == 39) { // координата начальная шарика -> 14,40
                background [line][column] = 'O';
            } else if (column == 0 || column == 79 || column == 39) {
                background [line][column] = 'x';
            } else if ((line == 0 || line == 24) && (column % 2 == 0)) {
                background [line][column] = 'x';
            } else if ((line == 11 || line == 12 || line == 13) && (column == 6 || column == 73)) {
                background [line][column] = '|';
            } else {
                background [line][column] = ' ';
            }
        }
    }
    
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            printf("%c", background[i][j]);
        }
        printf("\n");
    }
}

// // функция передвижения меча
// int ball (int numb) { // от 1 до 4
//     if (numb == 1) {
//         //
//         return 1;
//     } else if (numb == 2) {
//         //
//         return 1;
//     } else if (numb == 3){
//         //
//         return 1;
//     } else if (numb == 4){
//         //
//         return 1;
//     }
//     return 0;
// }

// // функция передвижения ракетки
// int rocket (int numb) {
//     ...
// }