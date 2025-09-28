#include "../includes/Sed.hpp"

int main(int ac, char **av){

	if (ac != 4)
	{
		std::cout << "Invalid Arguments" << std::endl;
		return 1;
	}

	std::string in_filename = av[1];
	std::string out_filename = in_filename + ".replace";
	std::string find = av[2];
	std::string replace = av[3];

	std::fstream infile;
	std::ofstream outfile;

	infile.open(in_filename.c_str());
	if (!infile)
	{
		std::cout << "Couldnt Open File" << std::endl;
		return 1;
	}
	outfile.open(out_filename.c_str());
	if (!outfile)
	{
		std::cout << "Couldnt Open Outfile" << std::endl;
		if (infile)
			infile.close();
		return 1;
	}
	std::string content;
	while (std::getline(infile, content))  //getline returns false when eof
	{
		int index = content.find(find);
		while (index != -1)
		{
			content.erase(index, find.length());
			content.insert(index, replace);
			index = content.find(find, index + replace.length());
		}
		outfile << content << std::endl;
	}
	infile.close();
	outfile.close();
}
