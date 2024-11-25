#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void testBesigned(Bureaucrat &john, Form &form) {
	static int index = 0;

	std::cout << "beSigned//test number " << index++ << std::endl;
	try {
		form.beSigned(john);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl << std::endl;
		return;
	}
	std::cout << form << std::endl;
	std::cout << "test done without exception" << std::endl << std::endl << std::endl;
	return;
}

void testSignForm(Bureaucrat &john, Form &form) {
	static int index = 0;
	
	std::cout << "signForm//test number " << index++ << std::endl;
	try {
		john.signForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl << std::endl;
		return;
	}
	std::cout << form << std::endl;
	std::cout << "test done without exception" << std::endl << std::endl << std::endl;
	return;
}

void testBureaucratFunc(Bureaucrat &john, void (Bureaucrat::*func)()) {
	static int index = 0;
	
	std::cout << "Bureaucrat//test number " << index++ << std::endl;
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

void testFormGen(int signableGrade, int executableGrade) {
	static int index = 0;
	
	std::cout << "FormGen//test number " << index++ << std::endl;
	try {
		Form testForm("testForm", signableGrade, executableGrade);
		std::cout << testForm << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl << std::endl;
		return;
	}
	std::cout << "test done without exception" << std::endl << std::endl << std::endl;
	return;
}

int main(void) {

	//0. form generation test
	//0.1. form generation with various grade

	//1. besigned test
	//1.1. beSigned with low graded bureaucrat
	//1.2. beSigned with enough graded bureaucrat
	//1.3. beSigned with already signed form

	//2. signForm test
	//2.1. signForm with low graded bureaucrat
	//2.2. signForm with enough graded bureaucrat
	//2.3. signForm with already signed form

	testFormGen(1, 1);
	testFormGen(150, 150);
	testFormGen(1, 150);
	testFormGen(150, 1);
	testFormGen(1, 10);
	testFormGen(10, 1);
	
	std::cout << "-----------------------------" << std::endl;
	testFormGen(0, 0);
	testFormGen(0, 1);
	testFormGen(1, 0);
	testFormGen(0, 150);
	testFormGen(150, 0);
	testFormGen(0, 10);
	testFormGen(10, 0);
	testFormGen(150, 150);
	testFormGen(-1, -1);
	testFormGen(-1, 1);
	testFormGen(1, -1);
	testFormGen(-1, 150);
	testFormGen(150, -1);
	testFormGen(1, 151);
	testFormGen(151, 1);
	testFormGen(1, 2147483647);
	testFormGen(2147483647, 1);

	std::cout << "-----------------------------" << std::endl;
	Form formA1("formA1", 1, 1);
	Form formA1_1("formA1_1", 1, 1);
	Form formA2("formA2", 50, 50);
	Form formA2_1("formA2_1", 50, 50);
	Form formA2_2("formA2_2", 50, 50);

	Bureaucrat worker1("worker1", 1);
	Bureaucrat worker2("worker2", 49);
	Bureaucrat worker3("worker3", 50);
	Bureaucrat worker4("worker4", 51);

	std::cout << "-----------------------------" << std::endl;
	testBesigned(worker4, formA1);
	testBesigned(worker3, formA1);
	testBesigned(worker2, formA1);
	testBesigned(worker1, formA1);

	std::cout << "-----------------------------" << std::endl;
	testSignForm(worker4, formA1_1);
	testSignForm(worker3, formA1_1);
	testSignForm(worker2, formA1_1);
	testSignForm(worker1, formA1_1);

	std::cout << "-----------------------------" << std::endl;
	testBesigned(worker4, formA2);
	testBesigned(worker3, formA2);
	testBesigned(worker2, formA2);
	testBesigned(worker1, formA2);

	std::cout << "-----------------------------" << std::endl;
	testSignForm(worker4, formA2_1);
	testSignForm(worker3, formA2_1);
	testSignForm(worker2, formA2_1);
	testSignForm(worker1, formA2_1);
	
	std::cout << "-----------------------------" << std::endl;
	testSignForm(worker2, formA2_2);
	testSignForm(worker3, formA2_2);
	testSignForm(worker4, formA2_2);
	
	std::cout << "-----------------------------" << std::endl;
	std::cout << "getname : " << formA2.getName() << std::endl;
	std::cout << "getsigned : " << formA2.getSigned() << std::endl;
	std::cout << "getsignablegrade : " << formA2.getSignableGrade() << std::endl;
	std::cout << "getexecutablegrade : " << formA2.getExecutableGrade() << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << formA2 << std::endl;
	std::cout << "-----------------------------" << std::endl;

}
