#include<stdio.h>

// 함수 선언: 각각 다른 패턴의 별 모양을 출력하는 함수들
int type1(int s);
int type2(int s);
int type3(int s);
int type4(int s);

int main(){
    int size = 0;
    int type = 0;
    printf("size and type :");
    scanf("%d %d", &size, &type);
    
    // 크기가 짝수이면 오류 출력
    if(size % 2 == 0){
        printf("size error");
    }
    // 선택된 타입에 따라 해당 함수 호출
    else if(type == 1){ type1(size); }
    else if(type == 2){ type2(size); }
    else if(type == 3){ type3(size); }
    else if(type == 4){ type4(size); }
    else{
        printf("type error"); // 타입 번호 오류 출력
    }
}

// Type 1: 왼쪽 정렬된 삼각형 패턴 출력
int type1(int s){
    for(int i = 1; i <= s; i++){
        if(i <= s / 2){ // 상단부
            for(int l = s - i; l < s; l++){ printf("*"); }
        }
        else{ // 하단부
            for(int l = i; l <= s; l++){ printf("*"); }
        }
        printf("\n");
    }
}

// Type 2: 오른쪽 정렬된 삼각형 패턴 출력
int type2(int s){
    for(int i = 1; i <= s; i++){
        if(i <= s / 2){ // 상단부: 공백 출력 후 별 출력
            for(int l = s / 2; l >= i; l--){ printf(" "); }
            for(int l = s - i; l < s; l++){ printf("*"); }
        }
        else { // 하단부: 공백 출력 후 별 출력
            for(int l = s - i + 1; l <= s / 2; l++){ printf(" "); }
            for(int l = i; l <= s; l++){ printf("*"); }
        }
        printf("\n");
    }
}

// Type 3: 가운데가 모이는 다이아몬드(또는 역삼각형 결합) 패턴
int type3(int s){
    int n = 0;
    for(int i = 1; i <= s; i++){
        if(i <= s / 2){ // 상단부: 공백 점진적 증가, 별 점진적 감소
            for(int l = 1; l < i; l++){ printf(" "); }
            for(int l = i * 2 - 1; l <= s; l++){ printf("*"); }
        }
        else{ // 하단부: 공백 점진적 감소, 별 점진적 증가
            for(int l = i; l < s; l++){ printf(" "); }
            for(int l = s; l < i * 2 - n; l++){ printf("*"); }
        }
        printf("\n");
    }
}

// Type 4: 특정 모양의 별 패턴 출력
int type4(int s){
    for(int i = 1; i <= s; i++){
        if(i <= s / 2){ // 상단부
           for(int l = 1; l < i; l++){ printf(" "); }
           for(int l = i - 1; l <= s / 2; l++){ printf("*"); }
        }
        else{ // 하단부
            for(int l = 0; l < s / 2; l++){ printf(" "); }
            for(int l = s - i; l <= s / 2; l++){ printf("*"); }
        }
        printf("\n");
    }
}