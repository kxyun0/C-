#include <stdio.h>
#define SIZE 100

int main()
{
    int n;
    int stock[SIZE]; //입고수량
    int sold[SIZE]; //판매수량
    int remain[SIZE]; //재고수량
    int i, ID;

    printf("상품의 종류(갯수)를 입력해주세요: ");
    scanf("%d",&n);

    printf("상품의 입고수량을 입력해주세요: \n");
    for(i=0; i< n; i++){
        scanf("%d", &stock[i]);
    }

    printf("상품의 판매수량을 입력해주세요: \n");
    for(i = 0; i < n; i++){
        scanf("%d", &sold[i]);
    }

    for(i= 0; i < n; i++){
        remain[i] = stock[i] - sold[i];
    }
    
    printf("조회할 상품 ID를 입력해주세요: ");
    scanf("%d", &ID);
    printf("%d\n", remain[ID-1]);

    printf("전체 재고: ");
    for(i = 0; i < n; i++){
        printf("%d", remain[i]);
    }
    printf("\n");

    return 0;
}
