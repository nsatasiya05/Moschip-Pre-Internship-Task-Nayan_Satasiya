#include <stdio.h>

/* Function declaration */
float celsius_to_fahrenheit(float celsius);

int main() {
    float celsius;
    int lower, upper, step;

    lower = 0;     // lower limit of temperature table
    upper = 300;   // upper limit
    step  = 20;    // step size

    celsius = lower;

    printf("Celsius\tFahrenheit\n");
    printf("-------------------\n");

    while (celsius <= upper) {
        printf("%7.0f\t%10.1f\n", celsius, celsius_to_fahrenheit(celsius));
        celsius = celsius + step;
    }

    return 0;
}

/* Function definition */
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32.0;
}
