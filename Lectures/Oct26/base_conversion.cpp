#include <iostream>
#include <string>

using namespace std;

bool PrintBase(int num, int base, string &answer);

int main()
{
    int number, base;
    string answer = "";
    cout << "Input Number: ";
    cin >> number;
    std::cout << "Input base: ";
    cin >> base;
    PrintBase(number, base, answer);
    cout << number << " is " << answer << " in base " << base << endl;
}

bool PrintBase(int num, int base, string &answer)
{
    string static kDigitArray = "0123456789ABCDEF";
    if ((num < 0) || (base < 2) || (base > 16))
    {
        return false;
    }
    if (num < base)
    {
        answer = kDigitArray[num] + answer;
        return true;
    }
    else
    {
        answer = kDigitArray[num % base] + answer;
        PrintBase(num / base, base, answer);
        return true;
    }
}