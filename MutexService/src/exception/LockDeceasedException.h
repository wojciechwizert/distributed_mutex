/*
 * LockDeceasedException.h
 *
 *  Created on: Mar 14, 2024
 *      Author: ww
 */

#ifndef EXCEPTION_LOCKDECEASEDEXCEPTION_H_
#define EXCEPTION_LOCKDECEASEDEXCEPTION_H_
#include <stdexcept>

class LockDeceasedException : public std::runtime_error {
public:
	using std::runtime_error::runtime_error;
	~LockDeceasedException() {}
};

#endif /* EXCEPTION_LOCKDECEASEDEXCEPTION_H_ */
