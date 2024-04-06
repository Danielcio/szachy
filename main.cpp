#include <iostream>
#include "Plansza.h"
#include "Pionek.h"
#include "Kolor.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    //przesun(1); //przesun(1)
//    przesun1(0);

   // Pionek pionek(Bialy, 0, 0);
   // pionek.czyRuchDozwolony(1,2);
//    Skoczek skoczek(Bialy, 0, 0);
//    pionek.czyRuchDozwolony(1,2);
//    Goniec goniec(Bialy,0,1);
//    goniec.czyRuchDozwolony(1,3);
//    Wieza wieza(Czarny,0,3);
//    wieza.czyRuchDozwolony(3,4);
//    Hetman hetman(Czarny,2,3);
//    hetman.czyRuchDozwolony(5,6);
//    Krol krol(Bialy,4,6);
//    krol.czyRuchDozwolony(4,6);

   Plansza plansza;
   plansza.wygenerujMape();
   //plansza.mapa[0][1]= nullptr;
   plansza.mapa[0][2]= nullptr;
  plansza.mapa[0][3]= nullptr;
  plansza.mapa[0][5]= nullptr;
std::cout<<"test pola="<<plansza.mapa[0][2]<<endl;
    std::cout<<"test pola="<<plansza.mapa[0][1]<<endl;
cout << plansza.mapa[0][0]->sprawdzRuch(0, 0,0,5,plansza.mapa) << endl;
//plansza.przesunPionek(4,0,5,0);
    //plansza.mapa[0][0]->czyRuchDozwolony(0, 0, 1, 1);
    //plansza.mapa[1][1]->czyRuchDozwolony(0, 0, 1, 1);
   // for(int x=0;x<8;x++) {
        //for(int y=0;y<8;y++){
//            std::cout<<plansza.mapa[6][0]->kolor;
//    std::cout<<",";
//    std::cout<<plansza.mapa[0][0]->kolor;
//            std::cout<<",";

       // }
      //  std::cout<< endl;
    //}
    //std::cout<<plansza.mapa[0][0]->kolor;

    return 0;
}