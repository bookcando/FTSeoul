#include "Bureaucrat.hpp"

void testBureaucratFunc(Bureaucrat &john, void (Bureaucrat::*func)()) {
	static int index = 0;
	
	std::cout << "Func//test number " << index++ << std::endl;
	try {
		(john.*func)();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl << std::endl;
		return;
	}
	std::cout << john << std::endl;
	std::cout << "test done without exception" << std::endl << std::endl << std::endl;
	return;
}

void testBureaucratGen(int grade) {
	static int index = 0;
	
	std::cout << "Gen//test number " << index++ << std::endl;
	try {
		Bureaucrat john("John", grade);
		std::cout << john << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl << std::endl;
		return;
	}
	std::cout << "test done without exception" << std::endl << std::endl << std::endl;
	return;
}

int main(void){

//1. bureaucrat constructor
//2. bureaucrat copy constructor
//3. bureaucrat assignment operator
//4. bureaucrat getName, getGrade

//1. making bureaucrat with lower grade
//2. making bureaucrat with higher grade
//3. making bureaucrat with any other strange-invalid grade
//4. making bureaucrat with grade 1
//5. making bureaucrat with grade 150
//6. making bureaucrat with grade 10

//1. promoting bureaucrat with grade 150
//2. promoting bureaucrat with grade 1
//3. promoting bureaucrat with grade 10

//1. demoting bureaucrat with grade 150
//2. demoting bureaucrat with grade 1
//3. demoting bureaucrat with grade 10

	testBureaucratGen(1);
	testBureaucratGen(150);
	testBureaucratGen(10);
	testBureaucratGen(0);
	testBureaucratGen(151);
	testBureaucratGen(-1);
	testBureaucratGen(2147483647);

	Bureaucrat worker1("worker1", 1);
	Bureaucrat worker2("worker2", 10);
	Bureaucrat worker3("worker3", 150);

	std::cout << "-----------------------------" << std::endl;
	testBureaucratFunc(worker1, &Bureaucrat::promoteGrade);
	testBureaucratFunc(worker2, &Bureaucrat::promoteGrade);
	testBureaucratFunc(worker3, &Bureaucrat::promoteGrade);

	testBureaucratFunc(worker1, &Bureaucrat::demoteGrade);
	testBureaucratFunc(worker2, &Bureaucrat::demoteGrade);
	testBureaucratFunc(worker3, &Bureaucrat::demoteGrade);

	testBureaucratFunc(worker1, &Bureaucrat::promoteGrade);
	testBureaucratFunc(worker3, &Bureaucrat::demoteGrade);

	std::cout << "-----------------------------" << std::endl;
	std::cout << worker1 << std::endl;
	std::cout << worker2 << std::endl;
	std::cout << worker3 << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << worker1.getGrade() << std::endl;
	std::cout << worker2.getGrade() << std::endl;
	std::cout << worker3.getGrade() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << worker1.getName() << std::endl;
	std::cout << worker2.getName() << std::endl;
	std::cout << worker3.getName() << std::endl;
		
	std::cout << "-----------------------------" << std::endl;
	Bureaucrat worker4(worker1);
	Bureaucrat worker5(worker2);
	Bureaucrat worker6(worker3);

	std::cout << worker4 << std::endl;
	std::cout << worker5 << std::endl;
	std::cout << worker6 << std::endl;

	std::cout << "-----------------------------" << std::endl;



}