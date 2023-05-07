// OOPLab5T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>

// Ваші файли загловки 
//
#include "Lab5Exmaple.h"

int main()
{
    setlocale(LC_CTYPE, "ukr");
    std::cout << " Lab #5  !\n";
    //  Код виконання завдань
    //  Головне меню завдань
    //  Функції та класи можуть знаходитись в інших файлах проекту

    int chain;
    cout << endl << "Select task: ";
    cin >> chain;
    //if (chain == 1) chain = mainExample1();
    //if (chain == 2) chain = mainExample2();
    if (chain == 3) chain = mainExample3();
    //if (chain == 4) chain = mainExample4();
    //if (chain == 5) chain = mainExample5();

}
