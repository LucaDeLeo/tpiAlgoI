#include "definiciones.h"
#include "auxiliares.h"
#include "ejercicios.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}

int mod(int i, int n)
{
    return (i % n + n) % n;
}

bool estaEnTor(vector<toroide> const &t, toroide const &k)
{
    return find(t.begin(), t.end(), k) != t.end();
}

bool estaEnPos(vector<posicion> const &t, posicion const &k)
{
    return find(t.begin(), t.end(), k) != t.end();
}

float dist(posicion const &a, posicion const &b, toroide const &t)
{
    float dx = abs(b.first - a.first);
    float dy = abs(b.second - a.second);

    if (dx > t.size()/2.0)
        dx = t.size() - dx;

    if (dy > t[0].size()/2.0)
        dy = t[0].size() - dy;

    return sqrt(dx*dx + dy*dy);
}

void llenar(posicion const &a, posicion const &b, toroide const &t, rectangulo &r)
{
    unsigned int area1 = abs(a.first - b.first) * abs(a.second - b.second);
    unsigned int area2 = abs(a.first - b.first) * (t[0].size() - abs(a.second - b.second));
    unsigned int area3 = (t.size() - abs(a.first - b.first)) * abs(a.second - b.second);
    unsigned int area4 = (t.size() - abs(a.first - b.first)) * (t[0].size() - abs(a.second - b.second));

    vector<pair<int, int>> vias{mp(1,1), mp(1, -1), mp(-1,1), mp(-1, -1)};
    vector<int> vacios;

    for (int v = 0; v < vias.size(); v++)
    {
        int hs = 0;
        int counter = 0;
        for (int i = a.first; mod(i, t.size()) != b.first; i += vias[v].first)
        {
            for (int j = a.second; mod(j, t[0].size()) != b.second; j += vias[v].second)
            {
                if (r[i][j] && counter > hs)
                    hs = counter;
                else counter++;
            }
        }
        vacios.push_back(hs);
    }
}