#define _CRT_SECURE_NO_WARNINGS
#include "all_func.hpp"

int main()
{
    const int NUM_CARS = 20;
    const int MENU_1 = 49;
    const int MENU_2 = 50;
    const int MENU_3 = 51;
    const int MENU_4 = 52;
    const int MENU_5 = 53;
    const int MENU_6 = 54;
    const int MENU_7 = 55;
    const int MENU_8 = 56;
    const int MENU_EXIT = 27;

    setlocale(LC_ALL, "rus");
    int req = 0;

    while (req != MENU_EXIT)
    {
        system("cls");
        cout << "  1. Первый номер.\n";
        cout << "  2. Второй номер.\n";
        cout << "  3. Третий номер.\n";
        cout << "  4. Четвертый номер.\n";
        cout << "  5. Пятый номер.\n";
        cout << "  6. Шестой номер.\n";
        cout << "  ESC. Выход.\n";
        req = _getch();

        switch (req)
        {
        case(MENU_1):
            system("cls");
            number1(); // добавить комментарии
            cout << "\nЧтобы продолжить нажмите любую клавишу...";
            _getch();
            break;
        case(MENU_2):
            system("cls");
            number2(); // добавить комментарии
            cout << "\nЧтобы продолжить нажмите любую клавишу...";
            _getch();
            break;
        case(MENU_3):
            system("cls");
            number3(); // добавить комментарии
            cout << "\nЧтобы продолжить нажмите любую клавишу...";
            _getch();
            break;
        case(MENU_4):
            system("cls");
            number4(); // добавить комментарии
            cout << "\nЧтобы продолжить нажмите любую клавишу...";
            _getch();
            break;
        case(MENU_5):
            system("cls");
            number5(); // добавить комментарии
            cout << "\nЧтобы продолжить нажмите любую клавишу...";
            _getch();
            break;
        case(MENU_6):
            system("cls");
            number6(); // добавить комментарии
            cout << "\nЧтобы продолжить нажмите любую клавишу...";
            _getch();
            break;
        default:
            break;
        }
    }

    
}
