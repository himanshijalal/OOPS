#include <iostream>
using namespace std;

double factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

int main()
{
    int number;

    cout << "Enter the Number for Factorial" << endl;
    cin >> number;

    cout << "Factorial of " << number << " is "
         << factorial(number) << endl;

    return 0;
}
