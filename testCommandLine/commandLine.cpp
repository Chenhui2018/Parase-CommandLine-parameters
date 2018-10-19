#include "ParseCmdLine.h"

#include <string>
#include <vector>
#include <memory>

int main(int argc, char* argv[])
{
	// paras
	std::string			Vstring		("");
	int					Vint		(0);
	unsigned int		Vuint		(0);
	long				Vlong		(0);
	unsigned long		Vulong		(0);
	long long			Vlonglong	(0);
	unsigned long long	Vulonglong	(0);
	short				Vshort		(0);
	unsigned short		Vushort		(0);
	float				Vfloat		(0.0);
	double				Vdouble		(0.0);
	bool				Vbool		(false);

	// parasing to std::string

	// variable name, variable type, variable meaning.
	nameAndType vecParaList = {
		{  "Vstring",	"string" ,		 "Image name, should be a std::string"},
		{  "Vint",		"int" ,			 "A integer"},
		{  "Vuint",		"uint" ,		 "NULL"},
		{  "Vlong",		"long" ,		 "NULL"},
		{  "Vulong",		"ulong" ,	 "NULL"},
		{  "Vlonglong",	"longlong" ,	 "NULL"},
		{  "Vulonglong",	"ulonglong" ,"NULL"},
		{  "Vshort",		"short" ,	 "NULL"},
		{  "Vushort",	"ushort" ,		 "NULL"},
		{  "Vfloat",		"float" ,	 "NULL"},
		{  "Vdouble",	"double" ,		 "NULL"},
		{  "Vbool",		"bool",			 "NULL"}
	};
	nameAndValue_str parameters;
	std::unique_ptr<ParseCmdLine> pPCL = std::make_unique<ParseCmdLine>();
	if (pPCL->parseCmdLine(argc, argv, vecParaList, parameters))
		pPCL->printNameAndValue(parameters);
	else
		return -1;


	// convert to different types 
	Vint			= atoi(parameters["Vint"].c_str());
	Vlong			= atol(parameters["Vlong"].c_str());
	Vlonglong		= atoll(parameters["Vlonglong"].c_str());
	Vfloat			= atof(parameters["Vfloat"].c_str());
	Vdouble			= atof(parameters["Vdouble"].c_str());
	Vbool			= atoi(parameters["Vbool"].c_str()) == 1;
	
	Vstring			= parameters["Vstring"];
	Vint			= pPCL->convertStringTo<int>(parameters["Vint"].c_str());
	Vuint			= pPCL->convertStringTo<unsigned int>(parameters["Vuint"]);
	Vlong			= pPCL->convertStringTo<long>(parameters["Vlong"].c_str());
	Vulong			= pPCL->convertStringTo<unsigned long>(parameters["Vulong"]);
	Vlonglong		= pPCL->convertStringTo<long long>((parameters["Vlonglong"].c_str()));
	Vulonglong		= pPCL->convertStringTo<unsigned long long>(parameters["Vulonglong"]);
	Vshort			= pPCL->convertStringTo<short>(parameters["Vshort"]);
	Vushort			= pPCL->convertStringTo<unsigned short>(parameters["Vushort"]);
	Vfloat			= pPCL->convertStringTo<float>((parameters["Vfloat"].c_str()));
	Vdouble			= pPCL->convertStringTo<double>((parameters["Vdouble"].c_str()));
	Vbool			= atoi(parameters["Vbool"].c_str()) == 1;


	return 0;
}