#include <iostream>

#include "Basamak.hpp"
#include "Sayi.hpp"
#include "Dugum.hpp"

Dugum::Dugum(Sayi& sayi)
{
    this->sayi=&sayi;
    this->sonraki=0;
}

Dugum::~Dugum()
{
    delete sayi;
    std::cout << "Dugum silindi" << std::endl;
}