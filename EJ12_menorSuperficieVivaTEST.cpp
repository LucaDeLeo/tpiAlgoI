#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(menorSuperficieVivaTEST, enunciado){
    toroide t = {
            {true, false, false, true},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {true, true, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}

TEST(menorSuperficieVivaTEST, simple){
    toroide t = {
            {true, false, false, false},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {false, false, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 1);
}

TEST(menorSuperficieVivaTEST, ninguno){
    toroide t = {
            {false, false, false, false},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {false, false, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 0);
}

TEST(menorSuperficieVivaTEST, simple2){
    toroide t = {
            {true, false, true, false},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {false, false, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 3);
}