#pragma once

#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

class JoKerException : public exception {
protected:
	const char* m_ErrorMessage;
public:
	JoKerException(const char* error) noexcept: m_ErrorMessage(error){}
	const char* what() const noexcept {
		//cout << m_ErrorMessage << " ";
		return m_ErrorMessage;
	}
	~JoKerException() {
		;
	}
};
