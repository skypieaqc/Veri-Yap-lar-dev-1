#ifndef Sayi_hpp
#define Sayi_hpp

#include "Basamak.hpp"

class Sayi//Sayi sinifi ve metotlarin bulundugu sinif
{
public:

    Basamak* ilk;

    Sayi();
    ~Sayi();

    void sonaEkle(int veri);

    int usAlma(int taban, int us);

    int sayiDegeri();

    void tekleriBasaAl();

    void sayiyiTersCevir();

    void yazdir();

};

#endif