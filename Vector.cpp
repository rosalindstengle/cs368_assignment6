////////////////////////////////////////////////////////////////////////////////
// File Name:      Vector.cpp
//
// Author:         Rosalind Stengle, Ben Chylla 
// CS email:       stengle@wisc.edu, chylla@wisc.edu
//
// Description:    A custom vector class with a subset
//                 of features from std::vector
//
// Sources:        cppreference.com
//
// // URL(s) of sources:
//                 http://en.cppreference.com/w/cpp/container/vector
//		   
////////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <iostream>
#include <stdexcept>

/**
 * @brief A templated sequence container that encapsulates dynamic size arrays.
 */

template<typename T>
class Vector {
private:
	T *elems; // an array of the elements stored in the Vector
	std::size_t cap; // the current capacity of the array
	std::size_t length; // the number of elements inside the Vector
	static const std::size_t initialCapacity = 4;
	/* If you want to add methods, add them below this line */

	/* If you want to add methods, add them above this line */

public:
	/**
	 * @brief Default Constructor.
	 */
	Vector() {
		//Ben, I implemented this so I could test my own fucntions
		cap = intialCapacity;
		*elems[cap];
	}

	/**
	 * @brief Copy Constructor.
	 * @param other The vector from which we should copy from.
	 */
	Vector(const Vector &other) {
		//create a new vector of the size of the current one
		Vector<int> copyVector = Vector();
		*copyVector = *other.copyVector;
		return copyVector;

		//https://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm
	}

	/**
	 * @brief Copy Assignment Operator.
	 * @param other The vector on the RHS of the assignment.
	 * @return A reference to the vector on the LHS.
	 */
	Vector &operator=(const Vector &other) {
		//idenitacal code to copy constructo
	}

	/**
	 * @brief Destructor.
	 */
	~Vector(){
		//BEN
	}

	typedef T* iterator;
	typedef const T* constIterator;

	/**
	 * @brief Begin iterator.
	 * @return An iterator to the first element.
	 */
	iterator begin() {
		iterator it = elems[0];
		return it;
	}

	/**
	 * @brief End iterator.
	 * @return An iterator to one past the last element.
	 */
	iterator end() {
		//BEN
	}

	/**
	 * @brief Const begin iterator. This is a const overloaded function.
	 * @return A const iterator to the first element.
	 */
	constIterator begin() const {
		constIterator constIt = elems[0];
		return cosntIt;
		//how is this different??
	}

	/**
	 * @brief Const end iterator. This is a const overloaded function.
	 * @return A const iterator to one past the last element.
	 */
	constIterator end() const {
		//BEN
	}

	/**
	 * @brief Gets the number of elements that the container has currently allocated space for.
	 * @return The number of elements that can be held in currently allocated storage.
	 */
	std::size_t capacity() const {
		return cap;
	}

	/**
	 * @brief Gets the number of elements.
	 * @return The number of elements in the container.
	 */
	std::size_t size() const {
		//BEN
	}

	/**
	 * @brief Adds an element to the end.
	 *        If there is no space to add an element, then the capacity of the vector is doubled..
	 * @param elem The element to be added.
	 */
	void pushBack(T elem) {
		//use end()?? or otherwise find the iterator pointing to the end
		//if get next of that is null, double the array using reserve()
		//put the new element in the spot
	}

	/**
	 * @brief Removes the last element of the container.
	 *        The capacity of the vector is unchanged.
	 *        If there are no elements in the container, then do nothing.
	 */
	void popBack() {
		//BEN
	}

	/**
	 * @brief Increases the capacity of the container to a value greater or equal to new_cap.
	 *        If new_cap is greater than the current capacity(), new storage is allocated,
	 *        otherwise the method does nothing.
	 * @param new_cap new capacity of the container.
	 */
	void reserve(std::size_t new_cap) {
		//create new array of elements of the desired size and set elems to that new array
		//copy current data to new array leaving the empty spots
	}

	/**
	 * @brief Overloaded array subscripting operator.
	 * @param pos The position of the element to access.
	 * @return A reference to the element at specified location pos.
	 *         No bounds checking is performed.
	 */
	T &operator[](std::size_t pos) {
		//BEN
	}

	/**
	 * @brief Const overload of the overloaded array subscripting operator.
	 * @param pos The position of the element to access.
	 * @return A const reference to the element at specified location pos.
	 *         No bounds checking is performed.
	 */
	const T &operator[](std::size_t pos) const {
		//BEN
	}

	/**
	 * @brief Access specified element with bounds checking.
	 * @param pos The position of the element to access.
	 * @return A reference to the element at specified location pos, with bounds checking.
	 * @throw std::out_of_range if pos >= the size of the vector.
	 */
	T &at(std::size_t pos) {
		// TODO: Implement this function.
	}

	/**
	 * @brief Const overload to access specified element with bounds checking.
	 * @param pos The position of the element to access.
	 * @return A const reference to the element at specified location pos, with bounds checking.
	 * @throw std::out_of_range if pos >= the size of the vector.
	 */
	const T &at(std::size_t pos) const {
		// TODO: Implement this function.
	}

	/**
	 * @brief Checks whether the container is empty.
	 * @return true if the container is empty, false otherwise.
	 */
	bool empty() const {
		for (int i = 0; i < *elems.sizeof(); i++) {
			if (elems[i] != NULL) {
				return false;
			}
		}
		return true;
	}

	/**
	 * @brief Removes all elements from the container.
	 *        Leaves the capacity of the vector unchanged.
	 */
	void clear() {
		for (int i = 0; i<=elems.sizeof(); i++) {
			elems[i] = null;
		}
	}

	/**
	 * @brief Erases an element at pos.
	 * @param pos Iterator to the element to remove.
	 * @return Iterator following the last removed element.
	 *         If the iterator pos refers to the last element, the end() iterator is returned.
	 */
	iterator erase(iterator pos) {

	}
}
