#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr) {
    FILE* fp = fopen("config.txt", "r");

    if (fp == NULL)
        return;

    char line[256];
    char key[64];
    char value[64];

    while(fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%[^=]=%s", key ,value);

        if(strcmp(key, "InputFileName") == 0){
            strcpy(config_ptr->InputFileName, value);
        }
        else if (strcmp(key, "Options") == 0) {
            config_ptr->Options = atoi(value);
        }
        else if(strcmp(key, "SectionName") == 0) {
            strcpy(config_ptr->SectionName, value);
        } 
        else if(strcmp(key, "Address") == 0) {
            sscanf(value, "%llx", &config_ptr->Address);
        }
    }

    fclose(fp);

}

int main(int argc, const char* argv[]) {
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n",
        config.InputFileName,
        config.Options,
        config.SectionName,
        config.Address);
    
    return 0;
}