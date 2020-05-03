/*
Ritoshree Gupta
CIS 3501
Fall 2019
Prof. John P. Baugh
Creation Date: 12/09/2019
Modification Date: 12/14/2019
Purpose: read values from the input file and print dead ends in undirected graph
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


const int N = 100000;

vector <int> Data_Input; //Initializing vector for store the input
vector <vector<int>> Graphlist; // Initializing vector for store Input(Graph) Adjacency List


//Function Prototypes
void DFS(int a, int b, vector<int> C, vector<int> &M, vector<int>P, int &cycNUM, vector<vector<int>>input);
vector<vector<int>> Store_n_PrintCYCLE(int edges, vector<int> M, int &cycNUM);
bool DeadEND(int a, int b);



/*
Pre-Condition: This main function will read the input file, store that input file in a vector, Store input based adjacency list in 2D vector, detect cycles
				from the adjacency list by calling DFS function, display cycle number and the elements on cycle by calling Store_n_printCYCLE function, will
				show Dead-Ends calling DEADEND function.
				
Post_Condition: Store input based adjacency list in 2D vector successfully, find the cycles based on the input successfully, but DeadEND function not
				working properly.
*/

int main() {

	ifstream infile;
	infile.open("input.txt");

	if (infile.peek() == EOF) {
		cout << "The file is empty." << endl;
	}

	else {

		int input, nodes, edges;

		if (infile.is_open()) {

			infile >> nodes >> edges;
			/*cout << nodes << " " << edges << endl;*/

			for (int i = 0; i <= nodes; i++) {
				Graphlist.push_back(vector<int>());
			}

			while (!infile.eof()) {
				while (infile >> input) {
					Data_Input.push_back(input);
				}

				for (int i = 0; i < Data_Input.size(); i+=2) {
					Graphlist[Data_Input[i]].push_back(Data_Input[i + 1]);
					Graphlist[Data_Input[i+1]].push_back(Data_Input[i]);
				}

				cout << "GRAPH ADJACENCY LIST: " << endl;
				for (int i = 1; i < Graphlist.size(); i++) {
					cout << "INDEX NUMBER: " << i << " =";
					for (int j = 0; j < Graphlist[i].size(); j++) {
						cout <<"  " << Graphlist[i][j];
					}
					cout << endl;
				}

				cout << endl;

				vector<int> C;
				vector<int> P;
				vector<int> M;

				for (int i = 0; i < N; i++)
				{
					C.push_back(0);
					P.push_back(0);
					M.push_back(0);
				}

				
				int cycNUM = 0; 

				DFS(1, 0, C, M, P, cycNUM, Graphlist);
				Store_n_PrintCYCLE(edges, M, cycNUM);			


				cout << endl << "DEAD ENDS: " << endl;
				for (int i = 0; i < Graphlist.size(); i++) {
					for (int j = 0; j < Graphlist[i].size(); j++) {
						int D = DeadEND(i, Graphlist[i][j]);
						/*cout << D << endl;*/
					}
				}

			}
		}
	}

	system("pause");
	return 0;
}


/*
Pre-Condition: This function will find the cycles of the graph input using Depth First Search.

Post_Condition: Find the cycles successfully.
*/



void DFS(int a, int b, vector<int> C, vector<int> &M, vector<int>P, int &cycNUM, vector<vector<int>>input)
{
	
	if (C[a] == 2) {
		return;
	}

	if (C[a] == 1) {

		cycNUM++;
		int current = b;
		M[current] = cycNUM;

		while (current != a) {
			current = P[current];
			M[current] = cycNUM;
		}
		return;
	}

	P[a] = b;
	C[a] = 1;

	
	for (int i : Graphlist[a]) {

		if (i == P[a]) {
			continue;
		}
		DFS(i, a, C, M, P, cycNUM, input);
	}

	C[a] = 2;
}


/*
Pre-Condition: This function will take edges, vector and reference of cycle numbers as a parameters,
				should print and store the number of cycles and the elements.

Post_Condition: Store and Print the cycles successfully.
*/

vector<vector<int>> Store_n_PrintCYCLE(int edges, vector<int> M, int &cycNUM)
{

	vector<vector<int>> Cycles;
	vector<int> c;
	int N2 = 100000;

	for (int i = 0; i < N2; i++) {
		Cycles.push_back(c);
	}

	for (int i = 1; i <= edges; i++) {
		if (M[i] != 0)
			Cycles[M[i]].push_back(i);
	}

	cout << "CYCLE: " << endl;
	for (int i = 1; i <= cycNUM; i++) {
		/*cout << i << endl;*/
		for (int x : Cycles[i]) {
			cout << x << " ";
		}
		cout << endl;
	}

	return Cycles;
}

/*
Pre-Condition: This function will take two integer of edges and check for deadends.

Post_Condition: return true if cycle exists, return false otherwise.
*/

bool DeadEND(int a, int b) {
	bool flag = true;
	for (int i = 0; i < Data_Input.size(); i++) {
		if (a == Data_Input[i]) {
			if (b == Data_Input[i]) {
				return flag;
			}
		}
		else
		{
			flag = false;
			return flag;
		}
	}

}