#include <iostream>
#include <iomanip>
#include <sstream>
#include <boost/uuid/sha1.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/zlib.hpp>

std::string calc_sha(const std::string &data) {
	boost::uuids::detail::sha1 sha;
	sha.process_bytes(data.c_str(), data.size());
	unsigned int digest[5];
	sha.get_digest(digest);
	std::ostringstream result;
	result << std::hex << std::setfill('0');
	for(int i = 0; i < 5; ++i) {
		result << std::setw(8) << digest[i];
	}
	return result.str();
}

int main() {
	std::string str { "hello\n" };
	std::cout << "raw: " << calc_sha(str) << '\n';
	std::ostringstream blob;
	blob << "blob " << str.size() << '\0' << str;
	std::cout << "blob: " << calc_sha(blob.str()) << '\n';
	std::ostringstream zipped;
	boost::iostreams::filtering_streambuf<boost::iostreams::output> filters;
	filters.push(boost::iostreams::zlib_compressor());
	filters.push(zipped);
	std::istringstream in { blob.str() };
	boost::iostreams::copy(in, filters);
	std::cout << "zipped: " << calc_sha(zipped.str()) << '\n';
}

