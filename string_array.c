#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


char* getWords(const char* myString, int* length) {
    int index = 0;
    int endIndex = 0;
    char* returnValue;
    for(int i = 0; i< strlen(myString); i++) {
        
        if(myString[i] == 'x') {
            printf("aa");
            break;
        } else {
            printf("bb");
            endIndex++;
        }
    }
    returnValue = (char*)malloc(endIndex+1);
    memset(returnValue, 0x00, endIndex+1);
    *length = endIndex;
    memcpy(returnValue, myString, endIndex);
        
    return returnValue;
}
void printLine(char** lines, int line) {
    printf("Line %d: %p %p %p %s \n", line, &lines[line], lines[line]);
}
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* myString) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int length = 0;
    int index = 0;
    int totalLength = 0;
    char** answer = malloc(sizeof(char*));
    int wordsLen = 0;
    
    while(index < strlen(myString)) {
        char* words = getWords(myString + index, &length);
        printf("addr = %p     , words = %s, length =%d\n", words, words, length);
        answer[wordsLen++] = words;
        index += length+1;
        totalLength += length;
    }

    return answer;
}

void main() {
    char** wordsTotal = solution("choixsungxhoon");
    printf("wordsTotal = %s\n", wordsTotal[0]);
    printf("wordsTotal = %s\n", wordsTotal[1]);
    printf("wordsTotal = %s\n", wordsTotal[2]);
    
    printLine(wordsTotal, 0);
    printLine(wordsTotal, 1);
    printLine(wordsTotal, 2);
}
