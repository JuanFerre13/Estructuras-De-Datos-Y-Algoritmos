// #include <cassert>
// #include <string>
// #include <iostream>
// #include <climits>
// using namespace std;

// #define INF INT_MAX
// #define TIPOS_MONEDAS 6
// int monedas[TIPOS_MONEDAS] = {1, 2, 5, 10, 12, 50};

// int *cambio_pd(int cambio)
// {
//   int *monedasQueDi = new int[TIPOS_MONEDAS]();
//   if (cambio == 0)
//     return monedasQueDi;
//   int *tab = new int[cambio + 1]();
//   tab[0] = 0;
//   for (int c = 1; c <= cambio; c++)
//   {
//     int min = INF;
//     for (int monedaIndex = 0; monedaIndex < TIPOS_MONEDAS; monedaIndex++)
//     {
//       int valorMoneda = monedas[monedaIndex];
//       if (c >= valorMoneda & tab[c - valorMoneda] < min)
//       {
//         // TODO
//       }
//     }
//     tab[c] = //TODO
//   }

//   return monedasQueDi;
// }

// int main()
// {
//   int cambio;
//   cin >> cambio;
//   int *monedasQueUse = cambio_pd(cambio);
//   for (int i = 0; i < TIPOS_MONEDAS; i++)
//   {
//     if (monedasQueUse[i] > 0)
//     {
//       cout << "Use la moneda " << monedas[i] << " " << monedasQueUse[i] << " veces" << endl;
//     }
//   }

//   return 0;
// }