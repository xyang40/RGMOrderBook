#pragma once
#ifndef PRIORITIES_H
#define PRIORITIES_H
#include<queue>
#include "Order.h"
using std::priority_queue;
class Priorities : private priority_queue<const Order* const> {
public:
	void add(const Order* const);
	void reduce(const Order* const);
};

#endif
