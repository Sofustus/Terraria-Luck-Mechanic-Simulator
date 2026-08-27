#include <iostream>
#include <random>
#include <cstdlib>
using namespace std;
#include <cmath>
#include <iomanip>

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

double computeNegativeLuckValue(int n_2, double neg_luck){
    // Sum of 1/k for k from n to 2n-1
    int lower = n_2; 
    double sum = 0.0;
    for (int k = lower; k <= 2 * n_2 - 1; ++k){
        sum += 1.0/k; 
    }
    double result2 = ((sum / n_2) * abs(neg_luck) + (1.0 / n_2) * (1.0 - abs(neg_luck)))*100;
    return result2; 
}

int main() {

    //1 in n chance of an event happening 
    int test_n = 10;
    
    //positive and negative luck are 2 different variables 
    double test_luck = 0.0;
    double neg_test_luck = -1.0; 

    double result = computePositiveLuckValue(test_n, test_luck);
    cout << "Positive: "<< fixed << setprecision(2) << result << "%" << '\n';

    double result2 = computeNegativeLuckValue(test_n, neg_test_luck);
    cout << "Negative: "<< fixed << setprecision(2) << result2 << "%" << '\n';
    return 0; 
}