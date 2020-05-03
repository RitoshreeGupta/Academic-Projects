/*
Author: Ritoshree Gupta
Creation Date: 09/17/2019
Modification Date: 09/29/2019
Purpose: From the input file, separate the words into equivalence classes and list the classes that have
         the greatest number of members in lexicographical order.
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Function Prototypes
bool AnagramOrNot(string word1, string word2);
bool ZeroExistence(vector <int> FlagVector);
bool compareWords(const vector<string> &word1, const vector<string> &word2);
void SortbyClasses();
void Print(int numberofclasses);

//Initializing a two dimensional vector which will have the all the words with anagram groups.
vector< vector<string> > ClassesofAnagram;
//Initializing a vector which will store the words from inputfile
vector<string> inputstringwords;


/*
Pre-Condition: This main function will read the input file, display that file, find the anagram (by call the anagram
               function) from inputfile, store anagrams of each word in the vector and and store that vector in 
			   2D vector as a groups of anagram, call the sorted class method and lastly print the 2D vector 
			   by calling print method
Post_Condition: Find anagrams successfully and print all the sorted anagram classes by decreasing size
			    (by calling all the functions)
*/
int main() {

	ifstream infile;
	infile.open("words.txt"); 

	string output, firstword, secondword; 

	if (infile.peek() == EOF) {
		cout << "The file is empty." << endl;
	}

	else {

		if (infile.is_open()) {

			infile >> firstword >> secondword;

			//String to integer conversion
			int total_words = stoi(firstword);
			int total_class = stoi(secondword);
			cout << total_words << " " << total_class << endl; //display the first two words as integer

			vector <int> FlagVector(total_words, 0); //Intialize Flagvector to zeros by the number of classes to print out

			while (!infile.eof()) {
				while (infile >> output) {
					inputstringwords.push_back(output); //storing each word in vector
				}

				for (int i = 0; i < inputstringwords.size(); i++) {
					cout << inputstringwords[i] << "\n"; // display the words

				}

				// Finding the anagram groups from the inputfile and store in the 2d vector 

				int counter = 0;
				while (ZeroExistence(FlagVector)) { //check if there is any zero's remaining in FlagVector or not
					if (FlagVector[counter] == 1) { //if any 1 found in Flagvector, 
						counter++;					//then update the counter
						continue;					//and go to the next iteration 
					}
					string word1 = inputstringwords[counter];

					vector <string> ClassVector; // this going to have anagram for each word
					ClassVector.push_back(word1);
					FlagVector[counter] = 1;
					for (int j = counter + 1; j <= inputstringwords.size() - 1; j++) {
						if (FlagVector[j] == 0) {
							string word2 = inputstringwords[j];
							if (AnagramOrNot(word1, word2)) { //call the anagram function
								FlagVector[j] = 1;           //if anagram, make that element 0 to 1 in FlagVector 
								ClassVector.push_back(word2); //store that word in ClassVector
							}
						}
					} //repetition loop till the all anagrams of that word stores into ClassVector

					ClassesofAnagram.push_back(ClassVector); //store the anagram in 2D vector 
					ClassVector.clear(); //clear that vector
					counter++; //update the counter
				}
			}

			SortbyClasses(); //call function
			Print(total_class);// call function
		}

		infile.close(); // close input file
	}
	system("pause");
	return 0;
}


/*
Pre-Condition: This function will take two strings to compare if they are anagrams or not
Post_Condition: Return true if both strings are anagrams, otherwise return false
*/
bool AnagramOrNot(string word1, string word2) {
	bool Anagram = true;
	if (word1.size() != word2.size()) {
		Anagram = false;
		return Anagram;
	}

	sort(word1.begin(), word1.end());
	sort(word2.begin(), word2.end());

	if (word1 != word2) {
		Anagram = false;
	}

	return Anagram;
}


/*
Pre-Condition: This Function will check if there is any zero in the FlagVector or not
Post_Condition: Return true if any zero remaining in the vector, otherwise return false
*/
bool ZeroExistence(vector<int> FlagVector)
{
	bool ZeroExistence = false;
	for (int i = 0; i < FlagVector.size(); i++) {
		if (FlagVector[i] == 0) {
			return true;
		}
	}
	return ZeroExistence;
}


/*
Pre-Condition: This Function is going to compare words for the sort function which is 
			   going to sort the classes of anagram by lexographically and sizewise
Post_Condition: return the lexographical sort if the words sizes are equal, otherwise sort by size
*/
bool compareWords(const vector<string> &word1, const vector<string> &word2) {
	if (word2.size() == word1.size()) {
		return word2[0].compare(word1[0]) > 0; //lexographical sort
	}
	return word2.size() < word1.size(); //sizewise sort
}


/*
Pre-Condition: First, this Function is going sort by the each classes 
			   and then going to sort entire classes based on their size
Post_Condition: return the sorted anagram classes
*/
void SortbyClasses() {
	for (int i = 0; i < ClassesofAnagram.size(); i++) {
		sort(ClassesofAnagram[i].begin(), ClassesofAnagram[i].end());
	} // sort each classes
		
	sort(ClassesofAnagram.begin(), ClassesofAnagram.end(), &compareWords); //sort entire anagram classes
}


/*
Pre-Condition: This function will print all the classes of anagram(sorted)
Post-Condition: All elements in 2D vector ClassesofAnagram will be printed
*/
void Print(int numberofclasses) {
	for (int i = 0; i < numberofclasses; i++) { //print based on number of classes from input file
		cout << "Class of size " << ClassesofAnagram[i].size() << ":";
		for (int j = 0; j < ClassesofAnagram[i].size(); j++) {
			cout << " " << ClassesofAnagram[i][j];
		}
		cout << " ." << endl;
	}
}