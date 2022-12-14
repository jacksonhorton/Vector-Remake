/**
 * @file main.cpp
 * @author Jackson Horton
 * @date 2022-09-07
 * @brief test the Vector class
 * 
 * Creates Vector objects and tests the Vector class's methods
 */


#include <iostream>
#include "Vector.cpp"

using namespace std;

int main() {
  // initializes 2 empty Vectors
  Vector v1;
  Vector v2;
  // pushes elements to both vectors and uses the other Vector methods.
  v1.reserve(3);
  
  v1.push_back(1);
  v1.push_back(99);

  v2 = v1;
  v2 = v2;
  
  for (int i = 0; i < 10; i++)
    v2.push_back(i);

  // prints contents of both Vectors
  cout << "v1: ";
  v1.print();

  cout << "v2: ";
  v2.print();

  // initializes a 3rd Vector with the copy constructor
  Vector v3(v2);

  // prints elements in third Vector
  v3[1] = 475;
  cout << "v3: ";
  v3.print();
  
  return 0;
}
