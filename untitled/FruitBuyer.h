#ifndef __FRUIT_BUYER_H__
#define __FRUIT_BUYER_H__
#include "FruitSeller.h"
class FruitBuyer {
private:
    int money; //�������� myMoney -> money�� ����
    int numOfApples=0;  //�����ڷ� �ʱ�ȭ�ϸ� 0���� �ʱ�ȭ�� �ȵ�
public:
    FruitBuyer();  //���   money��   0������   �ʱ�ȭ
    FruitBuyer(int money); //���   money��   money��   �ʱ�ȭ
//void InitMembers(int money);
    void BuyApples(FruitSeller& seller, int money);
    void ShowBuyResult();
};
#endif