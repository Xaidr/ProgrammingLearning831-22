// Atbash.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Индентификаторы кодовых страниц
//https://learn.microsoft.com/ru-ru/windows/win32/intl/code-page-identifiers

#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <sstream>

//#pragma execution_character_set("UTF-8")

using namespace std;

void Atbash(wstring &input)
{
    std::wstringstream ss;
    for (wchar_t c : input)
        if (c >= L'a' && c <= L'z')
            ss << (wchar_t)(L'z' - c + L'a');
        else if (c >= L'A' && c <= L'Z')
            ss << (wchar_t)(L'Z' - c + L'A');
        else if (c >= L'0' && c <= L'9')
            ss << (wchar_t)(L'9' - c + L'0');
        else if (c >= L'а' && c <= L'я')
            ss << (wchar_t)(L'я' - c + L'а');
        else if (c >= L'А' && c <= L'Я')
            ss << (wchar_t)(L'Я' - c + L'А');
        else
            ss << c;
    input = ss.str();
}

int main()
{
    //работает только на wcout и wcin
    //Правильный перевод на русский язык.
    //Более того, поддержка других языков.
    //Из минусов, теперь символ занимает нет 1 байт, а 2
    //Ну и требует подключения дополнительно fcntl.h и io.h 
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    wstring ss;
    getline(wcin, ss);
    Atbash(ss);
    wcout << "\n" << ss << "\n";

    return EXIT_SUCCESS;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
