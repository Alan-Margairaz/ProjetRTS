#include "NPC.hpp"
#include <iostream>

using namespace std;

NPC::NPC()
{
    cout << "Objet crée." << endl;
};

NPC::~NPC()
{
    cout << "Objet détruit." << endl;
};

NPC::NPC(const NPC& src) 
{
    cout << "Copie faite." << endl;
};

NPC &NPC::operator=(const NPC& rhs)
{
    cout << "Objet de la copie crée." << endl;
};


