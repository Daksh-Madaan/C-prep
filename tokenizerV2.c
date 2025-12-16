#include <stdio.h>

int WordCount(char *string){
    int words=0;
    int ls=0;
    int ns=0;
    int len=0;

    for(int j = 0;string[j] != '\0'; j++){
        len++;
    }
    
    for(int i = 0;i<=len; i++){
        if(string[i] == ' ' || string[i] == '\0'){
            ls=ns;
            ns=i;
            if((ls!=ns) && (ns!=ls+1)){
                words = words+1;
            }
        }
    }
    return words;
}

int main(){
    char *string = "Why use a lorem ipsum generator?";
    char tokens[WordCount(string)][25];
    int c=0;
    int k=0;
    int len = 0;
    while(string[c] != '\0'){
        if(string[c] != ' '){
            tokens[k][len] = string[c];
            len++;
        }
        else{
            tokens[k][len] = '\0';
            k++;
            len=0;
        }
        c++;
    }
    tokens[k][len] = '\0';
    for (int i = 0; i < WordCount(string); i++)
    {
        printf("%s\n",tokens[i]);
    }
    
    return 0;
}