#include <stdio.h>

#define SIZE 3 // Change this to the desired size of the matrices

// Function to perform Boolean matrix join operation
void boolean_join(int A[][SIZE], int B[][SIZE], int result[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = A[i][j] || B[i][j];
        }
    }
}

// Function to perform Boolean matrix meet operation
void boolean_meet(int A[][SIZE], int B[][SIZE], int result[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = A[i][j] && B[i][j];
        }
    }
}

// Function to perform Boolean matrix product operation
void boolean_product(int A[][SIZE], int B[][SIZE], int result[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int temp = 0;
            for (int k = 0; k < SIZE; k++) {
                temp = temp || (A[i][k] && B[k][j]);
            }
            result[i][j] = temp;
        }
    }
}

// Function to display a matrix
void display_matrix(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int A[SIZE][SIZE] = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    int B[SIZE][SIZE] = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    int result[SIZE][SIZE];

    printf("Matrix A:\n");
    display_matrix(A);

    printf("Matrix B:\n");
    display_matrix(B);

    printf("Boolean Matrix Join (A || B):\n");
    boolean_join(A, B, result);
    display_matrix(result);

    printf("Boolean Matrix Meet (A && B):\n");
    boolean_meet(A, B, result);
    display_matrix(result);

    printf("Boolean Matrix Product (A * B):\n");
    boolean_product(A, B, result);
    display_matrix(result);

    return 0;
}

