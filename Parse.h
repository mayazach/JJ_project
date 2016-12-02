#ifndef PARSE_H_
#define PARSE_H_
#include <sstream>
#include <string>
#include <stdlib.h> 
#include "Edge.h"
#include "Task.h"


using namespace std;

/*epistrefei: EXIT_SUCCESS an diabasthkan oi komboi ths akmhs, 
EXIT_FAILURE an parousiasthke problhma,
2 an diabasthke o termatikos xarakthras 'F'*/

class Parse
{
public:
	int parseInput(string, Edge&);
	int parseWorkload(string, Task&);
};

#endif