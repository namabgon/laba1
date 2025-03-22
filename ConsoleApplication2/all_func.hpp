#include <iostream>
using namespace std;

int number1()
{
    setlocale(LC_ALL, "rus");
    char str[50];
    FILE* input_file, * output_file;
    char file_name[50];
    int str_number = 0;
    cout << "\n1. Дан текстовый файл. Добавить в него строку из двенадцати символов ‘-’,\n"
        << "разместив ее после пятой строки. Результат записать в другой файл\n\n";
    cout << "Введите имя файла: ";
    cin >> file_name;
    input_file = fopen(file_name, "r");
    output_file = fopen("number1_out.txt", "w");
    if (input_file == NULL)
    {
        cout << "Ошибка. Возможно файл отсутствует.\n";
        fclose(output_file);
        return 0;
    }
    cout << "Файл " << file_name << " успешно открыт." << endl;


    while (!feof(input_file))
    {
        if (fgets(str, 50, input_file) != NULL)
        {
            if (str_number == 5)
            {
                if (fputs("------------\n", output_file) == EOF)
                {
                    cout << "Произошла ошибка записи в файл.\n";
                    fclose(input_file);
                    fclose(output_file);
                    return 0;
                }
            }

            if (fputs(str, output_file) == EOF)
            {
                cout << "Произошла ошибка записи в файл.\n";
                fclose(input_file);
                fclose(output_file);
                return 0;
            }
            str_number++;
        }
        else
        {
            cout << "Произошла ошибка при чтении файла.\n";
            fclose(input_file);
            fclose(output_file);
            return 0;
        }
    }


    cout << "\nВ файл добавлена строка из двенадцати символов '-' после 5-ой строки.\n"
        << "Результат записан в файл number1_out.txt\n";


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
    cout << "\n2. Имеется текстовый файл. Найти количество строк,\n"
        << "в которых имеется ровно пять букв ‘и’ (кириллица)\n\n";
    cout << "Введите имя файла: ";
    cin >> file_name;
    input_file = fopen(file_name, "r");
    int count_word = 0, count = 0;
    if (input_file == NULL)
    {
        cout << "Ошибка. Возможно файл " << file_name << " отсутствует.\n";
        return 0;
    }
    cout << "Файл " << file_name << " успешно открыт." << endl << endl;


    while (!feof(input_file))
    {
        if (fgets(str, 50, input_file) != NULL)
        {
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
            return 0;
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
    cout << "\n3. Дан текстовый файл. Переписать в другой файл те его строки,\n"
        << "в которых имеется более тридцати символов\n\n";
    cout << "Введите имя файла: ";
    cin >> file_name;
    input_file = fopen(file_name, "r");
    output_file = fopen("number3_out.txt", "w");
    if (input_file == NULL)
    {
        cout << "Ошибка. Возможно файл " << file_name << " отсутствует.\n";
        fclose(output_file);
        return 0;
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
                    return 0;
                }
            }
        }
        else
        {
            cout << "Произошла ошибка при чтении файла.\n";
            fclose(input_file);
            fclose(output_file);
            return 0;
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
    char str[80];
    FILE* input_file;
    char file_name[50];
    int str_number = 1;
    cout << "\n4. Имеется типизированный файл с числами. Вывести на экран\n"
        << "все его элементы с нечетным порядковым номером.\n\n";
    cout << "Введите имя файла: ";
    cin >> file_name;
    cout << endl;
    input_file = fopen(file_name, "r");
    if (input_file == NULL)
    {
        cout << "Ошибка. Возможно файл " << file_name << " отсутствует.\n";
        return 0;
    }
    cout << "Файл " << file_name << " успешно открыт." << endl << endl;


    while (!feof(input_file))
    {
        if (fgets(str, 80, input_file) != NULL)
        {
            if (str_number % 2 != 0)
            {
                cout << str;
            }
        }
        else
        {
            cout << "Произошла ошибка при чтении файла";
            fclose(input_file);
            return 0;
        }
        str_number++;
    }


    fclose(input_file);
    cout << "\n\nФайл успешно закрыт.\n";
    return 0;
}

int number5()
{
    char str[80];
    char file_name[30];
    int str_number = 1;
    FILE* input_file;
    cout << "\n5. Дан типизированный файл, элементами которого являются отдельные слова.\n"
        << "Получить предложение, составленное из слов, порядковый номер которых четный.";
    cout << "\n\nВведите имя файла: ";
    cin >> file_name;
    input_file = fopen(file_name, "r");
    if (input_file == NULL)
    {
        cout << "Ошибка. Возможно файл отсутствует.\n";
        return 0;
    }
    cout << "Файл " << file_name << " успешно открыт." << endl << endl;


    while (!feof(input_file))
    {
        if (fgets(str, 80, input_file) != NULL)
        {
            if (str_number % 2 == 0)
            {
                if (str[strlen(str) - 1] == '\n')
                {
                    str[strlen(str) - 1] = ' ';
                }
                cout << str;
            }
        }
        else
        {
            cout << "Произошла ошибка при чтении файла";
            fclose(input_file);
            return 0;
        }
        str_number++;
    }


    fclose(input_file);
    cout << "\n\nФайл успешно закрыт." << endl;
    return 0;
}

int number6()
{
    char str1[50], str2[50], str3[50];
    char file_name1[30], file_name2[30];
    int num1, num2;
    FILE* input_file1, * input_file2, *output_file;
    cout << "\n6. Имеются два типизированных файла одинакового размера, элементами которых являются числа.\n"
        << "Получить третий файл, каждый элемент которого равен сумме"
        << "соответствующих элементов заданных файлов.";
    cout << "\n\nВведите имя первого файла: ";
    cin >> file_name1;
    input_file1 = fopen(file_name1, "r");
    if (input_file1 == NULL)
    {
        cout << "Ошибка. Возможно файл " << file_name1 << " отсутствует.\n";
        return 0;
    }
    cout << "Файл " << file_name1 << " успешно открыт." << endl;

    cout << "\nВведите имя второго файла: ";
    cin >> file_name2;
    input_file2 = fopen(file_name2, "r");
    if (input_file2 == NULL)
    {
        cout << "Ошибка. Возможно файл " << file_name2 << " отсутствует.\n";
        fclose(input_file2);
        return 0;
    }
    cout << "Файл " << file_name2 << " успешно открыт." << endl << endl;

    output_file = fopen("number6_out.txt", "w");


    while (!feof(input_file1) && !feof(input_file2))
    {
        if (fgets(str1, 50, input_file1) != NULL && fgets(str2, 50, input_file2) != NULL)
        {
            num1 = atoi(str1);
            num2 = atoi(str2);
             _itoa(num1 + num2, str3, 10);
            if (fputs(str3, output_file) == EOF || fputs("\n", output_file))
            {
                cout << "Произошла ошибка записи в файл.\n";
                fclose(input_file1);
                fclose(input_file2);
                fclose(output_file);
                return 0;
            }
        }
        else
        {
            cout << "Произошла ошибка при чтении файла.\n";
            fclose(input_file1);
            fclose(input_file2);
            fclose(output_file);
            return 0;
        }
    }


    cout << "В файл number6_out.txt была записана сумма соответствующих элементов заданных файлов.";


    fclose(input_file1);
    fclose(input_file2);
    fclose(output_file);
    cout << "\n\nФайлы успешно закрыты." << endl;
    return 0;
}