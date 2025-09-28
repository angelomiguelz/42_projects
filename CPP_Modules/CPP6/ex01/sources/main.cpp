#include "../includes/Serializer.hpp"

int main(void)
{
	Data data = {"beterraba"};

	std::cout << "Data Pointer Before: ->" << &data << "<-" << std::endl;
	std::cout << "Data Info Before: ->" << data.preciousInformation << "<-" << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Data Raw Pointer Serialized: ->" << raw << "<-" << std::endl;
	Data *back = Serializer::deserialize(raw);
	std::cout << "Data Info Deserialized: ->" << back->preciousInformation << "<-" << std::endl;
	std::cout << "Data Pointer Deserialized: ->" << back << "<-" << std::endl;
}
