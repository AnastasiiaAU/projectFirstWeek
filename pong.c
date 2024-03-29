#include <stdio.h>
void printerarr (char mas [], int ind);
char* rocket(char input, char *mas);
char* rock_move(char *mas, char storona, char input);
char* ball(char *mas, char highlow, char rightltft);
char chengedir(char simb);
int stolknovenie(char *mas, char highlow, char rightltft, int x, int y);
char* ball_move(char *mas, char highlow, char rightltft, int x, int y, int st);
int goals(char *mas);
void clear(void);


int main() {
    char comand, n; // comand - пользовательский ввод команд, n - переменная для проверки ввода одного символа
    int schet [] = {0, 0}; // счет
    int win_numb = 0; //победитель
    char hl = '-', rl = '-'; // движение мяча
    char first[] = "                                     PINPONG                                    "; 
    char second [] = "             PLAYER 1   0                             PLAYER 2   0              "; // 24 и 64 индексы
    char counter [2][80] = {*first, *second};
    printf("двадцать первая строка");
    while (win_numb == 0) {
        char pole[25][80];// инициализация игрового поля 
        for (int line = 0; line < 25; line++){ //формирование базового изображения
            for (int column = 0; column < 80; column++){
                if (line == 12 && column == 39) { // координата начальная шарика -> 14,40
                    pole [line][column] = 'O';
                } else if ((column == 0 || column == 79 || column == 39) && (line > 0 && line < 24)) {
                    pole [line][column] = '|';
                } else if ((line == 0 || line == 24) && (column % 2 == 0)) {
                    pole [line][column] = '-';
                } else if ((line == 11 || line == 12 || line == 13) && (column == 6 || column == 73)) {
                    pole [line][column] = '|';
                } else {
                    pole [line][column] = ' ';
                }
            }
        }
        counter[1][24] = schet[0];
        counter[1][64] = schet[1];
        printerarr(counter, 1);
        printerarr(pole, 2);
        while(goals(pole) == 0){
            counter[1][24] = schet[0];
            counter[1][64] = schet[1];
            if (scanf('%c', &comand, &n) && n == '\n') {
                if (comand == ' ' || comand == 'Z' || comand == 'A' || comand == 'K' || comand == 'M') {
                    // действия при правильной активации
                    if (comand == ' ') {
                        ball(pole, hl, rl); // обратить внимание
                        printerarr(counter, 1);
                        printerarr(pole, 2);
                    } else {
                        rocket(comand, pole);// обратить внимание
                        ball(pole, hl, rl); // обратить внимание
                        printerarr(counter, 1);
                        printerarr(pole, 2);
                    }
                    if (goals(pole) == 0) { // был ли гол в целом? => нет (else -> был)
                        clear();
                        printerarr(counter, 1);
                        printerarr(pole, 2);
                    } else {
                        if (goals(pole) == 1) {
                            schet[0] += 1; 
                        } else if (goals(pole) == 2) {
                            schet[1] += 1;
                        }
                    }
                } else {
                    continue;
                }
            } else {
                continue;
            }
        }
        if (schet[0] == 21 || schet[1] == 21) {
            if (schet[0] == 21) {
                win_numb = 1;
            } else {
                win_numb = 2;
            }
            break;
        }
    }
    printf("CONGRATULATIONS! PLAYER %d WIN!", &win_numb); //вывод того, кто победил
    return 0;
}

// вывод
void printerarr (char mas [], int ind) {
    if (ind == 1) {
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 80; j++)
            {
                printf('%с', &mas[i][&j]);
            }
            printf("\n");   
        }
    } else {
        for (int i = 0; i < 25; i++){
            for (int j = 0; j < 80; j++)
            {
                printf('%с', &mas[i][&j]);
            }
            printf('\n');   
        }
    }
}

// функция передвижения ракеток 
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

// движение ракеток общие действия 
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
char* ball(char *mas, char highlow, char rightltft) {
    int ball_x = 0;
    int ball_y = 0;
    // поиск мяча
    for (int i=1; i < 24; i++) {
        for (int j = 1; j < 79; j++)
        {
            if (mas[i][&j] == 'O') {
                ball_x = i;
                ball_y = j;
            }
        }
    }
    if (stolknovenie(mas, highlow, rightltft, ball_x, ball_y) == 0) {
        mas = ball_move(mas, highlow, rightltft, ball_x, ball_y, 0);
        return mas;
    } else {
        mas = ball_move(mas, highlow, rightltft, ball_x, ball_y, 1);
        return mas;
    }
}

