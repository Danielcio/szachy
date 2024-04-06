#ifndef SZACH_GONIEC_H
#define SZACH_GONIEC_H
#include "Figura.h"

bool sprawdzRuchGonca(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]);
class Goniec : public Figura {
public:
    bool sprawdzRuch(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]) override;
    Goniec(Kolor kolor) : Figura(kolor){}
    //~Goniec

};


#endif //SZACH_GONIEC_H
