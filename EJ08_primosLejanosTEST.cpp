#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>
#include "../auxiliares.h"

using namespace std;

TEST(primosLejanosTEST, toroideHorizontalPeriodico2){
    toroide t1 = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    toroide t2 = { 
                  {false, false, false, false, false}, 
                  {false, false, true, false, false}, 
                  {false, false, true, false, false},
                  {false, false, true, false, false}, 
                  {false, false,false, false, false} };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, veintePorTreintayuno){
    const int WIDTH = 20;
    const int LENGHT = 31;
    vector<bool> columna(LENGHT, false);
    toroide t(WIDTH, columna);

    vector<posicion> coorT{ mp(-1,-2), mp(0, -1), mp(0,0), mp(-1,0), mp(-2,0)};
    for (int i = 0; i < coorT.size(); i++)
        t[LENGHT/2 + coorT[i].first][WIDTH/2 + coorT[i].second] = true;

    vector<posicion> coorU{ mp(-9,-10), mp(-8, -9), mp(-8,-8), mp(-9,-8), mp(-10,-8)};
    toroide u(WIDTH, columna);
    for (int i = 0; i < coorU.size(); i++)
        u[LENGHT/2 + coorU[i].first][WIDTH/2 + coorU[i].second] = true;


    bool res = primosLejanos(t, u);
    EXPECT_TRUE(res);
    res = primosLejanos(u, t);
    EXPECT_TRUE(res);
}

