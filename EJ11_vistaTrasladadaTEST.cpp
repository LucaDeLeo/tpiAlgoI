#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>
#include "../auxiliares.h"

using namespace std;

TEST(vistaTrasladadaTEST, muevoTerceraFilaParaArriba){
    toroide t1 = { 
                  {true, false, false}, // 1
                  {false, true, false}, // 2
                  {false, false, true}};// 3
    toroide t2 = { 
                  {false, false, true}, // 3
                  {true, false, false}, // 1
                  {false, true, false}};// 2

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, DiagonalVsTodoTrue){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {true, true, true},
                  {true, true, true},
                  {true, true, true}}; 
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}


TEST(vistaTrasladadaTEST, noventaYNuevePorCien)
{
    const int WIDTH = 99;
    const int LENGHT = 100;
    vector<bool> columna(LENGHT, false);
    toroide t(WIDTH, columna);
    toroide u(WIDTH, columna);

    int x = 17; int y = 44;

    vector<posicion> coorT{                                  mp(-2,0),
                            mp(-1,-2),                 mp(-1,0),
                                            mp(0, -1), mp( 0,0)  };

    vector<posicion> coorU{                                                  mp(-2 + x,0 + y),
                            mp(-1 + x,-2 + y),                         mp(-1 + x,0 + y),
                                                    mp(0 + x, -1 + y), mp( 0 + x,0 + y)  };

    for (int i = 0; i < coorT.size(); i++)
    {
        t[LENGHT/2 + coorT[i].first][WIDTH/2 + coorT[i].second] = true;
        u[LENGHT/2 + coorU[i].first][WIDTH/2 + coorU[i].second] = true;
    }


    bool res = vistaTrasladada(t , u);
    EXPECT_TRUE(res);
}
