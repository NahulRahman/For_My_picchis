#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include <time.h>
#include<windows.h>
//void myturn(){
//while(1){
//    Sleep(1000); // sleeping for 1 second.
//    printf("My turn!\n");
//}
//}
//
//void yourturn(){
//while(1){
//    Sleep(2000);
//    printf("Your turn!\n");
//}
//}
//
//int main(){
// while(1){
//    myturn();
//    yourturn();
// }
//
//}

// Thread function
void* myturn(void* arg){//fixed
for(int i=0; i< 8;i++){
    Sleep(10);
    printf("My turn!\n");
}
}

void yourturn(){
for(int i=0; i< 8;i++){
    Sleep(20);
    printf("Your turn!\n");
}
}

int main(){
    pthread_t newthread; //fixed syntax
    //Declaring a Thread Identifier; pthread_t- data type, newthread- var that will hold the thread identifier

    //pthread_create(&newthread, NULL, thread_func, NULL);
    pthread_create(&newthread, NULL, myturn, NULL); // the thread I wnat to work on, 4 params will go
    //myturn();
    yourturn();
}


    ///1.Pointer taken cz to modify the original variable, we need to pass a pointer to the variable
    ///2.Thread Attributes: NULL means "use the default attributes."
    ///3. A pointer to the function that the thread will execute. This function must match the signature void* function_name(void* arg).
    ///4. A pointer to the argument that will be passed to the start routine(function).
