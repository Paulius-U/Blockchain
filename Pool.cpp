#include "Pool.h"
#include <fstream>
#include <string>
#include <bitset>
#include "Hash.h"
#include "Random.cpp"

using namespace std;

void Poolas()
{
    bitset<256> hash;
    string temp, ats;
    ofstream R ("Pool.txt");
    for (int i = 0; i < 1000; i++)
    {    
        int pirmas = random_number(1, 1000),
            antras = (pirmas + random_number(1, 1000)) % 1000;
        string laikinas1 = "", laikinas2 ="";
        laikinas1 += to_string(pirmas);
        laikinas2 += to_string(antras);
        ifstream D2 ("Vartotojas" + laikinas2 + ".txt");
        ifstream D ("Vartotojas"+ laikinas1 + ".txt");
        string vardas1, vardas2, hash1, hash2;
        int money1, money2;
        D >> vardas1 >> hash1 >> money1;
        D2 >> vardas2 >> hash2 >> money2;
        int money = random_number(1, money1);
        string ran = "";
        ran += to_string(money);
        std::string n = hash1 + hash2 + ran;
        hash = Hash(n);
        temp = hash.to_string();
        ats = ATS (temp);
        R << ats << " ";
        R << hash1 << " ";
        R << hash2 << " ";
        R << money << endl;
    }
}

void Pool100 ()
{
    std::string line;
    std::vector<string> lines;
    std::ifstream D("Pool.txt");
    std::ofstream R("Pool100.txt");
    int kiek = 0, A[100];
    while(getline(D, line))
    {
        kiek++;
        lines.push_back(line);
    }
    D.close();
    for(int i = 0; i < 100; i++)
    {
        A[i] = (random_number(0, kiek) * i) % kiek;
        R << lines[A[i]] << std::endl;
    }
    R.close();
    ofstream RR ("Pool.txt");
    for(int i = 0; i < kiek; i++)
    {
        bool spauzdinti = true;
        for(int j = 0; j < 100; j++)
        {
            if(A[j] == i) spauzdinti = false;
        }
        if(spauzdinti) RR << lines[i] << std::endl;
    }   
    cout << "veikia" << endl;
}