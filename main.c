/*  Kyle J Green
 *  Programming Assignment 2: Computing City Data with Pointers
 *  2/21/17
 *  Description: Program reads city name, population, pollution amount, crime, expense and number of highways
 *  from file, storing these as variables. It then takes these variables and calculates population density,
 *  pollution rating, traffic rating, crime per capita and expense per capita for each city. These scores
 *  are combined to form each city's livability score. The city with the highest livability and its's score is
 *  returned in a summary, along with the name, population density and livability score for each city.
 */

#include "cities.h" // include header file

/* main method */
int main() {
    char file[80];  // the name of the file
    char city[80]; // city name from input file
    char mostLivableCity[80];  // city with highest livability score
    int population, squareMileage, pollutionAmount, crime, expense, numHighways, numberOfCities;  // population, square mileage, pollution, crime, expense and number of cities for each city from the input file
    double populationDensity, pollutionRating, trafficRating, crimePerCapita, expensePerCapita, livability, mostLivableValue;
    FILE *fp;   // input file

    /* Prompt user for the name of the file and save this */
    printf("%s", "Specify the name of the input file: ");
    scanf("%s", file);

    fp = fopen(file, "r");   // open file, read only

    printf("\n%-s%33s%28s\n", "City" , "Population Dens" , "Livability Score"); // print field names

    /* loop on cities in file, compute and print statistics */
    while(!feof(fp))
    {
        input(fp, city, &population, &squareMileage, &pollutionAmount, &crime, &expense, &numHighways); // get city data from fp
        populationDensity = calculatePopulationDensity(population, squareMileage);  // compute population density
        ratings(pollutionAmount, populationDensity, numHighways, crime, expense, &pollutionRating, &trafficRating, &crimePerCapita, &expensePerCapita); // compute pollution rating, traffic rating, crime per capita and expense per capita
        livability = calculateLivability(pollutionRating, trafficRating, crimePerCapita, expensePerCapita); // compute city's liveability score
        updateStatistics(livability, city, &numberOfCities, mostLivableCity, &mostLivableValue);    // update number of cities, most livable city, and most livable value
        output(city, populationDensity, livability);    // print city data
    }

    fclose(fp); // close file
    printf("\n%s%d%s%s%s%.2f", "Of the ", numberOfCities, " cities, the most livable was ", mostLivableCity, " with a score of ", mostLivableValue);    // print summary

    return 0;   // end program
}