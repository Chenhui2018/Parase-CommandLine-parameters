#pragma once

#include <vector>
#include <string>
#include <map>


#define IN
#define OUT
#define INOUT

typedef std::vector< std::vector< std::string > > nameAndType;
typedef std::map<std::string, std::string> nameAndValue_str;

class ParseCmdLine
{
public:
	ParseCmdLine();
	~ParseCmdLine();

	/*
	{ std::string			,string },
	{ int					,int },
	{ unsigned int			,uint },
	{ long					,long },
	{ unsigned long			,ulong },
	{ long long				,longlong},
	{ unsigned long long	,ulonglong },
	{ short					,short },
	{ unsigned short		,ushort },
	{ float					,float },
	{ double				,double },
	{ bool					,bool}
	*/
	bool parseCmdLine(IN int argc, IN char * argv[], 
		IN const nameAndType & vecParaList, OUT nameAndValue_str & result);

	template<class T>
	T convertStringTo(const std::string str);
	
	void help(IN const nameAndType & vecParaList);
	void printNameAndValue(nameAndValue_str & result);

	

protected:
	std::string & trim(std::string & s);
	


private:
	
	

};

