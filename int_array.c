#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_rows는 2차원 배열 arr의 행 길이, arr_cols는 2차원 배열 arr의 열 길이입니다.
int solution(int** arr, size_t arr_rows, size_t arr_cols) {
    int answer = 0;
    
//     printf("arr_rows = %d, arr_cols = %d\n");
    
//     int myIntPointer[arr_rows][arr_cols];
    
//     printf("sizeof(myIntPointer) = %d\n", sizeof(myIntPointer));
    
//     memcpy(myIntPointer, arr, sizeof(myIntPointer));
    
//     printf("myIntPointer = %d\n", myIntPointer[0][0]);
//     printf("myIntPointer = %d\n", myIntPointer[0][1]);
//     printf("myIntPointer = %d\n", myIntPointer[1][0]);
//     printf("myIntPointer = %d\n", myIntPointer[1][1]);

    //1. 왜 주석된 memcpy가 안된거지?
    
    for (size_t r=0; r<arr_rows; r++)
    {
        for (size_t c=0; c<arr_cols; c++)
        {
            printf("%d, ", arr[r][c]);
        }
        printf("\n");
    }
    
    printf("sizeof(arr) = %d", sizeof(arr));
    
    int** cc = malloc(sizeof(int)*arr_rows*arr_cols);
    printf("sizeof(cc) = %d", sizeof(cc));

    //2. 이렇게 해서 cc를 리턴하면 배열처럼 쓸수 있나?
    
    return answer;
}
