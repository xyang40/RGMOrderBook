#include "Priorities.h"
#include "Order.h"
#include<iterator>
#include<algorithm>
#include<iostream>

void Priorities::add(const Order* const order) {
	auto ptr = static_cast<std::priority_queue<const Order* const>*>(this);
	ptr->push(order);
}

void Priorities::reduce(const Order* const order) {

	auto found = std::find(this->c.begin(), this->c.end(), order);
	if (found == this->c.end()) {
		std::cout<< "The order is not in the queue" << std::endl;
	}
	else {
		this->c.erase(found);
	}
}