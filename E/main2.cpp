
#include <iostream>

using namespace std;

int main()
{
    double p = 0.01;
    double q = 1-p;
    double r = 0;
    int n = 50;
    double d = 50*49/2;
    d *= p * p;
    for(int i = 0; i<48; i++) d*=q;
    r += d;
    d = 50;
    d*=p;
    for(int i = 0; i<49; i++) d*=q;
    r += d;
    d=1;
    for(int i = 0; i<50; i++) d*=q;
    r+=d;
    cout<<r;
    return 0;
}
