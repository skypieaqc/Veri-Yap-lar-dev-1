#include <iostream>
#include <iomanip>

using namespace std;

class Basamak
{
public:
    int veri;

    Basamak* sonraki;

    Basamak(int veri)
    {
        this->veri = veri;
        this->sonraki = 0;
    }

    ~Basamak()
    {
        cout << &veri << "Adresindeki: " << veri << " silindi" << endl;
    }
};


class Sayi
{
public:

    Basamak* ilk;

    Sayi()
    {
        ilk = 0;
    }

    void sonaEkle(int veri)
    {
        Basamak* yeni = new Basamak(veri);

        if (ilk == 0)
        {
            ilk = yeni;
        }
        else
        {
            Basamak* gecici = ilk;

            while (gecici->sonraki != 0)
            {
                gecici = gecici->sonraki;
            }

            gecici->sonraki = yeni;
        }
    }

    void yazdir()
    {
        Basamak* gecici = ilk;

        int basamaksayisi = 0;

        while (gecici != 0)
        {
            basamaksayisi++;

            gecici = gecici->sonraki;
        }

        int i = 0;
        
        cout <<"##################\t";
        
        for (i = 0; i < basamaksayisi; i++)
        {
            cout <<"******* ";
        }

        cout << endl << "#" << &ilk << "#\t";

        gecici = ilk;
        while (gecici != 0)
        {
            long long int adres = reinterpret_cast<long long int>(gecici);
            int sonUcBasamak = adres % 0x1000; // 0x1000 ile mod alıyoruz
           
            cout << "* " << hex << setw(3) << sonUcBasamak << " * ";

            gecici = gecici->sonraki;
        }

        cout << endl<<"#----------------#\t";

        for (i = 0; i < basamaksayisi; i++)
        {
            cout <<"******* ";
        }

        cout << endl << "#";
        for (i = 0; i < 16 - basamaksayisi; i++)
            cout << " ";

        gecici = ilk;
        while (gecici != 0)
        {
            cout << gecici->veri;

            gecici = gecici->sonraki;
        }
        cout << "#\t";

        gecici = ilk;
        while (gecici != 0)
        {
            cout << "* " << setw(3) << right << dec << gecici->veri << " * ";
            gecici = gecici->sonraki;
        }

        cout << endl << "##################\t";

        for (i = 0; i < basamaksayisi; i++)
        {
            cout << "******* ";
        }
        cout << endl << endl;
    }

    ~Sayi()
    {
        Basamak* gecici = ilk;

        while (gecici != 0)
        {
            Basamak* sil = gecici;
            gecici = gecici->sonraki;
            delete sil;
        }
    }
};


class Dugum
{
public:
    Sayi* sayi;

    Dugum* sonraki;

    Dugum(Sayi& sayi)
    {
        this->sayi = &sayi;
        this->sonraki = 0;
    }

    ~Dugum()
    {
        cout << sayi << "Adresindeki Basamak silindi" << endl;
    }
};



class SayilarListesi
{
public:
    Dugum* ilk;

    SayilarListesi()
    {
        ilk = 0;
    }


    void sonaEkle(int veri)
    {

        Sayi* sayi = new Sayi();

        if (veri < 10)
        {
            sayi->sonaEkle(veri);
        }
        else
        {
            int ters = 0;
            while (veri != 0)
            {
                ters *= 10;
                ters += veri % 10;
                veri /= 10;
            }
            while (ters != 0)
            {
                sayi->sonaEkle(ters % 10);
                ters /= 10;
            }
        }

        Dugum* dugum = new Dugum(*sayi);

        if (ilk == 0)
        {
            ilk = dugum;
        }
        else
        {
            Dugum* gecici = ilk;

            while (gecici->sonraki != 0)
            {
                gecici = gecici->sonraki;
            }
            gecici->sonraki = dugum;
        }
    }

    void yazdir()
    {
        Dugum* geciciDugum = ilk;

        while (geciciDugum != 0)
        {
            geciciDugum->sayi->yazdir();

            geciciDugum = geciciDugum->sonraki;
        }
    }

};



int main()
{

    SayilarListesi* liste = new SayilarListesi();

    liste->sonaEkle(1);
    liste->sonaEkle(12);

    liste->yazdir();




    cin.get();

    return 0;
}