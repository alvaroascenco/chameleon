#ifndef OPERATIONS_H_ 
#define OPERATIONS_H_

bool addService(char* service){
    char lineToWrite[MAX_STRLEN];

    FILE *fp = fopen(".chamFile", "ab+");
    fputs(service, fp);
    fclose(fp);
    return true;
}

#endif