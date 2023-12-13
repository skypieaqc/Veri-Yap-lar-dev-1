#include <iostream>
#include <iomanip>

#include "Basamak.hpp"
#include "Sayi.hpp"

Sayi::Sayi()
{
    ilk=0;
}

void Sayi::sonaEkle(int veri)//En sona yeni basamak ekleyen metot
{
    Basamak* yeni = new Basamak(veri);

    if(ilk == 0)
    {
        ilk = yeni;
    }
    else
    {
        Basamak* gecici = ilk;

        while(gecici->sonraki!=0)
        {
            gecici = gecici->sonraki;
        }

        gecici->sonraki = yeni;
    }
}

int Sayi::usAlma(int taban, int us)//Lazim olabilir diye yazdim ancak main dosyasinda kullanmadim.
{
    int sonuc = 1;
    if(us > 0)
    {
        for(int i = 0 ; i < us ; i++)
        {
            sonuc *= taban;
        }
        return sonuc;
    }
    else if (us == 0)
        return 1;
    else
        return 0;
}

//Sayilar Listesinden en buyuk sayiyi cikartirken kullandigim fonksiyon.
//Metot Basamaklardaki sayilari tek bir sayi olarak dondurur.
int Sayi::sayiDegeri()
{
    Basamak* basamak = ilk;
    int basamaksayisi = 0 ;
    int toplam = 0;
    
    while(basamak!=0)//Her basamagi gezerek toplam sayisinin birler basamagina ekliyorum.
    {
        toplam*=10;                 //Sayilarin basamak degerlerini dogru elde etmek icin.
        toplam += basamak->veri;
        basamak = basamak->sonraki;
    }
    return toplam;
}

void Sayi::tekleriBasaAl()
{
	int basamaksayisi=0;
	Basamak* suanki=ilk;
	Basamak* onceki=0;
	Basamak* sira = 0;
	bool amk = true;
	while(suanki!=0)
	{
		basamaksayisi++;
		suanki = suanki->sonraki;
	}
	suanki = ilk;
	
	if(basamaksayisi >=3 )
	{
		onceki = ilk;
		suanki = ilk->sonraki;
		
		if(ilk->veri % 2 == 1)
		{
			sira = ilk;
			do
			{
				if(suanki->veri %2 == 1)
				{
					if(sira->sonraki!=suanki)
					{
						Basamak* tmp = sira->sonraki;
						sira->sonraki = suanki;
						onceki->sonraki=suanki->sonraki;
						suanki->sonraki=tmp;
						sira=suanki;
						suanki=onceki->sonraki;
					}
					else
					{
						onceki=suanki;
						suanki=suanki->sonraki;
					}
				}
				else
				{
					onceki=suanki;
					suanki=suanki->sonraki;
				}		
			}while(suanki!=0);
		}
		
		else
		{
			do
			{
				if(suanki->veri %2 == 1 && amk)
				{
					Basamak* tmp = suanki->sonraki;
					onceki->sonraki= tmp;
					suanki->sonraki = ilk;
					sira = suanki;
					ilk = suanki;
					amk = false;
					suanki = tmp;
				}
				else if(suanki->veri %2 == 1)
				{
					Basamak* tmp = sira->sonraki;
					sira->sonraki = suanki;
					onceki->sonraki=suanki->sonraki;
					suanki->sonraki=tmp;
					sira=suanki;
					suanki=onceki->sonraki;
					
				}
				else
				{
					onceki=suanki;
					suanki= suanki->sonraki;
				}
				
			}while(suanki!=0);	
		}	
	}
	
	if(basamaksayisi==2)
	{
		if(ilk->veri%2 == 0 )
		{
			onceki = ilk;
			suanki = ilk->sonraki;
			suanki-> sonraki = onceki;
			onceki->sonraki=0;
			ilk = suanki;
		}
	}
}


void Sayi::sayiyiTersCevir()
{
    Basamak* onceki = 0;
    Basamak* suanki = 0;
    Basamak* sonraki = 0;

    int basamaksayisi = 0;
    suanki = ilk;
    while(suanki !=0)
    {
        basamaksayisi++;
        suanki= suanki->sonraki;
    }
    suanki=0;
	std::cout << basamaksayisi << std::endl;
    if(basamaksayisi==2)
    {
        suanki=ilk;
        sonraki = ilk->sonraki;
        sonraki->sonraki = suanki;
        suanki->sonraki = 0;
        ilk = sonraki;
    }
    else if (basamaksayisi >= 3 )
    {
        onceki = ilk;
        suanki = onceki->sonraki;
        sonraki = suanki->sonraki;

        do
        {
            suanki->sonraki=onceki;
            onceki=suanki;
            suanki=sonraki;      
			sonraki= sonraki->sonraki;
			
        } while (sonraki!=0);
        
        suanki->sonraki=onceki;
        ilk->sonraki=0;
        ilk = suanki;
    }
}

void Sayi::yazdir()
{
    Basamak* gecici = ilk;
    int basamaksayisi= 0;

    while (gecici != 0 )
    {
        basamaksayisi++;
        gecici= gecici->sonraki;
    }
    gecici= ilk;
    int i = 0;

    std::cout <<"##############\t";

    for(i = 0 ; i < basamaksayisi; i++)
    {
        std::cout <<"******* ";
    }

    std::cout << std::endl << "#" << std::setw(12)<< &ilk << "#\t";

    while(gecici != 0 )
    {
        long long int adres = reinterpret_cast<long long int>(gecici);
        int sonUcBasamak = adres % 0x1000;

        std::cout << "* " << std::hex << std::setw(3) << sonUcBasamak << " * ";

        gecici = gecici->sonraki;
    }

    std::cout <<std:: endl<<"#------------#\t";

    for (i = 0; i < basamaksayisi; i ++ )
    {
        std::cout << "******* ";
    }

    std::cout << std::endl << "#";
    
	for (i = 0 ; i < 12-basamaksayisi; i++ )
    {
        std::cout << " ";
    }
	
	gecici = ilk;
	while(gecici !=0)
	{
		std::cout << gecici->veri;
		
		gecici = gecici->sonraki;
	}
	std::cout << "#\t";
		
	gecici = ilk;	
    while (gecici!=0)
    {
        std::cout << "* " << std::setw(3) << std::right << std::dec << gecici->veri << " * ";
        gecici = gecici->sonraki;
    }

    std::cout << std::endl <<"##############\t";

    for(i=0;i< basamaksayisi; i++)
    {
        std::cout << "******* ";
    }
    std::cout << std::endl<< std::endl;
}

Sayi::~Sayi()
{
    Basamak* gecici = ilk;
    int i =0;
    while (gecici!=0)
    {
        Basamak* sil = gecici;
        gecici=gecici->sonraki;
        delete sil;
        std::cout << ++i << " basamak silindi" << std::endl;
    }
}
