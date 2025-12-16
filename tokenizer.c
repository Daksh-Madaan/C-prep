#include <stdio.h>

int WordCount(char *string){
    int words=1;
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == ' '){
            words++;
        }
    }
    return words;
}

int length(char *string){
    int l=1;
    for(int i = 0; string[i] != '\0'; i++){
        l++;
    }
    return l;
}

int main() {
    char string[] =  "Why use a lorem ipsum generator?";
    int words = WordCount(string);
    char tokens[words][30]; 
    int ls=0;
    int us=0;
    int k=0;
    int len=0;
    for(int i = 0;i < length(string); i++){
        if(string[i] == ' ' || string[i] == '\0'){
            if(us!=0){
                ls=us+1;
            }
            else if (ls==0){
                ls=us;
            }
            us=i;
            for(int j = ls; j < us; j++){
                tokens[k][len] = string[j];
                len=len+1;  
            }
            tokens[k][len] = '\0';
            len=0;
            k=k+1;        
        }    
    }
    for (int i = 0; i < words; i++)
    {
        printf("{%s}\n",tokens[i]);
    }

    return 0;
}