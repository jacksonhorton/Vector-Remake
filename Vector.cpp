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

Vector::Vector() {
  // initialize empty Vector
  int *vec_ptr = nullptr;
  int vec_size = vec_capacity = 0;
}
