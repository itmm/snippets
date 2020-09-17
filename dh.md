# Small hex dump
* minimal implementation of the `hd` utility in C++

```
@Def(file: dh.cpp)
	@put(includes)
	@put(globals)
	int main() {
		@put(main)
	}
@End(file: dh.cpp)
```
* coarse structure of the program

```
@def(includes)
	#include <iostream>
	#include <iomanip>
	#include <cctype>
@end(includes)
```

```
@def(globals)
	constexpr int bytes_per_row { 16 };
	constexpr int bytes_per_group { 8 };
	constexpr int addr_size {
		2 * sizeof(size_t)
	};
@end(globals)
```

```
@add(globals)
	static char row[bytes_per_row + 1];
@end(globals)
```

```
@add(globals)
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
@end(globals)
```

```
@def(main)
	std::cout << std::setfill('0') <<
		std::hex;
@end(main)
```

```
@add(main)
	size_t count { 0 };
	int i { 0 };
	for (char ch; std::cin.get(ch); ++i) {
		@put(loop)
	}
@end(main)
```

```
@add(main)
	if (i) {
		@mul(finish line)
		@mul(write count)
		std::cout.put('\n');
	}
@end(main)
```

```
@def(loop)
	if (i == bytes_per_row) {
		@mul(finish line)
	}
@end(loop)
```

```
@add(loop)
	if (i == 0) {
		@mul(write count)
	}
@end(loop)
```

```
@add(loop)
	if (i % bytes_per_group == 0) {
		std::cout.put(' ');
	}
@end(loop)
```

```
@add(loop)
	std::cout << ' ' <<
		std::setw(2) << (ch & 0xff);
@end(loop)
```

```
@add(loop)
	row[i] = isprint(ch) ? ch : '.';
@end(loop)
```

```
@def(finish line)
	printasc(i);
	count += i; i = 0;
@end(finish line)
```

```
@def(write count)
	std::cout << std::setw(addr_size) <<
		count;
@end(write count)
```
