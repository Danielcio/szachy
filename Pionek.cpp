#include "Pionek.h"

bool Pionek::sprawdzRuch(int staryX, int staryY, int nowyX, int nowyY, Figura* mapa[][8]) {
    if(staryX == nowyX) {
        if (kolor == Bialy && staryY + 1 == nowyY) {
            return true;
        } else if (kolor == Czarny && staryY - 1 == nowyY) {
            return true;
        }
    }

    return false;
}
bool Pionek::sprawdzBicie(int staryX, int staryY, int nowyX, int nowyY,Figura* mapa[][8]) {
    if((nowyX == staryX-1 || nowyX == staryX + 1)) {
        if(nowyY == staryY + 1 && kolor == Bialy) {
            return true;
        }
        else if ((nowyX == staryX-1 || nowyX == staryX + 1) && nowyY == staryY-1 && kolor == Czarny ){
            return true;
        }
    }

    return false;
}