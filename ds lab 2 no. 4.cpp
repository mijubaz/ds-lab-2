#include <stdio.h>

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

// Function to find the solution of the system of congruences using Chinese Remainder Theorem
int chinese_remainder(int num[], int rem[], int k) {
    // Compute product of all numbers
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    int result = 0;

    // Apply the formula
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * mod_inverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main() {
    int num[] = {3, 5, 7};
    int rem[] = {2, 3, 2};
    int k = sizeof(num) / sizeof(num[0]);

    int solution = chinese_remainder(num, rem, k);

    printf("Solution of the system of congruences: x = %d (mod %d)\n", solution, num[0] * num[1] * num[2]);

    return 0;
}

