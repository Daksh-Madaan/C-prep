#include <stdio.h>

int main(){
    int a;
    int *b;
    printf("Value of a: %d\nAddress at b: %zu\n",a,b); // Should give garbage value
    
    b = &a; // b is for Address
    *b = 4; // *b is for Value 
    printf("Value of a: %d\nAddress at b: %zu\n",a,b);
    
    (*b)++; // Used Pointer for Operation
    printf("New Value of a: %d\nAddress of a: %zu\n",*b,b); // Used Pointer to pass variable to printf
    
    int **c; //Double Pointer
    c = &b;
    printf("Address of b: %zu\n", c);
    c++;
    printf("+1 to Address of b: %zu\n",c); // newAddress = oldAddress + 8 [Size of Int on 64 bit Compiler]
    
    char *d;
    d = (char*)b;// (char) normal typecasting and (char *) - typecasting for pointers
    printf("After Typecasting: %zu\n",d); // Address of a(stored in b) seen as Character Type Address
    printf("Typecasted and +1 to address: %zu\n",d+1); // Should only increase by 1
 

    int arr[5] = {1,2,3,4,5};
    int *e = arr;
    *(e+1) = *(e+1) + 8; //*(e+1) - refering to value at address of (arr[0] + 1) i.e Value of arr[1]
    for (int i = 0; i < 5; i++){
        printf("Value:%d \t Address:%zu\n",arr[i],e+i);
    }
    
    char *string = "Single String"; // string[0] = 's' does not work
    char *stringOne[4] = {"Array", "Of","Strings","!"};
    stringOne[0] = "array"; // can be hanged 
    printf("%s",stringOne[0]);

    char stringTwo[4][4] = {"One","Two","Six","Ten"}; // ROWS = No. of Strings. COL. = Length of Strings
    printf("\n%s",stringTwo[0]);// 1st Word
    printf("\n%c",stringTwo[0][2]); // Exact character i.e 3rd letter of 1st Word

    int twoD[2][2] = {{1,2},{3,4}}; 
    int (*f)[2] = twoD;
    printf("\n%d", f); // Address of [0], why? f --> twoD[0]
    printf("\n%d", f+1); // You can see it adds 8 bytes[2 elements] instead of 4 bytes[1 elements] i.e f+1 gives address of 2nd Row not 2nd Element

    printf("\n%d", *f); // Address of [0][0], why? *f --> twoD[0][0]
    printf("\n%d", *f+1); // Address of 2nd Element, adds only 4 to initial address
    printf("\n%d\n", **f); // Value of [0][0]

    printf("Address of [1][0] Using 1st Row: %d", *(f+1));
    return 0;
}