#pragma once
#include <vector>
#include "Rotor.h"
#include "EnigmaBase.h"

using namespace std;

class EnigmaMachine : EnigmaBase
{
public:
				EnigmaMachine() : EnigmaBase() {};
				EnigmaMachine(vector<Rotor>& Rotors, PairMapBase& Reflector, PairMapBase& Plugboard) : EnigmaBase(Rotors, Reflector, Plugboard) {};
};

