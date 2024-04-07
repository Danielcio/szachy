#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file

#include <boost/test/included/unit_test.hpp>
#include "../Plansza.h"
#include "../Wieza.h"
#include "../Krol.h"

struct P {
    Figura *mapa[8][8]{};
    P() {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                delete mapa[x][y];
                mapa[x][y] = nullptr;
            }
        }
    }
};

BOOST_FIXTURE_TEST_SUITE(testySz, P)
    BOOST_AUTO_TEST_CASE(testWieza) {
    mapa[0][0] = new Wieza(Bialy);
    mapa[7][1] = new Krol(Czarny);

    Plansza plansza(mapa);
    plansza.czarnyKrol = std::make_pair(7, 1);

    BOOST_CHECK(plansza.przesunFigure(0,0,0,1));
    BOOST_CHECK(plansza.czySzach(Czarny));

    BOOST_CHECK(plansza.przesunFigure(7,1,7,0));
    BOOST_CHECK(!plansza.czySzach(Czarny));
    }
}
