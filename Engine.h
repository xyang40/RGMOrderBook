#pragma once
#ifndef ENIGINE_H
#define ENGINE_H
#include<map>
#include<unordered_map>
#include "Pool.h"
#include "Order.h"

class Engine {
private:
	Pool buy;
	Pool sell;
	int target_size;
public:
	Engine();
	~Engine();
	void run(const Order* const);
};

#endif
