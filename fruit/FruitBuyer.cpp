#include "FruitBuyer.h"
#include "FruitSeller.h"
#include <iostream>

using namespace std;

FruitBuyer::FruitBuyer() : money(0), numOfApples(0) {}; //멤버   money를   0원으로   초기화
FruitBuyer::FruitBuyer(int money) {
    this->money = money;
} //멤버   money를   money로   초기화
//void InitMembers(int money);
void FruitBuyer::BuyApples(FruitSeller &seller, int money) {
    SaleResult result = seller.SaleApples(money);
    this->numOfApples +=result.numOfApplesBought;
    this->money -= (money - result.change); //money는 buyer의 money임
}

void FruitBuyer::ShowBuyResult() {
    cout << "현재 잔액 : " << this->money << endl;
    cout << "보유 사과 : " << this->numOfApples << endl;
}
