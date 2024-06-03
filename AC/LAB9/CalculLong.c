#include<stdio.h>

int main(int argc, char* argv[]) {
    long long z;
    long long x = 665857.0;
    long long y = 470832.0;
    z = (x*x*x*x) - 4*(y*y*y*y) - 4*(y*y);
    printf("%lld\n",z);

}   