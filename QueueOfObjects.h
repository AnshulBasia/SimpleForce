#ifndef QUEUEOFOBJECTS_H
#define QUEUEOFOBJECTS_H

#include "Object.h"

class Queue {
	static const double G;							// The universal gravitational constant.
	Object *start, *end;
public:
	Queue() { start = nullptr; end = nullptr; } 
	void Enqueue(Object *);							// Add an object to the queue.
	void Dequeue(int); 								// Dequeue an object from the queue.
	void AssignAccel();								// Compute the acceleration on each object in the queue.	
	void AssignVeloc(double);
	void AssignPosition(double);
	void ChangePosition();							// Change the position of every object based on it's acceleration.
};

const double Queue::G = 6.67*pow(10, -11);

void Queue::Enqueue(Object *ptr) {
	if (start == nullptr) {
		start = ptr;
		end = ptr;
	} 
	else {
		end->setNext(ptr);
		end = ptr;
		end->setNext(start);
	}
}

void Queue::Dequeue(int id) {
	Object *ptr = start; 
	bool loop = false;
	int count = 0;													// Will make sure we don't try to look for a non-existent object infinitely.
	if (Object::numberOfObjs() == 1) {
		if (start->getID() == id) {
			delete start;
			start = nullptr;
		} 
		else {
			cout << "\n\t\tThe object is not present in the universe.\n" << endl;
		}
		return;
	}
	while (ptr->getNext()->getID() != id && count <= 1) {
		if (ptr == start) 
			count++;
		ptr = ptr->getNext();
	}
	if (count <= 1) {
		Object *temp = ptr->getNext();
		ptr->setNext(temp->getNext());
		delete temp;
	} 
	else {
		cout << "\n\t\tThe object is not present in the universe.\n" << endl;
	}
}

void Queue::AssignAccel() {
	Object *ptr1, *ptr2;
	bool once = false;																			// Stop the loop the 2nd time it reaches start.
	Vector3D accel, distance; double magnitude = 0;												// Distance and force vectors + ForceMagnitude. 																				
	for (ptr1 = start; ptr1 != start || !once; ptr1 = ptr1->getNext()) {						// Start from the first element.
		once = true;																			
		accel = { 0, 0, 0 };																	// I can do that? Hmmm. Interesting.
		distance = { 0, 0, 0 };
		for (ptr2 = ptr1->getNext(); ptr2 != ptr1; ptr2 = ptr2->getNext()) {					// Calculate the accel on element i due to ..
			distance = ptr2->getPosition() - ptr1->getPosition();								// elements e ε Universe - {i}. 
			magnitude = (G * ptr2->getMass())/pow(distance.length(),2);							// Newtonian gravity, yep.  
			accel += (distance*(1/distance.length()))*magnitude;								// Normalize the distance and get vector accel^n.
		}
		ptr1->setAccel(accel);
	}
}

void Queue::AssignVeloc(double deltaT) {														// We'll update the velocity now.
	Object *ptr;																				// In the small (discrete) interval deltaT ..
	bool once = false;																			// Accel^n of an object can be assumed const.
	for (ptr = start; ptr != start || !once; ptr = ptr->getNext()) {
		once = true;
		ptr->setVeloc(ptr->getVelocity() + ptr->getAcceleration()*deltaT);						// Newton's first equation of motion.
	}
}	

void Queue::AssignPosition(double deltaT) {
	Object *ptr;
	bool once = false;
	for (ptr = start; ptr != start || !once; ptr = ptr->getNext()) {
		once = true;
		ptr->setPosition(ptr->getVelocity()*deltaT + ptr->getAcceleration()*pow(deltaT, 2)*(0.5));	// Newton's second equation.
	}
}

#endif