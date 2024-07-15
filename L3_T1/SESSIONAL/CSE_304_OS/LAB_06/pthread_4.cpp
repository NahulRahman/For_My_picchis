#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include <time.h>
#include <stdlib.h>
#include<windows.h>
// Thread function
void* myturn(void* arg) { //void pointer is generic, can point to anything.
    int *iptr = (int *)malloc(sizeof(int)); ///dynamically allocates memory in heap for an integer on the heap and assigns the address of this memory to the pointer iptr.
    *iptr = 5;
    for (int i = 0; i < 8; i++) {
        Sleep(1);
        printf("My turn! %d %d\n", i,*iptr);
        (*iptr)++;
    }
    return iptr; // Returning the pointer to the allocated integer
    ///Returning *iptr would return the integer value stored in the memory, not the address. This would make it impossible to free the allocated memory later, leading to potential memory leaks.
}

void yourturn() {

    for (int i = 0; i < 3; i++) {
        Sleep(2);
        printf("Your turn!\n");
    }
}
int main(){
    pthread_t newthread;
    int *result; //declared as a pointer to an integer
    //Function to create a new thread
    pthread_create(&newthread, NULL, myturn, NULL);

    yourturn();
    //Waits for the newthread to finish and retrieves the return value
    pthread_join(newthread, (void**)&result); //store the return value in "result" of the thread function.
    /// ** - a pointer to a pointer  is used to capture the return value of the thread function
    printf("Thread is done: result=%d\n",*result);
    free(result); /// to avoid memory leaks/waste
}

///Pointer (iptr): Holds the address of the dynamically allocated memory.
///Dereferencing (*iptr): Accesses or modifies the value stored at the memory location pointed to by iptr.
///Assignment (*iptr = 5;): Assigns the value 5 to the memory location accessed by dereferencing iptr.
