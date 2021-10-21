#include <bitset>
#include <string>
#include "Vartotojai.hpp"
#include "Hash.hpp"
#include "Random.hpp"
#include <fstream>

using namespace std;

void Vartotojai()
{
    bitset<256> hash;
    string temp, ats;
    for (int i = 0; i < 4; i++)
    {
        string laikians = "";
        laikians += to_string(i + 1); 
        string vardas = "Vartotojas" + laikians + ".txt";
        ofstream R (vardas);
        R << "Vardenis" << i + 1 << endl;
        string raide = gen_random(10);
        hash = Hash (raide);
        temp = hash.to_string();
        ats = ATS (temp);
        R << ats << endl;
        int valiuta = random_number(100, 1000000);
        R << valiuta << endl;
    }
}