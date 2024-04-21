#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file

#include <boost/test/included/unit_test.hpp>
#include "../Kolor.h"
#include "../Figura.h"
#include "../Pionek.h"
#include "../Wieza.h"
#include "../Goniec.h"
#include "../Skoczek.h"
#include "../Krol.h"
#include "../Hetman.h"
#include "../Plansza.h"

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

BOOST_FIXTURE_TEST_SUITE(testyFigur, P)

    BOOST_AUTO_TEST_CASE(ruchPionka)
    {
        mapa[1][1] = new Pionek(Bialy);
        BOOST_CHECK(mapa[1][1]->sprawdzRuch(1, 1, 1, 2, mapa));

        BOOST_CHECK(!mapa[1][1]->sprawdzRuch(1, 1, 1, 0, mapa));
        BOOST_CHECK(!mapa[1][1]->sprawdzRuch(1, 1, 2, 2, mapa));
        BOOST_CHECK(!mapa[1][1]->sprawdzRuch(1, 1, 2, 1, mapa));
        BOOST_CHECK(!mapa[1][1]->sprawdzRuch(1, 1, 0, 1, mapa));

        delete mapa[1][1];
        mapa[1][6] = new Pionek(Czarny);
        mapa[3][6] = new Pionek(Czarny);

        BOOST_CHECK(mapa[1][6]->sprawdzRuch(1, 6, 1, 5, mapa));

        BOOST_CHECK(!mapa[1][6]->sprawdzRuch(1, 6, 1, 7, mapa));
        BOOST_CHECK(!mapa[1][6]->sprawdzRuch(1, 6, 3, 6, mapa));
        BOOST_CHECK(!mapa[1][6]->sprawdzRuch(1, 6, 2, 6, mapa));
        BOOST_CHECK(!mapa[1][6]->sprawdzRuch(1, 6, 0, 7, mapa));
        BOOST_CHECK(!mapa[1][6]->sprawdzRuch(1, 1, 1, 7, mapa));
        BOOST_CHECK(!mapa[3][6]->sprawdzRuch(3, 6, 3, 3, mapa));
    }

    BOOST_AUTO_TEST_CASE(biciePionka)
    {
        mapa[1][1] = new Pionek(Bialy);
        mapa[2][2] = new Pionek(Bialy);

        BOOST_CHECK(mapa[1][1]->sprawdzBicie(1, 1, 0, 2, mapa));
//        BOOST_CHECK(!mapa[1][1]->sprawdzBicie(1, 1, 2, 2, mapa));

        BOOST_CHECK(!mapa[1][1]->sprawdzBicie(1, 1, 1, 2, mapa));
        BOOST_CHECK(!mapa[1][1]->sprawdzBicie(1, 1, 0, 0, mapa));
        BOOST_CHECK(!mapa[1][1]->sprawdzBicie(1, 1, 2, 0, mapa));

        delete mapa[1][1];
        mapa[1][6] = new Pionek(Czarny);

        BOOST_CHECK(mapa[1][6]->sprawdzBicie(1, 6, 0, 5, mapa));
        BOOST_CHECK(mapa[1][6]->sprawdzBicie(1, 6, 2, 5, mapa));

        BOOST_CHECK(!mapa[1][6]->sprawdzBicie(1, 6, 1, 5, mapa));
        BOOST_CHECK(!mapa[1][6]->sprawdzBicie(1, 6, 0, 7, mapa));
        BOOST_CHECK(!mapa[1][6]->sprawdzBicie(1, 6, 2, 7, mapa));
    }

    BOOST_AUTO_TEST_CASE(ruchWiezy)
    {
        mapa[2][1] = new Wieza(Bialy);
        mapa[1][5] = new Wieza(Czarny);
        mapa[2][6] = new Pionek(Bialy);
        //BOOST_CHECK(mapa[3][1]== nullptr);
        BOOST_CHECK(mapa[2][1]->sprawdzRuch(2, 1, 2, 4, mapa));
        BOOST_CHECK(mapa[2][1]->sprawdzRuch(2, 1, 5, 1, mapa));
        BOOST_CHECK(mapa[1][5]->sprawdzRuch(1, 5, 1, 1, mapa));
        BOOST_CHECK(mapa[1][5]->sprawdzRuch(1, 5, 5, 5, mapa));
        BOOST_CHECK(!mapa[2][1]->sprawdzRuch(2, 1, 2, 7, mapa));

        for (int y = 2; y < 5; y++) {
            BOOST_CHECK(mapa[2][1]->sprawdzRuch(2, 1, 2, y, mapa));
        }

        for (int y = 5; y < 8; y++) {
            BOOST_CHECK(mapa[1][5]->sprawdzRuch(1, 5, 1, y, mapa));
        }
    }

    BOOST_AUTO_TEST_CASE(bicieWiezy) {
        mapa[3][3] = new Wieza(Bialy);
        mapa[7][3] = new Pionek(Czarny);
        mapa[3][0] = new Pionek(Bialy);
        mapa[2][3] = new Wieza(Bialy);
        BOOST_CHECK(mapa[3][3]->sprawdzBicie(3, 3, 7, 3, mapa));
//        BOOST_CHECK(!mapa[3][3]->sprawdzBicie(3, 3, 3, 0, mapa));
    }

    BOOST_AUTO_TEST_CASE(ruchGonca)
    {
        mapa[2][0] = new Goniec(Bialy);
        mapa[4][2] = new Pionek(Czarny);

        BOOST_CHECK(mapa[2][0]->sprawdzRuch(2, 0, 3, 1, mapa));
        BOOST_CHECK(mapa[2][0]->sprawdzRuch(2, 0, 0, 2, mapa));
        BOOST_CHECK(!mapa[2][0]->sprawdzRuch(2, 0, 4, 0, mapa));
        BOOST_CHECK(!mapa[2][0]->sprawdzRuch(2, 0, 2, 4, mapa));
        BOOST_CHECK(!mapa[2][0]->sprawdzRuch(2, 0, 6, 4, mapa));
    }

    BOOST_AUTO_TEST_CASE(bicieGoniec) {
        mapa[3][3] = new Goniec(Czarny);
        mapa[5][1] = new Pionek(Bialy);
        mapa[2][2] = new Pionek(Bialy);
        mapa[1][5] = new Pionek(Bialy);
        mapa[5][5] = new Pionek(Czarny);
        BOOST_CHECK(mapa[3][3]->sprawdzBicie(3, 3, 5, 1, mapa));
        BOOST_CHECK(mapa[3][3]->sprawdzBicie(3, 3, 2, 2, mapa));
        BOOST_CHECK(mapa[3][3]->sprawdzBicie(3, 3, 1, 5, mapa));
//        BOOST_CHECK(!mapa[3][3]->sprawdzBicie(3, 3, 5, 5, mapa));
    }

    BOOST_AUTO_TEST_CASE(ruchHetmana) {
        mapa[3][0] = new Hetman(Bialy);
        mapa[3][4] = new Pionek(Bialy);
        mapa[6][0] = new Pionek(Bialy);

        BOOST_CHECK(mapa[3][0]->sprawdzRuch(3, 0, 3, 3, mapa));
        BOOST_CHECK(mapa[3][0]->sprawdzRuch(3, 0, 7, 4, mapa));
        BOOST_CHECK(mapa[3][0]->sprawdzRuch(3, 0, 0, 3, mapa));
        BOOST_CHECK(mapa[3][0]->sprawdzRuch(3, 0, 5, 0, mapa));
        BOOST_CHECK(mapa[3][0]->sprawdzRuch(3, 0, 0, 0, mapa));
        BOOST_CHECK(!mapa[3][0]->sprawdzRuch(3, 0, 3, 5, mapa));
        BOOST_CHECK(!mapa[3][0]->sprawdzRuch(3, 0, 7, 0, mapa));
    }

    BOOST_AUTO_TEST_CASE(bicieHetman) {
        mapa[3][3] = new Hetman(Czarny);
        mapa[5][1] = new Pionek(Bialy);
        mapa[2][2] = new Pionek(Bialy);
        mapa[1][5] = new Pionek(Bialy);
        mapa[5][5] = new Pionek(Czarny);
        mapa[7][3] = new Wieza(Bialy);
        mapa[3][5] = new Skoczek(Bialy);
        BOOST_CHECK(mapa[3][3]->sprawdzBicie(3, 3, 5, 1, mapa));
        BOOST_CHECK(mapa[3][3]->sprawdzBicie(3, 3, 2, 2, mapa));
        BOOST_CHECK(mapa[3][3]->sprawdzBicie(3, 3, 1, 5, mapa));
//        BOOST_CHECK(!mapa[3][3]->sprawdzBicie(3, 3, 5, 5, mapa));
        BOOST_CHECK(mapa[3][3]->sprawdzBicie(3, 3, 7, 3, mapa));
    }

    BOOST_AUTO_TEST_CASE(ruchSkoczka) {
        mapa[4][4] = new Skoczek(Czarny);
        mapa[4][3] = new Pionek(Czarny);
        BOOST_CHECK(mapa[4][4]->sprawdzRuch(4, 4, 5, 2, mapa));
        BOOST_CHECK(mapa[4][4]->sprawdzRuch(4, 4, 6, 3, mapa));
        BOOST_CHECK(mapa[4][4]->sprawdzRuch(4, 4, 6, 5, mapa));
        BOOST_CHECK(mapa[4][4]->sprawdzRuch(4, 4, 5, 6, mapa));
        BOOST_CHECK(mapa[4][4]->sprawdzRuch(4, 4, 3, 6, mapa));
        BOOST_CHECK(mapa[4][4]->sprawdzRuch(4, 4, 2, 5, mapa));
        BOOST_CHECK(mapa[4][4]->sprawdzRuch(4, 4, 2, 3, mapa));
        BOOST_CHECK(mapa[4][4]->sprawdzRuch(4, 4, 3, 2, mapa));
        BOOST_CHECK(!mapa[4][4]->sprawdzRuch(4, 4, 7, 4, mapa));
        BOOST_CHECK(!mapa[4][4]->sprawdzRuch(4, 4, 3, 5, mapa));
    }

    BOOST_AUTO_TEST_CASE(bicieSkoczka) {
        mapa[4][4] = new Skoczek(Czarny);
        mapa[5][2] = new Pionek(Bialy);
        mapa[6][3] = new Pionek(Bialy);
        mapa[6][5] = new Pionek(Bialy);
        mapa[5][6] = new Pionek(Bialy);
        mapa[3][6] = new Pionek(Bialy);
        mapa[2][5] = new Pionek(Bialy);
        mapa[2][3] = new Pionek(Czarny);
        mapa[3][2] = new Pionek(Czarny);
        BOOST_CHECK(mapa[4][4]->sprawdzBicie(4, 4, 5, 2, mapa));
        BOOST_CHECK(mapa[4][4]->sprawdzBicie(4, 4, 6, 3, mapa));
        BOOST_CHECK(mapa[4][4]->sprawdzBicie(4, 4, 6, 5, mapa));
        BOOST_CHECK(mapa[4][4]->sprawdzBicie(4, 4, 5, 6, mapa));
        BOOST_CHECK(mapa[4][4]->sprawdzBicie(4, 4, 3, 6, mapa));
        BOOST_CHECK(mapa[4][4]->sprawdzBicie(4, 4, 2, 5, mapa));
//        BOOST_CHECK(!mapa[4][4]->sprawdzBicie(4, 4, 2, 3, mapa));
   //     BOOST_CHECK(!mapa[4][4]->sprawdzBicie(4, 4, 3, 2, mapa));

    }

    BOOST_AUTO_TEST_CASE(ruchKrola) {
        mapa[3][2] = new Krol(Bialy);
        BOOST_CHECK(mapa[3][2]->sprawdzRuch(3, 2, 4, 2, mapa));
        BOOST_CHECK(mapa[3][2]->sprawdzRuch(3, 2, 4, 3, mapa));
        BOOST_CHECK(mapa[3][2]->sprawdzRuch(3, 2, 3, 3, mapa));
        BOOST_CHECK(mapa[3][2]->sprawdzRuch(3, 2, 2, 3, mapa));
        BOOST_CHECK(mapa[3][2]->sprawdzRuch(3, 2, 2, 2, mapa));
        BOOST_CHECK(mapa[3][2]->sprawdzRuch(3, 2, 2, 1, mapa));
        BOOST_CHECK(mapa[3][2]->sprawdzRuch(3, 2, 3, 1, mapa));
        BOOST_CHECK(mapa[3][2]->sprawdzRuch(3, 2, 4, 1, mapa));
        BOOST_CHECK(!mapa[3][2]->sprawdzRuch(3, 2, 5, 0, mapa));
        BOOST_CHECK(!mapa[3][2]->sprawdzRuch(3, 2, 3, 5, mapa));
    }

    BOOST_AUTO_TEST_CASE(bicieKrola) {
        mapa[3][2] = new Krol(Bialy);
        mapa[4][2] = new Pionek(Czarny);
        mapa[4][3] = new Pionek(Czarny);
        mapa[3][3] = new Pionek(Czarny);
        mapa[2][3] = new Pionek(Czarny);
        mapa[2][2] = new Pionek(Czarny);
        mapa[2][1] = new Pionek(Czarny);
        mapa[3][1] = new Pionek(Bialy);
        mapa[4][1] = new Pionek(Bialy);
        BOOST_CHECK(mapa[3][2]->sprawdzBicie(3, 2, 4, 2, mapa));
        BOOST_CHECK(mapa[3][2]->sprawdzBicie(3, 2, 4, 3, mapa));
        BOOST_CHECK(mapa[3][2]->sprawdzBicie(3, 2, 3, 3, mapa));
        BOOST_CHECK(mapa[3][2]->sprawdzBicie(3, 2, 2, 3, mapa));
        BOOST_CHECK(mapa[3][2]->sprawdzBicie(3, 2, 2, 2, mapa));
        BOOST_CHECK(mapa[3][2]->sprawdzBicie(3, 2, 2, 1, mapa));
//        BOOST_CHECK(!mapa[3][2]->sprawdzBicie(3, 2, 3, 1, mapa));
//        BOOST_CHECK(!mapa[3][2]->sprawdzBicie(3, 2, 4, 1, mapa));
        BOOST_CHECK(!mapa[3][2]->sprawdzBicie(3, 2, 5, 0, mapa));
        BOOST_CHECK(!mapa[3][2]->sprawdzBicie(3, 2, 3, 5, mapa));
    }

}