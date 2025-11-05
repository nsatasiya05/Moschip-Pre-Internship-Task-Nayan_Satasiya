#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    int lower, upper, step;

    lower = 0;     // lower limit of temperature table
    upper = 100;   // upper limit
    step  = 10;    // step size

    celsius = lower;

    printf("Celsius to Fahrenheit Table\n");
    printf("-----------------------------\n");
    printf("Celsius\tFahrenheit\n");

    while (celsius <= upper) {
        fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        printf("%7.2f\t%10.2f\n", celsius, fahrenheit);
        celsius = celsius + step;
    }

    return 0;
}
