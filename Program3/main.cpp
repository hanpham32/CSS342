#include "list342.h"
#include "child.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // string file_name = "names.txt";
    Child c1("Angie", "Ham", 7), c2("Han", "P", 4);
    List342<Child> class1;
    List342<string> class2;
    List342<int> numbers;
    string s = "Hi!";
    int a = -1, b = 10, c = 6;
    class1.Insert(&c1);
    class1.Insert(&c2);
    numbers.Insert(&a);
    numbers.Insert(&b);
    numbers.Insert(&c);
    cout << numbers << endl;
    int value;
    numbers.Remove(-1, value);
    cout << numbers << endl;
    cout << "removed: " << value << endl;
    // cout << typeid(list).name() << endl;
    return 0;
}
