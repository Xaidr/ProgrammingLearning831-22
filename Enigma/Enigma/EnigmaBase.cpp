#include "EnigmaBase.h"



EnigmaBase::EnigmaBase()
{
				return;
}

EnigmaBase::EnigmaBase(vector<Rotor>& Rotors, PairMapBase& reflector, PairMapBase& plugboard)
{
				vector<Rotor> rr(Rotors);
				rr.reserve(Rotors.size());
				this->Rotors = Rotors;
				this->RevRotors = rr;
				this->Reflector = reflector;
				
}

void EnigmaBase::step()
{
				this->Rotors[0].Step();
				if (this->Rotors[0].Steps.count(this->Rotors[0].pos) ||
								this->Rotors[1].Steps.count(Utils::Mod(this->Rotors[1].pos + 1, 26)))
				{
								this->Rotors[1].Step();
								if (this->Rotors[1].Steps.count(this->Rotors[1].pos))
												this->Rotors[2].Step();
				}
}

string EnigmaBase::crypt(string input)
{
				string result;
				for (char c : input)
				{
								int letter = Utils::a2i(c, true);
								if (letter == -1)
								{
												result += c;
												continue;
								}
								this->step();
								letter = this->Plugboard.Transform(letter);
								for (Rotor r : this->Rotors)
												letter = r.Transform(letter);
								letter = this->Reflector.Transform(letter);
								for (Rotor r : this->RevRotors)
												letter = r.RevTransform(letter);
								letter = this->Plugboard.RevTransform(letter);
								result += Utils::i2a(letter);
				}
				return result;
}
