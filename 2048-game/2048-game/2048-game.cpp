#include <iostream>

#include "Board.h"

//todo
// нарисовать панельку
// структуру ячейки поля
// структуру поля
// добавить обработку ввода с клавы
// генерация рандома в пустых ячейках
// действие по вводу с клавы
//

int main()
{
    Board b;
    char key = '1';
    while (key != 'q')
    {
        system("cls");
        b.drawFrame();
        std::cin >> key;
        
        b.update(key);
        
    }
}

