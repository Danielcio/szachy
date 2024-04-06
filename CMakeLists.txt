cmake_minimum_required(VERSION 3.27)
project(Szachy)

set(CMAKE_CXX_STANDARD 17)

add_executable(Szachy main.cpp
        Figura.cpp
        Figura.h
        Pionek.cpp
        Pionek.h
        Plansza.cpp
        Plansza.h
        Skoczek.cpp
        Skoczek.h
        Goniec.cpp
        Goniec.h
        Hetman.cpp
        Hetman.h
        Wieza.cpp
        Wieza.h
        Krol.cpp
        Krol.h
        Kolor.h
        Kolor.cpp
)

set(BOOST_ROOT "C:/Boost")
set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (TestyFigur tests/test_figura.cpp Pionek.h Pionek.cpp Kolor.h Kolor.cpp Figura.h Figura.cpp Wieza.h Wieza.cpp
Goniec.h Goniec.cpp Skoczek.h Skoczek.cpp Krol.h Krol.cpp Hetman.h Hetman.cpp Plansza.h Plansza.cpp)


add_executable(TestyPlanszy tests/test_plansza.cpp Pionek.h Pionek.cpp Kolor.h Kolor.cpp Figura.h Figura.cpp Wieza.h Wieza.cpp
Goniec.h Goniec.cpp Skoczek.h Skoczek.cpp Krol.h Krol.cpp Hetman.h Hetman.cpp Plansza.h Plansza.cpp )

target_link_libraries (TestyFigur ${Boost_LIBRARIES})
target_link_libraries (TestyPlanszy ${Boost_LIBRARIES})


set(Qt6_DIR "C:/Qt/6.6.2/msvc2019_64/lib/cmake/Qt6")
find_package(Qt6 REQUIRED COMPONENTS Core )
qt_standard_project_setup()
qt_add_executable(UI
        ui_app/main.cpp
        ui_app/hello.qml
)

#target_link_libraries(helloworld PRIVATE Widgets)
#
#set_target_properties(helloworld PROPERTIES
#        WIN32_EXECUTABLE ON
#)