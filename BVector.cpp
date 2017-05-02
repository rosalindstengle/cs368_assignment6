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
//                 <URLs of your sources, if any>
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
		std::cout << "Default Constructor" << std::endl;
		cap = initialCapacity;
		length = 0;
		elems = new T[cap];
	}

	/**
	 * @brief Copy Constructor.
	 * @param other The vector from which we should copy from.
	 */
	Vector(const Vector &other) {
		// copy all data into the new one
		std::cout << "Copy Constructor" << std::endl;
		cap = other.cap;
		length = other.length;
		elems = new T[cap];
		for (int i = 0; i < length; ++i) {
			elems[i] = other.elems[i];
		}
	}

	/**
	 * @brief Copy Assignment Operator.
	 * @param other The vector on the RHS of the assignment.
	 * @return A reference to the vector on the LHS.
	 */
	Vector &operator=(const Vector &other) {
		std::cout << "Copy Assignment Operator" << std::endl;
		if (this != &other) {
			cap = other.cap;
			length = other.length;
			// delete old array before creating a new one delete[] elems;
			elems = new T[cap];
			for (int i = 0; i < length; ++i) {
				elems[i] = other.elems[i];
			}
		}
		return *this;
	}

	/**
	 * @brief Destructor.
	 */
	~Vector(){
		delete[] elems;
		*elems = new elems[cap];
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
	 * @return An iterator to one past the last element.return true;
	 */
	iterator end() {
		iterator it = elems[length-1];
		return it;
	}

	/**
	 * @brief Const begin iterator. This is a const overloaded function.
	 * @return A const iterator to the first element.
	 */
	constIterator begin() const {
		constIterator constIt = elems[0];
		return constIt;
	}

	/**
	 * @brief Const end iterator. This is a const overloaded function.
	 * @return A const iterator to one past the last element.
	 */
	constIterator end() const {
		constIterator constIt = elems[length-1];
		return constIt;
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
		return length;
	}

	/**
	 * @brief Adds an element to the end.
	 *        If there is no space to add an element, then the capacity of the vector is doubled..
	 * @param elem The element to be added.
	 */
	void pushBack(T elem) {
		if (length >= cap) {
			cap = cap * 2;
			elems = new T[cap];
		}
		length++;
		elems[length-1] = elem;
	}

	/**
	 * @brief Removes the last element of the container.
	 *        The capacity of the vector is unchanged.
	 *        If there are no elements in the container, then do nothing.
	 */
	void popBack() {
		if (length != 0) {
			elems[length] = NULL;
			length--;
		}
	}

	/**
	 * @brief Increases the capacity of the container to a value greater or equal to new_cap.
	 *        If new_cap is greater than the current capacity(), new storage is allocated,
	 *        otherwise the method does nothing.
	 * @param new_cap new capacity of the container.
	 */
	void reserve(std::size_t new_cap) {
		if (new_cap > cap) {
			cap = new_cap;
		}
	}

	/**
	 * @brief Overloaded array subscripting operator.
	 * @param pos The position of the element to access.
	 * @return A reference to the element at specified location pos.
	 *         No bounds checking is performed.
	 */
	T &operator[](std::size_t pos) {
		T elem = elems[pos];
		return *elem;
	}

	/**
	 * @brief Const overload of the overloaded array subscripting operator.
	 * @param pos The position of the element to access.
	 * @return A const reference to the element at specified location pos.
	 *         No bounds checking is performed.
	 */
	const T &operator[](std::size_t pos) const {
		T elem = elems[pos];
		return *elem;
	}

	/**
	 * @brief Access specified element with bounds checking.
	 * @param pos The position of the element to access.
	 * @return A reference to the element at specified location pos, with bounds checking.
	 * @throw std::out_of_range if pos >= the size of the vector.
	 */
	T &at(std::size_t pos) {
		T elem = elems[pos];
		return *elem;
	}

	/**
	 * @brief Const overload to access specified element with bounds checking.
	 * @param pos The position of the element to access.
	 * @return A const reference to the element at specified location pos, with bounds checking.
	 * @throw std::out_of_range if pos >= the size of the vector.
	 */
	const T &at(std::size_t pos) const {
		T elem = elems[pos];
		return *elem;
	}

	/**
	 * @brief Checks whether the container is empty.
	 * @return true if the container is empty, false otherwise.
	 */
	bool empty() const {
		if (length == 0) {
			return true;
		}
		return false;
	}

	/**
	 * @brief Removes all elements from the container.
	 *        Leaves the capacity of the vector unchanged.
	 */
	void clear() {
		for (int i = 0; i <= length; i++) {
			elems[i] = NULL;
		}
		length = 0;
	}

	/**
	 * @brief Erases an element at pos.
	 * @param pos Iterator to the element to remove.
	 * @return Iterator following the last removed element.
	 *         If the iterator pos refers to the last element, the end() iterator is returned.
	 */
	iterator erase(iterator pos) {
		iterator it1 = elems[0];
		iterator it2;
		while (it1 != pos + 1) {
			it2 = it1 + 1;
		}
		it1 = it2;
		return it2;
	}
};
