#include <iostream>
#include "HashTable.hpp"

int main() {

	HashTable<std::string, std::string, 15> tb;
	tb.Add("Nick", "Kuzicki");
	tb.Add("Kate", "Young");
	tb.Add("Nicole", "Adams");
	tb.Add("Justin", "Brenner");
	tb.Add("Y", "G");
	try {
		std::cout << tb["x"].GetData() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "No such element" << std::endl;
	}
}