// смена направления движения 
char chengedir(char simb) {
    if (simb == '-') {
        return '+';
    } else {
        return '-';
    }
}

// проверка на столкновение с ракеткой -> 1,  стенкой -> 2 
int stolknovenie(char *mas, char highlow, char rightltft, int x, int y) {
    if ((x == 23 && highlow == '-') || (x == 1 && highlow == '+')) {  // проверка на столкновение со стенками
        if (x == 23) return 3;
        else return 2;
    } else if ((y == 72 || y == 7)){ //если мяч рядом с маршрутом ракетки 
        if (y==72 && rightltft == '+') {
            //проверяем есть ли ракетка
            if (highlow == '+') {
                if (mas[x-1][&y+1] == '|') {
                    return 1;
                } else {
                    return 0;
                }
            } else if (highlow == '-') {
                if (mas[x+1][&y+1] == '|') {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else if (y == 7 && rightltft == '-') {
            //проверяем есть ли ракетка
            if (highlow == '+') {
                if (mas[x-1][&y-1] == '|') {
                    return 1;
                } else {
                    return 0;
                }
            } else if (highlow == '-') {
                if (mas[x+1][&y-1] == '|') {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

// непосредственно перемещение мяча по полю 
char* ball_move(char *mas, char highlow, char rightltft, int x, int y, int st) {
    if (st == 0) { //если столкнвения не предвидится
        if (highlow == '+') {
            if (rightltft == '+') { //движение выше-правее
                if (y == 39) {
                    mas[x-1][&y+1] = mas[x][&y];
                    mas[x][&y] = '|';
                    return mas;
                } else {
                    mas[x-1][&y+1] = mas[x][&y];
                    mas[x][&y] = ' ';
                    return mas;
                }
            } else if (rightltft == '-') { //движение выше-левее
                if (y == 39) {
                    mas[x-1][&y-1] = mas[x][&y];
                    mas[x][&y] = '|';
                    return mas;
                } else {
                    mas[x-1][&y-1] = mas[x][&y];
                    mas[x][&y] = ' ';
                    return mas;
                }
            }
        } else if (highlow == '-') { 
            if (rightltft == '+') { //движение ниже-правее
                if (y == 39) {
                    mas[x+1][&y+1] = mas[x][&y];
                    mas[x][&y] = '|';
                    return mas;
                } else {
                    mas[x+1][&y+1] = mas[x][&y];
                    mas[x][&y] = ' ';
                    return mas;
                }
            } else if(rightltft == '-') { //движение ниже-левее
                if (y == 39) {
                    mas[x+1][&y-1] = mas[x][&y];
                    mas[x][&y] = '|';
                    return mas;
                } else {
                    mas[x+1][&y-1] = mas[x][&y];
                    mas[x][&y] = ' ';
                    return mas;
                }
            }
        } else {
            return mas;
        }
    } else { // если будет столкновение
        if (y == 39) {
            highlow = chengedir(highlow);
            st = stolknovenie(mas, highlow, rightltft, x, y);
            return ball_move(mas, highlow, rightltft, x, y, st);
        } else {
            if (st == 1) {
                rightltft = chengedir(rightltft);
                st = stolknovenie(mas, highlow, rightltft, x, y);
                return ball_move(mas, highlow, rightltft, x, y, st);
            } else if (st = 2) {
                highlow = chengedir(highlow);
                st = stolknovenie(mas, highlow, rightltft, x, y);
                return ball_move(mas, highlow, rightltft, x, y, st);
            } else return mas;
        }
    }
}

// проверка голов 
int goals(char *mas) {
    int ball_y = 0;
    // поиск мяча
    for (int i=1; i < 24; i++) {
        for (int j = 1; j < 79; j++)
        {
            if (mas[i][&j] == 'O') {
                ball_y = j;
            }
        }
    }
    // проверка гола
    if (ball_y == 1) {
        return 2; // забили первому
    } else if (ball_y == 78) {
        return 1; // забили второму игроку
    } else {
        return 0;
    }
}

void clear(void) {printf("\33[0d\33[2J");}
