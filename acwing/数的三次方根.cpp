//https://www.acwing.com/problem/content/description/792/
//精度问题

#include<iostream>
#include<cmath>
using namespace std;
int main() {
    double b; cin>> b;
    double f,t;
    if( b < 0 ) {
        f = b, t = 0;
    } else {
        f = -1, t = b;
    }
    
    while(t -f >= 1e-8) {
        double m = (f + t)  /2;
        double mm = m * m * m;
        if( mm >= b) {
            t = m;
        } else {
            f = m;
        }
    }
    
    printf("%.6f", f);
    
    return 0;
}
