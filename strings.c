#include <stdio.h>
#include <stdlib.h>

int length(char *string) {
    int l = 0;
    for(int i = 0; string[i] != '\0'; i++){
        l=l+1;
    }
    return l;    
}

void reverse(char *string, char *rev){
    int l = length(string);   
    for(int i = 0; i <= l; i++){
        rev[(l-1)-i] = string[i];
    } 
}

int compare(char *stringOne, char *stringTwo){
    if(length(stringOne) == length(stringTwo)){
        for(int i = 0; i < length(stringOne); i++){
            if(stringOne[i] != stringTwo[i]){
                return 0;
            }
        }
        return 1;
    }
    else{
        return 0;
    }
}

void copy(char *stringOne,char *stringTwo){
    for(int i = 0; i <= length(stringOne); i++){
        stringTwo[i] = stringOne[i];
    } 
}

void uppercase(char* string){
    for (int i = 0; i <= length(string); i++)
    {
        int c = (int)string[i];
        if(97<=c && c<=(97+26)){
            char d = (char)(c-32); 
            string[i] = d;
        }
    }
    
}

char lowercase(char *string){
    for (int i = 0; i <= length(string); i++)
    {
        int c = (int)string[i];
        if(65<=c && c<=(65+26)){
            char d = (char)(c+32); 
            string[i] = d;
        }
    }
}

char *join(char string1[], char string2[]){
    char *result = malloc(length(string1) + length(string2));
    for(int i = 0; i <= length(string1); i++){
        result[i] = string1[i];
    }  
    for(int i = 0; i <= length(string2); i++){
        result[length(string1)+i] = string2[i];
    }
    return result;
}

int main() {
    char name[] = "Joyboy";

    char reve[length(name)];
    reverse(name,reve);
    printf("%s\n",reve);

    printf("PACMAN vs MARIO:%d\n",compare("PACMAN","MARIO"));
    printf("Joyboy vs Joyboy:%d\n",compare(name,name));

    char copyName[length(name)];
    copy(name,copyName);
    printf("%s\n",copyName);

    uppercase(name);
    printf("%s\n",name);

    lowercase(name);
    printf("%s\n",name);

    char fn[] = "SAMPLE TEXT FOR JOINING A BIGGER STRING";
    char ln[] = ", HOPE THIS WORKS";
    
    printf("%s\n", join(fn,ln));
    return 0;
}