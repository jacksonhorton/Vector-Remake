/**
 * @file Vector.cpp
 * @author Jackson Horton
 * @date 2022-09-07
 * @brief Vector class member implementations 
 * 
 * All of the members of the Vector class as defined in Vector.h are implemented here.
 */

#include <iostream>
#include "Vector.h"

using namespace std;

Vector::Vector() {
  // initialize empty Vector
  vec_ptr = nullptr;
  vec_size = 0;
  vec_capacity = 0;
}

Vector::Vector(const Vector &other) {
  // initializes 
  vec_capacity = 0;
  vec_size = 0;

  // initialized Vector's dynamic array to size of the passed Vector
  reserve(other.vec_capacity);

  // deep copy and sets size to equal other's size
  for (int i = 0; i < other.vec_size; i++) {
    vec_ptr[i] = other.vec_ptr[i];
    vec_size++;
  }
}

Vector::~Vector() {
  // deallocate memory and set size and capacity to 0
  if (vec_ptr != nullptr) {
    delete[] vec_ptr;
    vec_ptr = nullptr;
  }

  // sets size and capacity of the vector to 0
  vec_capacity = 0;
  vec_size = 0;
}

int Vector::size() {
  return vec_size;
}

int Vector::capacity() {
  return vec_capacity;
}

void Vector::push_back(int element) {
  if (vec_size == vec_capacity) {
    if (vec_size == 0)
      reserve(1);
    else
      reserve(2*vec_capacity);
  }

  vec_ptr[vec_size] = element;
  vec_size++;
}

void Vector::reserve(int n) {
  // the Vector doesn't have to reserve anything if n < capacity
  if (n <= vec_capacity)
    return;
  
  // make a new dynamic array of size n
  int *temp = new int[n];

  // copies contents to temp array
  for (int i = 0; i < vec_size; i++) {
    temp[i] = vec_ptr[i];
  }

  // deletes old array and replaces it with new array with larger capacity
  delete[] vec_ptr;
  vec_ptr = temp;

  // sets vec_capacity
  vec_capacity = n;
}

void Vector::print() {
  if (vec_ptr == nullptr or vec_size == 0) {
    cout << "Empty Vector..." << endl;
    return;
  }
  
  cout << "Contents of vector with size " << vec_size << " and capacity " << vec_capacity << " is: ";
  for (int i = 0; i < vec_size; i++) {
    cout << vec_ptr[i] << " ";
  }
  cout << endl;
}

int& Vector::operator[](unsigned int index) {
  int& element_ref = vec_ptr[index];
  
  return element_ref;
}
