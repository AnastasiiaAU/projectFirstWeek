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

char* table();
char* rocket(char input, char *mas);
char* rock_move(char *mas, char storona, char input);

int main() {
    char pole[25][80] = table(); // инициализация игрового поля
    char comand, n; // comand - пользовательский ввод команд, n - переменная для проверки ввода одного символа
    int schet [] = {0, 0}; // счет
    int win_numb = 0; //победитель
    while (1) {
        if (scanf("%c", &comand, &n) && n == '\n') {
            if (comand == ' ' || comand == 'Z' || comand == 'A' || comand == 'K' || comand == 'M') {
                // действия при правильной активации
                if (comand == ' ') {
                    // ball();
                } else {
                    rocket(comand, pole);
                    // ball();
                }

                for (int i = 0; i < 25; i++) { // вывод массива
                    for (int j = 0; j < 80; j++) {
                        printf("%c", pole[i][j]);
                    }
                    printf("\n");
                }
                if (schet[0] == 21 || schet[1] == 21) {
                    if (schet[0] == 21) {
                        win_numb = 1;
                    } else {
                        win_numb = 2;
                    }
                    break;
                }
            } else {
                continue;
            }   
        } else {
            continue;
        }
    }
    printf("Player %d wins!", &win_numb); //вывод того, кто победил
    return 0;
}

// вывод игрового поля +
char* table() {
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
}

// функция передвижения ракеток +
char* rocket(char input, char *mas) {
    int high = 0, low = 0; // high - верхняя точка ракетки, low - нижняя
    if (input == 'A' || input == 'Z') {
        // нахождение координат левой ракетки
        return rock_move(mas, 'l', input);  
    } else {
        // нахождение координат правой ракетки
        return rock_move(mas, 'r', input);
    }
    return mas;
}

// движение рокеток общие действия +
char* rock_move(char *mas, char storona, char input) {
    int numb, high = 0, low = 0;;
    if (storona == 'r') {
        numb = 73;
    } else {
        numb = 6;
    }
    for (int i = 1; i < 24; i++) {
            if (mas[i][&numb] == '|' && high == 0) {
                high = i;
            } else if (mas[i][&numb] == '|') {
                low = i;
            }
    }
    if (input == 'K' || input == 'A') { //вверх
        if ((high - 1) != '-') {
            mas[low][&numb] = ' ';
            mas[high-1][&numb] = '|';
            return mas;
        } else {
            return mas;
        }
    } else { //вниз
        if ((low + 1) != '-') {
            mas[high][&numb] = ' ';
            mas[low+1][&numb] = '|';
            return mas;
        } else {
            return mas;
        }
    }
}

// функция передвижения мяча
char* ball() {

}
