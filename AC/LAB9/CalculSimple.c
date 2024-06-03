#include<stdio.h>

int main(int argc, char* argv[]) {
    float z;
    float x = 665857.0;
    float y = 470832.0;
    z = (x*x*x*x) - 4*(y*y*y*y) - 4*(y*y);
    printf("%f\n",z);

}