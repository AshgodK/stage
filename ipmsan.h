#pragma once
#include<list>
#include<string>
using namespace std;
class ipmsan
{
private:
	string IP;
	int nbr_plages;
	string nom;
	
public:
	//ipmsan();
	ipmsan(int, string, string);
	string getIP()const { return IP; }
	string getNOM()const { return nom; }
	int getPLAGE()const { return nbr_plages; }
	void afficher();


};

