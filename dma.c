#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 4;
    int *b = &a;
    printf("%zu\n",b); // Address in stack
    b = (int*)malloc(sizeof(int));
    printf("%zu\n",b); // Address in heap, This seems to change in every run
    
    int *c;
    c = (int*)calloc(5,sizeof(int));
    printf("%d\n", *c); // Returns 0 as no value was assigned to it and calloc initialized it as 0

    int array[5] = {1,2,3,4,5};
    for(int i = 0; i < 5; i++){
        c[i] = array[i];
        printf("%d\n", c[i]);
    }
    
    int *d = realloc(c,sizeof(int));
    for(int i = 0; i < 5; i++){
        printf("%d\n", d[i]); // Could only return 1 int value, rest all are Garbage Values
    }

    free(c);
    free(b);
    return 0;
}