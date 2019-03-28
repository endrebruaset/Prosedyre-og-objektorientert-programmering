#include <random>
#include <vector>

template <typename T>
T maximum(T lhs, T rhs) {
	if (lhs > rhs) {
		return lhs;
	}
	else {
		return rhs;
	}
}
// for at dette skal fungere for egendefinerte klasser må operatoren > overlastes

template <typename T>
void shuffle(std::vector<T>& vec) {
	for (unsigned int i{ 0 }; i < vec.size(); ++i) {
		int randomIndex = rand() % vec.size();

		T temp{ vec[randomIndex] };
		vec[randomIndex] = vec[i];
		vec[i] = temp;
	}
}