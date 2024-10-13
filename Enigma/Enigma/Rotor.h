#pragma once
#include <string>
#include <unordered_set>
#include <vector>
#include <map>
#include "Utils.h"

using namespace std;

class Rotor
{
public:
    vector<int> Map;
    vector<int> RevMap;
    int rs;
    unordered_set<int> Steps;
    int pos;

    Rotor(string Wiring, string Steps, char RingSetting, char InitialPosition);
    int Step();
    int Transform(int c);
    int RevTransform(int c);
};

