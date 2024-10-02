#pragma once
#include <string>
#include <map>

using namespace std;

const string Letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class Utils
{
public:
				map<int, string> Rotors;
				map<int, string> Reflectors;
				Utils();
				static int Mod(int x, int y);
				static int a2i(char c, bool permissive = false);
				static char i2a(int i);
};

