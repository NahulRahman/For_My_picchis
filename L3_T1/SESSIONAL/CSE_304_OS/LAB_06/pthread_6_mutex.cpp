#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include <time.h>
#include<windows.h>
#include<iostream>
using namespace std;

void *routine(void *args){
    cout<<"Hello from Threads"<<endl;
    Sleep(1);
    cout<<"Ending Threads"<<endl;// due to placement in same resources they cant access the thread at same time
}

int main(){
    pthread_t th[1000];
    int i;
    for(i=0;i<1000;i++){
        if(pthread_create(&th[i], NULL, &routine, NULL)!=0){
            perror("Failed to create thread");
            return 1;
        }cout<<"thread "<<i<<" Has started"<<endl;

    }
}
//critical section
