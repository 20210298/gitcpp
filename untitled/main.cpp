#include "FruitBuyer.h"
#include "FruitSeller.h"
#include <iostream>

using namespace std;

int main() {
    FruitSeller seller (1000, 20, 0);    //생성자 사용
//seller.InitMembers(1000, 20, 0);   //삭제
    FruitBuyer buyer (20000);           //생성자 사용
//buyer.InitMembers(20000); //삭제
    seller.ChangePrice(500);   //사과 가격 500원으로 변경
    while (1) {
        int tryBuy;
        cout << "구매를 원하는 금액 입력:";
        cin >> tryBuy;
        if (tryBuy < 0) break;
        buyer.BuyApples(seller, tryBuy);
        cout << "> 과일 판매자의 현황" << endl;
        seller.ShowSalesResult();
        cout << "> 과일 구매자의 현황" << endl;
        buyer.ShowBuyResult();
        cout << endl;
    }
    return 0;
}