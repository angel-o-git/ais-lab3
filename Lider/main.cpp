#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 80;

int main( )
{
    int Z [ N ], i, L, W;
    bool t;

    srand ( ( unsigned )time ( NULL ) );

    // Wype³niamy tablicê

    W = rand( ) % 100;
    for( i = 0; i < N; i++ )
        if( rand( ) % 2 ) Z [ i ] = rand( ) % 100; // rand() % 2 == rand() =! 0
        else              Z [ i ] = W;

    // Wyszukujemy lidera

    L = 0;
    for( i = 0; i < N; i++ )
    {
        if ( L == 0 ) // if( !L ) == if ( L == 0 )
        {
            W = Z [ i ];
            L = 1;
        }
        else if( Z [ i ] == W ) L++;
        else              L--;
        cout << "Z[" << i << "] = " << Z[i] << ", W = " << W << ", L = " << L << endl;

    }
    // Sprawdzamy, czy mamy lidera

    if ( L == 0 )
    {
        t = false;
        L = 0;
        for( i = 0; i < N; i++ ) if( W == Z [ i ] ) L++;
    }
    else
    {
        L = 0;
        for( i = 0; i < N; i++ ) if( W == Z [ i ] ) L++;
        if (L > N / 2) t = true;
        else t = false;
    }

    // Wyœwietlamy tablicê

    for( i = 0; i < N; i++ )
        if( t && ( Z [ i ] == W ) ) cout << " >" << setw ( 2 ) << Z [ i ];
        else                    cout << setw ( 4 ) << Z [ i ];

    // Wyœwietlamy wyniki

    cout << endl;
    cout << W << ": " << L << endl;
    if (t==true)
        cout << "Lider istnieje.";
    else
        cout << "Brak lidera.";
    cout << endl;
    return 0;
}
