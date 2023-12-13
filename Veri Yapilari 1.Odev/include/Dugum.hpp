#ifndef Dugum_hpp
#define Dugum_hpp

#include "Basamak.hpp"
#include "Sayi.hpp"

class Dugum
{
public:

    Sayi* sayi;

    Dugum* sonraki;

    Dugum(Sayi& sayi);
    
    ~Dugum();
};

#endif