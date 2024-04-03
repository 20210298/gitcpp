#include "FruitSeller.h"
#include <iostream>

using namespace std;

FruitSeller::FruitSeller() : applePrice(0), numOfApples(0), money(0) {}; //���   ���   ������   0����   �ʱ�ȭ
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
    //�ܵ� ó��
    int change=money-(num*this->applePrice);
    return {num,change};
}

void FruitSeller::ShowSalesResult() {
    cout << "���� ��� : " << this->numOfApples << endl;
    cout << "�Ǹ� ���� : " << this->money << endl;
}

void FruitSeller::ChangePrice(int price){
    this->applePrice=price;
}