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
  Vector v1;
  cout << "Size(): " << v1.size() <<"\tcapacity(): " << v1.size() << endl;
  v1.print();
  
  return 0;
}
