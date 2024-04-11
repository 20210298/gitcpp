#include <iostream>

using namespace std;

class Car {
	int gasGauge;
public:
	Car(int gasGauge) : gasGauge(gasGauge) {
		cout << "Car(int)" << endl;
	}
	int GetGasGauge() {
		return gasGauge;
	}
	~Car() {
		cout << "~Car()" << endl;
	}
};

class HybridCar:public Car {
	int elecGauge;
public:
	HybridCar(int gasGauge, int elecGauge) : Car(gasGauge), elecGauge(elecGauge) {
		cout << "HybridCar(int, int)" << endl;
	}
	int GetElecGauge(){
		return elecGauge;
	}
	~HybridCar() {
		cout << "~HybridCar()" << endl;
	}
};

class HybridWaterCar:public HybridCar {
	int waterGauge;
public:
	HybridWaterCar(int gasGauge, int elecGauge, int waterGauge) : HybridCar(gasGauge, elecGauge), waterGauge(waterGauge) {
		cout << "HybridWaterCar(int, int, int)" << endl;
	}
	int GetWaterGauge() {
		return waterGauge;
	};
	void ShowCurrentGauge() {
		cout << "ÀÜ¿© °¡¼Ö¸°: " << GetGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·®: " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·®: " << GetWaterGauge() << endl;
	}
	~HybridWaterCar() {
		cout << "~HybridWaterCar()" << endl;
	}
};

int main() {
	HybridWaterCar wCar(75, 65, 35);
	wCar.ShowCurrentGauge();
	return 0;
}