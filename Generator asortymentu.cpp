#include <iostream>
#include <fstream>
//#include <windows.h>
#include <cstdlib>
using namespace std;

	
void nowyProdukt(){

	int typ;
	string nazwa;
	float cena;
	string typek;
	int czy;
	
	fstream asortyment;
	asortyment.open("asortyment.txt", ios::out | ios::app);
	
	cout<<"Wybierz typ produktu"<<endl;
	cout<<"1. Batronik"<<endl<<"2. Napoj"<<endl;
	cin>>typ;
	system("cls");
	cout<<"Podaj nazwe produktu"<<endl;
	cin>>nazwa;
	system("cls");
	cout<<"Podaj cene produktu"<<endl;	
	cin>>cena;
	system("cls");

	
	if(typ==1)
	typek="Batonik";
	else 
	if(typ==2)
	typek="Napoj";
	else typek="error";

	
	system("cls");
	cout<<"Czy jestes pewien, ze chcesz dodac nastepujacy produkt: "<<typek<<" "<<nazwa<<" w cenie "<<cena<<"PLN do listy asortymentu?"<<endl;
	cout<<"1. Tak"<<endl<<"2. Nie"<<endl;
	cin>>czy;	
	if(czy==1)
	{
		asortyment<<typ<<endl;
		asortyment<<nazwa<<endl;
		asortyment<<cena<<endl;
		cout<<"Dodawanie zakonczone sukcesem"<<endl;
			
	}
	else{
		cout<<"Przerwano dodawanie produktu"<<endl;
	}
}

int main(){
	
	cout<<"Ile produktow chcesz dodac?"<<endl;
	int ile;
	cin>>ile;
	
	for(int i=0;i<ile;i++){
	system("cls");
	nowyProdukt();
	
}
	
	
	return 0;
}
