// CipherVigener.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <io.h>
#include <fcntl.h>

using namespace std;

int Mod(int x, int y)
{
    return (((x % y) + y) % y);
}

//не оптимизировано на скорость.
void CipherVigenerEncode(wstring& data, wstring& key)
{
    size_t dn = data.size();
    size_t kn = key.size();

    if (kn == 0)
        return;

    for (int i = 0; i < dn; i++)
        if (data[i] >= L'A' && data[i] <= L'Z' && key[Mod(i, kn)] >= L'A' && key[Mod(i, kn)] <= L'Z')
            data[i] = (wchar_t)(Mod((int)data[i] + (int)key[Mod(i, kn)] - 2 * (int)L'A', 26) + L'A');
        else if (data[i] >= L'a' && data[i] <= L'z' && key[Mod(i, kn)] >= L'a' && key[Mod(i, kn)] <= L'z')
            data[i] = (wchar_t)(Mod((int)data[i] + (int)key[Mod(i, kn)] - 2 * (int)L'a', 26) + L'a');
        else if (data[i] >= L'А' && data[i] <= L'Я' && key[Mod(i, kn)] >= L'А' && key[Mod(i, kn)] <= L'Я')
            data[i] = (wchar_t)(Mod((int)data[i] + (int)key[Mod(i, kn)] - 2 * (int)L'А', 26) + L'А');
        else if (data[i] >= L'а' && data[i] <= L'я' && key[Mod(i, kn)] >= L'а' && key[Mod(i, kn)] <= L'я')
            data[i] = (wchar_t)(Mod((int)data[i] + (int)key[Mod(i, kn)] - 2 * (int)L'а', 26) + L'а');
        else if (data[i] >= L'0' && data[i] <= L'9' && key[Mod(i, kn)] >= L'0' && key[Mod(i, kn)] <= L'9')
            data[i] = (wchar_t)(Mod((int)data[i] + (int)key[Mod(i, kn)] - 2 * (int)L'0', 26) + L'0');
}

//не оптимизировано на скорость.
void CipherVigenerDecode(wstring& data, wstring& key)
{
    size_t dn = data.size();
    size_t kn = key.size();

    if (kn == 0)
        return;

    for (int i = 0; i < dn; i++)
        if (data[i] >= L'A' && data[i] <= L'Z' && key[Mod(i, kn)] >= L'A' && key[Mod(i, kn)] <= L'Z')
            data[i] = (wchar_t)(Mod((int)data[i] - (int)key[Mod(i, kn)] - 2 * (int)L'A', 26) + L'A');
        else if (data[i] >= L'a' && data[i] <= L'z' && key[Mod(i, kn)] >= L'a' && key[Mod(i, kn)] <= L'z')
            data[i] = (wchar_t)(Mod((int)data[i] - (int)key[Mod(i, kn)] - 2 * (int)L'a', 26) + L'a');
        else if (data[i] >= L'А' && data[i] <= L'Я' && key[Mod(i, kn)] >= L'А' && key[Mod(i, kn)] <= L'Я')
            data[i] = (wchar_t)(Mod((int)data[i] - (int)key[Mod(i, kn)] - 2 * (int)L'А', 32) + L'А');
        else if (data[i] >= L'а' && data[i] <= L'я' && key[Mod(i, kn)] >= L'а' && key[Mod(i, kn)] <= L'я')
            data[i] = (wchar_t)(Mod((int)data[i] - (int)key[Mod(i, kn)] - 2 * (int)L'а', 32) + L'а');
        else if (data[i] >= L'0' && data[i] <= L'9' && key[Mod(i, kn)] >= L'0' && key[Mod(i, kn)] <= L'9')
            data[i] = (wchar_t)(Mod((int)data[i] - (int)key[Mod(i, kn)] - 2 * (int)L'0', 10) + L'0');
}

//test line
//PAIRALPHABET PAIRALPHABET PAIRALPHABET
int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    wstring data;
    wstring key = L"CAR";
    wcout << L"Input text: \n";
    getline(wcin, data);
    wcout << L"\n";
    wcout << L"Input key: \n";
    getline(wcin, key);
    wcout << L"\n";
    CipherVigenerEncode(data, key);
    wcout << L"Encode cipher vigener: \n";
    wcout << data << L"\n";
    CipherVigenerDecode(data, key);
    wcout << L"Decode cipher vigener: \n";
    wcout << data << L"\n";

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
