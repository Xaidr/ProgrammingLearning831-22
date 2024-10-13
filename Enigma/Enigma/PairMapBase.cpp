#include "PairMapBase.h"

PairMapBase::PairMapBase()
{
				return;
}

PairMapBase::PairMapBase(string Pairs, string name)
{
				this->Pairs = Pairs;
				if (Pairs == "")
								return;

				stringstream ss(Pairs);
				vector<string> tokens;
				string token;
				while (ss >> token)
								tokens.push_back(token);
				
				for (string pair : tokens)
				{
								int a = Utils::a2i(pair[0]);
								int b = Utils::a2i(pair[1]);
								if (a == b)
												return;
								//unique test pairs
								this->Map[a] = b;
								this->Map[b] = a;
				}
}


int PairMapBase::Transform(int c)
{
				if (this->Map.size() == 0)
								return c;
				return this->Map[c];
}

int PairMapBase::RevTransform(int c)
{
				return Transform(c);
}
