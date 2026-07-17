#include<stdio.h>

int main(){
    int N = 0;           // 수열의 길이
    int n = 0;           // 부분 수열의 합을 저장할 변수
    int B = 0;           // 타겟 중앙값
    int S[10000] = {0,}; // 수열을 저장할 배열
    int in = 0;          // 부분 수열 내에 B가 포함되어 있는지 확인하는 플래그
    int count = 0;       // 조건을 만족하는 부분 수열의 개수

    printf("N : ");
    scanf("%d", &N);
    printf("B : ");
    scanf("%d", &B);
    printf("\n");

    // 입력 범위 예외 처리
    if(N > 10000 || N <= 0){
        printf("error : 0<N<=10000");
        return 0;
    }
    else if(N < B){
        printf("error : B is bigger than N");
    }

    // 수열 입력 받기
    for(int i = 0; i < N; i++){
        scanf("%d", &S[i]);
    }

    // 수열 값 범위 유효성 검사
    for(int i = 0; i < N; i++){
       if(S[i] > N){
        printf("error : Sequence values range from 1 to N");
        return 0;
       }
    }

    // 부분 수열 탐색 (길이가 3, 5, 7... 인 홀수 길이 부분 수열 대상)
    for(int i = 2; i < N; i = i + 2){
        for(int l = 0; l < N - i; l++){
            // 부분 수열의 합 구하기 및 B 포함 여부 확인
            for(int k = l; k <= l + i; k++){
                if(S[k] == B){
                    in = 1;
                }
                n = n + S[k];
            }
            // 평균값이 B와 같고 B가 포함된 경우 count 증가
            if(n / (i + 1) == B && in == 1){
                count++;
            }
            n = 0;  // 합계 초기화
            in = 0; // 플래그 초기화
        }
    }
    
    // 최종 결과 출력
    printf("Number of fractional sequences with median value of %d : %d", B, count + 1);
}
