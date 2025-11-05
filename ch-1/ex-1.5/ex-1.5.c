#include <stdio.h>

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;     // lower limit of temperature table
    upper = 300;   // upper limit
    step = 20;     // step size

    printf("Celsius to Fahrenheit Table (Reverse Order)\n");
    printf("------------------------------------------\n");

    celsius = upper;
    while (celsius >= lower) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%6.1f °C = %6.1f °F\n", celsius, fahr);
        celsius = celsius - step;
    }

    return 0;
}
