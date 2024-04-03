#ifndef __FRUIT_BUYER_H__
#define __FRUIT_BUYER_H__
#include "FruitSeller.h"
class FruitBuyer {
private:
    int money; //변수명을 myMoney -> money로 변경
    int numOfApples=0;  //생성자로 초기화하면 0으로 초기화가 안됨
public:
    FruitBuyer();  //멤버   money를   0원으로   초기화
    FruitBuyer(int money); //멤버   money를   money로   초기화
//void InitMembers(int money);
    void BuyApples(FruitSeller& seller, int money);
    void ShowBuyResult();
};
#endif