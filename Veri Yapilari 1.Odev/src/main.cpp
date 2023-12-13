/**
* @file main.cpp
* @description Dosyadan sayıların okunduğu ve işlemlerin yapıldığı kodlar.
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date 26.11.2023
* @author Ahmet Yunus Çavuş ahmet.cavus1@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "Basamak.hpp"
#include "Sayi.hpp"
#include "Dugum.hpp"
#include "SayilarListesi.hpp"

using namespace std;

int main()
{
    SayilarListesi* liste = new SayilarListesi();
	
    ifstream dosya("Sayilar.txt");
    if(!dosya.is_open())
    {
        cerr << "Sayilar.txt dosyasi acilamadi.\n";
        return 1;
    }
    string satir;
    getline(dosya,satir);

    istringstream yazdir(satir);

    int sayi;
    while( yazdir >> sayi)
    {
        liste->sonaEkle(sayi);
    }
    dosya.close();

    int secim = 0;
    while(secim != 4)
    {
        if(liste->ilk!=0)
        {
            liste->yazdir();
        }
        cout << "1. Tek basamaklari Basa Al\n";
        cout << "2. Basamaklari Tersle\n";
        cout << "3. En Buyuk Sayiyi Cikar\n";
        cout << "4. Cikis\n\n";

        cout << "Yapmak istediginiz islemi tuslayiniz:  ";
        cin >> secim;
        cout << "\n\n";

        while(secim <1 && secim > 4 )
        {
            cout << "Olmayan bir islemi sectiniz lutfen 1,2,3,4 rakamlarini tuslayin.\n";
            cin >> secim;
        }
        if (secim == 1 )
        {
            liste->teklerBasaAl();
        }
        else if(secim == 2)
        {
            liste->sayiyiTersCevir();
        }
        else if(secim == 3)
        {
            if(liste->ilk!=0)
            {
                liste->enbuyukSil();
            }
        }
        else if (secim == 4)
        {
            cout << "Cikis yapiliyor.";
        }
    }

    return 0;
}