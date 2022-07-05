#ifndef OPERATIONS_H_ 
#define OPERATIONS_H_

bool addService(char* service){
    char lineToWrite[MAX_STRLEN];
    char field[101];
    char value[101];
    FILE *fp = fopen(".chamFile", "ab+");
    FILE *fpdbg = fopen(".chamFileDebug", "ab+");

    //printf(hash());
    lineToWrite[0] = '\0';

    // '&' is the character delimiting end of service and start of key
    strcat(service, "&");
    strcat(lineToWrite, service);

    // fputs(lineToWrite, fp);
    // fclose(fp);
    // return true;
    while(true){
        printf("what's the name of the field to be stored? (max 100 characters) (or press enter to terminate program) \n");
	fflush(stdout);
        fgets(field, sizeof(field), stdin);

        if(strcmp(field, "\n") == 0){
            break;
        }

        //removing newline character
        field[strcspn(field, "\n")] = 0;

        // //if line exceeds allowed line size, put line inside document, then clean line and get new values from variable
        // if(strlen(field) + strlen(lineToWrite) >= MAX_STRLEN - 1){
        //     strcat(lineToWrite, "\n");
        //     fputs(lineToWrite, fp);
        //     lineToWrite[0] = '\0';
        // }

        // '#' is the character delimiting end of key and start of value
        strcat(field, "#");
        strcat(lineToWrite, field);

        printf("what's the name of the value to be stored? (or press enter to terminate program) \n");
	fflush(stdout);
        fgets(value, MAX_STRLEN, stdin);

	//TODO: BUG LETS PROGRAM EXIT WITH NO VALUE ATTACHED TO FIELD
        if(strcmp(value, "\n") == 0){
            break;
        }

        //removing newline character
        value[strcspn(value, "\n")] = 0;
        
        // //if line exceeds allowed line size, put line inside document, then clean line and get new values from variable
        // if(strlen(value) + strlen(lineToWrite) >= MAX_STRLEN - 1){
        //     strcat(lineToWrite, "\n");
        //     fputs(lineToWrite, fp);
        //     lineToWrite[0] = '\0';
        // }

        // ';' is the character delimiting end of key value pair (which is also the end of the line)
        strcat(value, ";");
        strcat(lineToWrite, value);
    }

    // quitting function if user quits before registering a key - value pair
    if(strstr(lineToWrite, "#") == NULL
        || strstr(lineToWrite, ";") == NULL){
            fclose(fp);
            return false;
    }

    strcat(lineToWrite, "\n");

    // the original lineToWrite variable is overwritten for every call of the hash function
    fputs(hash(lineToWrite), fp);
    fputs(hash(lineToWrite), fpdbg);

    fclose(fp);
    fclose(fpdbg);
    return true;
}

bool fetchService(char* service){
    FILE *fp = fopen(".chamFile", "r");
    char buffer[MAX_STRLEN];
    char decodedBuffer[MAX_STRLEN];
    char* serviceToTest;
    char* fieldToTest;
    char* valueToTest;
    char* lineToTest;
    char* bufferRemainder;
    size_t lineToTestSize;

    if(fp == NULL){
      printf("no chamfile generated yet, please add a service so it can be fetched \n");
      exit(EXIT_FAILURE);
    }

    while(fgets(buffer, sizeof(buffer), fp)){
      strcpy(decodedBuffer, hash(buffer));

      lineToTest = strtok(decodedBuffer, "\n");

      //getting rest of the string
      bufferRemainder = strtok(NULL, "\0");

      /* printf("buffer remainder: %s\n", bufferRemainder); */

      //saving the rest of the buffer to be used after line is scanned
      /* printf("decoded buffer after: %s\n", decodedBuffer); */
      lineToTestSize = strlen(lineToTest);
      /* printf("line to test size: %d\n", lineToTestSize);  */

      char* p = decodedBuffer;
      printf("index of first occurence of line to test on decoded buffer: %d\n", strstr(decodedBuffer, lineToTest));

      /* while((p = strstr(p, lineToTest)) != NULL){ */
      /* 	memmove(p, p+lineToTestSize, strlen(p+lineToTestSize) + 1); */
      /* } */
      
      
      while(lineToTest != NULL){
	serviceToTest = strtok(lineToTest, "&");
	printf("servico: %s \n", serviceToTest);

	
	fieldToTest = strtok(NULL, "#");

	while(fieldToTest != NULL){
	  
	    printf("usuario: %s \n", fieldToTest);

	    valueToTest = strtok(NULL, ";");
	    printf("senha: %s \n", valueToTest);

	    fieldToTest = strtok(NULL, "#");
	}

	/* //doing a loop iteration once and then doing it repeatedly until the line finishes */
	/* fieldToTest = strtok(NULL, "#"); */
	/* printf("campo: %s ", fieldToTest); */
	/* valueToTest = strtok(NULL, ";"); */
	/* while(strstr(valueToTest, "\n") != NULL){ */
	/*   printf("valor: %s ", valueToTest); */
	/*   fieldToTest = strtok(NULL, "#"); */
	/*   printf("campo: %s ", fieldToTest); */
	/*   valueToTest = strtok(NULL, ";"); */
	/* }  */

	lineToTest = strtok(bufferRemainder, "\n");
	bufferRemainder = strtok(NULL, "\0");
      }
      printf("acabou o arquivo");
      /* serviceToTest = strtok(decodedBuffer, "&"); */

      /* printf("servico: %s", serviceToTest); */
      /* do{ */
      /* 	fieldToTest = strtok(NULL, "#"); */
      /* 	printf("campo: %s", fieldToTest); */
      /* 	valueToTest = strtok(NULL, ";"); */
      /* 	printf("valor: %s", valueToTest); */
      /* }while(strstr(fieldToTest, "\n") == NULL && strstr(valueToTest, "\n") == NULL); */
    }

    fclose(fp);
}

void showHelp(){
    printf("\nThanks for using chameleon! \n\n");
    printf("This is the command line program that remembers accounts and their details so you don't have to. \n\n");
    printf("How to use: \n\n");
    printf("cham [command] [service] - eg: cham add youtube \n\n");
    printf("available commands: add/delete/edit/fetch \n");
}

#endif
