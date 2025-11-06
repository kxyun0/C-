#include <stdio.h>
#include <string.h>
#define SIZE 5

int main() {
    int stock[SIZE] = {0}, sold[SIZE] = {0};
    int price[SIZE] = {0}, totalSales[SIZE] = {0};
    char names[SIZE][50] = {0};
    int menu, id, amount;
    int i;

    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("원하는 메뉴를 선택하세요. (1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료)\n> ");
        if (scanf("%d", &menu) != 1) {
            while (getchar() != '\n');
            printf("잘못된 입력입니다.\n");
            continue;
        }

        if (menu == 1) {
            printf("입고 메뉴 실행 (상품 개수 최대 5개)\n");
            printf("상품 ID를 입력하세요 (1~5): ");
            scanf("%d", &id);

            if (id < 1 || id > SIZE) {
                printf("상품 개수를 초과했습니다.\n");
                continue;
            }

            printf("상품명: ");
            scanf("%s", names[id - 1]);
            printf("입고수량: ");
            scanf("%d", &amount);
            printf("판매가격: ");
            scanf("%d", &price[id - 1]);

            stock[id - 1] += amount;
            printf("상품이 등록 또는 업데이트되었습니다.\n");
        }

        else if (menu == 2) {
            printf("판매 메뉴 실행\n");
            printf("상품 ID를 입력하세요 (1~5): ");
            scanf("%d", &id);

            if (id < 1 || id > SIZE || strlen(names[id - 1]) == 0) {
                printf("해당 상품이 존재하지 않습니다.\n");
                continue;
            }

            printf("판매수량: ");
            scanf("%d", &amount);

            if (amount > stock[id - 1] - sold[id - 1]) {
                printf("재고가 부족합니다. 현재 재고: %d\n", stock[id - 1] - sold[id - 1]);
                continue;
            }

            sold[id - 1] += amount;
            totalSales[id - 1] = sold[id - 1] * price[id - 1];
            printf("판매가 완료되었습니다.\n");
        }

        else if (menu == 3) {
            printf("상품 ID를 입력하세요: ");
            scanf("%d", &id);

            if (id < 1 || id > SIZE || strlen(names[id - 1]) == 0) {
                printf("해당 상품이 존재하지 않습니다.\n");
                continue;
            }

            printf("\n[개별 상품 현황]\n");
            printf("상품 ID: %d\n", id);
            printf("상품명: %s\n", names[id - 1]);
            printf("상품가격: %d\n", price[id - 1]);
            printf("입고량: %d\n", stock[id - 1]);
            printf("판매량: %d\n", sold[id - 1]);
            printf("총 판매금액: %d\n", totalSales[id - 1]);
        }

        else if (menu == 4) {
            int totalStock = 0, totalSold = 0, totalAmount = 0;
            printf("\n[전체 상품 현황]\n");

            for (i = 0; i < SIZE; i++) {
                if (strlen(names[i]) == 0) continue;
                int remain = stock[i] - sold[i];
                totalStock += stock[i];
                totalSold += sold[i];
                totalAmount += totalSales[i];
                printf("ID %d | 상품명: %s | 가격: %d | 입고: %d | 판매: %d | 재고: %d | 총판매금액: %d\n",
                       i + 1, names[i], price[i], stock[i], sold[i], remain, totalSales[i]);
            }

            printf("\n총 입고량: %d\n총 판매량: %d\n총 판매금액 합계: %d\n", totalStock, totalSold, totalAmount);
        }

        else if (menu == 5) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        else {
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}
