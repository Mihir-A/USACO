#include <iostream>
#include <array>
#include<vector>


template<size_t size, class type>
std::ostream& operator<<(std::ostream& stream, const std::array<type, size>& arr) {
	stream << "[ ";
	for (auto& a : arr) {
		stream << a << ", ";
	}
	stream << "]"
	return stream;
}

template< class type>
std::ostream& operator<<(std::ostream& stream, std::vector<std::vector<type>>& arr) {
	for (auto& a : arr) {
		stream << a << "\n";
	}
	stream << "\n";
	return stream;
}

template< class type>
std::ostream& operator<<(std::ostream& stream, std::vector<type>& arr) {
	for (auto& a : arr) {
		stream << a << ", ";
	}
	return stream;
}