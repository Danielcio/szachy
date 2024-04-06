#include "Plansza.h"
#include "Figura.h"
#include "Pionek.h"
#include "Goniec.h"
#include "Skoczek.h"
#include "Hetman.h"
#include "Krol.h"
#include "Wieza.h"
#include <iostream>
#include <typeinfo>

void Plansza::wygenerujMape() {
    for(int x = 0; x < 8; x++) {
        for(int y = 0; y < 8; y++) {
            mapa[x][y] = nullptr;
        }
    }

    for(int x = 0; x < 8; x++) {
        mapa[x][1] = new Pionek(Bialy);
        mapa[x][6] = new Pionek(Czarny);
    }
    mapa [0][0] =  new Wieza(Bialy);
    mapa [1][0] = new Skoczek (Bialy);
    mapa [2][0] = new Goniec (Bialy);
    mapa [3][0] = new Hetman (Bialy);
    mapa [4][0] = new Krol (Bialy);
    bialyKrol = std::make_pair(4, 0);
    mapa [5][0] = new Goniec (Bialy);
    mapa [6][0] = new Skoczek (Bialy);
    mapa [7][0] = new Wieza (Bialy);
    //druga strona szachow czarne figury
    mapa[0][7] =  new Wieza(Czarny);
    mapa [1][7] = new Skoczek (Czarny);
    mapa [2][7] = new Goniec (Czarny);
    mapa [3][7] = new Hetman (Czarny);
    mapa [4][7] = new Krol (Czarny);
    czarnyKrol = std::make_pair(4, 7);
    mapa [5][7] = new Goniec (Czarny);
    mapa [6][7] = new Skoczek (Czarny);
    mapa [7][7] = new Wieza (Czarny);
}

bool Plansza::przesunFigure(int staryX, int staryY, int nowyX, int nowyY) {
    // 1. Czy figura znajduje sie na wskazanych wspolrzednych
    // 2. Czy figura moze przesunac sie na nowe wspolrzedne
    // 2.1 jesli bicie ->  imapa[staryY][staryX].czyBicieDozwolone(staryX, staryY, nowyY, nowyX),
    // 2.1 w innym wypadku -> imapa[staryY][staryX].czyRuchDozwolony(staryX, staryY, nowyY, nowyX)
    // 2.2 jezeli figura to nie koń -> sprawdzKolizje(staryX, staryY, nowyX, nowyY)

    //pionek[staryX][nowyX] -> czyRuchDozwolony(...)
    //      <przesun pionek>
    //      return true
    // else
    //      <nie przesuwaj>
    //      return false

    if (staryX > 7 || staryX < 0 || staryY > 7 || staryY < 0 || nowyX > 7 || nowyX < 0 || nowyY > 7 || nowyY < 0) {
        return false;
    }

    if(mapa[nowyX][nowyY] == nullptr && mapa[staryX][staryY] -> sprawdzRuch(staryX, staryY, nowyX, nowyY, mapa)) {
        if(!zmienPozycje(staryX, staryY, nowyX, nowyY))
            return false;

        return true;
    }
    else if(mapa[staryX][staryY] -> kolor != mapa[nowyX][nowyY] -> kolor && mapa[staryX][staryY] -> sprawdzBicie(staryX, staryY, nowyX, nowyY, mapa)) {
        if(!zmienPozycje(staryX, staryY, nowyX, nowyY))
            return false;

        zbiteFigury.push_back(mapa[nowyX][nowyY]);
        return true;
    }

    return true;
}

bool Plansza::zmienPozycje(int staryX, int staryY, int nowyX, int nowyY) {
    Figura* figura = mapa[nowyX][nowyY];
    mapa[nowyX][nowyY] = mapa[staryX][staryY];
    mapa[staryX][staryY] = nullptr;

    if(czySzach(mapa[nowyX][nowyY]->kolor)) {
        mapa[staryX][staryY] = mapa[nowyX][nowyY];
        mapa[nowyX][nowyY] = figura;
        return false;
    }

    // Jesli figura jest krolem, to sprawdz jej kolor i zaktualizuj odpowiednia parę współrzędnych
    const std::type_info& type = typeid(*mapa[nowyX][nowyY]);

    if (type == typeid(Krol)) {
        if(mapa[nowyX][nowyY]->kolor == Bialy) {
            bialyKrol = std::make_pair(nowyX, nowyY);
        }
        else {
            czarnyKrol = std::make_pair(nowyX, nowyY);
        }
    }

    return true;
}


bool Plansza::czySzach(Kolor kolorKrola) {
    std::pair<int, int> wspolrzedne;
    Kolor kolorFigury = przeciwnyKolor(kolorKrola);
    if(kolorKrola == Bialy)
        kolorFigury = Czarny;
    else
        kolorFigury = Bialy;

    if (kolorKrola == Bialy) {
        wspolrzedne = bialyKrol;
    }
    else {
        wspolrzedne = czarnyKrol;
    }

     //Przejdz po wszystkich polach mapy
     //Jesli kolor jest przeciwny do koloru krola, to sprawdzamy czy figura ma na niego bicie
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if(mapa[x][y]->kolor == kolorFigury && mapa[x][y]->sprawdzBicie(x,y,wspolrzedne.first, wspolrzedne.second, mapa)) {
               return true;
            }
        }
    }

    return false;
}
Plansza::Plansza() {
    wygenerujMape();

   // std::cout << "Plansza()" << std::endl;
}