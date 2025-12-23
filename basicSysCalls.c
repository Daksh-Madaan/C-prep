#include <unistd.h>
#include <sys/wait.h>

int main() {
    sleep(2);// sleeps for 2 seconds and then the following lines are executed

    fork(); // creates a Child Process, 0 if Child and P-id if Parent
    wait(NULL); // makes the parent wait for child to finish otherwise both run side by side

    write(1,"Enter one digit:\n",18); // prints 18 bytes of data
    int buff[1];
    /*
    write() and read() take something known as File Descriptor as their 1st arguement
    0 -- Input
    1 -- Output
    2 -- Error
    */
    read(0,buff,1); // takes input of 1 byte
    write(1,buff,1); // prints given digit
    write(1,"\n",1);
    return 0;
}