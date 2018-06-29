#include "ComplexGenerator.h"
 

int main(int rgc,char *argv[])
{
	printf("started...\n");
    AlgoGenerator *ag = dynamic_cast<AlgoGenerator *>( new ComplexGenerator(atoi(argv[1])));
	ag->gen_value();
	//getc(stdin);
    return 0;
}

