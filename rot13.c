#include <stdio.h>

int main() {
	for (;;) {
		int c = getchar();
		if (c == EOF) { break; }
		int d = -1;
		if (c >= 'A' && c <= 'Z') {
			d = c - 'A'; c = 'A';
		}
		if (c >= 'a' && c <= 'z') {
			d = c - 'a'; c = 'a';
		}
		if (d >= 0) {
			d += 13;
			if (d >= 26) { d -= 26; }
			c += d;
		}
		putchar(c);
	}
}
