#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

void InsertionSort(vector<int>& arr)
{
    size_t n = arr.size();

    for (size_t i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            for (size_t j = i + 1; j > 0; j--)
                if (arr[j - 1] <= arr[j])
                    break;
                else
                    swap(arr[j], arr[j - 1]);

    //2 версия, но медленная из-за стандартных функций
    /*size_t n = arr.size();

    for (size_t i = 1; i < n; i++)
        if (arr[i - 1] > arr[i])
        {
            for (size_t j = i; j > 0; j--)
                if (arr[i] >= arr[j - 1] || (j - 1) == 0)
                {
                    arr.insert(arr.begin() + j - 1, arr[i]);
                    arr.erase(arr.begin() + i + 1);
                    break;
                }
        }*/

    //size_t n = arr.size();
    //size_t h = n;

    //while (h /= 2)
    //{
    //    for (size_t i = 0; i < n - h; i += h)
    //        if (i < n)
    //            if (arr[i] > arr[i + h])
    //                for (size_t j = i + h; j > 0; j -= h)
    //                    if (arr[j - h] <= arr[j])
    //                        break;
    //                    else
    //                        swap(arr[j], arr[j - h]);
    //    if (h == 1)
    //        break;
    //}
}

int main()
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(0, 5000);
    // = { 4,3,2,1,5,5,6,12,43,53,53,1,2,3,4,5 }
    vector<int> arr;
    for (int i = 0; i < 15; i++)
        arr.push_back(dist(rng));
    cout << "unsorted arr: " << "\n";
    for (int i : arr)
        cout << i << "\t";
    
    cout << "\n";
    auto start_time = chrono::steady_clock::now();
    InsertionSort(arr);
    auto end_time = chrono::steady_clock::now();
    cout << "time: " << "\n";
    cout << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count() << " ns\n";
    cout << "sorted arr: " << "\n";
    for (int i : arr)
        cout << i << "\t";
    cout << "\n";
    std::cout << "Hello World!\n";
}