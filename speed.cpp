#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

template<int I>
class Container {
		const float value_;
	public:
		constexpr explicit Container(float value): value_ { value } { }
		constexpr operator float() const { return value_; }
};

using Speed = Container<0>;
using Length = Container<1>;

constexpr Length operator""_m(unsigned long long value) { return Length { static_cast<float>(value) }; }
constexpr Length operator""_m(long double value) { return Length { static_cast<float>(value) }; }

constexpr Speed operator/(Length length, std::chrono::seconds time) {
	return Speed { static_cast<float>(length) / time.count() };
}

void change_speed(Speed speed) {
	std::cout << static_cast<float>(speed) << '\n';
}

int main() {
	change_speed(Speed { 10.0_m / 2s });
}
