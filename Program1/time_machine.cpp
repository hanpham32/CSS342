#include <iostream>
#include "time_span.h"

using namespace std;

int main()
{
    TimeSpan dur1(77.4, 15, 6); // (1)
    // TimeSpan dur2(127.86); // (0) ** round up 
    TimeSpan dur3(8, -23, 0);  // (1)
    // TimeSpan dur4(0,0,0); // (1)
    // TimeSpan dur5(-3, 73, 2); // (1)
    // TimeSpan dur6(7, 35, 120); // (1)
    TimeSpan dur7, dur8;

    dur7 = dur1 + dur3;

    cout << dur1 << endl;
    // cout << dur2 << endl;
    // cout << dur3 << endl;
    // cout << dur4 << endl;
    // cout << dur5 << endl;
    // cout << dur6 << endl;
    cout << dur7 << endl;

    // dur7 += dur3;
    // cout << dur3 << endl;
    // cout << dur7 << endl;
    // cout << "" << endl;
    return 0;
}