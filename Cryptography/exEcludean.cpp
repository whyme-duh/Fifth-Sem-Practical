#include <iostream>
using namespace std;
int extendedEuclidean(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    cout<<x << "\t" <<y<<endl;

    return gcd;
}

int main()
{
    int a, b, x, y;
    cout<<"Student roll no : 23497"<<endl;

    cout << "Enter two integers: ";
    cin >> a >> b;
    cout<<"x "<<"\t"<<"y"<<endl;

    int gcd = extendedEuclidean(a, b, x, y);

    cout << "The gcd of " << a << " and " << b << " is " << gcd << endl;
    cout << "x: " << x << ", y: " << y << endl;

    return 0;
}
