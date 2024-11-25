#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "util.hpp"

#include <iostream>

// void leakTest() {
// 	system("leaks ex02 | grep leaked");
// }
#ifdef DEBUG
void typeConversionExamples() {
	
	// static cast : type check in compile time
	int numA = 42;
	char numAC = static_cast<char>(numA);
	float numAF = static_cast<float>(numA);
	double numAD = static_cast<double>(numA);
	std::cout << "numA: " << numA << std::endl;
	std::cout << "numAC: " << numAC << std::endl;
	std::cout << "numAF: " << numAF << std::endl;
	std::cout << "numAD: " << numAD << std::endl;
	// float *numAFP = static_cast<float *>(&numA);
	int *numAP = static_cast<int *>(&numA);
	std::cout << "numAP: " << *numAP << std::endl;
	// float *numAFP = static_cast<float *>(numAP); //compile error
	
	// Base *numBase1 = static_cast<Base *>(numA); //compile error
	// Base numBase2 = static_cast<Base>(numA); //compile error
	Base *numBase3 = static_cast<Base *>(new A());
	delete numBase3;
	numBase3 = 0;
	// A *tempObjectA = static_cast<Base *>(new Base()); // compile error
	// putting Base into A * with static cast : compile error
	
	
	// dynamic cast : type check in runtime
	// used for downcasting
	Base *base = new A();
	A *a = dynamic_cast<A *>(base); // putting base into A pointer
	if (a == 0) {
		std::cout << "base is not A" << std::endl;
	}
	else {
		std::cout << "base is A" << std::endl;
	}
	// why? because then, base can use A's member function
	delete base;
	
	base = new B();
	a = dynamic_cast<A *>(base); // putting B into A pointer
	if (a == 0) {
		std::cout << "B is not A" << std::endl;
	}
	else {
		std::cout << "B is A" << std::endl;
	}
	delete base;
	
	C *refBase = new C();
	try {
		A &tempRef = dynamic_cast<A &>(*refBase);
		std::cout << "C is A" << std::endl;
		(void)tempRef;
		delete refBase;
	}
	catch (std::bad_cast &e) {
		std::cout << "C is not A" << std::endl;
	}
	delete refBase;
	refBase = 0;
	//people say, upcast is safe and always success
	
	
	
	
	//const cast
	const int numConst = 100;
	int *numNonConst = const_cast<int *>(&numConst);
	*numNonConst = 50;
	std::cout << "numConst: " << numConst << std::endl;
	std::cout << "numNonConst: " << *numNonConst << std::endl;
	
	int numNonConst2 = 123;
	const int *numConst2 = const_cast<const int *>(&numNonConst2);
	// *numConst2 = 321; //compile error
	(void)numConst2;
	
	
	
	//reinterpret cast, bit level conversion
	float baseNum = 42.195;
	int *numReinterpretInt = reinterpret_cast<int *>(&baseNum);
	std::cout << "baseNum: " << baseNum << std::endl;
	std::cout << "numReinterpretInt: " << *numReinterpretInt << std::endl;
	
	double *numReinterpretDouble = reinterpret_cast<double *>(&numReinterpretInt);
	std::cout << "numReinterpretDouble: " << *numReinterpretDouble << std::endl;
	
	
	
}
#endif

int main(void) {
	// atexit(leakTest);
	#ifdef DEBUG
	typeConversionExamples();
	#endif
	
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	
	base = generate();
	identify(base);
	identify(*base);
	delete base;

	base = generate();
	identify(base);
	identify(*base);
	delete base;

}