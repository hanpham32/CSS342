#include <iostream>
using namespace std;

int Factorial(int n);

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    cout << Factorial(n) << endl;
}

int Factorial(int n)
{
    if (n < 0)
    {
        return;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
    }
    int ans = n * Factorial(n - 1);
    return ans;
}