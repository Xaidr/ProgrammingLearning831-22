﻿// CountingMethod.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> CountingMethod(vector<int>& arr)
{
    set<int> data;
    for (int i : arr)
        data.insert(i);

    size_t n = arr.size();
    size_t j = 0;
    vector<int> out(n, 0);
    for (int d : data)
        for (int i = 0; i < n; i++)
            if (arr[i] == d)
                out[i] = j++;

    return out;
}

int main()
{
    vector<int> arr = { 19,17,19,19,17 };
    cout << "unsorted arr: " << "\n";
    for (int i : arr)
        cout << i << "\t";
    cout << "\n";
    arr = CountingMethod(arr);
    cout << "sorted arr: " << "\n";
    for (int i : arr)
        cout << i << "\t";
    cout << "\n";
    cout << "Hello World!\n";
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
