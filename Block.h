#pragma once

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <ctime>
#include <bitset>

using namespace std;

void Block();
void Trade(string ID[], string siuntejas[], string gavejas[], int suma[], int i, bool& valid);
std::bitset<256> Hash(std::string inp);
std::string ATS(std::string temp);
void Miner(string& x, int& n);
