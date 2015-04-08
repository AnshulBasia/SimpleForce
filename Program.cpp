#include "QueueOfObjects.h"
#include <process.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

using namespace std;

bool invalid(int);
bool invalid(char);
void constructionMenu();
void textBasedSimulation(Queue);

int main() {
	Queue Universe;																				// Where everything happens.		
	cout << "\t\t Welcome to the SimpleForce particle simulator!\n" << endl;
	cout << "\tThe program is in the construction phase." << endl;
	int key; char default;
	do {
		constructionMenu();
		cin >> key;
		while (invalid(key)) {
			cout << "\tPlease enter a valid choice: ";
			cin >> key;
		}
		cout << endl;
		switch (key) {
			case 1:	{																			// Adding an object.
				cout << "\tDo you want to create a default object (Y or N)? : ";
				cin >> default;
				default = toupper(default);
				while (invalid(default)) {
					cout << "\tPlease enter a valid choice: ";
					cin >> default;
				}
				if (default == 'Y') {
					Object *newObj = new Object();
					Universe.Enqueue(newObj);
				} 
				else {
					double mass; Vector3D position; Vector3D velocity;
					cout << "\tEnter the mass of the object: ";
					cin >> mass;
					cout << "\tEnter the position of the object (Vector): ";
					cin >> position;
					cout << "\tEnter the initial velocity of the object (Vector): ";
					cin >> velocity;
					Object *newObj = new Object(mass, position, velocity);
					Universe.Enqueue(newObj);
				}
				break;
			} 
			case 2: {																			// Deleting an object.
				int id;
				cout << "Enter the ID of the object you want to delete: ";
				cin >> id;
				Universe.Dequeue(id);
				break;
			} 
			case 3: {																			// Viewing phase.
				system("cls");																	// Clears the screen. Hmm..
				break;
			} 
			case 4: {																			// Simulation phase.
				system("cls");																	
				break;
			} 
			case 0: {
				exit(0);
			}
	    }
	} while (key != 0);
	return 0;
}

void constructionMenu() {
	cout << "\n\t\t1. Add an object." << endl;
	cout << "\t\t2. Delete an object." << endl;
	cout << "\t\t3. View your universe." << endl;
	cout << "\t\t4.	Start the simulation." << endl;
	cout << "\t\t0. Exit the program.\n" << endl;
	cout << "\tChoose one of the options to continue: ";
}

bool invalid(int key) {
	return (key != 0 && key != 1 && key != 2 && key!= 3);
}

bool invalid(char key) {
	return (key != 'Y' && key != 'N');
}

void textBasedSimulation(Queue Universe) {
	char display[100][100]; 																		// Assign acceleration first.
	double lastTime = time(NULL);			   														// Then position (detect key-press)
	double currentTime;																				// Then velocity
	while (kbhit() != 0) {																		    
		currentTime
	}
}