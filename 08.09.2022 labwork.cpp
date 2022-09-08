#include <iostream>
using namespace std;

class Car {
	char* model;
	char* country;
	double price;
	static int count;   

public:
	Car();
	Car(const char* m, const char* c, double p);
	~Car();
	void Input();
	void Print();
	const char* GetModel();
	void SetModel(const char* m);

	static int GetCount();
};

int Car::count = 0;

Car::Car() {
	model = nullptr;
	country = nullptr;
	price = 0;
}

Car::Car(const char* m, const char* c, double p) {
	model = new char[strlen(m) + 1];
	strcpy_s(model, strlen(m) + 1, m);

	country = new char[strlen(c) + 1];
	strcpy_s(country, strlen(c) + 1, c);

	price = p;
}

void Car::SetModel(const char* m) {
	m = "Porsche";
	model = new char[strlen(m) + 1];
	strcpy_s(model, strlen(m) + 1, m);
}
const char* Car::GetModel() {
	return model;
}

Car::~Car() {
	delete[] model;
	delete[] country;
	count--;
}

void Car::Input() {
	cin.ignore();
	cout << "\nEnter country: ";
	char buf[20];
	cin.getline(buf, 20);
	if (country != nullptr) {
		delete[]country;
	}
	country = new char[strlen(buf) + 1];
	strcpy_s(country, strlen(buf) + 1, buf);

	cout << "Enter price of car: ";
	cin >> price;
}

void Car::Print() {
	cout << "\nCountry: " << country << endl;
	cout << "Price: " << price << endl;
}

int Car::GetCount() {
	count++;
	return 0;
}

int main() {
	Car type;


	int count;
	cin >> count;
	Car* shop = new Car[count];
	for (int i = 0; i < count; i++) {
		shop[i].Input();
		type.GetCount();
	}
	type.SetModel("Porsche");
	for (int i = 0; i < count; i++) {
		shop[i].Print();
		cout << "Model: " << type.GetModel() << endl;
	}
	delete[] shop;
	

	cout << "\nCount: " << count << endl;

}
