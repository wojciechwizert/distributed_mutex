/*
 * Cache.cpp
 *
 *  Created on: Mar 31, 2024
 *      Author: ww
 */

#include "Cache.h"
#include <string>
#include <iostream>

Cache::Cache() {
	// TODO Auto-generated constructor stub

}

Cache::~Cache() {
	// TODO Auto-generated destructor stub
}

void Cache::foo() const {
	struct Costam{
		int* tmp;
		Costam() {
			tmp = new int[100];
		}
		~Costam() {
			delete[] tmp;
		}
	} costam;
	std::string str1 = "costam";
	int k=100;
	while(k-->0) {
		str1=std::to_string(k);
	}

	std::cout << "costam wypisz na console" << std::endl;
}

