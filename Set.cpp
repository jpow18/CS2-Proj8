#include <iostream>
#include "Set.h"

namespace templateset {

	template<class T>
	Set<T>::Set() : items(NULL), numItems(0) {

	}

	template<class T>
	Set<T>::Set(const Set<T>& other) {
		numItems = other.numItems;
		items = other.toArray();
	}

	template<class T>
	Set<T>::~Set() {
		if (items != NULL) {
			delete[] items;
		}
	}

	template<class T>
	void Set<T>::operator=(const Set<T>& rightSide) {
		if (items != NULL) {
			delete[] items;
		}
		numItems = rightSide.numItems;
		items = rightSide.toArray();
	}

	template<class T>
	void Set<T>::add(T item) {
		if (!contains(item)) {
			T* newItems = new T[numItems + 1];
			for (int i = 0; i < numItems; i++) {
				newItems[i] = items[i];
			}
			newItems[numItems] = item;
			if (numItems > 0) {
				delete[] items;
			}
			numItems++;
			items = newItems;
		}
	}

	template<class T>
	void Set<T>::remove(T item) {
		if (contains(item)) {
			T* copy = NULL;
			if (numItems > 1) {
				copy = new T[numItems - 1];
				for (int i = 0, j = 0; i < numItems; i++) {
					if (items[i] != item) {
						copy[j] = items[i];
						j++;
					}
				}
			}
			delete[] items;
			items = copy;
			numItems--;
		}
	}

	template<class T>
	int Set<T>::length() const {
		return numItems;
	}

	template<class T>
	bool Set <T>::contains(T item) const {
		for (int i = 0; i < numItems; i++) {
			if (items[i] == item) {
				return true;
			}
		}
		return false;
	}

	template<class T>
	T* Set<T>::toArray() const {
		T* copy = NULL;
		if (numItems > 0) {
			copy = new T[numItems];
			for (int i = 0; i < numItems; i++) {
				copy[i] = items[i];
			}
		}
		return copy;
	};
}