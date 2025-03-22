#include <iostream>
using namespace std;

int number1()
{
    setlocale(LC_ALL, "rus");
    char str[50];
    FILE* input_file, * output_file;
    char file_name[50];
    int str_number = 0;
    cout << "\n1. ��� ��������� ����. �������� � ���� ������ �� ���������� �������� �-�,\n"
        << "��������� �� ����� ����� ������. ��������� �������� � ������ ����\n\n";
    cout << "������� ��� �����: ";
    cin >> file_name;
    input_file = fopen(file_name, "r");
    output_file = fopen("number1_out.txt", "w");
    if (input_file == NULL)
    {
        cout << "������. �������� ���� �����������.\n";
        fclose(output_file);
        return 0;
    }
    cout << "���� " << file_name << " ������� ������." << endl;


    while (!feof(input_file))
    {
        if (fgets(str, 50, input_file) != NULL)
        {
            if (str_number == 5)
            {
                if (fputs("------------\n", output_file) == EOF)
                {
                    cout << "��������� ������ ������ � ����.\n";
                    fclose(input_file);
                    fclose(output_file);
                    return 0;
                }
            }

            if (fputs(str, output_file) == EOF)
            {
                cout << "��������� ������ ������ � ����.\n";
                fclose(input_file);
                fclose(output_file);
                return 0;
            }
            str_number++;
        }
        else
        {
            cout << "��������� ������ ��� ������ �����.\n";
            fclose(input_file);
            fclose(output_file);
            return 0;
        }
    }


    cout << "\n� ���� ��������� ������ �� ���������� �������� '-' ����� 5-�� ������.\n"
        << "��������� ������� � ���� number1_out.txt\n";


    fclose(input_file);
    fclose(output_file);
    cout << "\n����� ������� �������." << endl;
    return 0;
}

int number2()
{
    char str[50];
    FILE* input_file;
    char file_name[50];
    cout << "\n2. ������� ��������� ����. ����� ���������� �����,\n"
        << "� ������� ������� ����� ���� ���� �� (���������)\n\n";
    cout << "������� ��� �����: ";
    cin >> file_name;
    input_file = fopen(file_name, "r");
    int count_word = 0, count = 0;
    if (input_file == NULL)
    {
        cout << "������. �������� ���� " << file_name << " �����������.\n";
        return 0;
    }
    cout << "���� " << file_name << " ������� ������." << endl << endl;


    while (!feof(input_file))
    {
        if (fgets(str, 50, input_file) != NULL)
        {
            for (int i = 0; i < strlen(str) - 1; i++)
            {
                if (str[i] == '�')
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
            cout << "��������� ������ ��� ������ �����.\n";
            fclose(input_file);
            return 0;
        }
    }

    cout << "���������� ����� � ����� ������� '�': " << count << endl;


    fclose(input_file);
    cout << "\n���� ������� ������.\n";
    return 0;
}

int number3()
{
    char str[80];
    FILE* input_file, *output_file;
    char file_name[50];
    cout << "\n3. ��� ��������� ����. ���������� � ������ ���� �� ��� ������,\n"
        << "� ������� ������� ����� �������� ��������\n\n";
    cout << "������� ��� �����: ";
    cin >> file_name;
    input_file = fopen(file_name, "r");
    output_file = fopen("number3_out.txt", "w");
    if (input_file == NULL)
    {
        cout << "������. �������� ���� " << file_name << " �����������.\n";
        fclose(output_file);
        return 0;
    }
    cout << "���� " << file_name << " ������� ������." << endl;


    while (!feof(input_file))
    {
        if (fgets(str, 50, input_file) != NULL)
        {
            if (strlen(str) - 1 > 30)
            {
                if (fputs(str, output_file) == EOF)
                {
                    cout << "��������� ������ ��� ������ � ����.\n";
                    fclose(input_file);
                    fclose(output_file);
                    return 0;
                }
            }
        }
        else
        {
            cout << "��������� ������ ��� ������ �����.\n";
            fclose(input_file);
            fclose(output_file);
            return 0;
        }
    }


    cout << "\n������, � ������� ������ �������� ��������, �������\n"
        << "���������� � ���� number3_out.txt\n\n";


    fclose(input_file);
    fclose(output_file);
    cout << "����� ������� �������.\n";
    return 0;
}

int number4()
{
    char str[80];
    FILE* input_file;
    char file_name[50];
    int str_number = 1;
    cout << "\n4. ������� �������������� ���� � �������. ������� �� �����\n"
        << "��� ��� �������� � �������� ���������� �������.\n\n";
    cout << "������� ��� �����: ";
    cin >> file_name;
    cout << endl;
    input_file = fopen(file_name, "r");
    if (input_file == NULL)
    {
        cout << "������. �������� ���� " << file_name << " �����������.\n";
        return 0;
    }
    cout << "���� " << file_name << " ������� ������." << endl << endl;


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
            cout << "��������� ������ ��� ������ �����";
            fclose(input_file);
            return 0;
        }
        str_number++;
    }


    fclose(input_file);
    cout << "\n\n���� ������� ������.\n";
    return 0;
}

int number5()
{
    char str[80];
    char file_name[30];
    int str_number = 1;
    FILE* input_file;
    cout << "\n5. ��� �������������� ����, ���������� �������� �������� ��������� �����.\n"
        << "�������� �����������, ������������ �� ����, ���������� ����� ������� ������.";
    cout << "\n\n������� ��� �����: ";
    cin >> file_name;
    input_file = fopen(file_name, "r");
    if (input_file == NULL)
    {
        cout << "������. �������� ���� �����������.\n";
        return 0;
    }
    cout << "���� " << file_name << " ������� ������." << endl << endl;


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
            cout << "��������� ������ ��� ������ �����";
            fclose(input_file);
            return 0;
        }
        str_number++;
    }


    fclose(input_file);
    cout << "\n\n���� ������� ������." << endl;
    return 0;
}

int number6()
{
    char str1[50], str2[50], str3[50];
    char file_name1[30], file_name2[30];
    int num1, num2;
    FILE* input_file1, * input_file2, *output_file;
    cout << "\n6. ������� ��� �������������� ����� ����������� �������, ���������� ������� �������� �����.\n"
        << "�������� ������ ����, ������ ������� �������� ����� �����"
        << "��������������� ��������� �������� ������.";
    cout << "\n\n������� ��� ������� �����: ";
    cin >> file_name1;
    input_file1 = fopen(file_name1, "r");
    if (input_file1 == NULL)
    {
        cout << "������. �������� ���� " << file_name1 << " �����������.\n";
        return 0;
    }
    cout << "���� " << file_name1 << " ������� ������." << endl;

    cout << "\n������� ��� ������� �����: ";
    cin >> file_name2;
    input_file2 = fopen(file_name2, "r");
    if (input_file2 == NULL)
    {
        cout << "������. �������� ���� " << file_name2 << " �����������.\n";
        fclose(input_file2);
        return 0;
    }
    cout << "���� " << file_name2 << " ������� ������." << endl << endl;

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
                cout << "��������� ������ ������ � ����.\n";
                fclose(input_file1);
                fclose(input_file2);
                fclose(output_file);
                return 0;
            }
        }
        else
        {
            cout << "��������� ������ ��� ������ �����.\n";
            fclose(input_file1);
            fclose(input_file2);
            fclose(output_file);
            return 0;
        }
    }


    cout << "� ���� number6_out.txt ���� �������� ����� ��������������� ��������� �������� ������.";


    fclose(input_file1);
    fclose(input_file2);
    fclose(output_file);
    cout << "\n\n����� ������� �������." << endl;
    return 0;
}