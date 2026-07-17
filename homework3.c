#include<stdio.h>

// 문자열의 정렬 상태를 체크하는 함수 선언
int mcheck(char m[8]);

int main(){
    char mc[8]; // 입력을 저장할 배열
    int n;
    
    // 8개의 문자를 입력받음
    for(int i = 0; i < 8; i++){
        scanf("%c", &mc[i]);
    }
    
    // 상태 체크 함수 호출
    n = mcheck(mc);
    
    // 결과에 따른 상태 출력
    switch(n){
        case 0:
            printf("ascending"); // 오름차순
            break;
        case 1:
            printf("descending"); // 내림차순
            break;
        case 10:
            printf("ERROR"); // 잘못된 입력
            break;
        default:
            printf("mixed"); // 섞여 있음
    }
}

// 음계가 오름차순(cdefgabC)인지 내림차순(Cbagfedc)인지 판별하는 함수
int mcheck(char m[8]){
    int n = 0;
    char c1[8] = "cdefgabC"; // 오름차순 기준 문자열
    char c2[8] = "Cbagfedc"; // 내림차순 기준 문자열
    
    for(int i = 0; i < 8; i++){
        // 오름차순과 일치하는지 확인
        if(m[i] == c1[i] && n == 0){
            n = 0;
        }
        // 내림차순과 일치하는지 확인
        else if(m[i] == c2[i] && n <= 1){
            n = 1;
        }
        // 일치하지 않을 경우, 음계에 포함된 문자인지 검사
        else{
            switch(m[i]){
            case 'c': case 'd': case 'e': case 'f': case 'g': case 'a': case 'b': case 'C':
                n++; // 유효한 음계라면 n을 증가시켜 'mixed' 상태로 유도
                break;
            default:
                return 10; // 유효하지 않은 문자인 경우 ERROR 반환
            }
        } 
    }
    return n; // 최종 판별 결과값 반환
}
