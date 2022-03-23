#include <iostream>
#include <array>
#include<vector>


template<size_t size, class type>
std::ostream& operator<<(std::ostream& stream, const std::array<type, size>& arr) {
	stream << "[";
	for (int i = 0; i < arr.size(); i++) {
		if (i == arr.size() - 1) {
			stream << arr[i] << "]";
		}
		else {
			stream << arr[i] << ", ";
		}
	}
	return stream;
}

template<class type>
std::ostream& operator<<(std::ostream& stream, const std::vector<type>& arr) {
	stream << "[";
	for (int i = 0; i < arr.size(); i++) {
		if (i == arr.size() - 1) {
			stream << arr[i] << "]";
		}
		else {
			stream << arr[i] << ", ";
		}
	}
	return stream;
}

template<class type>
std::ostream& operator<<(std::ostream& stream, const std::vector<std::vector<type>>& arr) {
	stream << "[";
	for (int i = 0; i < arr.size(); i++) {
		if (i == arr.size() - 1) {
			stream << arr[i] << "]";
		}
		else {
			stream << arr[i] << ",\n ";
		}
	}
	return stream;
}