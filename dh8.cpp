#include <iostream>
#include <iomanip>
#include <cctype>

constexpr int bytes_per_row { 8 };
constexpr int bytes_per_group { 4 };
constexpr int addr_size { 4 };

static char row[bytes_per_row + 1];

void pad_group(int cnt) {
	if (cnt % bytes_per_group == 0) {
		std::cout.put(' ');
	}
}

void printasc(int cnt) {
	row[cnt] = '\0';
	for (; cnt < bytes_per_row; ++cnt) {
		std::cout << "   ";
		pad_group(cnt);
	}
	std::cout << "  |" << row << "|\n";
}

int main() {
	std::cout << std::setfill('0') << std::hex;

	size_t count { 0 };
	int i { 0 };
	for (char ch; std::cin.get(ch); ++i) {
		if (i == bytes_per_row) {
			printasc(i);
			count += i; i = 0;
		}
		if (i == 0) {
			std::cout << std::setw(addr_size) << count;
		}

		pad_group(i);

		std::cout << ' ' << std::setw(2) << (ch & 0xff);

		row[i] = isprint(ch) ? ch : '.';
	}

	if (i) {
		printasc(i);
		count += i; i = 0;

		std::cout << std::setw(addr_size) << count;
		std::cout.put('\n');
	}
}
