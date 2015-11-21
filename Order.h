#pragma once
#ifndef ORDER_H
#define ORDER_H
#include<string>
using std::string;

struct Order {
	unsigned int timestamp;
	char action;
	string id;
	char side;
	double price;
	int size;

	Order(unsigned int ts, char act, string id, char side, double p, int size)://A type order
		timestamp(ts),action(act),id(id),side(side),price(p),size(size) {}

	Order(unsigned int ts, char act, string id, int size) :
		timestamp(ts), action(act), id(id), size(size) {}

	~Order() = default;
};

#endif
