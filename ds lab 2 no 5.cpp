#include <stdio.h>

// Function to calculate the gcd of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// Function to find the modular inverse using extended Euclidean algorithm
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply extended Euclid Algorithm
    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to apply Chinese Remainder Theorem
int chinese_remainder(int num[], int rem[], int n) {
    int prod = 1;
    for (int i = 0; i < n; i++)
        prod *= num[i];

    int result = 0;

    for (int i = 0; i < n; i++) {
        int pp = prod / num[i];
        result += rem[i] * mod_inverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main() {
    int num[100], rem[100], n;

    printf("Enter number of congruences (max 100): ");
    scanf("%d", &n);

    printf("Enter the %d pairs of (remainder modulus): \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &rem[i], &num[i]);
    }

    int x = chinese_remainder(num, rem, n);
    printf("The solution of the system of congruences is: %d\n", x);

    return 0;
}

