#include "Figura.h"
#include <vector>
#include <utility>

#ifndef SZACH_PLANSZA_H
#define SZACH_PLANSZA_H

class Plansza {
private:
    std::vector<Figura*> zbiteFigury;
    void zaktualizujKrola(Kolor kolor, int x, int y);
    bool zmienPozycje(int staryX, int staryY, int nowyX, int nowyY);
    Figura* mapa[8][8]{};
    Kolor poprzednikolor=Czarny;
public:
    std::pair<int, int> bialyKrol;
    std::pair<int, int> czarnyKrol;
    Plansza();
    Plansza(Figura* mapa[8][8]);
    void wygenerujMape();
    bool przesunFigure(int staryX, int staryY, int nowyX, int nowyY);
    bool czySzach(Kolor kolorKrola);
};


#endif //SZACH_PLANSZA_H
