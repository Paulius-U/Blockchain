#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <ctime>
#include <bitset>
#include "Block.h"
#include "Hash.h"

using namespace std;

void Block()
{
    int p = 1;
    bool valid, valid2 = false;
    string bendras = " ";
    ifstream D;
    string filename = "Pool100.txt";
    ofstream Rez ("Block.txt");
    string ID[100], siuntejas[100], gavejas[100];
    int suma[100];
    D.open(filename.c_str());
    for(int i = 0; i < 100; i++)
    {
        D >> ID[i] >> siuntejas[i] >> gavejas[i] >> suma[i];
    }
    for(int i = 0; i < 100; i++)
    {
        if(ID[i] != "") 
        {
            string a = " ";
            a += to_string(suma[i]);
            Trade(ID, siuntejas, gavejas, suma, i, valid);
            if(valid) 
            {
                bendras += ID[i] + siuntejas[i] + gavejas[i] + a;
                Rez << "------------------------" << endl;
                Rez << siuntejas[i] << endl;
                Rez << gavejas[i] << endl;
                Rez << suma[i] << endl;
                Rez << "------------------------" << endl;
                valid2 = true;
            }
        }
    }
    Rez.close();
    if(valid2)
    {
        std::time_t t = std::time(0);;
        bitset<256> hash = 0;
        int n;
        string eilute, nn = "";
        bitset<256> PrevHash;
        ifstream in("Block.txt");
        ifstream inchain("Prevhash.txt");
        ofstream out("Blockchain.txt");

        inchain >> PrevHash;
        inchain.close();
        nn += PrevHash.to_string();
        bendras += nn;
        cout << "Mininig: " << endl;
        Miner(bendras, n);
        string h;
        h = ATS(bendras);
        cout << endl;
        cout << h << endl;
        out << "------------------------------------------------" << endl;
        out << PrevHash << endl;
        ofstream outchain("PrevHash.txt");
        outchain << bendras;
        out << bendras << endl;
        out << t << endl;
        out << "1" << endl;
        out << n << endl;
        while(getline(in, eilute))
        {
            out << eilute << endl;
        }
        out << "------------------------------------------------" << endl;
        in.close();
        string fileName = "PrevBlocks.txt";
        ifstream duota (fileName);
        while(getline(duota, eilute))
        {
            out << eilute << endl;
        }
        ifstream ddd ("Blockchain.txt");
        ofstream rez (fileName);
        while(getline(ddd, eilute))
        {
            rez << eilute << endl;
        }
    }
}

void Trade(string ID[], string siuntejas[], string gavejas[], int suma[], int i, bool& valid)
{
    bool a = false;
    for(int j = 1; j <= 1000; j++)
    {
        bool randomas = false;
        ifstream in;
        ofstream out;
        string vardas, hash;
        int bal;
        string laikinas = "";
        laikinas += to_string(j);
        string fileName = "Vartotojas" + laikinas + ".txt";
        in.open(fileName.c_str());
        in >> vardas >> hash >> bal;
        in.close();
        if(hash == siuntejas[i]) 
        {
            if(suma[i] <= bal) 
            {
                bal -= suma[i];
                randomas = true;
                a = randomas;
            }
        }
        if(hash == gavejas[i]) 
        {
            if(randomas == true) 
            {
                bal += suma[i];
            }
        }
        out.open (fileName);
        out << vardas << endl;
        out << hash << endl;
        out << bal << endl;
        out.close();
    }
    valid = a;
    if(valid == true)
    {
        cout << "------------------------------------------------" << endl;
        cout << "siutejo hash: " << siuntejas[i] << endl;
        cout << "Gavejo hash: " << gavejas[i] << endl;
        cout << "Pervesta suma: " << suma[i] << endl;
        cout << "------------------------------------------------" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    } 
}

void Miner(string& x, int& n)
{
    string temp, ats, b;
    for(int i = 0; i < 1000000; i++)
    {
        char random[300] = {0};
        int kiek = 0;
        string a = ""; 
        b = x;
        bitset<256> hash = 0;
        a += to_string(i);
        b += a;
        hash = Hash(b);
        temp = hash.to_string();
        strcpy(random, temp.c_str());
        for (int j = 0; j < 10; j++)
        {
            if(random[j] == '0')
            {
                kiek++;
            } 
        }
        if(kiek == 10) 
        {
            x = temp;
            n = i;
            break;
        }
        if(i % 100 == 0)
        {
            cout << ".";
        }
    }
}