
#line 5 "dh.md"

	
#line 16 "dh.md"

	#include <iostream>
	#include <iomanip>
	#include <cctype>

#line 6 "dh.md"

	
#line 24 "dh.md"

	constexpr int bytes_per_row { 16 };
	constexpr int bytes_per_group { 8 };
	constexpr int addr_size {
		2 * sizeof(size_t)
	};

#line 34 "dh.md"

	static char row[bytes_per_row + 1];

#line 40 "dh.md"

	void printasc(int cnt) {
		row[cnt] = '\0';
		for (;
			cnt < bytes_per_row; ++cnt
		) {
			std::cout << "   ";
		}
		std::cout << "  |" <<
			row << "|\n";
	}

#line 7 "dh.md"

	int main() {
		
#line 55 "dh.md"

	std::cout << std::setfill('0') <<
		std::hex;

#line 62 "dh.md"

	size_t count { 0 };
	int i { 0 };
	for (char ch; std::cin.get(ch); ++i) {
		
#line 82 "dh.md"

	if (i == bytes_per_row) {
		
#line 119 "dh.md"

	printasc(i);
	count += i; i = 0;

#line 84 "dh.md"

	}

#line 90 "dh.md"

	if (i == 0) {
		
#line 126 "dh.md"

	std::cout << std::setw(addr_size) <<
		count;

#line 92 "dh.md"

	}

#line 98 "dh.md"

	if (i % bytes_per_group == 0) {
		std::cout.put(' ');
	}

#line 106 "dh.md"

	std::cout << ' ' <<
		std::setw(2) << (ch & 0xff);

#line 113 "dh.md"

	row[i] = isprint(ch) ? ch : '.';

#line 66 "dh.md"

	}

#line 72 "dh.md"

	if (i) {
		
#line 119 "dh.md"

	printasc(i);
	count += i; i = 0;

#line 74 "dh.md"

		
#line 126 "dh.md"

	std::cout << std::setw(addr_size) <<
		count;

#line 75 "dh.md"

		std::cout.put('\n');
	}

#line 9 "dh.md"

	}
