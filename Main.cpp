#include <iostream>
#include "Vartotojai.cpp"
#include "Pool.cpp"
#include "Balancas.cpp"
#include "Block.cpp"
#include "Hash.cpp"

using namespace std;

int main()
{
    int random;
    cout << "Sugeneruoti vartotojus: (1) " << endl;
    cout << "Sugegnruoti pool tranzakciju (2)" << endl;
    cout << "Is sugeneruotu tranzakciju pasirenkama atsitiktinu 100 (3) " << endl;
    cout << "Tikrinti asmeninius duomenis: (4) " << endl;
    cout << "Sudaryti block ir ideti ji i blockchain (5)" << endl;
    cin >> random;

    if(random == 1) 
    {
        Vartotojai();
    }

    if(random == 2)
    {
        Poolas();
    }

    if(random == 3)
    {
        Pool100();
    }

    if(random == 4)
    {
        Skaitymas();
    }

    if(random == 5)
    {
        Block();
    }
}