#ifndef Basamak_hpp
#define Basamak_hpp

class Basamak//Sayilari basamaklar halinde tasiyan basamak sinifi
{
public:
    int veri;
    
    Basamak *sonraki;

    Basamak(int veri);

    ~Basamak();

};

#endif