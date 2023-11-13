#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

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

    int usAlma(int taban, int us)
    {
        int sonuc = 1;
        if (us > 0)
        {
            for (int i = 0; i < us; i++)
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

    int sayiDegeri()
    {
        Basamak* basamak = ilk;
        int basamaksayisi = 0;
        int toplam = 0;

        while (basamak != 0)
        {
            basamaksayisi++;
            basamak = basamak->sonraki;
        }
        basamak = ilk;

        while (basamak != 0)
        {
            toplam += basamak->veri * usAlma(10, basamaksayisi - 1);
            basamak = basamak->sonraki;
        }
        return toplam;
    }


    void tekleriBasaAl()
    {
        Basamak* sira = ilk;
        Basamak* onceki = 0;
        Basamak* suanki = 0;
        Basamak* sonraki = 0;

        int basamaksayisi = 0;
        suanki = ilk;
        while (suanki != 0)
        {
            basamaksayisi++;
            suanki = suanki->sonraki;
        }
        suanki = 0;


        if (basamaksayisi >= 3)
        {

            Basamak* onceki = ilk;
            Basamak* suanki = onceki->sonraki;
            Basamak* sonraki = suanki->sonraki;
            bool tek = true;

            if (ilk->veri % 2 == 1)
            {
                do
                {
                    if (suanki->veri % 2 == 1)
                    {
                        if (sira->sonraki == suanki)
                        {
                            sira = suanki;
                            onceki = suanki;
                            suanki = sonraki;
                            sonraki = sonraki->sonraki;
                        }
                        else
                        {
                            onceki->sonraki = sonraki;
                            suanki->sonraki = sira->sonraki;
                            sira->sonraki = suanki;
                            sira = suanki;
                            suanki = sonraki;
                            sonraki = sonraki->sonraki;
                        }
                    }
                    else
                    {
                        onceki = suanki;
                        suanki = sonraki;
                        sonraki = sonraki->sonraki;
                    }
                } while (suanki->sonraki != 0);
            }
            else
            {
                do
                {
                    if (suanki->veri % 2 == 1 && tek)
                    {
                        onceki->sonraki = sonraki;
                        suanki->sonraki = sira;
                        sira = suanki;
                        ilk = suanki;
                        suanki = sonraki;
                        sonraki = sonraki->sonraki;
                        tek = false;
                    }
                    else if (suanki->veri % 2 == 1)
                    {
                        onceki->sonraki = sonraki;
                        suanki->sonraki = sira->sonraki;
                        sira->sonraki = suanki;
                        sira = suanki;
                        suanki = sonraki;
                        sonraki = sonraki->sonraki;
                    }
                    else
                    {
                        onceki = suanki;
                        suanki = sonraki;
                        sonraki = sonraki->sonraki;
                    }
                } while (suanki->sonraki != 0);
            }

            if (suanki->veri % 2 == 1)
            {
                suanki->sonraki = sira->sonraki;
                sira->sonraki = suanki;
                onceki->sonraki = 0;
            }


        }
    }


    void sayiyiTersCevir()
    {
        Basamak* onceki = 0;
        Basamak* suanki = 0;
        Basamak* sonraki = 0;

        int basamaksayisi = 0;
        suanki = ilk;
        while (suanki != 0)
        {
            basamaksayisi++;
            suanki = suanki->sonraki;
        }
        suanki = 0;

        if (basamaksayisi == 2)
        {
            suanki = ilk;
            sonraki = ilk->sonraki;
            sonraki->sonraki = suanki;
            suanki->sonraki = 0;
            ilk = sonraki;
        }

        else if (basamaksayisi >= 3)
        {
            onceki = ilk;
            suanki = ilk->sonraki;
            sonraki = suanki->sonraki;

            do
            {
                suanki->sonraki = onceki;
                onceki = suanki;
                suanki = sonraki;
                sonraki = sonraki->sonraki;

            } while (sonraki != 0);

            suanki->sonraki = onceki;
            ilk->sonraki = 0;
            ilk = suanki;
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

    void sayiyiTersCevir()
    {
        Dugum* geciciDugum = ilk;

        while (geciciDugum != 0)
        {
            geciciDugum->sayi->sayiyiTersCevir();

            geciciDugum = geciciDugum->sonraki;
        }

    }

    void enbuyukSil()
    {
        Dugum* onceki = 0;
        Dugum* sonraki = 0;
        Dugum* suanki = ilk;
        Dugum* sil = 0;
        int buyukSayi = ilk->sayi->sayiDegeri();
        cout << "aaaaaaaaaaaaaaaaaaaaaa : " << buyukSayi << endl;

        int basamaksayisi = 0;
        while (suanki != 0)
        {
            basamaksayisi++;
            suanki = suanki->sonraki;
        }
        suanki = ilk;

        if (basamaksayisi == 1)
        {

        }
        else if (basamaksayisi == 2)
        {

        }
        else if (basamaksayisi >= 3)
        {







        }





    }

    void tekleriBasaAl()
    {
        Dugum* geciciDugum = ilk;

        while (geciciDugum != 0)
        {
            geciciDugum->sayi->tekleriBasaAl();

            geciciDugum = geciciDugum->sonraki;
        }

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
    /* Verileri dosyada okuma kismi*/
    SayilarListesi* liste = new SayilarListesi();

    string dosyaAdi = "Sayilar.txt";

    ifstream dosya(dosyaAdi);

    if (!dosya.is_open())
    {
        cerr << "Sayilar.txt dosyasi acilamadi.\n";
        return 1;
    }

    string satir;
    getline(dosya, satir);

    istringstream ss(satir);

    int sayi;

    while (ss >> sayi)
    {
        liste->sonaEkle(sayi);
    }

    /* Verileri dosyada okuma kismi*/


    /* Menu basma asamasi */
    int secim = 0;
    while (secim != 4)
    {
        liste->yazdir();

        cout << "1. Tek basamaklari Basa Al\n";
        cout << "2. Basamaklari Tersle\n";
        cout << "3. En Buyuk Sayiyi Cikar\n";
        cout << "4. Cikis\n\n";

        cout << "Yapmak istediginiz islemi tuslayiniz:  ";
        cin >> secim;
        cout << "\n\n";

        while (secim < 1 && secim > 4)
        {
            cout << "Olmayan bir islemi sectiniz lutfen 1,2,3,4 tuslarindan birini tuslayiniz.\n";
            cin >> secim;
        }
        
        if (secim == 1)
        {
            liste->tekleriBasaAl();
        }
        else if (secim == 2)
        {
            liste->sayiyiTersCevir();
        }
        else if (secim == 3)
        {
            liste->enbuyukSil();
        }
        else if (secim == 4)
        {
            cout << "Cikis yapiliyor.";
        }
        else
        {
            cout << "BUG";
        }
    }
    /* Menu basma asamasi */




    cin >> secim;

    return 0;
}
