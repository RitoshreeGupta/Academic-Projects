//Author: Ritoshree Gupta

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
	string name;
	string make;
	string model;
	float quartermiletime;
	int maxspeed;

public:


	
	void setquartermiletime(float quartermiletime);

	float getquartermiletime();

	void setName(string name);

	string getName();

	Car(string n, string m, string mo, float q, int max);

	~Car();
	
	friend ostream& operator<<(ostream& os, const Car& x);

	string race(Car &car);
	

};



