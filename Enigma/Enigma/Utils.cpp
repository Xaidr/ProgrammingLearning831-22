#include "Utils.h"

Utils::Utils()
{
    Rotors[0] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ<R";
    Rotors[1] = "AJDKSIRUXBLHWTMCQGZNPYFVOE<F";
    Rotors[2] = "BDFHJLCPRTXVZNYEIWGAKMUSQO<W";
    Rotors[3] = "ESOVPZJAYQUIRHXLNFTGKDCMWB<K";
    Rotors[4] = "VZBRGITYUPSDNHLXAWMJQOFECK<A";
    Rotors[5] = "JPGVOUMFYQBENHZRDKASXLICTW<AN";
    Rotors[6] = "NZJHGRCXMYSWBOUFAIVLPEKQDT<AN";
    Rotors[7] = "FKQHTLXOCBJSPDZRAMEWNIUYGV<AN";

    Reflectors[0] = "AY BR CU DH EQ FS GL IP JX KN MO TZ VW";
    Reflectors[1] = "AF BV CP DJ EI GO HY KR LZ MX NW TQ SU";
    Reflectors[2] = "AE BN CK DQ FU GY HW IJ LO MP RX SZ TV";
    Reflectors[3] = "AR BD CO EJ FN GT HK IV LM PW QZ SX UY";
}

int Utils::Mod(int x, int y)
{
				return (((x % y) + y) % y);
}

int Utils::a2i(char c, bool permissive)
{
    int i = (int)c;
    if (i >= 65 && i <= 90)
        return (i - 65);
    if (permissive)
        if (i >= 97 && i <= 122)
            return (i - 97);

    return -1;
}

char Utils::i2a(int i)
{
    if (i >= 0 && i < 26)
        return ('A' + (char)i);
    return '*';
}


