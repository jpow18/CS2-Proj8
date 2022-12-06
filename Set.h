#ifndef _SET_H
#define _SET_H

namespace templateset {

	template<class T>
	class Set {
	public:
		Set();
		Set(const Set<T>& other);
		~Set();
		void operator=(const Set<T>& rightSide);
		void add(T item);
		void remove(T item);
		int length() const;
		bool contains(T item) const;
		T* toArray() const;
	private:
		T* items;
		int numItems;
	};
}

#endif