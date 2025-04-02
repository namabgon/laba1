#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

int number1()
{
    char str[50];
    // FILE* — это указатель на структуру, которая используется для работы с файлами
    FILE* input_file, * output_file;
    char file_name[50];
    int str_number = 0;
    cout << "1. Дан текстовый файл. Добавить в него строку из двенадцати символов ‘-’,\n"
        << "разместив ее после пятой строки. Результат записать в другой файл\n\n";
    cout << "Введите имя файла: ";
    cin >> file_name;
    // fopen() используется для открытия файла и возвращает указатель
    // на объект типа FILE (если файл успешно открыт),
    // который представляет собой поток для работы с файлом.
    input_file = fopen(file_name, "r");
    output_file = fopen("number1_out.txt", "w");
    // Если произошла ошибка, fopen возвращает NULL
    if (input_file == NULL)
    {
        cout << "Ошибка. Возможно файл отсутствует.\n";
        fclose(output_file);
        return -1;
    }
    cout << "Файл " << file_name << " успешно открыт." << endl;


    // feof() используется для проверки, достигнут ли конец файла
    // Если достигнут конец файла, то возвращает ненулевое значение,
    // иначе - 0
    while (!feof(input_file))
    {
        // fgets() используется для чтения строки из файла
        // возвращает указатель на введенную строку
        // если произошла ошибка, то возвращает NULL
        if (fgets(str, 50, input_file) != NULL)
        {
            if (str_number == 5)
            {
                // fputs() используется для записи строки в файл
                // возвращает ненулевое значение при успешной записи строки
                // при возникновении ошибки возвращает EOF
                if (fputs("------------\n", output_file) == EOF)
                {
                    cout << "Произошла ошибка записи в файл.\n";
                    fclose(input_file);
                    fclose(output_file);
                    return -1;
                }
            }

            if (fputs(str, output_file) == EOF)
            {
                cout << "Произошла ошибка записи в файл.\n";
                fclose(input_file);
                fclose(output_file);
                return -1;
            }
            str_number++;
        }
        else
        {
            cout << "Произошла ошибка при чтении файла.\n";
            fclose(input_file);
            fclose(output_file);
            return -1;
        }
    }


    cout << "\nВ файл добавлена строка из двенадцати символов '-' после 5-ой строки.\n"
        << "Результат записан в файл number1_out.txt\n";

    // fclose() используется для закрытия потока, связанного с указанным параметром
    fclose(input_file);
    fclose(output_file);
    cout << "\nФайлы успешно закрыты." << endl;
    return 0;
}

int number2()
{
    char str[50];
    FILE* input_file;
    char file_name[50];
    cout << "2. Имеется текстовый файл. Найти количество строк,\n"
        << "в которых имеется ровно пять букв ‘и’ (кириллица)\n\n";
    cout << "Введите имя файла: ";
    cin >> file_name;
    input_file = fopen(file_name, "r");
    int count_word = 0, count = 0;
    if (input_file == NULL)
    {
        cout << "Ошибка. Возможно файл " << file_name << " отсутствует.\n";
        return -1;
    }
    cout << "Файл " << file_name << " успешно открыт." << endl << endl;


    while (!feof(input_file))
    {
        if (fgets(str, 50, input_file) != NULL)
        {
            // strlen() используется для вычисления длины строки,
            // которая представлена в виде массива символов
            // не учитывает нулевой символ ('0') в подсчете длины строки
            for (int i = 0; i < strlen(str) - 1; i++)
            {
                if (str[i] == 'и')
                {
                    count_word++;
                }
            }

            if (count_word == 5)
            {
                count++;
            }
            count_word = 0;
        }
        else
        {
            cout << "Произошла ошибка при чтении файла.\n";
            fclose(input_file);
            return -1;
        }
    }

    cout << "Количество строк с пятью буквами 'и': " << count << endl;


    fclose(input_file);
    cout << "\nФайл успешно закрыт.\n";
    return 0;
}

