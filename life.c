#include <stdio.h>
#include <stdbool.h>

int (*init_matrix())[10] {
    static int arr[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = 0;
        }
    }
    return arr;
}

void print_matrix(int (*matrix)[10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 9) {
                printf("%d\n", matrix[i][j]);
            } else
                printf("%d ", matrix[i][j]);
        }
    }
}

int frame_check(int x) {
    if (x == 10) return 0;
    if (x == -1) return 9;
    return x;
}

bool live_or_die(int x, int y, int matrix[10][10]) {
    int counter = 0;
    
    if (matrix[frame_check(x + 1)][frame_check(y + 1)]) counter++;
    if (matrix[x][frame_check(y + 1)]) counter++;
    if (matrix[frame_check(x - 1)][frame_check(y + 1)]) counter++;
    if (matrix[frame_check(x + 1)][y]) counter++;
    if (matrix[frame_check(x - 1)][y]) counter++;
    if (matrix[frame_check(x + 1)][frame_check(y - 1)]) counter++;
    if (matrix[x][frame_check(y - 1)]) counter++;
    if (matrix[frame_check(x - 1)][frame_check(y - 1)]) counter++;
    
    printf("%d\n", counter);
    
    if (matrix[x][y]) {
        if (counter == 2 || counter == 3) {
            return true;
        } else
            return false;
    } else {
        if (counter == 3) {
            return true;
        } else
            return false;
    }
}

int main() {
//    int (*matrix)[10] = init_matrix();
    int matrix[10][10] = {
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}
                  };
    printf("%d\n", (live_or_die(0, 0, matrix)) ? 1 : 0);
//    print_matrix(matrix);
    return 0;
    }
