//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
int mod(int i, int n);
bool estaEnTor(vector<toroide> const &t, toroide const &k);
bool estaEnPos(vector<posicion> const &t, posicion const &k);
float dist(posicion const &a, posicion const &b, toroide const &t);

#endif //REUNIONESREMOTAS_AUXILIARES_H
