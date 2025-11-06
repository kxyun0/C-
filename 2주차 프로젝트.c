#include <stdio.h>
#define SIZE 100

int main() {
    int n;
    int stock[SIZE], sold[SIZE], remain[SIZE];
    int i, ID;

    printf("상품의 종류(갯수)를 입력해주세요: ");
    scanf("%d", &n);

    printf("상품의 입고수량을 입력해주세요: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &stock[i]);
    }

    printf("상품의 판매수량을 입력해주세요: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &sold[i]);
    }

    for (i = 0; i < n; i++) {
        remain[i] = stock[i] - sold[i];
    }

    printf("조회할 상품 ID를 입력해주세요: ");
    scanf("%d", &ID);

    printf("%d\n", remain[ID - 1]);

    printf("재고수량: ");
    for (i = 0; i < n; i++) {
        printf("%d", remain[i]);
    }
    printf("\n");

    int totalSold = 0, totalStock = 0;
    for (i = 0; i < n; i++) {
        totalSold += sold[i];
        totalStock += stock[i];
    }

    double rate = ((double)totalSold / totalStock) * 100;
    printf("총 판매량: %d (판매율 %.2f%%)\n", totalSold, rate);

    int maxID = 1, minID = 1;
    int maxSold = sold[0], minSold = sold[0];
    for (i = 1; i < n; i++) {
        if (sold[i] > maxSold) {
            maxSold = sold[i];
            maxID = i + 1;
        }
        if (sold[i] < minSold) {
            minSold = sold[i];
            minID = i + 1;
        }
    }

    printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", maxID, maxSold);
    printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", minID, minSold);

    for (i = 0; i < n; i++) {
        if (remain[i] <= 2) {
            printf("상품 ID %d : 재고부족(%d)\n", i + 1, remain[i]);
        }
    }

    return 0;
}
