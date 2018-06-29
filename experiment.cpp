#include "ComplexGenerator.h"
 

int main(int rgc,char *argv[])
{
	printf("started...\n");
    AlgoGenerator *ag = dynamic_cast<AlgoGenerator *>( new ComplexGenerator(5));
	ag->gen_value();
	getc(stdin);
    return 0;
}

