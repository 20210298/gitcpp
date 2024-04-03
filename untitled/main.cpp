#include "FruitBuyer.h"
#include "FruitSeller.h"
#include <iostream>

using namespace std;

int main() {
    FruitSeller seller (1000, 20, 0);    //������ ���
//seller.InitMembers(1000, 20, 0);   //����
    FruitBuyer buyer (20000);           //������ ���
//buyer.InitMembers(20000); //����
    seller.ChangePrice(500);   //��� ���� 500������ ����
    while (1) {
        int tryBuy;
        cout << "���Ÿ� ���ϴ� �ݾ� �Է�:";
        cin >> tryBuy;
        if (tryBuy < 0) break;
        buyer.BuyApples(seller, tryBuy);
        cout << "> ���� �Ǹ����� ��Ȳ" << endl;
        seller.ShowSalesResult();
        cout << "> ���� �������� ��Ȳ" << endl;
        buyer.ShowBuyResult();
        cout << endl;
    }
    return 0;
}