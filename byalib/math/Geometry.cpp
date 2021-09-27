#include <bits/stdc++.h>
using namespace std;

// tan: y / x
// sin: y / sqr(x^2 + y^2)
// cos: x / sqr(x^2 + y^2)

int main() {
    // Angle -> Value: sin/cos/tan
    // Value -> Angle: asin/acos/atan
    printf("\n------------\n");
    printf("sin(%d) = %.12lf\n", 30, sin(30 / 180 * M_PI));
    printf("asin(%f) = %.12lf\n", 0.5, asin(0.5) / M_PI * 180);
    printf("cos(%d) = %.12lf\n", 60, sin(60 / 180 * M_PI));
    printf("acos(%f) = %.12lf\n", 0.5, acos(0.5) / M_PI * 180);
    printf("tan(%d) = %.12lf\n", 45, tan(45 / 180 * M_PI));
    printf("atan(%d) = %.12lf\n", 1, atan(1) / M_PI * 180);

    // (x,y) -> Angle: atan2
    // Range: [-180:180]
    printf("\n------------\n");
    printf("atan2(%d, %d) = %.12lf\n", 1, 1, atan2(1, 1) / M_PI * 180);
    printf("atan2(%d, %d) = %.12lf\n", 1, -1, atan2(1, -1) / M_PI * 180);
    printf("atan2(%d, %d) = %.12lf\n", -1, 1, atan2(-1, 1) / M_PI * 180);
    printf("atan2(%d, %d) = %.12lf\n", -1, -1, atan2(-1, -1) / M_PI * 180);
}
