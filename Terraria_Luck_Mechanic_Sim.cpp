/*
Calculates a player's luck and how it affects random chances with a positive and negative luck

Luck value range: -1.1 <= X <= 1.76
Positive luck greater than 1 and negative luck less than -1 don't provide additional effects

items that give luck cannot stack



*/

#include <iostream>
#include <random>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

//formula for positive luck
/*Uses summation with final index of n-1, summation index of k with starting index of n/2, and function of 1/k
*/ 
double computePositiveLuckValue(int n, double luck) {
    // Sum of 1/k for k from floor(n/2) to n-1
    int lower = n / 2;          // integer division = floor(n/2) for n >= 0
    double sum = 0.0;
    for (int k = lower; k <= n - 1; ++k) { //upper bound = n-1
        sum += 1.0 / k;
    }

    // Ceiling of n/2
    int ceilHalf = (n + 1) / 2; // integer trick for ceil(n/2), avoids <cmath> ceil on ints

    double result = ((sum / ceilHalf) * luck + (1.0 / n) * (1.0 - luck))*100;
    return result;
}

//formula for negative luck
double computeNegativeLuckValue(int n, double luck){
    // Sum of 1/k for k from n to 2n-1
    int lower = n; 
    double sum = 0.0;
    for (int k = lower; k <= 2 * n - 1; ++k){
        sum += 1.0/k; 
    }
    double result2 = ((sum / n) * abs(luck) + (1.0 / n) * (1.0 - abs(luck)))*100;
    return result2;
}




int main(){


/*
1. Enter a luck value in the range [-1.1, 1.76]
*/

cout << "Enter a luck value in the range of -1.1 to 1.76" << endl; 
double luck, luck_to_percent, base_chance, base_chance_converted, n; 
if (!(cin >> luck)){
    cout << "Invalid input!" << endl; 
    cin.clear();
    return 1;
}
/*
1a. Enter a chance of an event happening (1 in n)
*/
cout << "The base chance of a certain event happening is 1 in: " << endl; 
cin >> n; 
base_chance = 1/n; 
base_chance_converted = (1/n)*100;



/*
2. Convert luck to a percent 
*/

luck_to_percent = luck * 100;


/*  
3. Use the appropriate formula to calculate new base chance of an event occuring 

n >= 0 uses the positive luck value formula
n <= 0 uses the negative luck value formula

*/

if (luck > 0){
     double result = computePositiveLuckValue(n, luck);
    double percentage_point_increase = abs(base_chance_converted - result);
    cout << "A Luck of " << luck << " increases the base chance of "
         << fixed << setprecision(2) << base_chance_converted << "% to "
         << result << "%, which is a " << percentage_point_increase
         << " percentage point increase" << '\n';

} else if (luck == 0){
    cout << "A Luck of " << luck << " doesn't change the probability, leaving the final probability at " << base_chance_converted << "%" << endl; 
} else {
   
    double result = computeNegativeLuckValue(n, luck);
    double percentage_point_decrease = base_chance_converted - result;
    cout << "A Luck of " << luck << " decreases the base chance of "
         << fixed << setprecision(2) << base_chance_converted << "% to "
         << result << "%, which is a " << percentage_point_decrease
         << " percentage point decrease" << '\n';
}





return 0;


}

