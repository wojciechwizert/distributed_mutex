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
	for(int i=0;i<50;++50) {
		str1+=(str1 + std::to_string(i));
		for(int j=0;j<50;++j) {
			str1+=(str1 + std::to_string(i));
		}
	}
	struct Helper{
		int* tmp;
		Helper() {
			tmp = new int[100];
		}
		~Helper() {
			delete[] tmp;
		}
	} helper;
	std::cout << "costam wypisz na console" << std::endl;
}

