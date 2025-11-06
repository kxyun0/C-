#include <stdio.h>
#define SIZE 100

int main() {
    int stock[SIZE] = {0}, sold[SIZE] = {0}, remain[SIZE] = {0};
    char names[SIZE][50] = {0};
    int n = 5;
    int i, menu, choice, id, amount;

    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("원하는 메뉴를 선택하세요. (1. 입고, 2. 판매, 3. 상품현황, 4. 상품명 입력, 5. 종료)\n> ");
        if (scanf("%d", &menu) != 1) {
            while (getchar() != '\n');
            printf("잘못된 입력입니다. 다시 선택해주세요.\n");
            continue;
        }

        if (menu == 1) {
            printf("입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택하세요.\n> ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("전체 상품 입고수량을 입력하세요:\n");
                for (i = 0; i < n; i++) {
                    scanf("%d", &amount);
                    stock[i] += amount;
                    remain[i] = stock[i] - sold[i];
                }
            } else if (choice == 2) {
                printf("상품 ID를 입력하세요: ");
                scanf("%d", &id);
                printf("입고수량을 입력하세요: ");
                scanf("%d", &amount);
                stock[id - 1] += amount;
                remain[id - 1] = stock[id - 1] - sold[id - 1];
            } else {
                printf("잘못된 선택입니다.\n");
            }
        }

        else if (menu == 2) {
            printf("판매수량 입력: 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택하세요.\n> ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("전체 상품 판매수량을 입력하세요:\n");
                for (i = 0; i < n; i++) {
                    scanf("%d", &amount);
                    sold[i] += amount;
                    remain[i] = stock[i] - sold[i];
                }
            } else if (choice == 2) {
                printf("상품 ID를 입력하세요: ");
                scanf("%d", &id);
                printf("판매수량을 입력하세요: ");
                scanf("%d", &amount);
                sold[id - 1] += amount;
                remain[id - 1] = stock[id - 1] - sold[id - 1];
            } else {
                printf("잘못된 선택입니다.\n");
            }
        }

        else if (menu == 3) {
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

            double rate = totalStock == 0 ? 0 : ((double)totalSold / totalStock) * 100;
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

            printf("가장 많이 판매된 상품: ID %d, 상품명: %s, 판매량 %d\n", maxID, names[maxID - 1], maxSold);
            printf("가장 적게 판매된 상품: ID %d, 상품명: %s, 판매량 %d\n", minID, names[minID - 1], minSold);

            for (i = 0; i < n; i++) {
                if (remain[i] <= 2) {
                    printf("상품 ID %d, 상품명: %s : 재고부족(%d)\n", i + 1, names[i], remain[i]);
                }
            }
        }

        else if (menu == 4) {
            printf("상품명을 입력하세요.\n");
            for (i = 0; i < n; i++) {
                printf("ID %d 상품명: ", i + 1);
                scanf("%s", names[i]);
            }
        }

        else if (menu == 5) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        else {
            printf("잘못된 입력입니다. 다시 선택해주세요.\n");
        }
    }

    return 0;
}
