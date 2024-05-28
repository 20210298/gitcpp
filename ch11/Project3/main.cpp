#include <iostream>
#include "BdyChkArray.h"
#include "PointTemplate.h"
using namespace std;
int main() {
	/***int형 자료 저장***/
	BdyChkArray<int> intArr(5);
	for (int idx = 0; idx < 5; idx++)
		intArr[idx] = (idx + 1) * 10;
	intArr.ShowAllData();
	/***Point 객체 저장***/
	BdyChkArray<Point<int>> oArr(3);
	oArr[0] = Point<int>(3, 4);
	oArr[1] = Point<int>(5, 6);
	oArr[2] = Point<int>(8, 9);
	oArr.ShowAllData();
	/***Point 객체의 주소 저장***/
	typedef Point<int>* POINT_PTR;
	BdyChkArray<POINT_PTR> pArr(3);
	pArr[0] = new Point<int>(3, 4);
	pArr[1] = new Point<int>(5, 6);
	pArr[2] = new Point<int>(8, 9);
	for (int idx = 0; idx < 3; idx++) {
		cout << (*pArr[idx]) << endl;
	}
	//메모리 해제
	for (int idx = 0; idx < 3; idx++)
		delete pArr[idx];
	return 0;
}