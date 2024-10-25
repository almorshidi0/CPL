#include <stdio.h>

int fahrToCelsius(int fahr);

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahr\tCelsius\n");
    while(fahr <= upper){
        celsius = fahrToCelsius(fahr);
        printf("%4.0f\t%7.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

int fahrToCelsius(int fahr)
{
    float celsius = 0;

    celsius = (5.0 / 9.0) * (fahr - 32.0);
    
    return celsius;
}