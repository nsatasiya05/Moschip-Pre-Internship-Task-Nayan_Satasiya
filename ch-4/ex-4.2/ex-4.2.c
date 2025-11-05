// ex-4.2.c
#include <stdio.h>
#include <ctype.h>

double atof_extended(char s[]);

int main(void)
{
    char str1[] = "123.45e-6";
    char str2[] = "1.2E3";
    char str3[] = "-7.89E+2";

    printf("%s = %g\n", str1, atof_extended(str1));
    printf("%s = %g\n", str2, atof_extended(str2));
    printf("%s = %g\n", str3, atof_extended(str3));

    return 0;
}

double atof_extended(char s[])
{
    double val, power;
    int i, sign, exp_sign, exp_val;

    // Skip whitespace
    for (i = 0; isspace(s[i]); i++)
        ;

    // Handle sign
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    // Integer part
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    // Fractional part
    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    val = sign * val / power;

    // Check for exponent (scientific notation)
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp_val = 0; isdigit(s[i]); i++)
            exp_val = 10 * exp_val + (s[i] - '0');

        // Apply exponent
        double p = 1.0;
        while (exp_val-- > 0)
            p *= 10.0;

        if (exp_sign == -1)
            val /= p;
        else
            val *= p;
    }

    return val;
}
