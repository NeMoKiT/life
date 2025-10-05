#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 86

int (*init_matrix(int density))[SIZE] {
    static int arr[SIZE][SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = (rand() % 100 < density) ? 1 : 0;
        }
    }
    return arr;
}

void print_matrix(int (*matrix)[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(matrix[i][j] ? "■ " : "  ");
        }
        printf("\n");
    }
}

int frame_check(int x) {
    if (x == SIZE) return 0;
    if (x == -1) return SIZE - 1;
    return x;
}

bool live_or_die(int x, int y, int matrix[SIZE][SIZE]) {
    int counter = 0;
    
    if (matrix[frame_check(x + 1)][frame_check(y + 1)]) counter++;
    if (matrix[x][frame_check(y + 1)]) counter++;
    if (matrix[frame_check(x - 1)][frame_check(y + 1)]) counter++;
    if (matrix[frame_check(x + 1)][y]) counter++;
    if (matrix[frame_check(x - 1)][y]) counter++;
    if (matrix[frame_check(x + 1)][frame_check(y - 1)]) counter++;
    if (matrix[x][frame_check(y - 1)]) counter++;
    if (matrix[frame_check(x - 1)][frame_check(y - 1)]) counter++;
    
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

void update_matrix(int matrix[SIZE][SIZE]) {
    int temp[SIZE][SIZE];
    
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            temp[x][y] = live_or_die(x, y, matrix);
        }
    }
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            matrix[x][y] = temp[x][y];
        }
    }
}

void start_life(int density) {
    int (*matrix)[SIZE] = init_matrix(density);
    int gen = 1;
    while (1) {
        printf("\033[3;1H");
        print_matrix(matrix);
        update_matrix(matrix);
        printf("%d\n", gen++);
        usleep(100000);
    }
}


int main() {
    int density;
    printf("Density in percent: ");
    if (scanf("%d", &density) != 1)
        density = 15;
    start_life(density);
    return 0;
    }
