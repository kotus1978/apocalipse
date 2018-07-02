#include "ComplexGenerator.h"
 

int main(int rgc,char *argv[])
{
	printf("started...\n");
    AlgoGenerator *ag = dynamic_cast<AlgoGenerator *>( new ComplexGenerator(15));
	ag->gen_value();
	delete ag;
	//getc(stdin);
    return 0;
}

