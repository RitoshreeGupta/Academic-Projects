//Author: Ritoshree Gupta
//References: 
//https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=vs-2019
//https://stackoverflow.com/questions/7887941/random-number-from-9-to-9-in-c
//http://www.cplusplus.com/reference/string/to_string/
//https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Car.h"
using namespace std;

int main() {

	int wallet = 100, car_num, bet = 1;
	char playagn = 'Y';
	while (wallet > 0) {

		char pass = 'N', valid = 'N';
		string name, make, model;
		float quartermiletime, maxspeed;

		cout << setw(65) << "Welcome Race Fans!" << endl;

		cout << "Please Enter The Car Details: " << endl;
		
			cout << "CAR 1: " << endl;
			cout << "Name: ";
			cin >> name;
			cout << "Make: ";
			cin >> make;
			cout << "Model: ";
			cin >> model;
			cout << "Quarter Mile Time: ";
			cin >> quartermiletime;
			cout << "Maximum Speed Limit: ";
			cin >> maxspeed;

			Car car1(name, make, model, quartermiletime, maxspeed);
			cout << "Details For Car 1: " << endl;
			cout << car1;
			
			car1.setName(name);
			car1.setquartermiletime(quartermiletime);

			cout << "CAR 2: " << endl;
			cout << "Name: ";
			cin >> name;
			cout << "Make: ";
			cin >> make;
			cout << "Model: ";
			cin >> model;
			cout << "Quarter Mile Time: ";
			cin >> quartermiletime;
			cout << "Maximum Speed Limit: ";
			cin >> maxspeed;

		Car car2(name, make, model, quartermiletime, maxspeed);
		cout << "Details For Car 2: " << endl;
		cout << car2;

		car2.setName(name);
		car2.setquartermiletime(quartermiletime);

		while (pass != 'Y' && playagn == 'Y') {
			string win_result = "";
			int found = -2;
			cout << "Please select the car which will win the race: (1. Car1 2. Car2)" << endl;
			cin >> car_num;
			if (car_num == 1 || car_num == 2) {
				pass = 'Y';

				while (valid != 'Y') {

					cout << "Please select the amount you want to bet: " << endl;
					cin >> bet;
					if (bet <= 0 || bet > wallet) {
						cout << "Please enter a valid amount" << endl;
					}
					else {
						valid = 'Y';
					}
				}
				win_result = car1.race(car2);
				cout << win_result;

				if (win_result == "TIE! ") {
					cout << "Your Current Balance is: " << wallet << endl;
					continue;
				}

					if (car_num == 1) {

						if ((win_result.find(car1.getName()) != std::string::npos)) {
							wallet = wallet + bet;
							cout << "Current Wallet: " << wallet << endl;
						}

						else {
							wallet = wallet - bet;
							cout << "Sorry! You Lost. Current Wallet: " << wallet << endl;
						}

					}

					else if (car_num == 2) {

						if ((win_result.find(car2.getName()) != std::string::npos)) {
							wallet = wallet + bet;
							cout << "Current Wallet: " << wallet << endl;
						}
						else {
							wallet = wallet - bet;
							cout << "Sorry! You Lost. Current Wallet: " << wallet << endl;
						}
				}

			}

		}

			cout << "PLAY ANOTHER ROUND? Y/N " << endl;
			cin >> playagn;

			if (wallet <= 0 || playagn == 'N') {
				if (wallet <= 0) {
					cout << "Sorry! Run out of money" << endl;
					playagn = 'N';
				}
				break;
			}
	}

	system("pause");
	return 0;
}
