#pragma once
#include <string>
#include <vector>
#include <map>
#include "Utils.h"

using namespace std;

class Rotor
{
    vector<int> Map;
    vector<int> RevMap;
    int rs;
    vector<int> Steps;
    int pos;

public:
    Rotor(string Wiring, string Steps, char RingSetting, char InitialPosition);
    int Step();
    int Transform(int c);
    int RevTransform(int c);
};

