// Enigma.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    map<int, string> Rotors;
    Rotors[0] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ<R";
    Rotors[1] = "AJDKSIRUXBLHWTMCQGZNPYFVOE<F";
    Rotors[2] = "BDFHJLCPRTXVZNYEIWGAKMUSQO<W";
    Rotors[3] = "ESOVPZJAYQUIRHXLNFTGKDCMWB<K";
    Rotors[4] = "VZBRGITYUPSDNHLXAWMJQOFECK<A";
    Rotors[5] = "JPGVOUMFYQBENHZRDKASXLICTW<AN";
    Rotors[6] = "NZJHGRCXMYSWBOUFAIVLPEKQDT<AN";
    Rotors[7] = "FKQHTLXOCBJSPDZRAMEWNIUYGV<AN";

    map<int, string> Reflectors;
    Reflectors[0] = "AY BR CU DH EQ FS GL IP JX KN MO TZ VW";
    Reflectors[1] = "AF BV CP DJ EI GO HY KR LZ MX NW TQ SU";
    Reflectors[2] = "AE BN CK DQ FU GY HW IJ LO MP RX SZ TV";
    Reflectors[3] = "AR BD CO EJ FN GT HK IV LM PW QZ SX UY";

    string Letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::cout << "Hello World!\n";
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
