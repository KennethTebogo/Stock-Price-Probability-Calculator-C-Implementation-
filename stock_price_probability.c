#include <stdio.h>
#include <math.h>

// Function to approximate the error function (erf)
double erf_approx(double x) {
    // Constants for approximation
    double a1 =  0.254829592, a2 = -0.284496736, a3 =  1.421413741;
    double a4 = -1.453152027, a5 =  1.061405429;
    double p  =  0.3275911;
    
    // Save the sign of x
    int sign = (x < 0) ? -1 : 1;
    x = fabs(x);
    
    // Approximate the error function
    double t = 1.0 / (1.0 + p * x);
    double y = 1.0 - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * exp(-x * x);
    
    return sign * y;
}

// Function to compute the cumulative distribution function (CDF) for the standard normal distribution
double normal_cdf(double x) {
    return 0.5 * (1.0 + erf_approx(x / sqrt(2.0)));
}

// Function to calculate probability P(F(M) > F(0)) for lognormal stock price evolution
void probability_stock_price_increase(double mu, double sigma, double M) {
    if (M < 1) {
        printf("Error: M must be at least 1 (weeks must be positive).\n");
        return;
    }

    // Compute Z-score
    double z_score = sqrt(M) * (mu / sigma);

    // Compute probability using normal CDF
    double probability = normal_cdf(z_score);

    // Display results
    printf("Z-score: %.6f\n", z_score);
    printf("Probability P(F(M) > F(0)): %.6f\n", probability);
}

int main() {
    double mu, sigma, M;

    // User input
    printf("Enter the value of Mu μ: ");
    scanf("%lf", &mu);

    printf("Enter the value of Sigma σ: ");
    scanf("%lf", &sigma);

    printf("Enter the number of Weeks: ");
    scanf("%lf", &M);

    // Calculate probability
    probability_stock_price_increase(mu, sigma, M);

    return 0;
}

