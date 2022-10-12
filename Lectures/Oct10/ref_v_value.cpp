// ref_v_value.cpp: this file contains the 'main' function.
//

#include <iostream>
using namespace std;

typedef struct
{
    int width;
    int length;
} Rectangle;

int Area(const Rectangle& rect);

int main()
{
    Rectangle my_yard = {5, 7};
    int result = Area(my_yard);
    cout << my_yard.width << ", " << my_yard.length << ", Area is " << result << endl;
}

int Area(const Rectangle& rect)
{
    int area;
    area = rect.width * rect.length;
    return area;
}