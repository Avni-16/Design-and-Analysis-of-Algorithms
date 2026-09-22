#include <stdio.h>

int n, target;
int arr[100];
int subset[100];

int solutions[100][100];
int sizes[100];
int count = 0;

void backtrack(int index, int sum, int size) {
    if (sum == target) {
        for (int i = 0; i < size; i++)
            solutions[count][i] = subset[i];

        sizes[count] = size;
        count++;
        return;
    }

    if (index == n || sum > target)
        return;

    // Include current element
    subset[size] = arr[index];
    backtrack(index + 1, sum + arr[index], size + 1);

    // Exclude current element
    backtrack(index + 1, sum, size);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &target);

    backtrack(0, 0, 0);

    if (count == 0) {
        printf("-1");
    } else {
        // Reverse order of discovery
        for (int i = count - 1; i >= 0; i--) {
            for (int j = 0; j < sizes[i]; j++) {
                if (j > 0)
                    printf(" ");
                printf("%d", solutions[i][j]);
            }
            printf(" \n");
        }
    }

    return 0;
}
