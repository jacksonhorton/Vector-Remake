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
  vec_ptr = nullptr;
  vec_capacity = 0;
  vec_size = 0;

  // reserves the same capacity as the other Vector
  reserve(other.vec_capacity);

  // deep copy and sets size to equal other's size
  for (int i = 0; i < other.vec_size; i++) {
    vec_ptr[i] = other.vec_ptr[i];
  }
  vec_size = other.vec_size;
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

Vector& Vector::operator=(const Vector &other) {
  // if the other, passed Vector is this Vector, do nothing.
  if (this == &other)
    return *this;
    
  // reserves the capacity of this array to the capacity of the other array
  reserve(other.vec_capacity);
  // transfers contents
  for (int i = 0; i < other.vec_size; i++) {
    vec_ptr[i] = other.vec_ptr[i];
  }

  // sets size and returns this Vector
  vec_size = other.vec_size;
  return *this;
}

int Vector::size() {
  return vec_size;
}

int Vector::capacity() {
  return vec_capacity;
}

void Vector::push_back(int element) {
  // if the Vector's array is full, reserve more memory first
  if (vec_size == vec_capacity) {
    if (vec_size == 0)
      reserve(1);
    else
      reserve(2*vec_capacity);
  }

  // then adds element to end and increments size
  vec_ptr[vec_size] = element;
  vec_size++;
}

void Vector::reserve(int n) {
  // this function doesn't have to do anything if n < capacity
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

int& Vector::operator[](unsigned int index) {
  // returns the reference to the elemnt of index "index" so it can be read or modified
  int& element_ref = vec_ptr[index];
  
  return element_ref;
}

void Vector::print() {
  // checks if Vector's array is empty or a nullptr to avoid errors
  if (vec_ptr == nullptr or vec_size == 0) {
    cout << "Empty Vector..." << endl;
    return;
  }

  // prints out all the elements in this Vector
  cout << "Contents of vector with size " << vec_size << " and capacity " << vec_capacity << " is: ";
  for (int i = 0; i < vec_size; i++) {
    cout << vec_ptr[i] << " ";
  }
  cout << endl;
}
