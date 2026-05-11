#include <stdio.h>
#include <math.h>

int main() {
    double delta, x1, x2, a, b, c;

    a = 2;
    b = 4;
    c = -3;
    delta = pow(b, 2) - 4 * a * c;
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);

    return 0;
}