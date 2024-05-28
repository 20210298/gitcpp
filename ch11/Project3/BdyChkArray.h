#ifndef __BDY_CHK_ARRAY_H__
#define __BDY_CHK_ARRAY_H__
#include <iostream>
using namespace std;
template <typename T>
class BdyChkArray {
private:
	T* arr;
	int arrLen;
	//복사생성자
	BdyChkArray(const BdyChkArray& arr) {}
	//대입연산자
	BdyChkArray& operator=(const BdyChkArray& arr) {}
public:
	BdyChkArray(int len) :arrLen(len) {
		arr = new T[len];
	}
	T& operator[](int idx) {
		if (idx < 0 || idx >= arrLen) {
			//error
			exit(1);
		}
		return arr[idx];
	}
	T operator[](int idx) const {
		if (idx < 0 || idx >= arrLen) {
			//error
			exit(1);
		}
		return arr[idx];
	}
	int GetLength() const {
		return arrLen;
	}
	void ShowAllData() const {
		for (int i = 0; i < arrLen; i++) {
			cout << arr[i] << endl;
		}
		return;
	}
	~BdyChkArray() {
		delete[] arr;
	}
};
#endif