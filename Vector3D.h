#define CRT_SECURE_NO_WARNINGS_

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Vector3D {
	double x, y, z;																					// Components of a vector
public:
	Vector3D()   { x = y = 0; }
	Vector3D(double, double, double);
	~Vector3D();
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
	Vector3D operator+(Vector3D);																	// Sum of two vectors.
	Vector3D operator-(Vector3D);																	// Difference, likewise.
	Vector3D operator*(double);																		// The scale operation. 
	void operator+=(Vector3D); 
	void operator-=(Vector3D); 
	void operator*=(double); 
	Vector3D* operator=(Vector3D);
	bool operator==(Vector3D);
	friend istream &operator>>(istream &, Vector3D &);												// The input operator for a Vector3D object.
	friend ostream& operator<<(ostream&, Vector3D &);												// To display the vector on screen.
	double length();																				// Returns the magnitude/length.
	Vector3D crossProduct(Vector3D);															    // The cross-product. (This X Arg)
	double dotProduct(Vector3D);																	// The dot-product.			
};

Vector3D::Vector3D(double xComp, double yComp, double zComp) {
	x = xComp, y = yComp, z = zComp;
}

Vector3D::~Vector3D() { }

Vector3D Vector3D::operator+(Vector3D addend) {														
	Vector3D sum(x + addend.getX(), y + addend.getY(), z + addend.getZ());
	return sum;
}

Vector3D Vector3D::operator-(Vector3D subtrahend) {														
	Vector3D difference(x - subtrahend.getX(), y - subtrahend.getY(), z - subtrahend.getZ());
	return difference;
}

Vector3D Vector3D::operator*(double scalingFactor) { 												
	Vector3D scaledVector(x*scalingFactor, y*scalingFactor, z*scalingFactor);
	return scaledVector;
}

void Vector3D::operator+=(Vector3D addend) {
	x += addend.getX(); y += addend.getY(); z += addend.getZ();
}

void Vector3D::operator-=(Vector3D subtrahend) {
	x -= subtrahend.getX(); y -= subtrahend.getY(); z -= subtrahend.getZ();
}

void Vector3D::operator*=(double scalingFactor) {
	x *= scalingFactor; y *= scalingFactor; z *= scalingFactor;
}

Vector3D* Vector3D::operator=(Vector3D rhs) {
	x = rhs.getX(); y = rhs.getY(); z = rhs.getZ();
	return this;
}

bool Vector3D::operator==(Vector3D argument) {
	return (x == argument.getX() && y == argument.getY() && z == argument.getZ());
}

istream& operator>>(istream &in, Vector3D &v) {
	in >> v.x >> v.y >> v.z;
	return in;
}

double Vector3D::length() {
	return pow((x*x + y*y + z*z), 0.5);															
}

Vector3D Vector3D::crossProduct(Vector3D multiplicand) {												    
	double xComp = y*multiplicand.getZ() - z*multiplicand.getY();
	double yComp = z*multiplicand.getX() - x*multiplicand.getZ();
	double zComp = x*multiplicand.getY() - y*multiplicand.getX();
	Vector3D crossProduct(xComp, yComp, zComp);
	return crossProduct;
}

double Vector3D::dotProduct(Vector3D argument) {																
	return (x*argument.getX() + y*argument.getY() + z*argument.getZ());
}

ostream& operator<<(ostream &out, Vector3D &v) {
	out << fixed << setprecision(2) << v.x << "i + " << v.y << "j + " << v.z << "k";
	return out;
}

#endif