#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t)
{
    bool resp = true;
    if (t.size() >= 3 && t[0].size() >= 3)
    {
        for (int i = 0; resp && i < t.size() - 1; i++)
            if (t[i].size() != t[i + 1].size())
                resp = false;
    } else
        resp = false;
    return resp;
}

// EJERCICIO 2
vector<posicion> posicionesVivas(toroide const &t)
{
	vector<posicion> vivos;
    for (int i = 0; i < t.size(); i++)
        for (int j = 0; j < t[0].size(); j++)
            if (t[i][j])
                vivos.emplace_back(mp(i,j));
    return vivos;
}

// EJERCICIO 3
float densidadPoblacion(toroide const &t)
{
    float cantVivas = 0;
    for (int i = 0; i < t.size(); i++)
        for (int j = 0; j < t[0].size(); j++)
            if (t[i][j])
                cantVivas++;
    return cantVivas / float(t.size() * t[0].size());
}

// EJERCICIO 4
bool evolucionDePosicion(toroide const &t, posicion x)
{
    int filas = t.size();
    int columnas = t[0].size();
    vector<posicion> vecinos{ mp(x.first - 1, x.second - 1), mp(x.first - 1, x.second), mp(x.first - 1, x.second + 1),
                              mp(x.first       , x.second - 1),                               mp(x.first       , x.second + 1),
                              mp(x.first + 1, x.second - 1), mp(x.first + 1, x.second), mp(x.first + 1, x.second + 1) };
    int cantVecinos = 0;
    for (int i = 0; i < vecinos.size(); i++)
    {
        int a = mod(vecinos[i].first, filas);
        int b = mod(vecinos[i].second, columnas);
	    if (t[a][b])
	        cantVecinos++;
    }
    return (t[x.first][x.second] && (1 < cantVecinos && cantVecinos < 4)) || (!t[x.first][x.second] && cantVecinos == 3);
}

// EJERCICIO 5
void evolucionToroide(toroide &t)
{
    toroide t0 = t;
    for (int i = 0; i < t.size(); i++)
        for (int j = 0; j < t[0].size(); j++)
            t[i][j] = evolucionDePosicion(t0, mp(i, j));
}

// EJERCICIO 6
toroide evolucionMultiple(toroide const &t, int K)
{
    toroide out = t;
    for (int i = 0; i < K; i++)
        evolucionToroide(out);
    return out;
}

// EJERCICIO 7
bool esPeriodico(toroide const &t, int &p)
{
    bool res = false;
    vector<toroide> cache;
    toroide k = t;
    toroide last = k;
    evolucionToroide(k);

    int i = 0;
    for (; k != t && k != last && !(i > 2500 && estaEnTor(cache, k)); i++)
    {
        cache.push_back(k);
        last = k;
        evolucionToroide(k);
    }

    res = k == t;
    if (res)
        p = i + 1;
    return res;
}

// EJERCICIO 8
bool primosLejanos(toroide const &t, toroide const &u)
{
    vector<toroide> cache;
    toroide k = t;
    toroide last = k;
    evolucionToroide(k);
    for (int i = 0; k != last && k != u && k != t && !(i > 2500 && estaEnTor(cache, k)); i++)
    {
        cache.push_back(k);
        last = k;
        evolucionToroide(k);
    }
    return k == u;
}

// EJERCICIO 9
int seleccionNatural(vector <toroide> ts)
{
    int hs = -1;
    int res;
    for (int i = 0; i < ts.size(); i++)
    {
        vector<bool> columnaMuerta(ts[i][0].size(), false);
        toroide muerto(ts[i].size(), columnaMuerta);

        int tardaEnMorir = 0;
        for (;ts[i] != muerto; tardaEnMorir++)
            evolucionToroide(ts[i]);

        if (tardaEnMorir > hs)
        {
            hs = tardaEnMorir;
            res = i;
        }
    }
    return res;
}

// EJERCICIO 10
toroide fusionar(toroide const &t, toroide const &u)
{
    toroide out = u;
    for (int i = 0; i < t.size(); i++)
        for (int j = 0; j < t[0].size(); j++)
            out[i][j] = t[i][j] && u[i][j];
    return out;
}

// EJERCICIO 11
bool vistaTrasladada(toroide const &t, toroide const &u)
{
	bool res = false;
	vector<posicion> vivasT;
    vector<posicion> vivasU;
    for (int i = 0; i < t.size(); i++)
        for (int j = 0; j < t[0].size(); j++)
        {
            if (t[i][j])
                vivasT.push_back(mp(i,j));
            if (u[i][j])
                vivasU.push_back(mp(i,j));
        }

    if (vivasT.size() == vivasU.size())
        for (int i = 0; i < vivasT.size() && !res; i++)
        {
            pair<int, int> move = mp(vivasU[0].first - vivasT[i].first,vivasU[0].second - vivasT[i].second);
            res = true;
            for (int j = 0; res && j < vivasT.size(); j++)
                res = res && estaEnPos(vivasU, mp(mod(vivasT[j].first + move.first, t.size()),
                                                       mod(vivasT[j].second + move.second, t[0].size())));
        }
    return res;
}

// EJERCICIO 12
int menorSuperficieViva(toroide const &t)
{
    vector<posicion> vivas;
    for (int i = 0; i < t.size(); i++)
        for (int j = 0; j < t[0].size(); j++)
            if (t[i][j])
                vivas.push_back(mp(i,j));

    float distCorta = numeric_limits<float>::max();
    int centro = 0;
    for (int i = 0; i < vivas.size(); i++)
    {
        float sumas = 0;
        for (int j = 0; j < vivas.size(); j++)
            if (i != j)
                sumas += dist(vivas[i], vivas[j], t);
        if (sumas <= distCorta)
        {
            distCorta = sumas;
            centro = i;
        }
    }
    rectangulo r = t;
    vector<pair<int, int>> vias{mp(1,1), mp(1, -1), mp(-1,1), mp(-1, -1)};
    for (int c = 0; c < vivas.size(); c++)
    {
            if (c != centro)
            {
                pair<int, int> vi;
                int hhs = 0;
                for (int v = 0; v < vias.size(); v++)
                {
                    int hs, counter = 0;

                    int j = vivas[c].second;
                    for (int i = vivas[c].first; mod(i, t.size()) != vivas[centro].first ||
                            mod(j, t[0].size()) != vivas[centro].second; i += vias[v].first)
                    {
                        for (; mod(j, t[0].size()) != vivas[centro].second; j += vias[v].second)
                        {
                            if (r[ mod(i, t.size()) ][ mod(j, t[0].size()) ] && counter >= hs)
                                hs = counter;
                            else counter++;
                        }
                    }
                    if (hs >= hhs)
                    {
                        vi = vias[v];
                        hhs = hs;
                    }
                }
                int j = vivas[c].second;
                for (int i = vivas[c].first; mod(i, t.size()) != vivas[centro].first ||
                        mod(j, t[0].size()) != vivas[centro].second; i += vi.first)
                {
                    for (; mod(j, t[0].size()) != vivas[centro].second; j += vi.second)
                    {
                        r[ mod(i, t.size()) ][ mod(j, t[0].size()) ] = true;
                    }
                }
            }
    }
    int area = 0;
    for (int i = 0; i < r.size(); i++)
        for (int j = 0; j < r[0].size(); j++)
        {
            int f = 0;
            for (; f < r.size() && !r[f][j]; f++)
                ;

            if (f != r.size() && find(r[i].begin(), r[i].end(), true) != r[i].end())
                area++;

            // if (r[i][j]) area++;
        }





	return area;
}
