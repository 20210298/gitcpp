#ifndef __FRUIT_SELLER_H__
#define __FRUIT_SELLER_H__
struct SaleResult {
    int numOfApplesBought; //������ ��� ����
    int change;
};
class FruitSeller {
private:
    int applePrice;
    int numOfApples;
    int money;
public:
//�ܵ�
    FruitSeller(); //���   ���   ������   0����   �ʱ�ȭ
    FruitSeller(int price, int num, int money);
//void InitMembers(int price, int num, int money);
    SaleResult SaleApples(int money);
    void ShowSalesResult();
    void ChangePrice(int price);
};
#endif