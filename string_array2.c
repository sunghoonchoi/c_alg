#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* myString) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(sizeof(char*) * 4);
    answer[0] = (char*)malloc(sizeof(char)*5); 
    memset(answer[0], 0x00, sizeof(char)*5);
    answer[1] = (char*)malloc(sizeof(char)*5); 
    memset(answer[1], 0x00, sizeof(char)*5);
    answer[2] = (char*)malloc(sizeof(char)*5); 
    memset(answer[2], 0x00, sizeof(char)*5);
    answer[3] = (char*)malloc(sizeof(char)*5); 
    memset(answer[3], 0x00, sizeof(char)*5);
    
    char buffer[100001] = {0x00,};
    memcpy(buffer, myString, strlen(myString)+1);
    
    printf("buffer = %s\n", buffer);
    
    // 일단 자른다. 그리고 정렬한다.
    int token_count = 0;
    char *ptr = strtok(buffer, "x");
    while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
    {
        printf("%s\n", ptr);          // 자른 문자열 출력
        answer[token_count] = (char*)malloc(sizeof(char)*strlen(ptr)+1); 
        memset(answer[token_count], 0x00, sizeof(char)*strlen(ptr)+1); 
        
        
        printf("%s\n", ptr);          // 자른 문자열 출력
        
        memcpy(answer[token_count], ptr, strlen(ptr));
        printf("token count = %d\n", token_count);
        token_count++;
        ptr = strtok(NULL, "x");      // 다음 문자열을 잘라서 포인터를 반환     
     }
    
    printf("token count= %d", token_count);
    for(int i = 0; i < token_count; i++)
    {
        for(int j = i; j < token_count; j++)
        {
            if(strcmp(answer[i], answer[j]) > 0)
            {
                char* tmp = malloc(strlen(answer[i]));
                strcpy(tmp, answer[i]);
                strcpy(answer[i], answer[j]);
                strcpy(answer[j], tmp);
            }
        }
    }
    
    return answer;
}
