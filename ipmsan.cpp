#include "ipmsan.h"
#include <iostream>



/*ipmsan::ipmsan()
{
    //ctor
}
*/

ipmsan::ipmsan(int a, string b, string c)
{
    this->nbr_plages = a;
    this->nom = b;
    this->IP = c;
    
}
void ipmsan::afficher()
{
    cout << getIP()<<endl;
    cout << getNOM() << endl;
    cout << getPLAGE() << endl;
}