#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone;
		std::string secret;
	public:
		Contact();
		~Contact();
		int getInfoBase(std::string keyword);
		void showInfoBase(std::string keyword);
		void showInfoAll();
};


#endif
