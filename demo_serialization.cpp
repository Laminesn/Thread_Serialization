//
// Author: Lamine Deen
// Project: Thread Serialization
//
/* Includes */

#include "semaphore_class.h"


/* prototype for thread routine */
void *thread_1( void *ptr);
void *thread_2( void *ptr);


void task_A()
{
    printf("This is task A\n"); 
    fflush(stdout);
}

void task_B()
{
    printf("This is task B\n");    
    fflush(stdout);
}

void task_C()
{
    printf("This is task C\n"); 
    fflush(stdout);
}

void task_D()
{
    printf("This is task D\n"); 
    fflush(stdout);
}

void task_E()
{
    printf("This is task E\n"); 
    fflush(stdout);
}

void task_F()
{
    printf("This is task F\n"); 
    fflush(stdout);
}

void task_G()
{
    printf("This is task G\n"); 
    fflush(stdout);
}

void task_H()
{   
    printf("This is task H\n"); 
    fflush(stdout);
}








/* global vars */
/* semaphores are declared global so they can be accessed
 in main() and in thread routine. */
Semaphore A_Done(0);
Semaphore E_Done(0);
Semaphore F_Done(0);


int main()
{
    pthread_t t_1;
    pthread_t t_2;
        
    
    /* Note: you can check if thread has been
     successfully created by checking return value of
     pthread_create */
    pthread_create (&t_1, NULL, thread_1, NULL);
    pthread_create (&t_2, NULL, thread_2, NULL);

    
    // Join threads
    (void) pthread_join(t_1, NULL);
    (void) pthread_join(t_2, NULL);
    
    /* exit */
    exit(0);
    
} /* main() */


void *thread_1(void *ptr)
{   
    sleep(3);
    task_A(); 
    A_Done.signal();       // Signal (semaphore) that task A is done
    
    E_Done.wait();	// Check (sempahore) if task E is done
    task_B(); 

    task_C(); 
    
    F_Done.wait();	// Check (semaphore) if task F is done
    task_D(); 
    
    pthread_exit(0); /* exit thread */
}

void *thread_2(void *ptr)
{    
    task_E();
    E_Done.signal();	// Signal (semaphore) that task E is done 
    
    task_F();
    F_Done.signal();	// Signal (sempahore) that task F is done

    task_C(); 
    
    A_Done.wait();        // Check (semaphore) if task A is done
    task_H(); 
    
    pthread_exit(0); /* exit thread */
}

