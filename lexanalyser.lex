%{
    #include <math.h>
	#include <cstdio> 
	#include <map>
	#include <utility>
	#include <vector>
	#include <string>
	#include <iostream>
	#include <algorithm>
	#include <iomanip>

    using namespace std;
    map<string,vector<string>> tokentoLexeme;

%}

BOOL bool
BREAK break
CASE case
CONTINUE continue
GOTO goto
DO do
DEFAULT default 
IF if
ELSE else 
FOR for 
CONST const 
TRUE true 
FALSE false
STATIC static 
SWITCH switch 
WHILE while 
VOID void 
RETURN return 
SIZEOF sizeof
FLOAT float 
INTEGER int 
DOUBLE double 
EXTERN extern 
SHORT short 
LONG long 