#pragma once
#ifndef ORDER_H
#define ORDER_H

struct Order {
	unsigned int timestamp;
	char action;
	char* id;
	char side;
	double price;
	int size;
};

#endif
