#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file

#include <boost/test/included/unit_test.hpp>
#include "../Plansza.h"
struct P {
   Plansza plansza;

    P() {
        plansza.wygenerujMape();
    }
};

BOOST_FIXTURE_TEST_SUITE(testyPlanszy, P)
    BOOST_AUTO_TEST_CASE(ruchPusty) {

        BOOST_CHECK(!plansza.przesunFigure(1,1,1,2));
    }
                BOOST_AUTO_TEST_CASE(ruchPionka) {
       BOOST_CHECK(plansza.przesunFigure(1,1,1,2));
       BOOST_CHECK(!plansza.przesunFigure(1,2,1,1));
       for(int y = 3; y < 6; y++) {
            BOOST_CHECK(plansza.przesunFigure(1,y - 1,1,y));
       }

       BOOST_CHECK(!plansza.przesunFigure(1,5,1,6));
       BOOST_CHECK(plansza.przesunFigure(1,5,2,6));
}

}