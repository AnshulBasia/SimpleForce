#ifndef OBJECT_H
#define OBJECT_H

#include "Vector3D.h"

using namespace std;

class Object {
	double mass; 
	static int runningID;									// Assigned to a newly created object.
	static int numberOfObjects;
	Vector3D *position;
	Object *next;
	Vector3D *velocity;										// The velocity of the object at any instant.
	Vector3D *acceleration;									// The acceleration.
	int id;													// Access ID.
public: 
	Object();
	Object(double, Vector3D, Vector3D);
	~Object();
	double getMass();						
	Vector3D getPosition();									
	Vector3D getVelocity();	
	Vector3D getAcceleration();
	Object *getNext();
	int getID();
	void setNext(Object *);	 								// Used for enqueue and dequeue operations. 
	void setAccel(Vector3D);
	void setVeloc(Vector3D);
	void setPosition(Vector3D);
	static int numberOfObjs();
};

int Object::numberOfObjects = 0;
int Object::runningID = 1;

Object::Object() {
	mass = 1;
	position = new Vector3D(0, 0, 0);
	velocity = new Vector3D(0, 0, 0);
	acceleration = new Vector3D(0, 0, 0);
	numberOfObjects++;
	next = nullptr;
	id = runningID; runningID++;
}

Object::Object(double mass, Vector3D initialPosition, Vector3D initialVelocity) {
	this->mass = mass;
	position = new Vector3D();
	*position = initialPosition;
	velocity = new Vector3D();
	*velocity = initialVelocity;
	acceleration = new Vector3D(0, 0, 0);
	numberOfObjects++;
	next = nullptr;
	id = runningID; runningID++;
}

Object::~Object() {
	delete position;
	delete velocity;
	delete acceleration;
	numberOfObjects--;
}

double Object::getMass() {
	return mass;
}

Vector3D Object::getPosition() {
	return *position;
}

Vector3D Object::getVelocity() {
	return *velocity;
}

Vector3D Object::getAcceleration() {
	return *acceleration;
}

Object* Object::getNext() {
	return next;
}

int Object::getID() {
	return id;
}

void Object::setNext(Object *ptr) {								
	next = ptr;
}

void Object::setAccel(Vector3D a) {
	*acceleration = a;
}

void Object::setVeloc(Vector3D v) {
	*acceleration = v;
}

void Object::setPosition(Vector3D p) {
	*position = p;
}

int Object::numberOfObjs() {
	return numberOfObjects;
}

#endif