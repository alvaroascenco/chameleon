#include "includes.h"

int main(int argc, char** argv){

	char acceptedArgs[OPERATIONS_QUANTITY][OPERATIONS_STRLEN] = OPERATIONS;

	//CALL CRUD FUNCTIONS FROM OPERATIONS FILE
	if(strcmp(argv[1], "add") == 0){
		addService(argv[2]);
		return 0;
	}  

	if(strcmp(argv[1], "delete") == 0){
		printf("deletes a service \n");
		return 0;
	}  

	if (strcmp(argv[1], "edit") == 0){
		printf("edits a service \n");
		return 0;
	}  

	if (strcmp(argv[1], "fetch") == 0){
		fetchService(argv[2]);
		return 0;
	}  

	if(strcmp(argv[1], "help") == 0){
		showHelp();
		return 0;
	}

	if (argv[1] == NULL){
		printf("no argument passed. use the 'cham help' command for help \n");
		return 1;
	} 
	
	printf("wrong argument passed. to see what arguments are valid use the 'cham help' command \n");
	return 1;

	// printf("num of args: %d \n", argc);
	// for(int counter = 0; counter < argc; counter++){
	// 	printf("arg %d : %s \n", counter, argv[counter]);
	// }

	// for(int counter = 0; counter < OPERATIONS_QUANTITY; counter++){
	// 	printf("op %d : %s \n", counter, acceptedArgs[counter]);
	// }

}
