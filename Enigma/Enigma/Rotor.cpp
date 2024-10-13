#include "Rotor.h"

Rotor::Rotor(string Wiring, string Steps, char RingSetting, char InitialPosition)
{
				//test wiring
				//test steps
				//test ringsetting
				//test initialposition

				Map.resize(26);
				RevMap.resize(26);
				int ls = Letters.size();

				for (int i = 0; i < ls; i++)
				{
								int a = Utils::a2i(Letters[i]);
								int b = Utils::a2i(Wiring[i]);
								Map[a] = b;
								RevMap[b] = a;
				}

				rs = Utils::a2i(RingSetting);
				for (char c : Steps)
								this->Steps.insert(Utils::Mod(Utils::a2i(c) - rs, 26));
				pos = Utils::Mod(Utils::a2i(InitialPosition) - rs, 26);
}

int Rotor::Step()
{
				pos = Utils::Mod(pos + 1, 26);
				return pos;
}

int Rotor::Transform(int c)
{
				return Utils::Mod(Map[Utils::Mod(c + pos, 26)] - pos, 26);
}

int Rotor::RevTransform(int c)
{
				return Utils::Mod(RevMap[Utils::Mod(c + pos, 26)] - pos, 26);
}
