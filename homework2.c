#include<stdio.h>

int main(){
    int numer[8] = {0,}; // 정렬할 8개의 숫자를 담을 배열
    int max = 0;         // 현재 구간에서의 최댓값을 저장할 변수
    int a = 0;           // 최댓값이 위치한 인덱스를 저장할 변수
    int n;               // 값을 교환할 때 사용하는 임시 변수
    int er = 1;          // 정렬 상태를 체크하는 플래그
    
    printf("input\n");
    // 8개의 숫자 입력 받기
    for(int i = 0; i < 8; i++){
        printf("%d : ", i);
        scanf("%d", &numer[i]);
    }
    
    max = numer[7]; // 초기 최댓값을 배열의 마지막 요소로 설정
    
    // 선택 정렬 알고리즘 수행 (뒤에서부터 정렬)
    for(int i = 7; i > 0; i--){
        // 현재 구간(0 ~ i)에서 최댓값과 그 인덱스(a)를 찾음
        for(int l = 0; l < i; l++){
            if(max <= numer[l]){
                max = numer[l];
                a = l;
                er++;
            }
        }
        
        // 최댓값을 찾았다면 교환 과정 수행
        if(er != 0){
            // 현재 배열 상태 출력
            for(int l = 0; l < 8; l++){
                printf(" %2d", numer[l]);
            }
            // 최댓값과 현재 위치(i)의 값을 교환
            n = numer[i];
            numer[i] = max;
            numer[a] = n;
            printf("\n");
            er = 0; // 플래그 초기화
        }
        max = numer[i - 1]; // 다음 루프를 위해 최댓값 재설정
    }
    
    // 최종 정렬된 배열 출력
    for(int l = 0; l < 8; l++){
        printf(" %2d", numer[l]);
    }
    printf("\n");
    
    // 인덱스와 함께 최종 결과 출력
    for(int i = 0; i < 8; i++){
        printf("%d : %2d\n", i, numer[i]);
    }
}
