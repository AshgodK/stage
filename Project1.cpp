// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "E:\VS\Project1\Project1\include\ipmsan.h"
#include <conio.h>

using namespace std;
void delete_line(const char* file_name, int n);
int main()
{
    start:
    int ch;


    
    int erreur;
    int i;
    int compt;

   
   

 




        cout << "outils staistique\n";
        cout << "1- ajouter ipmsan" << endl;
        cout << "2- supprimer ipmsan" << endl;
        cout << "3- modifier ipmsan" << endl;
        cout << "4- afficher list ipmsan" << endl;
        cout << "5- afficher les commandes" << endl;
        cout << "6- clear screen" << endl;
        cout << "7- quitter" << endl;
        cin >> ch;
        int plgD[10];
        int plgF[10];
        string a, b;
        int c;
        string t = ":2944";
        char p[16];
        switch (ch)
        {
        case 1:
        {
            cout << "donner nom:";
            cin >> a;
            ad:
            cout << "donner adresse ip:";
            cin >> p;
            erreur = 0;
            compt = 0;
            for (i = 0; erreur == 0 && i < strlen(p) - 1; i++)
            {
                if (p[i] == '.')
                {
                    p[i] == ' ';
                    compt = compt + 1;
                    i++;
                }

                if (p[i] < '0' || p[i] > '9')
                {
                    erreur = 1;
                }

            }

            if (erreur == 1 || compt != 3)
            {
                printf("Erreur");
                goto ad;
            }
            b = p + t;
            cout << "donner nombre de plages:";
            cin >> c;
            ipmsan i1(c, b, a);
            for (int i = 0; i < c; i++)
            {
                cout << "donner le debut de plage " << i + 1 << ":";
                cin >> plgD[i];
                cout << "donner le fin de plage " << i + 1 << ":";
                cin >> plgF[i];
                ofstream file;
                file.open("les commandes.txt", fstream::app);
                if (file.is_open())
                {
                    file << endl;
                    file <<"LST VSBR:LP=0," << "EID=\"" << b << "\",";
                    
                        file <<"TID=" << plgD[i] << ",";
                        file <<"ENDTID=" << plgF[i] << ";";
                    

                }
                file.close();
            }
            ofstream file;
            file.open("list ipmsan.txt", fstream::app);
            if (file.is_open())
            {
                file << endl;
                file << a << "     " << b << "    " << c << "  ";
                for (int i = 0; i < c; i++)
                {
                    file << plgD[i] << "  ";
                    file << plgF[i] << "  ";
                }
                
            }
            file.close();
            ofstream file1;
            file1.open("ip.txt", fstream::app);
            if (file1.is_open())
            {
                file1 << endl << b ;

            }
            file1.close();
            goto start;
        }
        case 2:
        {
            std::ifstream file2;
            int i = 0;
            file2.open("list ipmsan.txt", ifstream::app);

            if (file2.is_open())
            {


                std::cout << "donner adresse ip a supprimer: \n";
                std::string word;
                std::cin >> word;
                std::string line;

                std::string candidate;

                while (!file2.eof()) // for each candidate word read from the file 
                {
                    std::getline(file2, line);
                    std::size_t found = line.find(word);
                    i++;
                    if (found != std::string::npos)
                    {
                        
                        file2.close();
                        goto del;
                    }
                }

            }

            else
            {
                std::cerr << "Error! File not found!\n";
                return 1;
            }

            
            del:
            int n = i;
            cout << n;
            delete_line("list ipmsan.txt", n);
            //delete_line("ip.txt", n);
            
            goto start;
        }
        case 3:
        {
            std::ifstream file2;
            int i = 0;
            file2.open("list ipmsan.txt", ifstream::app);

            if (file2.is_open())
            {


                std::cout << "donner adresse ip a modifier: \n";
                std::string word;
                std::cin >> word;
                std::string line;

                std::string candidate;

                while (!file2.eof()) // for each candidate word read from the file 
                {
                    std::getline(file2, line);
                    std::size_t found = line.find(word);
                    i++;
                    if (found != std::string::npos)
                    {

                        file2.close();
                        goto del2;
                    }
                  
                }
                cout << "adresse ip introuvable";
                goto start;

            }

            else
            {
                std::cerr << "Error! File not found!\n";
                return 1;
            }


        del2:
            int n = i;
            cout << n;
            delete_line("list ipmsan.txt", n);
            //delete_line("ip.txt", n);
            cout << "donner nouveau nom:";
            cin >> a;
        ad2:
            cout << "donner adresse ip:";
            cin >> p;
            erreur = 0;
            compt = 0;
            for (i = 0; erreur == 0 && i < strlen(p) - 1; i++)
            {
                if (p[i] == '.')
                {
                    p[i] == ' ';
                    compt = compt + 1;
                    i++;
                }

                if (p[i] < '0' || p[i] > '9')
                {
                    erreur = 1;
                }

            }

            if (erreur == 1 || compt != 3)
            {
                printf("Erreur");
                goto ad2;
            }
            b = p + t;
            cout << "donner nouveau nombre de plages:";
            cin >> c;
            ipmsan i1(c, b, a);
            for (int i = 0; i < c; i++)
            {
                cout << "donner le debut de plage " << i + 1 << ": ";
                cin >> plgD[i];
                cout << "donner le fin de plage " << i + 1 << ": ";
                cin >> plgF[i];
                ofstream file;
                file.open("les commandes.txt", fstream::app);
                if (file.is_open())
                {
                    file << endl;
                    file << "LST VSBR:LP=0," << "EID=\"" << b << "\",";

                    file << "TID=" << plgD[i] << ",";
                    file << "ENDTID=" << plgF[i] << ";";


                }
                file.close();
            }
            ofstream file;
            file.open("list ipmsan.txt", fstream::app);
            if (file.is_open())
            {
                file << endl;
                file << a << "     " << b << "    " << c << "  ";
                for (int i = 0; i < c; i++)
                {
                    file << plgD[i] << "  ";
                    file << plgF[i] << "  ";
                }
                
            }
            file.close();
            ofstream file1;
            file1.open("ip.txt", fstream::app);
            if (file1.is_open())
            {
                file1 << endl << b ;

            }
            file1.close();
            goto start;
        }
        
        case 4:
        {
            string line;
            ifstream myfile("list ipmsan.txt");
            if (myfile.is_open())
            {
                while (getline(myfile, line))
                {
                    cout << line << '\n';
                }
                myfile.close();
            }

            else cout << "Unable to open file";
            goto start;

        }
        case 5:
        {
            string line;
            ifstream myfile("les commandes.txt");
            if (myfile.is_open())
            {
                while (getline(myfile, line))
                {
                    cout << line << '\n';
                }
                myfile.close();
            }

            else cout << "Unable to open file";
            goto start;
        }
        case 6:
        {
            system("cls");
            goto start;
        }
        case 7:
        {
            exit;
        }
        }
        

        
        
    
        
            /////////////////

        return 0;

            
    
}
void delete_line(const char* file_name, int n)
{
    // open file in read mode or in mode
    ifstream is(file_name);

    // open file in write mode or out mode
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    // loop getting single characters
    char c;
    int line_no = 1;
    while (is.get(c))
    {
        // if a newline character
        if (c == '\n')
            line_no++;

        // file content not to be deleted
        if (line_no != n)
            ofs << c;
    }

    // closing output file
    ofs.close();

    // closing input file
    is.close();

    // remove the original file
    remove(file_name);

    // rename the file
    rename("temp.txt", file_name);
}
