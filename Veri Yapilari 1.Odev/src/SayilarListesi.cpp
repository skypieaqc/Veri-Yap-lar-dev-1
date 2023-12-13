#include <iostream>

#include "Basamak.hpp"
#include "Sayi.hpp"
#include "Dugum.hpp"
#include "SayilarListesi.hpp"

SayilarListesi::SayilarListesi()
{
    ilk=0;
}

SayilarListesi::~SayilarListesi()
{
    Dugum* gecici = ilk;

    int i = 0;
    while (gecici !=0 )
    {
        Dugum* sil = gecici;
        gecici = gecici->sonraki;
        delete sil;
        std::cout << ++i<< " Dugum silindi " << std::endl;
    }
}

void SayilarListesi::sayiyiTersCevir()
{
    Dugum* geciciDugum = ilk;

    while(geciciDugum!=0)
    {
        geciciDugum->sayi->sayiyiTersCevir();
        geciciDugum=geciciDugum->sonraki;
    }
}

void SayilarListesi::enbuyukSil()
{
    Dugum* onceki = 0;
    Dugum* suanki = 0;
    Dugum* sonraki=0;
    Dugum* sil = 0;
    int buyukSayi = ilk->sayi->sayiDegeri();
    int kucukSayi =0;

    std::cout << "Sayi:  " << buyukSayi << std::endl;

    int basamaksayisi=0;
	suanki = ilk;
    while(suanki!=0)
    {
        basamaksayisi++;
        suanki=suanki->sonraki;
    }
    suanki=ilk;

    if(basamaksayisi==1)
    {
        delete ilk;
        ilk=0;
    }
    else if (basamaksayisi == 2 )
    {
        suanki=ilk;
        sonraki=ilk->sonraki;

        if(suanki->sayi->sayiDegeri() > sonraki->sayi->sayiDegeri())
        {
            delete suanki;
            ilk = sonraki;
        }
        else
        {
            delete sonraki;
            suanki->sonraki=0;
        }
    }

    else if(basamaksayisi >= 3)
    {
        Dugum* sil = ilk;
        buyukSayi = ilk->sayi->sayiDegeri();
        bool first = true; //Silinecek olan dugumun ilk dugum olup olmadigini gosteriyor

        onceki = ilk;
        suanki = ilk->sonraki;
        sonraki = suanki->sonraki;

        if(buyukSayi < suanki->sayi->sayiDegeri())
        {
            buyukSayi = suanki->sayi->sayiDegeri();
            sil = suanki;
            first = false;
        }

        while (sonraki->sonraki != 0)
        {
            onceki = suanki;
            suanki = sonraki;
            sonraki = sonraki->sonraki;

            if(buyukSayi < suanki->sayi->sayiDegeri())
            {
                buyukSayi = suanki->sayi->sayiDegeri();
                sil = suanki;
                first = false; 
            }
        }

        if (buyukSayi < sonraki->sayi->sayiDegeri())
        {
            buyukSayi = sonraki->sayi->sayiDegeri();
            sil = sonraki;
            first = false;
        }

        if(first)//Silinecek dugum ilk dugum ise
        {
            suanki = sil;
            sonraki = suanki->sonraki;
            delete sil;
            ilk = sonraki;
        }
        else 
        {
            onceki = ilk;
            suanki = ilk->sonraki;
            sonraki = suanki->sonraki;


            while (suanki!=sil)
            {
                onceki = suanki;
                suanki = suanki->sonraki;
            }
            sonraki = suanki->sonraki;

             delete sil;
             onceki->sonraki = sonraki;
        }
    }
}

void SayilarListesi::teklerBasaAl()
{
    Dugum* geciciDugum = ilk;

    while(geciciDugum!=0)
    {
        geciciDugum->sayi->tekleriBasaAl();

        geciciDugum = geciciDugum->sonraki;
    }
}

void SayilarListesi::sonaEkle(int veri)
{
    Sayi* sayi = new Sayi();

    if(veri < 10)//Sayi tek basamakli ise
    {
        sayi->sonaEkle(veri);
    }
    else
    {
        int ters = 0;
        while(veri !=0)
        {
            ters *=10;
            ters += veri %10;
            veri/=10;
        }
        while(ters!=0)
        {
            sayi->sonaEkle(ters%10);
            ters/=10;
        }
    }

    Dugum* dugum = new Dugum(*sayi);

    if(ilk == 0)
    {
        ilk = dugum;
    }
    else 
    {
        Dugum* gecici = ilk;

        while(gecici->sonraki!=0 )
        {
            gecici = gecici->sonraki;
        }
        gecici->sonraki=dugum;
    }
}

void SayilarListesi::yazdir()
{
    Dugum* geciciDugum = ilk;

    while(geciciDugum!=0)
    {
        geciciDugum->sayi->yazdir();
        geciciDugum = geciciDugum->sonraki;
    }
}