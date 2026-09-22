// AVNI MANKAR

#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    int A[100][100], B[100][100], C[100][100];
    int i, j, k;

    // Read dimensions of matrix A
    scanf("%d %d", &r1, &c1);

    // Read matrix A
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read dimensions of matrix B
    scanf("%d %d", &r2, &c2);

    // Check whether multiplication is possible
    if (c1 != r2) {
        printf("Invalid input");
        return 0;
    }

    // Read matrix B
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Matrix multiplication
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            C[i][j] = 0;

            for (k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display result
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
