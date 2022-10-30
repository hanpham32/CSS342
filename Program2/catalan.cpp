/*
Project 2 - CSS342
Hannah Pham
10/28/2022
catalan.cpp
*/
#include <iostream>
#include "catalan.h"
#include <math.h>
using namespace std;

int main(int arg, char *argv[])
{
    if (arg == 2)
    {
        int n = stoi(argv[1]);
        Catalan catalan = Catalan(n);
    }
    else
    {
        cout << "Please pass one number" << endl;
    }
}

Catalan::Catalan(int n)
{
    cout << ComputeCatalan(n) << endl;
}

int Catalan::ComputeCatalan(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        int a = n - 1;
        int ans = 0;
        for (int i = 0; i <= a; i++)
        {
            ans += ComputeCatalan(i) * ComputeCatalan(a - i);
        }
        return ans;
    }
}