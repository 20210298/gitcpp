#include "FruitSeller.h"
#include <iostream>

using namespace std;

FruitSeller::FruitSeller() : applePrice(0), numOfApples(0), money(0) {}; //모든   멤버   변수를   0으로   초기화
FruitSeller::FruitSeller(int price, int num, int money) {
    this->applePrice = price;
    this->numOfApples = num;
    this->money = money;
}

//void InitMembers(int price, int num, int money);
SaleResult FruitSeller::SaleApples(int money){
    int num = money/this->applePrice;
    if(num>this->numOfApples){
        num=this->numOfApples;
    }
    this->numOfApples-=num;
    //잔돈 처리
    int change=money-(num*this->applePrice);
    return {num,change};
}

void FruitSeller::ShowSalesResult() {
    cout << "남은 사과 : " << this->numOfApples << endl;
    cout << "판매 수익 : " << this->money << endl;
}

void FruitSeller::ChangePrice(int price){
    this->applePrice=price;
}