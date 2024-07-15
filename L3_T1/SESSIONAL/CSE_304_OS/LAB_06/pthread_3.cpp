#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include <time.h>
#include<windows.h>

// Thread function
void* myturn(void* arg) { //void pointer is generic, can point to anything.
    int *iptr = (int *)arg; //v is int- we have to tell the pointer
    for (int i = 0; i < 8; i++) {
        Sleep(1);
        printf("My turn! %d, v= %d\n", i,*iptr);
        (*iptr)++;
    }
    return NULL;//it wont carew= what the function will return
}

void yourturn() {

    for (int i = 0; i < 3; i++) {
        Sleep(2);
        printf("Your turn!\n");
    }
}
int main(){
    pthread_t newthread;
    int v= 5;
    //Function to create a new thread
    pthread_create(&newthread, NULL, myturn, &v);
    //myturn();
    yourturn();
    //wait until the thread is done before we exit, "null"- idc what the thread returns
    pthread_join(newthread, NULL);
    printf("Thread is done: v= %d\n",v);
}
