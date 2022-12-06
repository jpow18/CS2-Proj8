#include <iostream>
#include <string>
#include <cstdlib>>
#include "Set.cpp"

using namespace templateset;

template<class T>
void output(Set<T> set) {
	T* ptr = set.toArray();
	if (ptr != NULL) {
		for (int i = 0; i < set.length(); i++) {
			std::cout << ptr[i] << std::endl;
		}
		delete[] ptr;
		std::cout << std::endl;
	}
	else {
		std::cout << "Sorry, empty set." << std::endl;
	}
}

int main() {

	Set<char> charSet;
	charSet.add('a');
	charSet.add('b');
	charSet.add('c');
	std::cout << "charSet contains: " << std::endl;
	output(charSet);


	Set<int> intSet;
	intSet.add(22);
	intSet.add(11);
	intSet.add(201);
	intSet.add(17);
	intSet.add(22);
	intSet.add(49);

	std::cout << "intSet holds: " << std::endl;
	output(intSet);

	std::cout << "intSet contains 11: " << intSet.contains(11) << std::endl;
	std::cout << "intSet contains 420: " << intSet.contains(420) << std::endl;
	std::cout << "intSet contains 17: " << intSet.contains(17) << std::endl;
	std::cout << "intSet contains -12: " << intSet.contains(-12) << std::endl;

	std::cout << "Removing 22, 9012, and 49 from intSet." << std::endl;
	intSet.remove(22);
	intSet.remove(9012);
	intSet.remove(49);
	output(intSet);

	std::cout << "The old set contains: " << std::endl;
	output(intSet);

	Set<int> intSet2 = intSet;
	intSet2.add(-123);
	intSet2.add(92);
	std::cout << "The new set contains: " << std::endl;
	output(intSet2);

	
	


	return 0;
}