#include <iostream>
using namespace std;

bool checkPalindrome(int number)
{
    int originalNum = number;
    int reversedNum = 0;
    int remainder;

    while (number > 0)
    {
        remainder = number % 10;
        reversedNum = (reversedNum * 10) + remainder;
        number = number / 10;
    }

    if (originalNum == reversedNum)
        return true;
    else
        return false;
}

int main()
{
    int inputNumber;

    cout << "Enter a positive number: ";
    cin >> inputNumber;

    if (checkPalindrome(inputNumber))
        cout << inputNumber << " is a palindrome." << endl;
    else
        cout << inputNumber << " is not a palindrome." << endl;

    return 0;
}
