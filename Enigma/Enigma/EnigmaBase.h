#pragma once
#include <vector>
#include <string>
#include "Rotor.h"
#include "PairMapBase.h"

using namespace std;

class EnigmaBase
{
				vector<Rotor> Rotors;
				vector<Rotor> RevRotors;
				PairMapBase Reflector;
				PairMapBase Plugboard;

public:
				EnigmaBase();
				EnigmaBase(vector<Rotor>& Rotors, PairMapBase& reflector, PairMapBase& plugboard);
				void step();
				string crypt(string input);
};

