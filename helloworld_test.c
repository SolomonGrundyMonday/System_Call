/*
 *  Test Program for the system call sys_helloworld().  Component file for 
 *  CSCI 3753 - Operating Systems: Programming Assessment 1.
 *  Created by Jeffrey Colgan, September 12, 2020.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

/*
 *  testHelloWorld function.
 *
 *  Returns 0 if the hello world system call successfully executed, -1 otherwise.
 */
int testHelloWorld();

//Main entry point for test program for the hello world system call.
int main(int argc, char* argv[]) {

  printf("%s\n", "----------------------------------------------");
  printf("%s\n", "First testing the hello world function.");
  printf("%s\n", "----------------------------------------------");

  if( testHelloWorld() == 0) {
    printf("Hello World Test successful!\n");
    printf("Now run the shell command: $tail -n 10 /var/log/syslog\n");
    printf("This will allow you to test if the printk statements successfully logged hello world\n");
  }else {
    printf("Hello World Test unsuccessful!");
  }
  
  return 0;
}

//Definition of testHelloWorld function.
int testHelloWorld() {
  
  for (int i = 0; i < 5; i++){
    if( syscall(333) != 0 ) {
      return -1;
    }
  }

  return 0;
}
