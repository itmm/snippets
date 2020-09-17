
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
			if (cnt % bytes_per_group == 0) {
				std::cout.put(' ');
			}
		}
		std::cout << "  |" <<
			row << "|\n";
	}

#line 7 "dh.md"

	int main() {
		
#line 58 "dh.md"

	std::cout << std::setfill('0') <<
		std::hex;

#line 65 "dh.md"

	size_t count { 0 };
	int i { 0 };
	for (char ch; std::cin.get(ch); ++i) {
		
#line 85 "dh.md"

	if (i == bytes_per_row) {
		
#line 122 "dh.md"

	printasc(i);
	count += i; i = 0;

#line 87 "dh.md"

	}

#line 93 "dh.md"

	if (i == 0) {
		
#line 129 "dh.md"

	std::cout << std::setw(addr_size) <<
		count;

#line 95 "dh.md"

	}

#line 101 "dh.md"

	if (i % bytes_per_group == 0) {
		std::cout.put(' ');
	}

#line 109 "dh.md"

	std::cout << ' ' <<
		std::setw(2) << (ch & 0xff);

#line 116 "dh.md"

	row[i] = isprint(ch) ? ch : '.';

#line 69 "dh.md"

	}

#line 75 "dh.md"

	if (i) {
		
#line 122 "dh.md"

	printasc(i);
	count += i; i = 0;

#line 77 "dh.md"

		
#line 129 "dh.md"

	std::cout << std::setw(addr_size) <<
		count;

#line 78 "dh.md"

		std::cout.put('\n');
	}

#line 9 "dh.md"

	}
