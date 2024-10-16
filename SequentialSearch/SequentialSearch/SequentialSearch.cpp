﻿// SequentialSearch.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

size_t* SequentialSearch(vector<int>& arr, int &s)
{
    size_t n = arr.size();
    size_t i = 0;

    for (; i < n; i++)
        if (arr[i] == s)
            return &i;

    return NULL;
}

int main()
{
    vector<int> arr = {2,3,4,5,6,32,56,8,43,123,65,34,98,45,787,235,66,412};
    int key = 412;
    cout << "arr: " << "\n";
    for (int i : arr)
        cout << i << "\t";
    cout << "\n";
    size_t* num = SequentialSearch(arr, key);
    if (num == NULL)
        cout << "NaN" << "\n";
    else
        cout << "number of element: " << (*num + 1) << "\n";
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
