#include<stdio.h>

int main(int argc, char* argv[]) {
    double z;
    double x = 665857.0;
    double y = 470832.0;
    z = (x*x*x*x) - 4*(y*y*y*y) - 4*(y*y);
    printf("%lf\n",z);

}