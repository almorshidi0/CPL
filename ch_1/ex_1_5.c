#include <stdio.h>

/* print Fahrenheit−Celsius table
    for fahr = 0, 20, ..., 300; floating−point version
    Reversed Order */
void main(){
    int fahr;
    
    printf("Fahr\tCelsius\n");
    for(fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%4d\t%7d\n", fahr, 5 * (fahr - 32) / 9);
}