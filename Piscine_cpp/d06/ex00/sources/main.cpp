#include <iostream>
#include <limits>
#include <stdexcept>
#include <sstream>

class Type
{
};

class Float : public Type
{
	public:
	float f;

	Float(float p_f) { f = p_f; }

};

class Double : public Type
{
	double d;
	public:
	Double(double p_d) { d = p_d; }
};

class Int : public Type
{
	int i;
	public:
	Int(int p_i) { i = p_i; }
};

class Char : public Type
{
	char c;
	public:
	Char(char p_c) { c = p_c; }
};


Type	*convert(std::string p_str)
{
	std::stringstream ss;
	ss << p_str;

	if (p_str.length() == 1)
	{
		char c;
		ss >> c;
		if (!ss.fail())
		{
			std::cout << "char " << c << std::endl;
			return new Char(c);
		}
	}
	if (p_str.find(".") != std::string::npos || p_str.find("nan") != std::string::npos)
	{
		if (p_str[p_str.length() - 1] == 'f')
		{
			float f;
			ss >> f;
			if (!ss.fail())
			{
				std::cout << "float " << f << std::endl;
				return new Float(f);
			}
			else if (p_str.compare("nanf") == 0)
			{
				f = std::numeric_limits<float>::quiet_NaN();
				std::cout << "float " << f << std::endl;
				return new Float(f);
			}
		}
		else
		{
			double d;
			ss >> d;
			if (!ss.fail())
			{
				std::cout << "double " << d << std::endl;
				return new Double(d);
			}
			else if (p_str.compare("nan") == 0)
			{
				d = std::numeric_limits<double>::quiet_NaN();
				std::cout << "double " << d << std::endl;
				return new Double(d);
			}
		}
	}
	else
	{
	}
	return NULL;
}

Float	*isFloat(std::string p_str)
{
	std::stringstream ss;
	if (p_str.find(".") != std::string::npos && p_str[p_str.length() - 1] == 'f')
	{
		float f;
		ss >> f;
		if (!ss.fail())
			return new Float(f);
	}
	else if (!p_str.compare("nan"))
	{
		return new Float(std::numeric_limits<float>::quiet_NaN());
	}
	else if (!p_str.compare("inf"))
	{
		return new Float(std::numeric_limits<float>::infinity());
	}
	else if (!p_str.compare("-inf"))
	{
		return new Float(std::numeric_limits<float>::infinity());
	}
	return NULL;
}

int main(/*int pn_argc, char ** pp_argv*/)
{
	//	if (pn_argc != 2)
	//		return (1);
	try
	{
		Float	*f = isFloat("nan");
		if (f)
		{
			std::cout << "char: " << static_cast<char>(f->f) << std::endl;
			std::cout << "int: " << static_cast<int>(f->f) << std::endl;
			std::cout << "float: " << f->f << std::endl;
			std::cout << "double: " << static_cast<double>(f->f) << std::endl;
		}
	}
	catch(std::exception &e)
	{
		std::cout << "caca";
	}
	return (0);
}
