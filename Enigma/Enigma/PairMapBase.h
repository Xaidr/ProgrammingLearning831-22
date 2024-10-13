#pragma once
#include "Utils.h"
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class PairMapBase
{
				string Pairs;
				map<int, int> Map;

public:
				PairMapBase();
				PairMapBase(string Pairs, string name);
				int Transform(int c);
				int RevTransform(int c);
};

