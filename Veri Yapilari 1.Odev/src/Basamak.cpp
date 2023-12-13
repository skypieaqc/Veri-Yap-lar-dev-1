/**
* @file Basamak.cpp
* @description Basamak Sınıfını oluşturan kodlar.
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date 26.11.2023
* @author Ahmet Yunus Çavuş ahmet.cavus1@ogr.sakarya.edu.tr
*/
#include <iostream>

#include "Basamak.hpp"

Basamak::Basamak(int veri)//Basamak sinifinin Kurucu fonksiyonu tanimi
{
    this->veri=veri;
    this->sonraki=0;
}

Basamak::~Basamak()//Basamak sinifinin Yokedici fonksiyonun tanimi 
{
    std::cout << &veri << " Adresindeki: " << veri << " silindi" << std::endl;
}