//Author: Ritoshree Gupta

#include "Car.h"
#include <stdlib.h> 
#include <time.h>
#include <string>




void Car::setquartermiletime(float quartermiletime)
{
	this->quartermiletime = quartermiletime;
}

float Car:: getquartermiletime() {

	return quartermiletime;
}

void Car::setName(string name)
{
	this->name = name;
}

string Car::getName()
{
	return name;
}

Car::Car(string n, string m, string mo, float q, int max)
{
	name = n, make = m, model = mo;
	quartermiletime = q;
	maxspeed = max;
}

Car::~Car()
{
}

string Car::race(Car &car)
{
	int num, num2;
	float adjustment, adjustment2, win_time=0;
	srand(time(NULL));

	num = rand() % 21 + (-10);
	num2 = rand() % 21 + (-10);
	adjustment = float(num) / 10;
	adjustment2 = float(num2) / 10;
	
	
	quartermiletime = quartermiletime + adjustment;
	car.quartermiletime = car.quartermiletime + adjustment2;
	
	if (quartermiletime < car.quartermiletime) {
		win_time = car.quartermiletime - quartermiletime;
		string to_string(float win_time);
		return name + " won by " + to_string(win_time)+"\n";
	}
	else if (quartermiletime > car.quartermiletime) {
		win_time = quartermiletime - car.quartermiletime;
		string to_string(float win_time);
		return car.name + " won by " + to_string(win_time)+"\n";
	}
	else if (quartermiletime == car.quartermiletime) {
		return "TIE! ";
	}
}


ostream & operator<<(ostream & os, const Car & x)
{
	os << "Name: " << x.name << endl << "Make: " << x.make << endl
		<< "Model: " << x.model << endl << "Quarter Mile Time: " << x.quartermiletime << endl
		<< "Maximum Speed: " << x.maxspeed << endl;
	return os;
}

