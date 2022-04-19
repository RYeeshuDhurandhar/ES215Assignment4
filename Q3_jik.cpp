#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define N 128

long current_time()
{
    struct timespec time;
    timespec_get(&time, CLOCK_MONOTONIC);
    return time.tv_sec * 1000000000 + time.tv_nsec;
}

void multiply(int matrix1[N][N],
              int matrix2[N][N],
              int result[N][N])
{
    int i, j, k;
    for (j = 0; j < N; j++)
    {
        for (i = 0; i < N; i++)
        {
            result[i][j] = 0;
            for (k = 0; k < N; k++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}

void random_matrix(int matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = (rand() % 100) * 0.21;
        }
    }
}

int main()
{
    long start_programExT = current_time();
    int i, j;
    int result[N][N];
    int matrix1[N][N];
    int matrix2[N][N];
    random_matrix(matrix1);
    random_matrix(matrix2);

    srand(time(0));

    long start_time_meat_portion = current_time();

    multiply(matrix1, matrix2, result);

    long end_time_meat_portion = current_time();

    cout << endl
         << "Time taken for meat portion of program (in ns): " << end_time_meat_portion - start_time_meat_portion << endl;

    long end_programExT = current_time();
    cout << endl
         << "Program Execution Time (in ns): " << end_programExT - start_programExT << endl;
    return 0;
}