int number3()
{
    char str[80];
    FILE* input_file, *output_file;
    char file_name[50];
    cout << "3. Дан текстовый файл. Переписать в другой файл те его строки,\n"
        << "в которых имеется более тридцати символов\n\n";
    cout << "Введите имя файла: ";
    cin >> file_name;
    input_file = fopen(file_name, "r");
    output_file = fopen("number3_out.txt", "w");
    if (input_file == NULL)
    {
        cout << "Ошибка. Возможно файл " << file_name << " отсутствует.\n";
        fclose(output_file);
        return -1;
    }
    cout << "Файл " << file_name << " успешно открыт." << endl;


    while (!feof(input_file))
    {
        if (fgets(str, 50, input_file) != NULL)
        {
            if (strlen(str) - 1 > 30)
            {
                if (fputs(str, output_file) == EOF)
                {
                    cout << "Произошла ошибка при записи в файл.\n";
                    fclose(input_file);
                    fclose(output_file);
                    return -1;
                }
            }
        }
        else
        {
            cout << "Произошла ошибка при чтении файла.\n";
            fclose(input_file);
            fclose(output_file);
            return -1;
        }
    }


    cout << "\nСтроки, в которых больше тридцати символов, успешно\n"
        << "переписаны в файл number3_out.txt\n\n";


    fclose(input_file);
    fclose(output_file);
    cout << "Файлы успешно закрыты.\n";
    return 0;
}

int number4()
{
    // Создание типизированного файла для номера 4
    /*srand(time(NULL));
    const int KOLVO = 10;
    int num[KOLVO];
    char fname[20];
    FILE* fc;
    cout << "Введите имя файла: ";
    cin >> fname;
    fc = fopen(fname, "wb");
    for (int i = 0; i < KOLVO; i++)
    {
        number[i] = 1 + rand() % 100;
    }
    cout << "\n\nФайл " << fname << " создан.\n";
    fclose(fc);*/


    int number;
    FILE* input_file;
    char file_name[50];
    int str_number = 1;
    cout << "4. Имеется типизированный файл с числами. Вывести на экран\n"
        << "все его элементы с нечетным порядковым номером.\n\n";
    cout << "Введите имя файла: ";
    cin >> file_name;
    input_file = fopen(file_name, "rb");
    if (input_file == NULL)
    {
        cout << "Ошибка. Возможно файл " << file_name << " отсутствует.\n";
        return -1;
    }
    cout << "Файл " << file_name << " успешно открыт." << endl << endl;
    cout << "Содержимое файла " << file_name << ": \n";
    while (!feof(input_file))
    {
        // fread()используется для чтения бинарных данных из файла
        if (fread(&number, sizeof(int), 1, input_file) == 1)
        {
            cout << number << " ";
        }
    }

    // rewind() используется для перемещения указателя позиции чтения/записи в начало файла
    rewind(input_file);
    cout << "\n\nДанные из файла после обработки:\n";
    while (!feof(input_file))
    {
        if (fread(&number, sizeof(int), 1, input_file) == 1)
        {
            if (str_number % 2 != 0)
            {
                cout << number << " ";
            }
        }
        str_number++;
    }


    fclose(input_file);
    cout << "\n\nФайл успешно закрыт.\n";
    return 0;
}

int number5()
{
    // Создание типизированного файла для номера 5
    /*const int ESC = 27;
    char slovo[30];
    char fname[20];
    FILE* fc;
    cout << "Введите имя файла: ";
    cin >> fname;
    fc = fopen(fname, "wb");
    int req = 0;
    while (req != ESC)
    {
        cout << "Введите слово: ";
        cin >> slovo;
        fwrite(slovo, sizeof(char), 30, fc);
        cout << "Для продолжения записи нажмите любую клавишу, для завершения - ESC:\n";
        req = _getch();
    }
    cout << "\n\nФайл " << fname << " создан.\n";
    fclose(fc);
    return 0;*/


    char str[30];
    char file_name[30];
    int str_number = 1;
    FILE* input_file;
    cout << "5. Дан типизированный файл, элементами которого являются отдельные слова.\n"
        << "Получить предложение, составленное из слов, порядковый номер которых четный.";
    cout << "\n\nВведите имя файла: ";
    cin >> file_name;
    input_file = fopen(file_name, "rb");
    if (input_file == NULL)
    {
        cout << "Ошибка. Возможно файл отсутствует.\n";
        return -1;
    }
    cout << "Файл " << file_name << " успешно открыт." << endl << endl;


    cout << "Содержимое файла " << file_name << ": \n";
    while (!feof(input_file))
    {
        if (fread(str, sizeof(char), 30, input_file) == 30)
        {
            cout << str << " ";
        }
    }
    rewind(input_file);
    cout << "\n\nДанные из файла после обработки:\n";
    while (!feof(input_file))
    {
        if (fread(str, sizeof(char), 30, input_file) == 30)
        {
            if (str_number % 2 == 0)
            {
                cout << str << " ";
            }
            str_number++;
        }
    }


    fclose(input_file);
    cout << "\n\nФайл успешно закрыт." << endl;
    return 0;
}

