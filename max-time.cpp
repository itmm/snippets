#include <limits>
#include <iostream>
#include <time.h>

int main() {
	time_t max { std::numeric_limits<time_t>::max() };
	std::cout << ctime(&max) << "\n";
}
