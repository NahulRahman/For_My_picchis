#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include <time.h>
#include<windows.h>

//Time function
void get_current_time(char* buffer, size_t buffer_size) {
    time_t raw_time;
    struct tm* time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);

    strftime(buffer, buffer_size, "%H:%M:%S", time_info);
}

// Thread function
void* myturn(void* arg) {
    char time_buffer[9];
    for (int i = 0; i < 8; i++) {
        Sleep(1000);
        get_current_time(time_buffer, sizeof(time_buffer));
        printf("%s My turn!\n", time_buffer);
    }
    return NULL;
}

void yourturn() {
    char time_buffer[9];
    for (int i = 0; i < 3; i++) {
        Sleep(2000);
        get_current_time(time_buffer, sizeof(time_buffer));
        printf("%s Your turn!\n", time_buffer);
    }
}
int main(){
    pthread_t newthread;
    //Function to create a new thread
    pthread_create(&newthread, NULL, myturn, NULL);
    yourturn();
    //wait until the thread is done before we exit
    pthread_join(newthread, NULL);
    printf("Both threads have finished execution.\n");
}

///When the pthread_create function is called, it performs the following actions:

///1. Allocates resources for the new thread.
///2. Initializes the new thread.
///3. Makes the new thread start executing the specified start routine (myturn in this case).
///4. Populates the newthread variable with the identifier of the newly created thread.
