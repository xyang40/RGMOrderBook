#pragma once
#ifndef POOL_H
#define POOL_H
#include "Order.h"
#include<map>
#include<unordered_map>
#include<queue>
#include "Priorities.h"
class Pool {
private:
	char* id;
	unsigned int size;
	Priorities queue;//sorted by price, facilitating fast order match
	std::unordered_map<char*, Order*> map;//mapping unique id to order, facilitating fast order location et modification
public:
	void add(Order* const);//add an order to the pool
	void reduce(Order* const);//order reduction
};

#endif
