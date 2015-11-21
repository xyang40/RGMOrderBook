#include "Pool.h"
#include<iterator>
#include<iostream>
#include<unordered_map>

Pool::Pool() {
	//todo
}

Pool::~Pool() {
	//todo
}

//need to deal with race condition in future editions
void Pool::add(Order* const order) {
	this->map[order->id] = order;
	this->queue.add(order);
	this->size += order->size;
}

//likewise
void Pool::reduce(Order* const order) {
	std::unordered_map<char*, Order*>::iterator found = this->map.find(order->id);
	if (found == this->map.end()) {
		std::cerr << "The order does not exist yet" << std::endl;
	}
	else {
		if (found->second->size <= order->size) {
			this->map.erase(found);
			this->queue.reduce(order);
			this->size -= order->size;
		}
		else {
			found->second->size -= order->size;
			this->size -= order->size;
		}
	}

}