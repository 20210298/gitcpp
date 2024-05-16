#include <iostream>

using namespace std;

class Point {
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) :x(x), y(y) {}

	friend ostream& operator<<(ostream& os, const Point& a);
};

ostream& operator<<(ostream& os, const Point& a) {
	os << "[" << a.x << ", " << a.y << "]" << endl;
	return os;
}

class BdyChkPointArray {
	int arrLen;
	Point* arr;
public:
	BdyChkPointArray(int len) :arrLen(len) {
		arr = new Point[len];
	}

	Point& operator[](int idx) const {
		if (idx < 0 || idx >= arrLen) {
			cout << "Out of range!" << endl;
			exit(1);
		}
		return arr[idx];
	}

	int GetArrLen() const {
		return arrLen;
	}

	~BdyChkPointArray() {
		delete[] arr;
	}

};

//class BdyChkIntArray {
//	int arrLen;
//	int* arr;
//public:
//	BdyChkIntArray(int len) :arrLen(len) {
//		arr = new int[len];
//	}
//
//	int& operator[](int idx) const {
//		if (idx < 0 || idx >= arrLen) {
//			cout << "Out of range!" << endl;
//			exit(1);
//		}
//		return arr[idx];
//	}
//
//	int GetArrLen() const {
//		return arrLen;
//	}
//
//	~BdyChkIntArray() {
//		delete[] arr;
//	}
//};

void ShowAllData(const BdyChkPointArray& ref) {
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
		cout << ref[idx];
}

int main() {
	BdyChkPointArray arrObj(3); //크기가 3인 배열 생성
	arrObj[0] = Point(3, 4);
	arrObj[1] = Point(2, 7);
	arrObj[2] = Point(6, 2);
	ShowAllData(arrObj);
	return 0;
}


