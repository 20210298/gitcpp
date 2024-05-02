#include <iostream>

using namespace std;

class Animal {
	string species;
public:
	Animal() :species("Unknown") {}
	Animal(string species) :species(species) {}
	void SetSpecies(string species) {
		this->species = species;
	}
	string GetSpecies() {
		return this->species;
	}
};

class Mammal : virtual public Animal {
	int temperature;
public:
	Mammal(int temperature) :temperature(temperature) {}
	void SetTemperature(int temperature) {
		this->temperature = temperature;
	}
	int GetTemperature() const {
		return this->temperature;
	}
	void ShowMammalInfo() {
		cout << "Species: " << GetSpecies() << " , ";
		cout << "Body Temperature: " << GetTemperature() << " degrees Celsius" << endl;
	}
};

class Bird :virtual public Animal {
	int wingspan;
public:
	Bird(int wingspan) :wingspan(wingspan) {}
	void SetWingSpan(int wingspan) {
		this->wingspan = wingspan;
	}
	int GetWingSpan() const {
		return this->wingspan;
	}
	void ShowBirdInfo() {
		cout << "Species: " << GetSpecies() << " , ";
		cout << "Wing Span: " << GetWingSpan() << "cm" << endl;

	}
};

class Bat :public Mammal, public Bird {
public:
	Bat(int temperature, int wingspan) :Mammal(temperature), Bird(wingspan), Animal("Bat") {}
	void ShowBatInfo() {
		ShowMammalInfo();
		ShowBirdInfo();
	}
};

int main() {
	Bat myBat(37, 50);
	myBat.ShowBatInfo();
	return 0;
}