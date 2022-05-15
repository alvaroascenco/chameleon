#ifndef OPERATIONS_H_ 
#define OPERATIONS_H_

bool addService(char* service){
    char lineToWrite[MAX_STRLEN];
    char field[MAX_STRLEN];
    char value[MAX_STRLEN];
    FILE *fp = fopen(".chamFile", "ab+");

    lineToWrite[0] = '\0';

    // '&' is the character delimiting end of service and start of key
    strcat(service, "&");
    printf("%s", lineToWrite);
    strcat(lineToWrite, service);

    // fputs(lineToWrite, fp);
    // fclose(fp);
    // return true;
    while(true){
        printf("what's the name of the field to be stored? (or press enter to terminate program)\n");
        fgets(field, MAX_STRLEN, stdin);

        if(strcmp(field, "\n") == 0){
            break;
        }

        //if line exceeds allowed line size, put line inside document, then clean line and get new values from variable
        if(strlen(field) + strlen(lineToWrite) >= MAX_STRLEN - 1){
            strcat(lineToWrite, "\n");
            fputs(lineToWrite, fp);
            lineToWrite[0] = '\0';
        }

        // '#' is the character delimiting end of key and start of value
        strcat(field, "#");
        strcat(lineToWrite, field);

        printf("what's the name of the value to be stored? (or press enter to terminate program)\n");
        fgets(value, MAX_STRLEN, stdin);

        if(strcmp(value, "\n") == 0){
            break;
        }
        
        //if line exceeds allowed line size, put line inside document, then clean line and get new values from variable
        if(strlen(value) + strlen(lineToWrite) >= MAX_STRLEN - 1){
            strcat(lineToWrite, "\n");
            fputs(lineToWrite, fp);
            lineToWrite[0] = '\0';
        }

        // ';' is the character delimiting end of key value pair (which is also the end of the line)
        strcat(value, ";");
        strcat(lineToWrite, value);

        fputs(lineToWrite, fp);
    }

    fclose(fp);
    return true;
}

void showHelp(){
    printf("\nThanks for using chameleon! \n\n");
    printf("This is the command line program that remembers accounts and their details so you don't have to. \n\n");
    printf("How to use: \n\n");
    printf("cham [command] [service] - eg: cham add youtube \n\n");
    printf("available commands: add/delete/edit/fetch \n");
}

#endif