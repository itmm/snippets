#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> v; v.push_back(10); v.push_back(2); v.push_back(3);
	std::sort(begin(v), end(v), std::greater<>());
	for (const auto& x: v) { std::cout << x << '\n'; }
}
