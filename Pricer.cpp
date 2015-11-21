#include "Order.h"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<iterator>
#include<vector>

bool input_chck(std::string& input) {
	//checking size only; should have assumed more responsibilities like constructing order objects etc; return an Order or return a nullptr, etc
	if (input.size() == 4 || input.size() == 6) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	std::ifstream file;
	file.open("input.txt");
	if (file.is_open()) {
		std::string orderstring;
		while (std::getline(file,orderstring)) {
			if (!input_chck(orderstring)) {
				//if the order data is not of format, goto nextline
				std::cout << "bad order" << std::endl;
				continue;
			}
			else {
				//well-formed order: parse and form an objet d'order
				std::stringstream ss(orderstring);
				std::istream_iterator<std::string> begin(ss);
				std::istream_iterator<std::string> end;
				std::vector<std::string> vec_str(begin, end);
				if (vec_str[1] == "R") {//if to reduce
					Order* order = new Order(std::stoi(vec_str[0]), vec_str[1][0], vec_str[2], vec_str[3][0],std::stod(vec_str[4]),std::stoi(vec_str[5]));
				}
				else {//if to add
					Order* order = new Order(std::stoi(vec_str[0]), vec_str[1][0], vec_str[2], std::stoi(vec_str[3]));
				}
				//process the order:
				//initialize the engine
				//run()
				//...
			}
		}
	}
	else {
		std::cout << "lost connection with the file" << std::endl;
	}

	return 0;
}