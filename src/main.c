#include <stdio.h>
#include "configs.h"

int main(int argc, char** argv){

	char acceptedArgs[OPERATIONS_QUANTITY][OPERATIONS_STRLEN] = OPERATIONS;

	printf("num of args: %d \n", argc);
	for(int counter = 0; counter < argc; counter++){
		printf("arg %d : %s \n", counter, argv[counter]);
	}

	for(int counter = 0; counter < OPERATIONS_QUANTITY; counter++){
		printf("op %d : %s \n", counter, acceptedArgs[counter]);
	}

}
