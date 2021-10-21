#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

#include "Blockchain.cpp"
#include "Block.cpp"
#include "TransactionData.hpp"
#include "Vartotojai.cpp"
#include "Random.cpp"

using namespace std;

int main()
{
    ifstream D ("Pool100.txt");
    time_t data_time[100];
    string ID[100], siuntejas[100], gavejas[100];
    int suma[100];
    Blockchain awesomeCoin;

    for(int i = 0; i < 100; i++)
    {
        D >> ID[i] >> siuntejas[i] >> gavejas[i] >> suma[i];
    }

    for(int i = 0; i < 100; i++)
    {
        TransactionData data(suma[i], siuntejas[i], gavejas[i], time(&data_time[i]));
        awesomeCoin.addBlock(data);
    }
    awesomeCoin.printChain();
}