#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

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
            printf(matrix[i][j] ? "■ " : "  ");
        }
        printf("\n");
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

void update_matrix(int matrix[10][10]) {
    int temp[10][10];
    
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            temp[x][y] = live_or_die(x, y, matrix);
        }
    }
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            matrix[x][y] = temp[x][y];
        }
    }
}

//bool check_life(matrix[10][10]) {
//    
//}


int main() {
//    int (*matrix)[10] = init_matrix();
    int gen = 1;
    int matrix[10][10] = {
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                  {0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
                  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                  };
//    printf("%d\n", (live_or_die(9, 0, matrix)) ? 1 : 0);
    while (1) {
        printf("\033[3;1H");
        print_matrix(matrix);
        update_matrix(matrix);
        printf("%d\n", gen++);
        usleep(100000);
    }
    return 0;
    }
