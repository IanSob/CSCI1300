#include <iostream>
#include <iomanip>
using namespace std;

void stepCountCumulativeSum(int daily_steps[], const int NUM_DAYS, int cumulative_steps[]);
void stepCountDelta(int daily_steps[], int last_month_steps[] , int delta[], const int NUM_DAYS);
double stepCountDeviation(int daily_steps[], const int NUM_DAYS, const int OPTIMAL_STEP_COUNT);

int main()
{
    const int NUM_DAYS = 4;
    int daily_steps[NUM_DAYS] = {4000, 2000, 8000, 3000};
    int last_month_steps[NUM_DAYS] = {5000, 3000, 8000, 6000};
    int delta[NUM_DAYS];

    stepCountDelta(daily_steps, last_month_steps, delta, NUM_DAYS);
    
    for (int i = 0; i < NUM_DAYS; i++)
    {
        cout << delta[i] << "\n";
    }
    
    return 0;
}

void stepCountCumulativeSum(int daily_steps[], const int NUM_DAYS, int cumulative_steps[])
{
    int previousCumulativeSteps = 0;
    for (int i = 0; i < NUM_DAYS; i++)
    {
        //Takes the previous cumulative steps and adds it to the total
        cumulative_steps[i] = daily_steps[i] + previousCumulativeSteps;
        //Setting the previous cumulative steps
        previousCumulativeSteps = cumulative_steps[i];
    } 
}

double stepCountDeviation(int daily_steps[], const int NUM_DAYS, const int OPTIMAL_STEP_COUNT)
{
    double total = 0;
    double mean = 0;

    for (int i = 0; i < NUM_DAYS; i++)
    {
        total += daily_steps[i];
    }

    mean = total / NUM_DAYS;

    return mean - OPTIMAL_STEP_COUNT;
}

void stepCountDelta(int daily_steps[], int last_month_steps[] , int delta[], const int NUM_DAYS)
{
    for (int i = 0; i < NUM_DAYS; i++)
    {
        delta[i] = daily_steps[i] - last_month_steps[i];
    }  
}