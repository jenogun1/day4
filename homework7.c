#include<stdio.h>

int str_find(); // 함수 선언

int main(){
    char inputStr[99]; // 검색 대상 문자열 저장 배열
    char subStr[99];   // 찾을 부분 문자열 저장 배열
    int n = 0;         // 입력 문자열의 길이 카운터
    int l = 0;         // 부분 문자열의 길이 카운터
    int ok = 0;        // 문자 일치 여부 확인용 플래그
    
    // 입력 문자열 받기 (개행 문자 전까지)
    printf("Enter up to 99 characters <innputStr> : ");
    for(int i = 0; i < 99; i++){
        scanf("%c", &inputStr[i]);
        n++;
        if(inputStr[i] == (char)10){ // 개행 문자 입력 시 중단
            break;
        }
    }
    
    // 찾을 문자열 받기 (개행 문자 전까지)
    printf("Find String <subStr> : ");
    for(int i = 0; i < 99; i++){
        scanf("%c", &subStr[i]);
        l++;
        if(subStr[i] == (char)10){ // 개행 문자 입력 시 중단
            break;
        }
    }
    
    // 찾고자 하는 문자열 출력
    printf("the position of ");
    for(int i = 0; i < l - 1; i++){
        printf("%c", subStr[i]);
    }
    printf(" : ");
    
    // 문자열 검색 루프
    for(int i = 0; i < n; i++){
        // 첫 글자가 일치하는 위치에서 부분 문자열 비교 시작
        if(inputStr[i] == subStr[0]){
            for(int j = 0; j < l - 1; j++){
                if(inputStr[i + j] == subStr[j]){
                    ok++; // 글자가 일치할 때마다 카운트 증가
                }
            }
            // 모든 글자가 일치하면 위치 출력 
            if(ok == l - 1){
                printf("%d ", i + 1);
                ok = 0;
            }
            ok = 0; // 플래그 초기화
        }
    }
}