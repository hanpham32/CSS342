#include "list342.h"
#include "child.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // string file_name = "names.txt";
    Child c1("Angie", "Ham", 7);
    List342<Child> class1;
    bool status = class1.Insert(&c1);
    cout << status << endl;

    // cout << typeid(list).name() << endl;
    return 0;
}
