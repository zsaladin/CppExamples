#include <iostream>

using namespace std;

int gMatrix[20240][20240] = {};

int main()
{
    {
        // 2차원 배열
        int matrix[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        // 2차원 배열 순회
        for (int i = 0; i < size(matrix); ++i)
        {
            for (int j = 0; j < size(matrix[i]); ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    {
        // 2차원 행렬의 곱셈
        int matrix0[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        int matrix1[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        int matrix2[3][3] = {};

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    matrix2[i][j] += matrix0[i][k] * matrix1[k][j];
                }
            }
        }
        for (int i = 0; i < size(matrix2); ++i)
        {
            for (int j = 0; j < size(matrix2[i]); ++j)
            {
                cout << matrix2[i][j] << " ";
            }
            cout << endl;
        }
    }
    {
        // 배열의 메모리 
        // int[3]
        // int, int, int

        // int[3][3]
        // int, int, int | int, int, int | int, int, int
    }
    {
        // 배열의 복사
        int matrix0[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        int matrix1[3][3];

        // 순회를 이용한 복사
        for (int i = 0; i < size(matrix1); ++i)
        {
            for (int j = 0; j < size(matrix1[i]); ++j)
            {
                matrix1[i][j] = matrix0[i][j];
            }
        }

        // 함수를 이용한 복사
        memcpy(matrix1, matrix0, sizeof(matrix0));
        copy(&matrix0[0][0], &matrix0[0][0] + 3 * 3, &matrix1[0][0]);


        for (int i = 0; i < size(matrix1); ++i)
        {
            for (int j = 0; j < size(matrix1[i]); ++j)
            {
                cout << matrix1[i][j] << " ";
            }
            cout << endl;
        }
    }
    {
        // 캐싱에 따른 순회 속도의 차이 비교
        // 시간 지역성, 공간 지역성
        int sum = 0;
        for (int i = 0; i < 20240; ++i)
        {
            for (int j = 0; j < 20240; ++j)
            {
                sum += gMatrix[i][j]; // 빠름
                sum += gMatrix[j][i]; // 느림
            }
        }
    }
}