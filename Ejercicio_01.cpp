#include <iostream>
using namespace std;

int sum(int n) 
{
    int sum = 0;
    for (int i = 1; i < n; ++i) 
    {
        if (n % i == 0) 
        {
            sum += i;
        }
    }
    return sum;
}
int main()
{
    int a, b;
    cout << "ingrese el primer número: ";
    cin >> a;
    cout << "ingrese el segundo número: ";
    cin >> b;
    int a1= sum(a);
    int b1= sum(b);
    if(a1==b && b1==a)
    {
        cout<< "los numeros son amigos";
    }else
        cout<< "no son amigos";
}
