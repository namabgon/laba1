#define _CRT_SECURE_NO_WARNINGS
#include "all_func.hpp"

int main()
{
    setlocale(LC_ALL, "rus");
    int num;
    cout << "Введите номер задачи: ";
    cin >> num;

    switch (num)
    {
    case(1):
        number1(); // добавить комментарии
        break;
    case(2):
        number2(); // добавить комментарии
        break;
    case(3):
        number3(); // добавить комментарии
        break;
    case(4):
        number4(); // добавить комментарии
        break;
    case(5):
        number5(); // добавить комментарии
        break;
    case(6):
        number6(); // добавить комментарии
        break;
    default:
        break;
    }
}
