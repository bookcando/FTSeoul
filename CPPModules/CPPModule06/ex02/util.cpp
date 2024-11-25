
#include <ctime>
#include <sys/time.h>
#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <typeinfo>

Base *generate(void) {
	struct timeval time;
	
	gettimeofday(&time, NULL);
	std::srand(time.tv_usec);
	size_t random = std::rand() % 3;

#ifndef DEBUG
	if (random == 0) {
		return new A();
	}
	else if (random == 1) {
		return new B();
	}
	else {
		return new C();
	}
#else
	if (random == 0) {
		std::cout << "A has made" << std::endl;
		return new A();
	}
	else if (random == 1) {
		std::cout << "B has made" << std::endl;
		return new B();
	}
	else {
		std::cout << "C has made" << std::endl;
		return new C();
	}
#endif
	
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B *>(p)) {
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C *>(p)) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::bad_cast &e) {
		try {
			B &b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			(void)b;
		}
		catch (std::bad_cast &e) {
			try {
				C &c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				(void)c;
			}
			catch (std::bad_cast &e) {
				std::cout << "Not in A, B and C." << std::endl;
			}
		}
	}
}
