#include <iostream>

using namespace std;

class Point {
private:
	int xpos, ypos;

public:
	void ShowPoint()const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	/*
	Point Add(const Point& p) {
		Point temp(xpos + p.xpos, ypos + p.ypos);
		return temp;
	}
	Point operator+(const Point& p) {
		Point pos(xpos + p.xpos, ypos + p.ypos);
		return pos;
	};
	Point operator+(const int n) {
		Point pos(xpos + n, ypos + n);
		return pos;
	};
	Point operator-(const Point& p) {
		Point pos(xpos - p.xpos, ypos - p.ypos);
		return pos;
	}*/
	Point& operator++() {
		xpos++;
		ypos++;
		return	*this;
	}
	const Point operator++(int) {
		const Point tmpObj(xpos, ypos);
		xpos += 1;
		ypos += 1;
		return tmpObj;
	}


	friend Point operator+(const Point& a, const Point& b);
	friend Point operator-(const Point& a, const Point& b);
	friend Point operator+(const Point& a, const  int n);
	friend Point& operator--(Point& a);
	friend const Point operator--(Point& a, int);
	friend ostream& operator<<(ostream& os, const Point& pos);
	friend istream& operator>>(istream& is, Point& pos);
};

Point operator+(const Point& a, const Point& b) {
	Point pos(a.xpos + b.xpos, a.ypos + b.ypos);
	return pos;
}
Point operator+(const Point& a, const  int n) {
	Point pos(a.xpos + n, a.ypos + n);
	return pos;
}
Point operator-(const Point& a, const Point& b) {
	Point pos(a.xpos - b.xpos, a.ypos - b.ypos);
	return pos;
}

Point& operator--(Point& a) {
	a.xpos--;
	a.ypos--;
	return a;
}

const Point operator--(Point& a, int) {
	const Point tmpObj(a.xpos, a.ypos);
	a.xpos -= 1;
	a.ypos -= 1;
	return tmpObj;
}

ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

istream& operator>>(istream& is, Point& pos) {
	is >> pos.xpos >> pos.ypos;
	return is;
}



int main() {
	Point pos1;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos1;
	cout << pos1;
	Point pos2;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos2;
	cout << pos2;
	Point pos3 = pos1 + pos2;
	cout << pos3;

	return	0;
}