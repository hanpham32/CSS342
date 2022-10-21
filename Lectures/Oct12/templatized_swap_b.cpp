
#include <iostream>
using namespace std;

template<class T>
void Swap(T& a, T& b); // Look more into swap alg!!

int main()
{
    int x=3, y=7;
    string name1 = "han", name2 = "seb";
    cout << name1 << " " << name2 << endl;
    Swap(name1, name2);
    cout << name1 << " " << name2 << endl;
    return 0;
}

template<class T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}