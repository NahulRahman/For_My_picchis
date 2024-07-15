#include <iostream>
#include <pthread.h>
#include <windows.h>
#include<windows.h>
#include<iostream>
using namespace std;



pthread_mutex_t mutex; /// Create a mutex

int x = 2;

void* routine(void *args) {
     pthread_mutex_lock(&mutex); /// Lock the mutex before accessing the critical section
    for (int i = 0; i < 1; i++) {
       x += 5; // Critical section /// 7 7+5= 12//12+5= 17//22

    }
     pthread_mutex_unlock(&mutex); /// Unlock the mutex after accessing the critical section
    return NULL;
}

int main() {
    pthread_t th[4]; /// Create an array for 4 thread identifiers
    pthread_mutex_init(&mutex, NULL); /// Initialize the mutex

    for (int i = 0; i < 4; i++) { //4 threads
        pthread_create(&th[i], NULL, routine, NULL) ;
        }


    for (int i = 0; i < 4; i++) {
        pthread_join(th[i], NULL); // Wait for all threads to finish
    }

    pthread_mutex_destroy(&mutex); /// Destroy the mutex

    cout << "Final value of x: " << x << endl;
    return 0;
}

///Thread 1 locks the mutex, adds 5 to x (2 + 5 = 7), unlocks the mutex.
///Thread 2 locks the mutex, adds 5 to x (7 + 5 = 12), unlocks the mutex.
///Thread 3 locks the mutex, adds 5 to x (12 + 5 = 17), unlocks the mutex.
///Thread 4 locks the mutex, adds 5 to x (17 + 5 = 22), unlocks the mutex.
///Each thread does this twice, so the changes accumulate.
///By locking and unlocking the mutex, the critical section is protected,
///ensuring that all increments are correctly applied without interference from other threads.
