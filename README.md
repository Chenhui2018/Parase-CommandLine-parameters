# Parase-CommandLine-parameters
This code is for parasing command line parameter easier.
===

## The example of how to use it could be:
```
xxxx.exe --Vstring="lai" --Vint=5 --Vdouble=1.0 --Vbool=1 --Vulong=123456789
```
Note that, for now, there shold no have space beside "=". We will fix it in next version.
---

## Part of demo
```
typedef std::vector< std::vector< std::string > > nameAndType;
typedef std::map<std::string, std::string> nameAndValue_str;

	// variable name, variable type, variable meaning.
	nameAndType vecParaList = {
		{  "Vstring",	"string" ,		 "Image name, should be a std::string"},
		{  "Vint",		"int" ,			 "A integer"},
		{  "Vuint",		"uint" ,		 "NULL"},
		{  "Vlong",		"long" ,		 "NULL"},
		{  "Vulong",	"ulong" ,		"NULL"},
		{  "Vlonglong",	"longlong" ,	 "NULL"},
		{  "Vulonglong","ulonglong" ,	"NULL"},
		{  "Vshort",	"short" ,		"NULL"},
		{  "Vushort",	"ushort" ,		 "NULL"},
		{  "Vfloat",	"float" ,		"NULL"},
		{  "Vdouble",	"double" ,		 "NULL"},
		{  "Vbool",		"bool",			 "NULL"}
	};
	nameAndValue_str parameters;
	std::unique_ptr<ParseCmdLine> pPCL = std::make_unique<ParseCmdLine>();
	if (pPCL->parseCmdLine(argc, argv, vecParaList, parameters))
		pPCL->printNameAndValue(parameters);
	else
		return -1;
```
Every elements of vecParaList should contain NAME,TYPE,MEANING(Can be "");
When you give a type, you need to modify it into the keywords as follow.


## The list of supported types
  { typeName in C++			,keywords },
	{ std::string			    ,string },
	{ int					        ,int },
	{ unsigned int		    ,uint },
	{ long					      ,long },
	{ unsigned long		    ,ulong },
	{ long long				    ,longlong},
	{ unsigned long long	,ulonglong },
	{ short					      ,short },
	{ unsigned short		  ,ushort },
	{ float					      ,float },
	{ double				      ,double },
	{ bool					      ,bool}
  
---


