#include <stdio.h>

int main() {
    int n;
    int found = 0; // 조건을 만족하는 경우가 있는지 확인하는 변수 (있으면 1로 바꿀 거임!)

    // 정수 N 입력받기
    scanf("%d", &n);

    // 삼중 for문 시작! i는 A상품, j는 B상품, k는 C상품 개수
    // 최소 한 개 이상 사야 하니까 다 1부터 시작함
    for (int i = 1; i * 900 < n; i++) {
        for (int j = 1; i * 900 + j * 750 < n; j++) {
            for (int k = 1; i * 900 + j * 750 + k * 200 <= n; k++) {
                
                // 1. 잔돈이 남지 않아야 함 (금액 합계가 N이랑 딱 맞아야 함)
                if (i * 900 + j * 750 + k * 200 == n) {
                    
                    // 2. B상품(j)은 항상 짝수 개여야 함
                    if (j % 2 == 0) {
                        
                        // 3. C상품 수량(k)은 A(i)보다 작거나 B(j)보다 작아야 함
                        if (k < i || k < j) {
                            // 모든 조건을 다 통과했다면 출력!
                            printf("%d %d %d\n", i, j, k);
                            found = 1; // 하나라도 찾았으니까 found를 1로 변경
                        }
                    }
                }
            }
        }
    }

    // 반복문 다 돌았는데 하나도 못 찾았으면 none 출력
    if (found == 0) {
        printf("none\n");
    }

    return 0;
}
