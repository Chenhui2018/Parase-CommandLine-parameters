#include "ParseCmdLine.h"
#include <iostream>
#include <vector>


ParseCmdLine::ParseCmdLine()
{
}

ParseCmdLine::~ParseCmdLine()
{
}



bool ParseCmdLine::parseCmdLine(
	IN int argc, IN char* argv[],
	IN const nameAndType & vecParaList, OUT nameAndValue_str & result)
{
	if (argc <= 1)
	{
		help(vecParaList);
		result = std::map<std::string, std::string>();
		return false;
	}

	for (int i = 1; i < argc; ++i)
	{
		std::string word(argv[i]);
		//word = trim(word); // todo: allow space

		// check
		if (word.substr(0, 2) != "--")
		{
			std::cout << "Input parameter format error : "<< word << std::endl << std::endl;
			help(vecParaList);
			return false;
		}

		result.insert({
			word.substr(2, word.find_first_of("=")-2),
			word.substr(word.find_first_of("=") + 1, word.length() - word.find_first_of("="))
		});
	}

	return true;
}

void ParseCmdLine::help(IN const nameAndType & vecParaList)
{
	std::cout << "--help: " << std::endl << std::endl
		<< "  The parameters format is --example=1.0 " << std::endl << std::endl
		<< "  The parameters list is as follow:" << std::endl
		<< "-  Name  |  Type  |  Meaning  -" << std::endl;

	for (size_t i=0;  i<vecParaList.size(); ++i)
	{
		std::cout << "-    " << vecParaList[i][1] << " | " << vecParaList[i][0] 
			<< " | " << vecParaList[i][2]<<";"<< std::endl;
	}
	std::cout << std::endl;
}


void ParseCmdLine::printNameAndValue(nameAndValue_str & result)
{
	std::cout << "--debug: print result in std::string " << std::endl;
	if(result.empty())
		std::cout << "-  result is empty." << std::endl;


	for (auto sub : result)
	{
		std::cout << "-  " << sub.first.c_str() << "=" << sub.first.c_str() << ";" << std::endl;
	}
	std::cout << std::endl;
}

template<class T>
T ParseCmdLine::convertStringTo(const std::string str)
{
	auto begin = str.find_first_of(".");
	auto end = str.find_last_of(".");

	T result(0);

	if (begin != end)
		return result;

	size_t integerLength(str.size());
	for (int i = str.size() - 1; i >= 0; --i)
	{
		T temp(0);
		size_t k = integerLength - i - 1;
		if (isdigit(str[i]))
		{
			temp = str[i] - '0';
			while (k--)
				temp *= 10;
			result += temp;
		}
		else if (str[i] == '.')
		{
			integerLength = integerLength - k - 1;
			while (k--)
				result *= static_cast<T>(0.1);
		}
		else
			break;
	}

	return result;
}


std::string& ParseCmdLine::trim(std::string &s)
{
	if (s.empty())
		return s;

	std::string temp;
	for (size_t i=0; i<s.size(); ++i)
	{
		if (s[i] != ' ')
			temp.push_back(s[i]);
	}

	s = temp;
	return s;
}

