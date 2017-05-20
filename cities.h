/* header file */

// library include statements
#include <stdio.h>  // for input/output
#include <ctype.h>  // for character functions
#include <string.h> // for copying strings
// define statements
#ifndef CITIES_CITIES_H // required for build-file
#define CITIES_CITIES_H // required for build-file
#define DENSITY_SCALE 1.7   // for computing traffic ratings
#define CPC_DENOM 872.6 // for computing crime per capita scores
#define EPC_DENOM 1217.1    // for computing expense per capita scores
#define LIVABILITY_DENOM 13.81  // for computing livability scores
#endif //CITIES_CITIES_H

/* function prototypes */
void input(FILE *fp, char [], int *, int *, int *, int *, int *, int *);  // input a city’s name, population, square mileage, pollution, crime, expense, number of highways
double calculatePopulationDensity(int, int); //compute and return the city’s population density
void ratings(int, int, int, int, int, double *, double *, double *, double *);  // compute the city’s pollution rating, traffic rating, crime per capita, expense per capita
double calculateLivability(double, double, double, double);  // compute the city’s livability
void updateStatistics(double, char [], int *, char[], double *);   // update statistics of the total of all of the city livability values, the number of cities, and whether this is the best city found so far
void output(char[], double, double);    // output a summary of this city (name, livability, population density