int number6()
{
    // Создание типизированных файлов для номера 6
    /*srand(time(NULL));
    const int KOLVO = 10;
    int number[KOLVO];
    char fname1[20], fname2[20];
    FILE* fc;
    cout << "Введите имя первого файла: ";
    cin >> fname1;
    fc = fopen(fname1, "wb");
    for (int i = 0; i < KOLVO; i++)
    {
        number[i] = 1 + rand() % 20;
    }
    fwrite(number, sizeof(int), KOLVO, fc);
    cout << "Файл " << fname1 << " создан.\n\n";
    fclose(fc);

    cout << "Введите имя второго файла: ";
    cin >> fname2;
    fc = fopen(fname2, "wb");
    for (int i = 0; i < KOLVO; i++)
    {
        number[i] = 100 + rand() % 20;
    }
    fwrite(number, sizeof(int), KOLVO, fc);
    cout << "Файл " << fname2 << " создан.\n";
    fclose(fc);
    return 0;*/




    char file_name1[30], file_name2[30];
    int num1, num2, num3;
    FILE* input_file1, * input_file2, *output_file;
    cout << "6. Имеются два типизированных файла одинакового размера, элементами которых являются числа.\n"
        << "Получить третий файл, каждый элемент которого равен сумме"
        << "соответствующих элементов заданных файлов.";


    cout << "\n\nВведите имя первого файла: ";
    cin >> file_name1;
    input_file1 = fopen(file_name1, "rb");
    if (input_file1 == NULL)
    {
        cout << "Ошибка. Возможно файл " << file_name1 << " отсутствует.\n";
        return -1;
    }
    cout << "Файл " << file_name1 << " успешно открыт." << endl;
    cout << "Содержимое первого файла: ";
    while (!feof(input_file1))
    {
        if (fread(&num1, sizeof(int), 1, input_file1) == 1)
        {
            cout << num1 << " ";
        }
    }
    rewind(input_file1);

    cout << "\n\nВведите имя второго файла: ";
    cin >> file_name2;
    input_file2 = fopen(file_name2, "rb");
    if (input_file2 == NULL)
    {
        cout << "Ошибка. Возможно файл " << file_name2 << " отсутствует.\n";
        return -1;
    }
    cout << "Файл " << file_name2 << " успешно открыт.";
    cout << "\nСодержимое второго файла: ";
    while (!feof(input_file2))
    {
        if (fread(&num2, sizeof(int), 1, input_file2) == 1)
        {
            cout << num2 << " ";
        }
    }
    rewind(input_file2);

    output_file = fopen("number6_out.bin", "wb");


    while (!feof(input_file1) && !feof(input_file2))
    {
        if (fread(&num1, sizeof(int), 1, input_file1) == 1 && 
            fread(&num2, sizeof(int), 1, input_file2) == 1)
        {
            num3 = num1 + num2;
            // fwrite() используется для записи в файл блоков данных любого типа
            fwrite(&num3, sizeof(int), 1, output_file);
        }
    }
    cout << "\n\nВ файл number6_out.bin была записана сумма соответствующих элементов заданных файлов.\n";
    fclose(output_file);
    fclose(input_file1);
    fclose(input_file2);
    output_file = fopen("number6_out.bin", "rb");


    cout << "Содержимое файла number6_out.bin:\n";
    while (!feof(output_file))
    {
        if (fread(&num3, sizeof(int), 1, output_file) == 1)
        {
            cout << num3 << " ";
        }
    }


    fclose(output_file);
    cout << "\n\nФайлы успешно закрыты." << endl;
    return 0;
}