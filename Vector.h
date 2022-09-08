/**
 * @file Vector.h
 * @author Jackson Horton
 * @date 2022-09-07
 * @brief Header file for Vector class.
 * 
 * The member definitions are defined here and implemented in Vector.cpp.
 */

#ifndef VECTOR_H
#define VECTOR_H

/**
 * A basic remake of the std::vector class from the C++ stl.
 *
 * @class Vector Vector.h "Vector/Vector.h"
 * @brief My remake of the standard vector class. This includes basic functionalities to create new Vectors and basic modifiers.
 *
 */
class Vector {
 private:
  int *vec_ptr;
  int vec_size;
  int vec_capacity;

 public:

/**
 * Default constructor. Creates an empty vector.
 *
 * @post vec_ptr is nullptr and vec_size and vec_capacity are set to 0.
 * 
 */
  Vector();

/**
 * Copy constructor. Initializes a new Vector as a deep copy of the passed Vector
 *
 * @param const Vector &other a given vector whose contents and properties will be deep copied from.
 * @pre a given vector must be initialized.
 * @post A new Vector is created that is a deep copy of the passed Vector. Size/capacity are also copied.
 * 
 */
  Vector(const Vector &other);

/**
 * Destructor.
 *
 * @pre an array must exist to be destroyed
 * @post The dynamic array's memory is deallocated and vec_size and vec_capacity are set to 0.
 * 
 */
  ~Vector();

/**
 * Assignment overload
 *
 * @param const Vector &other the right hand side of assignment operator; the source vector
 * @pre the source vector must exist and not be this vector.
 * @return Vector& a reference to a Vector that is the result of the assignment operation
 * @post the new Vector reference is returned
 * 
 */
  Vector& operator=(const Vector &other);

/**
 * Accessor for vec_size
 *
 * @pre Vector must be initialized
 * @return int returns the vec_size of this Vector
 * 
 */
  int size();

/**
 * Accessor for vec_capacity
 *
 * @pre Vector must be initialized
 * @return int returns the vec_capacity of this Vector
 * 
 */
  int capacity();

/**
 * Push new element to back of Vector's dynamic array
 *
 * @param int element element to be pushed to Vector
 * @pre this Vector must be initialized
 * @post the element is added to the Vector
 * 
 */
  void push_back(int element);

/**
 * Reserves a capacity of n for this Vector
 *
 * @param int n the capacity that should be reserved
 * @post the capacity of Vector is now n if n > vec_capacity
 * 
 */
  void reserve(int n);

/**
 * Overloading the index subscript operator
 *
 * @param unsigned int index the index passed via the []; denotes a reference to the element of the passed index should be returned
 * @pre the Vector must have a size of at least index-1
 * @return int& returns a reference to the int at the index given
 * 
 */
  int& operator[](unsigned int index);

/**
 * Prints contents of vector
 *
 * @pre vector must have elements to print
 * 
 */
  void print();
};

#endif //VECTOR_H
