#include <iostream>

using namespace std;

template <typename T>
class SmartPtr {
private:
	T* posPtr;
public:
	SmartPtr(T* ptr)
		:posPtr(ptr) {}
	~SmartPtr() {
		delete posPtr;
	}
	T* operator->() const {
		return posPtr;
	}
	T& operator*() const {
		return *posPtr;
	}
};

template <typename T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y) {}
	void ShowPoint() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

int main() {
	SmartPtr<Point<int>> sPtr1(new Point<int>(1, 2));
	SmartPtr<Point<double>> sPtr2(new Point<double>(3.2, 4.5));
	sPtr1->ShowPoint();
	sPtr2->ShowPoint();
	return 0;
}

