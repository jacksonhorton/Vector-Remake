/**
 * @file Vector.cpp
 * @author Jackson Horton
 * @date 2022-09-07
 * @brief Vector class member implementations 
 * 
 * All of the members of the Vector class as defined in Vector.h are implemented here.
 */

#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector() {
  // initialize empty Vector
  //int *vec_ptr = nullptr;
  int *vec_ptr = nullptr;
  int vec_size = 0;
  int vec_capacity = 0;
}


Vector::Vector(const Vector &other) {
  // initialized Vector's dynamic array to size of the passed Vector
  int *vec_ptr = nullptr;
  int vec_capacity = 0;
  int vec_size = 0;
  reserve(other.vec_capacity);

  // deep copy and sets size to equal other's size
  int size = 0;
  for (int i = 0; i < other.vec_size; i++) {
    vec_ptr[i] = other.vec_ptr[i];
    size++;
  }
}

Vector::~Vector() {
  // deallocate memory and set size and capacity to 0
  //if (vec_size != 0) {
  //  delete[] vec_ptr;
  //}
  
  vec_ptr = nullptr;
  vec_capacity = 0;
  vec_size = 0;
}

int Vector::size() {
  return vec_size;
}

int Vector::capacity() {
  return vec_capacity;
}

void Vector::reserve(int n) {
  if (n <= vec_capacity)
    return;
  
  // make a new dynamic array of size n
  int *temp = new int[n];

  // copies contents to temp array
  for (int i = 0; i < vec_size; i++) {
    temp[i] = vec_ptr[i];
  }

  delete[] vec_ptr;
  vec_ptr = temp;

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
