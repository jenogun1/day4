#include <stdio.h>

// 집합의 상태(S)와 입력 순서(order)를 관리하는 전역 변수
int S[21] = {0}; 
int order[21] = {0}; 
int order_count = 0; 

// 현재 집합의 원소들을 입력된 순서대로 출력하는 함수
void print_set() {
    printf("set : { ");
    for (int count = 1; count <= order_count; count++) {
        for (int i = 1; i <= 20; i++) {
            // 원소가 존재하고 해당 순서가 일치할 경우 출력
            if (S[i] == 1 && order[i] == count) {
                printf("%d, ", i);
            }
        }
    }
    printf("}\n\n");
}

int main() {
    char cmd[10];
    int n;
    // 프로그램 운영 안내 문구 출력
    printf("Please select the operation. (1 <= x <= 20)\nadd X\nremove X\ncheck X\ntoggle X\nall 0\nempty 0\n\n");
    
    // 무한 루프를 통해 명령어 반복 입력 처리
    while (1) {
        printf("input : ");
        // 명령어와 숫자를 입력받음
        if (scanf("%s %d", cmd, &n) != 2) break;
        // 명령어 첫 글자로 분기 처리
        if (cmd[0] == 'a') {
            if (cmd[1] == 'd') { // add X: 원소 추가
                if (S[n] == 0) {
                    S[n] = 1;
                    order[n] = ++order_count; // 원소 추가 시 순서 기록
                }
            } else { // all 0: 모든 원소 추가
                order_count = 0;
                for(int i = 1; i <= 20; i++) {
                    S[i] = 1;
                    order[i] = ++order_count; // 1부터 20까지 순차적 순서 부여
                }
            }
        } 
        else if (cmd[0] == 'r') { // remove X: 원소 제거
            S[n] = 0;
            order[n] = 0; // 제거된 원소의 순서 기록 초기화
        }
        else if (cmd[0] == 'c') { // check X: 원소 포함 여부 출력

            printf("%d ", S[n]);
        }
        else if (cmd[0] == 't') { // toggle X: 존재하면 제거, 없으면 추가
            if (S[n] == 1) {
                S[n] = 0;
                order[n] = 0;
            } else {
                S[n] = 1;
                order[n] = ++order_count;
            }
        }
        else if (cmd[0] == 'e') { // empty 0: 전체 집합 초기화
            for(int i = 1; i <= 20; i++) {
                S[i] = 0;
                order[i] = 0;
            }
            order_count = 0; // 순서 기록 카운트 초기화
        }
        
        // 매 명령 수행 후 집합 상태 출력
        print_set();
    }
    return 0;
}