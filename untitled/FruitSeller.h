#ifndef __FRUIT_SELLER_H__
#define __FRUIT_SELLER_H__
struct SaleResult {
    int numOfApplesBought; //구매한 사과 개수
    int change;
};
class FruitSeller {
private:
    int applePrice;
    int numOfApples;
    int money;
public:
//잔돈
    FruitSeller(); //모든   멤버   변수를   0으로   초기화
    FruitSeller(int price, int num, int money);
//void InitMembers(int price, int num, int money);
    SaleResult SaleApples(int money);
    void ShowSalesResult();
    void ChangePrice(int price);
};
#endif