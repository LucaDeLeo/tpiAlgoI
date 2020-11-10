#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>
#include "../auxiliares.h"

using namespace std;

TEST(esPeriodicoTEST, toroideHorizontalPeriodico2){
    toroide t = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 2);
}

// mis tests

TEST(esPeriodicoTEST, veintePorTreintayuno){
    const int WIDTH = 20;
    const int LENGHT = 31;
    vector<bool> columna(LENGHT, false);
    toroide t(WIDTH, columna);
    vector<posicion> coorT{                                  mp(-2,0),
                            mp(-1,-2),                 mp(-1,0),
                                            mp(0, -1), mp( 0,0)  };

    for (int i = 0; i < coorT.size(); i++)
        t[LENGHT/2 + coorT[i].first][WIDTH/2 + coorT[i].second] = true;
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 2480);
}

TEST(esPeriodicoTEST, grande){
    const int WIDTH = 70;
    const int LENGHT = 41;
    vector<bool> columna(LENGHT, false);
    toroide t(WIDTH, columna);
    t[LENGHT/2 + 1][WIDTH/2 + 1] = true; t[LENGHT/2 + 2][WIDTH/2 + 2] = true; t[LENGHT/2 + 2][WIDTH/2 + 3] = true; t[LENGHT/2 + 3][WIDTH/2 + 3] = true;
    t[LENGHT/2 + 2][WIDTH/2 + 3] = true; t[LENGHT/2 + 2][WIDTH/2 + 4] = true; t[LENGHT/2 + 2][WIDTH/2 + 5] = true; t[LENGHT/2 + 3][WIDTH/2 + 4] = true;
    t[LENGHT/2 + 5][WIDTH/2 + 9] = true; t[LENGHT/2 + 5][WIDTH/2 + 11] = true; t[LENGHT/2 + 4][WIDTH/2 + 11] = true; t[LENGHT/2 + 3][WIDTH/2 + 12] = true;
    t[LENGHT/2 + 2][WIDTH/2 + 12] = true; t[LENGHT/2 + 1][WIDTH/2 + 12] = true;
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
}