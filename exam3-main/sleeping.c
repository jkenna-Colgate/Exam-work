/********
 * Exam 3 Take-home
 * COSC 208, Introduction to Computer Systems, Spring 2023
 ********/
#include <stdio.h>
#include <stdin.h>
int main() {        
int pid1 = fork();
if (pid1 < 0){
    printf("fork failed");
    return 0;
}
else if (pid1 > 0){
    printf ("my first child is %d", pid1);
    int pid2 = fork();
    if (pid2 < 0){
        prinf("fork failed");
        return 0;
    }
    else if(pid2 > 0){
        wait(NULL);
    }


}
}
