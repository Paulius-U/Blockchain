#include "Balancas.h"
#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
#include "Hash.h"

using namespace std;

string GetFile() 
{
    bool Failas;
    std::string FileName;
    cout << "account pavadinimas: " << std::endl;
    cin >> FileName;
    do {
        try {
            std::ifstream D (FileName);
            if (!D.good())      
                throw 0;
            else {
                D.close();
                Failas = false;
            }
        } catch (int exception) {   
            Failas = true;
            cout << "Failas - " << FileName << " Neegzistuoja" << std::endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> FileName;
        }
    } while (Failas);             
    return FileName;
}

void Skaitymas()
{
    std::string FileName = GetFile();
    std::ifstream D (FileName);
    std::string vardas, hash;
    int money;
    D >> vardas >> hash >> money;
    cout << "Vartotojo vardas:     " << vardas << std::endl;
    cout << "Vartotojo hash:       " << hash << std::endl;
    cout << "Vartotojo balancas:   " << money << std:: endl;
    int x;
    cout << "Ar norite daryti pavedima (1/0) " << endl;
    cin >> x;
    if(x == 1)
    {
        string siuntejas, line, ID, a = "", b = "";
        int suma;
        bitset<256> bits;
        cout << "Gavejo hash" << endl;
        cin >> siuntejas;
        cout << "pavedimo suma" << endl;
        cin >> suma;
        if(suma > 0)
        {
            ifstream in ("Pool.txt");
            ofstream out ("Pool0.txt");
            while(getline(in, line))
            {
                out << line << endl;
            }

            b += to_string(suma);
            ID = hash + siuntejas + b;
            bits = Hash(ID);
            a += bits.to_string();
            line = ATS(a);
            out << line << " " << hash << " " << siuntejas << " " << suma << endl;
            in.close();
            out.close();
            ifstream duota ("Pool0.txt");
            ofstream rez ("Pool.txt");
            while(getline(duota, line))
            {
                rez << line << endl;
            }
        }
    }
}