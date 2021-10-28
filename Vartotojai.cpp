#include "Vartotojai.h"
#include <fstream>
#include <bitset>
#include <string>
#include "Hash.h"
#include "Random.h"

using namespace std;

void Vartotojai()
{
    std::bitset<256> hash;
    std::string temp, ats;
    for (int i = 0; i < 1000; i++)
    {
        std::string laikians = "";
        laikians += to_string(i + 1); 
        std::string vardas = "Vartotojas" + laikians + ".txt";
        std::ofstream R (vardas);
        R << "Vardenis" << i + 1 << std::endl;
        std::string raide = vardas;
        hash = Hash (raide);
        temp = hash.to_string();
        ats = ATS (temp);
        R << ats << endl;
        int valiuta = random_number(100, 1000000);
        R << valiuta << std::endl;
    }
}