/* input/output file */

#include "cities.h" // include header file

/* this function gets one line of input about the current city */
void input(FILE *fp, char city[], int *population, int *squareMileage, int *pollutionAmount, int *crime, int *expense, int *numHighways)
{
    fscanf(fp, "%s %d %d %d %d %d %d", city, population, squareMileage, pollutionAmount, crime, expense, numHighways);  // scan file for city name, population, square mileage, pollution amount, crime, expense and number of highways
}

/* output a summary of this city (name, livability, population density) */
void output(char city[], double populationDensity, double livability)
{
    printf("%-22s%3.2f%26.2f\n", city, populationDensity, livability);  // print city name, population density and livability score
}