#ifndef SayilarListesi_hpp
#define SayilarListesi_hpp

#include "Basamak.hpp"
#include "Sayi.hpp"
#include "Dugum.hpp"

class SayilarListesi
{
public:
    Dugum* ilk;

    SayilarListesi();
    ~SayilarListesi();

    void sayiyiTersCevir();

    void enbuyukSil();

    void teklerBasaAl();

    void sonaEkle(int veri);

    void yazdir();
};

#endif