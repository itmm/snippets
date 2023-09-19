// Implementation of CRC-16/ARC

#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int crc16(const char *str) {
	int crc { 0x0000 }; // init
	for (; *str; ++str) {
		crc ^= *str & 0xff;
		for (int n = 8; n; --n) {
			if (crc & 0x0001) {
				crc = (crc >> 1) ^ 0xa001; // bitreversed poly 0x8005
			} else {
				crc = crc >> 1;
			}
		}
	}
	return crc;
}

void run_unit_tests() {
	assert(crc16("") == 0x0000);
	assert(crc16("123456789") == 0xbb3d);
	assert(crc16("1234") == 0x14ba);
}

int main(int argc, const char *argv[]) {
	if (argc != 2) { 
		std::cerr << "syntax: " << argv[0] << " <value>\n";
		std::exit(EXIT_FAILURE);
	}

	run_unit_tests();

	const char *cur { argv[1] };
	int crc { crc16(argv[1]) };

	std::cout << std::hex << std::setw(4) << std::setfill('0') << crc << '\n';
}
