// Enigma.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include "PairMapBase.h"
#include "Rotor.h"
#include "EnigmaMachine.h"

using namespace std;

vector<string> ParseRotorStr(string rotor)
{
    if (rotor.empty())
        return vector<string>{};
    if (!rotor.find('<'))
        return vector<string>{rotor, ""};
    return vector<string>{rotor.substr(0, 26), rotor.substr(27,29 + rotor.size() - 29)};
}

int main()
{
    map<int, string> RotorsStr;
    RotorsStr[0] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ<R";
    RotorsStr[1] = "AJDKSIRUXBLHWTMCQGZNPYFVOE<F";
    RotorsStr[2] = "BDFHJLCPRTXVZNYEIWGAKMUSQO<W";
    RotorsStr[3] = "ESOVPZJAYQUIRHXLNFTGKDCMWB<K";
    RotorsStr[4] = "VZBRGITYUPSDNHLXAWMJQOFECK<A";
    RotorsStr[5] = "JPGVOUMFYQBENHZRDKASXLICTW<AN";
    RotorsStr[6] = "NZJHGRCXMYSWBOUFAIVLPEKQDT<AN";
    RotorsStr[7] = "FKQHTLXOCBJSPDZRAMEWNIUYGV<AN";

    map<int, string> ReflectorsStr;
    ReflectorsStr[0] = "AY BR CU DH EQ FS GL IP JX KN MO TZ VW";
    ReflectorsStr[1] = "AF BV CP DJ EI GO HY KR LZ MX NW TQ SU";
    ReflectorsStr[2] = "AE BN CK DQ FU GY HW IJ LO MP RX SZ TV";
    ReflectorsStr[3] = "AR BD CO EJ FN GT HK IV LM PW QZ SX UY";

    string Letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    vector<Rotor> Rotors;
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
            continue;
        string RotorWiring = ParseRotorStr(RotorsStr[i])[0];
        string RotorSteps = ParseRotorStr(RotorsStr[i])[1];
        Rotors.push_back(Rotor(RotorWiring, RotorSteps, 'A', 'A'));
    }
    Rotors.reserve(Rotors.size());
    PairMapBase Reflector(ReflectorsStr[0], "Reflector");
    PairMapBase Plugboard("", "Plugboard");
    EnigmaBase enigma(Rotors, Reflector, Plugboard);
    string input = "hello the wonderful world";
    //string input = "GWKZO LQEHV";
    //string input = "IBSFO FDDZT";
    //cin >> input;
    string result;
    result = enigma.crypt(input);
    cout << "\n" << result << "\n";
    //test run
    
    

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
