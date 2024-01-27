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

// вывод игровой поверхности
void table() {
    char background [28][82]; // 3 строки на обводку, вывод счета и надписей "игрок 1 -> 00", "игрок 2 -> 00" и счета
    char tex1 [] = "00";
    char tex2 [] = "00";
    for (int line = 0; line < 28; line++){
        for (int column = 0; column < 82; column++){
            if (line == 14 && column == 40) { // координата начальная шарика -> 14,40
                background [line][column] = 'O';
            } else if ((line == 0 || line == 27 || line == 2) || (column == 0 || column == 81 || column == 40)) {
                background [line][column] = '+';
            //  else if (line == 1) {
            //     if (column == 27) {
            //         for (int i = 27; i < 29; i++)
            //         {
            //             background[column][i] = tex1[i-13]; //очки первого игрока - 1 линия 24 и 25
            //         }
            //     } else if (column == 52) {
            //         for (int i = 52; i < 54; i++)
            //         {
            //             background[column][i] = tex1[i-54]; //очки второго игрока - 1 линия 54 и 55
            //         }
            //     }
            } else {
                background [line][column] = ' ';
            }
        }
    }
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 82; j++) {
            printf("%c", background[i][j]);
        }
        printf("\n");
    }
}

// функция передвижения меча
int ball (int numb) { // от 1 до 4
    if (numb == 1) {
        //
        return 1;
    } else if (numb == 2) {
        //
        return 1;
    } else if (numb == 3){
        //
        return 1;
    } else if (numb == 4){
        //
        return 1;
    }
    return 0;
}

// функция передвижения ракетки
int rocket (int numb) {
    ...
}