#include <stdio.h>

int main(void) {
    int price, shipping_fee;
    char location;

    printf("제품의 가격을 입력하세요: ");
    scanf("%d", &price);

    printf("배송지의 지역을 입력하세요 (A, B): ");
    scanf(" %c", &location);

    if (location == 'A') {
        if (price < 50000)
            shipping_fee = 5000;
        else
            shipping_fee = 0;
    }
    else if (location == 'B') {
        if (price < 30000)
            shipping_fee = 3000;
        else
            shipping_fee = 0;
    }
    else {
        printf("유효하지 않은 지역 코드입니다. A, B 중 하나를 입력하세요.\n");
        return 1;
    }

    printf("해당 주문의 배송비는 %d원입니다.\n", shipping_fee);
    return 0;
}
