#ifndef OPERATIONS_H_ 
#define OPERATIONS_H_

bool addService(char* service){
    char lineToWrite[MAX_STRLEN];

    FILE *fp = fopen(".chamFile", "ab+");
    fputs(service, fp);
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