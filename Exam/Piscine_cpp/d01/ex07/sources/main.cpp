#include <fstream>
#include <iostream>

std::string toUpper(std::string p_String)
{
	for (unsigned int i = 0; i < p_String.length(); i++)
	{
		if (p_String[i] >= 'a' && p_String[i] <= 'z')
			p_String[i] -= 32;
	}
	return p_String;
}

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "USAGE: filename, s1, s2" << std::endl;
		return (1);
	}
	std::ifstream ifs(argv[1]);
	if (ifs.is_open())
	{
		std::string ofsName = toUpper(argv[1]);
		ofsName += ".replace";
		std::ofstream ofs(ofsName);
		if (ofs.is_open())
		{
			std::string file;

			ifs.seekg(0, std::ios::end);   
			file.reserve(ifs.tellg());
			ifs.seekg(0, std::ios::beg);

			file.assign((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

			std::string newString = ReplaceAll(file, argv[2], argv[3]);
			ofs << newString.c_str();
			ofs.close();
		}
		ifs.close();
	}
	else
		std::cout << "Can't open file" << std::endl;


	return (0);
}