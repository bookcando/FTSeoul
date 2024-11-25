#include "Serializer.hpp"
#include "Data.hpp"

// void leakCheck(void) {
// 	system("leaks ex01 | grep leaked");
// }

int main(void) {
	// atexit(leakCheck);
	Data *data = new Data();
	data->name = "Percy Jackson";
	data->age = 17;
	// Serializer serializer; // can't compile
	
	uintptr_t serialized = Serializer::serialize(data);
	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << deserialized->name << std::endl;
	std::cout << deserialized->age << std::endl;
	
	delete data;
}