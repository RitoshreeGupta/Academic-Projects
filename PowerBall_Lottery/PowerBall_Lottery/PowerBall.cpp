#include <iostream>
#include <ctime>
#include "PowerBall.h"
#include <stdlib.h>
using namespace std;


int main() {

	int digit, white[5], red, randwhiteNumbers[5], randredNumber, prize, ticketnumbers = 0, options;
	bool isDuplicate;
	char choice = 'y';


	cout << "					WELCOME TO POWERBALL LOTTERY" << endl;
	cout << endl;

	int spend = 0;
	int dlr = 0;



	cout << "Enter how you want to buy a ticket: 1. Pick the numbers 2. Buy a random ticket : " << endl;
	cin >> digit;

	while (choice == 'y') {

		if (digit == 1) {
			cout << "Enter the 6 numbers: There are 5 white numbers from 1-69 and 1 red number from 1-26 : " << endl;
			cout << "Please enter the red number from 1-26 range: ";
			cin >> red;
			while (!redrange(red)) {
				cout << "Please enter the red number again from 1 - 26 range: ";
				cin >> red;
			}
			cout << "Enter the 5 white numbers from 1-69 range: " << endl;
			for (int i = 0; i < 5; i++) {
				cin >> white[i];
				while (!betweenNum(white[i])) {
					cout << "Sorry! This number is out of range. Please enter remaining white numbers from 1-69 range:" << endl;
					cin >> white[i];
				}

			}

			isDuplicate = false;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (i != j && white[i] == white[j]) {
						isDuplicate = true;
					}
				}


			}

			if (isDuplicate == true) {
				cout << "Sorry! Cannot take duplicate numbers. " << endl;
				break;
			}




			srand(time(0));
			randwhiteNumbers[0] = rand() % 69;
			randwhiteNumbers[1] = rand() % 69;
			randwhiteNumbers[2] = rand() % 69;
			randwhiteNumbers[3] = rand() % 69;
			randwhiteNumbers[4] = rand() % 69;
			randredNumber = rand() % 26;


			int count1 = 0, count2 = 0;
			for (int i = 0; i < 5; i++) {
				if (white[i] == randwhiteNumbers[i]) {
					count1++;
				}
			}

			if (red == randredNumber) {
				count2++;
			}

			int count = count1 + count2;


			cout << "Total Winning Ball: " << count << endl;
			cout << "The White Winning Ball:" << count1 << endl;
			cout << "Red Winning Ball: " << count2 << endl;
			cout << "The Random winning red number is: " << randredNumber << endl;
			cout << "The Random winning 5 white numbers are: " << randwhiteNumbers[0] << " " << randwhiteNumbers[1] << " " << randwhiteNumbers[2] << " " << randwhiteNumbers[3] << " " << randwhiteNumbers[4] << endl;


			int prize = 0;


			if (count2 == 1 || count == 2) {
				prize = prize + 4;
			}
			else if (count1 == 3 || count == 3) {
				prize = prize + 7;
			}
			else if (count1 == 4 || count == 4) {
				prize = prize + 100;
			}
			else if (count1 == 4 && count2 == 1) {
				prize = prize + 50000;
			}
			else if (count1 == 5) {
				prize = prize + 100000;
			}

			else if (count1 == 5 && count2 == 1)
			{
				prize = prize + 1000000;
			}
			else
			{
				cout << "Sorry! Better luck next time." << endl;
			}

			cout << "You Won: " << "$" << prize << endl;
			dlr = dlr + prize;

		}


		else if (digit == 2) {

			cout << "How Many tickets you want to buy: " << endl;
			cin >> ticketnumbers;

			cout << "Do you want to see: 1. All tickets or 2.Winning tickets: ";
			cin >> options;

			int countTicket = 0;
			while (countTicket < ticketnumbers) {
				for (int i = 0; i < 5; i++) {
					//srand(time(0));
					white[i] = rand() % 69;
					randwhiteNumbers[i] = rand() % 69;



				}
				randredNumber = rand() % 26;
				red = rand() % 26;


				for (int i = 0; i < 5; i++)
				{
					randwhiteNumbers[i];
				}

				int count1 = 0, count2 = 0;
				for (int i = 0; i < 5; i++) {
					if (white[i] == randwhiteNumbers[i]) {
						if (options == 2) {
							cout << "The Winning 5 white numbers are: " << randwhiteNumbers[i];
						}
						count1++;
					}
				}

				if (red == randredNumber) {
					if (options == 2) {
						cout << "The Winning Red Ball: " << count2 << endl;
					}
					count2++;
				}

				int count = count1 + count2;



				if (options == 1) {
					cout << "The Random winning red number is: " << randredNumber << endl;
					cout << "The Random winning 5 white numbers are: " << randwhiteNumbers[0] << " " << randwhiteNumbers[1] << " " << randwhiteNumbers[2] << " " << randwhiteNumbers[3] << " " << randwhiteNumbers[4] << endl;
					cout << "Total Winning Ball: " << count << endl;
					cout << "The White Winning Ball:" << count1 << endl;
					cout << "Red Winning Ball: " << count2 << endl;
				}

				int prize = 0;


				if (count2 == 1 || count == 2) {
					prize = prize + 4;
				}
				else if (count1 == 3 || count == 3) {
					prize = prize + 7;
				}
				else if (count1 == 4 || count == 4) {
					prize = prize + 100;
				}
				else if (count1 == 4 && count2 == 1) {
					prize = prize + 50000;
				}
				else if (count1 == 5) {
					prize = prize + 100000;
				}

				else if (count1 == 5 && count2 == 1)
				{
					prize = prize + 1000000;
				}
				else
				{
					cout << "Sorry! Better luck next time." << endl;
				}

				cout << "You Won: " << "$" << prize << endl;
				dlr = dlr + prize;


				countTicket++;
			}

		}

		cout << "Do you want to play again: y/n : ";
		cin >> choice;
		spend++;


	}

	if (digit == 2) {
		spend = ticketnumbers * 2;
	}
	else
		spend = spend * 2;
	int loss;

	cout << "Total Spend: $" << spend << endl;

	cout << "Total Won: $" << dlr << endl;
	if (spend > dlr)
		loss = spend - dlr;
	else
		loss = 0;
	cout << "Total loss: $" << loss << endl;




	system("pause");
	return 0;
}