/* computations file */

#include "cities.h" // include header file

/* compute and return the city’s population density */
double calculatePopulationDensity(int population, int squareMileage)
{
    return (double)population / (double)squareMileage;   // return population density
}

/* compute the city’s pollution rating, traffic rating, crime per capita, expense per capita */
void ratings(int pollutionAmount, int populationDensity, int numHighways, int crime, int expense, double * pollutionRating, double * trafficRating, double * crimePerCapita, double * expensePerCapita)
{
    *pollutionRating = pollutionAmount * populationDensity / (double)1000;    // compute pollution rating
    *trafficRating = (populationDensity * DENSITY_SCALE) / numHighways; // compute traffic rating (DENSITY_SCALE = 1.7)
    *crimePerCapita = (crime * populationDensity) / CPC_DENOM;  // compute crime per capita (CPC_DENOM = 872.6)
    *expensePerCapita = (expense * populationDensity) / EPC_DENOM;  // compute expense per capita (EPC_DENOM = 1217.1)
}

/* compute livability score for individual  */
double calculateLivability(double pollutionRating, double trafficRating, double crimePerCapita, double expensePerCapita)  // compute the city’s livability
{
    return 100 - (pollutionRating + trafficRating + crimePerCapita + expensePerCapita) / LIVABILITY_DENOM; // return livability score (LIVABILITY_DENOM = 13.81)
}

/* update statistics of the total of all of the city livability values, the number of cities, and whether this is the best city found so far */
void updateStatistics(double livability, char city[], int * numberOfCities, char mostLivableCity[] , double * mostLivableValue)   // update statistics of the total of all of the city livability values, the number of cities, and whether this is the best city found so far
{
    float epsilon = 0.000000001;    // for more accurate double comparison

    (*numberOfCities)++;    // increment the total number of cities by one

    /* compare city's livability score to value of the most livable city: update if necessary */
    if(livability - (* mostLivableValue) > epsilon)
    {
        strncpy(mostLivableCity, city, 80); // update most livable city
        * mostLivableValue = livability;    // update most livable value
    }
}
