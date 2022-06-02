#ifndef OPERATIONS_H_ 
#define OPERATIONS_H_

bool addService(char* service){
    char lineToWrite[MAX_STRLEN];
    char field[101];
    char value[101];
    FILE *fp = fopen(".chamFile", "ab+");

    //printf(hash());
    lineToWrite[0] = '\0';

    // '&' is the character delimiting end of service and start of key
    strcat(service, "&");
    printf("%s", lineToWrite);
    strcat(lineToWrite, service);

    // fputs(lineToWrite, fp);
    // fclose(fp);
    // return true;
    while(true){
        printf("what's the name of the field to be stored? (max 100 characters) (or press enter to terminate program)\n");
        fgets(field, MAX_STRLEN, stdin);


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

        printf("what's the name of the value to be stored? (or press enter to terminate program)\n");
        fgets(value, MAX_STRLEN, stdin);

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

    fputs(hash(lineToWrite), fp);

    fclose(fp);
    return true;
}

bool fetchService(char* service){
    FILE *fp = fopen(".chamFile", "r");
    char buffer[MAX_STRLEN];
    char lineFetched[MAX_STRLEN];
    char hashedLine[MAX_STRLEN];
    char* delimiter;
    int delimiterIndex;
    char serviceToCompare[MAX_STRLEN-4];

    while(fgets(buffer, sizeof(buffer), fp)){
        //TODO: fgets is bringing every line at once, splt them by newline
        strcpy(hashedLine, hash(buffer));

        printf(hashedLine);
        //terminate line at delimiter
        delimiter = strchr(hashedLine, '&');
        delimiterIndex = (int)(delimiter - hashedLine);
        hashedLine[delimiterIndex] = 0;


        strcpy(serviceToCompare, hashedLine);

        if(strcmp(serviceToCompare, service) == 0){
            continue;
        }
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
