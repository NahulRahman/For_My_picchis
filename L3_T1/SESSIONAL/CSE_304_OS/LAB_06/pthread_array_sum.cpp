#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include <time.h>
#include<windows.h>
#include<iostream>
using namespace std;
#define n 10
#define thread 2

int arr[n] = {1,2,3,4,5,3,2,1,5,5};

void * routine(void * arg){
    int *index = (int*) arg;
    int sum=0;
    for(int j=0;j<(n/thread);j++){
        sum+=arr[*index+ j];//0+1+2+3+4+5 -> n/thread //position+index
    }
    cout<<"Local sum "<<sum<<endl;
    *(int*) arg = sum;
    return arg;
}

int main(){
    pthread_t th[thread];
    for(int i=0;i<thread;i++){
    int *a=(int*)malloc(sizeof(int));
    *a = (n/thread)*i;//i=0 -> a=(10/2)*0; i=1 -> a= (10/2)*i=5
        if(pthread_create(&th[i], NULL, &routine, a)!=0){
           perror("Failed to create thread");
        }
    }
    int *result;
     for(int i=0;i<thread;i++){
        if(pthread_join(th[i], (void **)&result)!=0){
           perror("Failed to join thread");
        }
    }
}
