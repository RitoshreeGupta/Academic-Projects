/*
Purpose: A Project to grade several multiple-choice exams.
Author: Ritoshree Gupta
Creation Date: March 04, 2019
Modification Date: March 10, 2019
*/
#include <stdio.h>
#include <cassert>
#include <iostream>
#include<string>
using namespace std;
bool check_id(string);
float calculate_score(string, string);


/*
Purpose: Set the range of the score and calculate the statistics
Author: Ritoshree Gupta
Creation Date: March 04, 2019
Modification Date: March 10, 2019
Input: number_of_students, students_id[counter], students_answer[counter]
Output: Students_score, Grade, Average score, Minimum score, Maximum Score
Precondition: Average score, minimum, maximum are float and positive
Postcondition: Returns a postive value
Keyword: Students Score, Grade, Statistics
*/


int main()
{
	float average, max = FLT_MIN, min = FLT_MAX, sum = 0;
	int number_of_students;
	cout << "Please enter the number of students to be graded: ";
	cin >> number_of_students;
	int no = int(number_of_students);
	string* students_id = new string[no];
	string* students_answer = new string[no]; // it contains the answer keys of the students
	float* students_score = new float[no];
	string exam_key = "abcdefabcdefabcdefab";
	
	int counter = 0;
	
	cout << "For each of the following students, enter the Student ID and answers: " << endl;
	
	while (counter < number_of_students)
	{
		cout << "Student " << counter + 1 << ": ";
		cin >> students_id[counter] >> students_answer[counter];
		

		if (check_id(students_id[counter]) == true)
		{
			students_score[counter] = calculate_score(students_answer[counter], exam_key);
			sum = sum + students_score[counter];

				if (students_score[counter] < min)
				min = students_score[counter];
				if (students_score[counter] > max)
				max = students_score[counter];
			
				if (students_score[counter] >= 90)
				{
					cout << "Score: " << students_score[counter] << "% " << 'A';
				}
				else if (students_score[counter] >= 80)
				{
					cout << "Score: " << students_score[counter] << "% " << 'B';
				}
				else if (students_score[counter] >= 70)
				{
					cout << "Score: " << students_score[counter] << "% " << 'C';
				}
				else if (students_score[counter] >= 60)
				{
					cout << "Score: " << students_score[counter] << "% " << 'D';
				}
				else if (students_score[counter] >= 50)
				{
					cout << "Score: " << students_score[counter] << "% " << 'E';
				}
				else
					cout << "Score: " << students_score[counter] << "% " << 'F';

		}

		else {
			cout << "ERROR in the Student ID number. Please re-enter Student information: \n";
			continue;
		}
		
		
		cout << endl;
		counter++;

	}

	cout << "Statistics: " << endl;
	average = sum / number_of_students;
	cout << "Average Score: " << average << "%" << endl;
	cout << "Minimum Score: " << min << "%" << endl;
	cout << "Maximum Score: " << max << "%" << endl;

	system("pause");
	return 0;
}

    /*
	Purpose: Set the length of the students ID
	Author : Ritoshree Gupta
	Creation Date : March 04, 2019
	Modification Date : March 10, 2019
	Input : students_id[counter]
	Output : true or false
	Precondition : Takes the input string id and checks the ID lenghth
	Postcondition : ID length is not equal 7 then return false and ask again for correct id number.
	Keyword : bool, id.length
	*/


 bool check_id(string id) {
	if (id.length() == 7)
	{
		return true;
	}
	else {
		return false;
	}
}

   /*
   Purpose: Check the student answer length, calculates the score and percentage of a string and returns a float percentage in the main function by calling sequence.
   Author : Ritoshree Gupta
   Creation Date : March 04, 2019
   Modification Date : March 10, 2019
   Input : Students_answer, exam_key, percentage
   Output : students_score, percentage
   Precondition : String students_answer and string exam_key is a positive float percentage. Calculate_score function return the score to the main function.
   Postcondition : answer length is 20. After 20, the extra answers doesn't count.
   Keyword : loop_counter, percentage
   */

float calculate_score(string answer, string key) {

	int no_of_correct_answers = 0, loop_counter;
	float percentage;

	if (answer.length() < 20) {
		loop_counter = answer.length();
	}
	else {
		loop_counter = 20;
	}

	for (int j = 0; j < loop_counter; j++) { // j represents the question number we are grading 
		if (answer[j] == key[j])
			no_of_correct_answers++;
	}
	percentage = float ((no_of_correct_answers * 100) / 20);
	assert(percentage >= 0);
	return percentage;
}

