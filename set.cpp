#include <iostream>
#include <set>

int main() {
	std::set<int> s;
	if (auto [ iter, success ] = s.insert(5); success) {
		std::cout << "not found\n";
	}
}
