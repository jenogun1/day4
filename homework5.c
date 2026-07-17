#include<stdio.h>

// 제곱수가 아닌 숫자를 처리하기 위한 함수 선언
int square_number(int min, int max);

int main(){
    int min, max;
    printf("1<=min<=max<=10000\nmin :");
    scanf("%d", &min);
    printf("max :");
    scanf("%d", &max);
    
    // 입력값 범위에 대한 오류 처리
    if(1 > min){
        printf("ERROR");
    }
    else if(min > max){
        printf("ERROR");
    }
    else if(max > 10000){
        printf("ERROR");
    }
    else{
        // 유효한 범위인 경우 함수 호출
        square_number(min, max);
    }
}

// 범위 내의 제곱수를 제외한 숫자들을 찾아 출력하는 함수
int square_number(int min, int max){
    int n = 0; // 제곱수의 개수를 저장할 변수
    
    // 1단계: 범위 내의 제곱수 개수(n) 계산
    for(int i = min; i <= max; i++){
        for(int j = 1; j <= i / 2; j++){
            if(i == j * j){ // i가 j의 제곱과 같다면
                n++;
            }
        }
    }
    // 제곱수가 아닌 숫자의 개수 출력 (전체 개수 - 제곱수 개수)
    printf("Total number of non-square numbers : %d\n", max - min + 1 - n);
    
    n = 0; // 개수 카운트 변수 초기화
    printf("not a square number : ");
    
    // 2단계: 제곱수가 아닌 숫자들만 출력
    for(int i = min; i <= max; i++){
        for(int j = 1; j <= i / 2; j++){
            if(i == j * j){
                n++; // 제곱수이면 n 증가
            }
        }
        // 제곱수가 아닌 경우(n이 0인 상태) 숫자 출력
        if(n == 0){
            printf("%d ", i);
        }
        n = 0; // 다음 숫자를 확인하기 위해 초기화
    }
}