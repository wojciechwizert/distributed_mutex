/*
 * InvalidArgumentError.h
 *
 *  Created on: Mar 31, 2024
 *      Author: ww
 */
#include <exception>

#ifndef EXCEPTION_INVALIDARGUMENTERROR_H_
#define EXCEPTION_INVALIDARGUMENTERROR_H_

class InvalidArgumentError : public std::exception{
public:
	InvalidArgumentError();
	virtual ~InvalidArgumentError();
};

#endif /* EXCEPTION_INVALIDARGUMENTERROR_H_ */
