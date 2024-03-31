/*
 * WrongFormatException.h
 *
 *  Created on: Mar 31, 2024
 *      Author: ww
 */

#include <exception>

#ifndef EXCEPTION_WRONGFORMATEXCEPTION_H_
#define EXCEPTION_WRONGFORMATEXCEPTION_H_

class WrongFormatException : public std::exception{
public:
	WrongFormatException();
	virtual ~WrongFormatException();
};

#endif /* EXCEPTION_WRONGFORMATEXCEPTION_H_ */
