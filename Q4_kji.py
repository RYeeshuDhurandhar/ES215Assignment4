from audioop import mul
import random
import time


def mul_mat(N):
    rslt = [[0] * N] * N
    mat1 = [[0] * N] * N
    mat2 = [[0] * N] * N
    serial = 0

    for i in range(0, N):
        for j in range(0, N):
            mat1[i][j] = random.randint(0, 50)

    for i in range(0, N):
        for j in range(0, N):
            mat2[i][j] = random.randint(0, 50)

    start_meat_portion = time.time()
    for k in range(0, N):
        for j in range(0, N):
            rslt[i][j] = 0

            for i in range(0, N):
                rslt[i][j] += mat1[i][k] * mat2[k][j]
    end_meat_portion = time.time()
    meat_portion_time = end_meat_portion - start_meat_portion
    return meat_portion_time

start_programExT = time.time()

N = 128
meat_portion_time = mul_mat(N)

end_programExT = time.time()

programExT = end_programExT - start_programExT
print('Time taken for meat portion of program (in s): ', meat_portion_time)
print('Program Execution Time (in s): ', programExT)