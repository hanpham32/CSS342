#include "catalan.h"

Catalan::Catalan(int n)
{
}

int Catalan::ComputeCatalan(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        int catalan_number = ;
        for (int i = 0; i < n; i++)
        {
        }
        return n * ComputeCatalan(n - 1);
    }
}