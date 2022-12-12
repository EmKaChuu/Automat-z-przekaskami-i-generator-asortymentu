#include <iostream>
#include <fstream>
//#include <windows.h>
#include <cstdlib>
using namespace std;


int main(){
	
	fstream asortyment;
	asortyment.open("asortyment.txt", ios::in);
	if(asortyment.good()==false){
	cout<<"Plik nie istnieje"<<endl;
	exit(0);}
	
	//zliczanie ilosci linii do dynamicznych tablic
	string linie;
	int dlugosc_pliku = 0;
	while(getline(asortyment, linie))
    {dlugosc_pliku++;}
	int ilosc_produktow=dlugosc_pliku/3;
	asortyment.close();
	
	//dynamiczna deklaracja tablic
	string * Nazwa = new string[ilosc_produktow];
	int * Typ = new int[ilosc_produktow];
	float * Cena = new float[ilosc_produktow];
	/*
	string Nazwa[5];
	int Typ[5];
	float Cena[5];
	*/
	
	asortyment.open("asortyment.txt", ios::in);
	if(asortyment.good()==false){
	cout<<"Plik nie istnieje"<<endl;
	exit(0);}
	
	
	int nr_produktu=0;
	int nr_linii=1;
	string linia;

	//Wpisywanie produkt�w do tablic
	 while (getline(asortyment, linia))
    {
        switch (nr_linii)
        {
            case 1: Typ[nr_produktu]=atoi(linia.c_str()); break;
            case 2: Nazwa[nr_produktu]=linia; break;
            case 3: Cena[nr_produktu]=atoi(linia.c_str());nr_linii=0;nr_produktu++; break;	
        }
     nr_linii++;  
    }
	
	//Wypisywanie produkt�w na ekranie
	cout<<"Wybierz produkt"<<endl<<endl<<endl;
	for(int i=0;i<ilosc_produktow;i++)
	{
		cout<<i+1<<" "<<Nazwa[i]<<" - "<<Cena[i]<<"zl"<<endl;
	}
	cout<<endl;
	int wybor;
	int wybrano;
	cin>>wybor;
	system("cls");
	wybrano=wybor-1;
	int platnosc;
	cout<<"Wybrales "<<Nazwa[wybrano]<<" za "<<Cena[wybrano]<<"zl"<<endl<<"Wybierz forme zaplaty"<<endl;
	cout<<"1 - karta"<<endl<<"2 - gotowka"<<endl;
	cin>>platnosc;
	switch(platnosc){
	case 1:
		cout<<"Prosze przylozyc karte do czytnika i wprowadzic PIN"<<endl;
		break;
	
	case 2:
		cout<<"Prosze dokonac platosci gotowka"<<endl;
		break;
	
	
	}
	cout<<"Platnosc dokonana, odbierz produkt, ";
	if(platnosc=2){
		cout<<" odbierz reszte, ";
	}
	cout<<"zapraszamy ponownie do skorzystania z naszych uslug"<<endl;
	
	
	
	
	
	return 0;
}
