#include <stdio.h>

// Function to find the greatest common divisor using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the modular multiplicative inverse using Extended Euclidean algorithm
int mod_inverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        int q = a / m;
        int t = m;

        // m is remainder now, process same as Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

// Function to solve linear congruence ax = b (mod m)
void solve_linear_congruence(int a, int b, int m) {
    int gcd_a_m = gcd(a, m);
    
    if (b % gcd_a_m != 0) {
        printf("No solution exists.\n");
        return;
    }

    int a_prime = a / gcd_a_m;
    int b_prime = b / gcd_a_m;
    int m_prime = m / gcd_a_m;

    int x0 = mod_inverse(a_prime, m_prime);
    int solution = (x0 * b_prime) % m_prime;

    printf("One solution of %dx = %d (mod %d) is: x = %d (mod %d)\n", a, b, m, solution, m);
}

int main() {
    int a, b, m;
    printf("Enter the coefficients (a, b) and the modulus (m) for the linear congruence ax = b (mod m): ");
    scanf("%d %d %d", &a, &b, &m);

    solve_linear_congruence(a, b, m);

    return 0;
}

