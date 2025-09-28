#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
# include "Contact.hpp"

class Phonebook {
    private:
        Contact contacts[8];
		int		index;
    public:
		Phonebook();
        void ADD();
		void SEARCH();
};


#endif
