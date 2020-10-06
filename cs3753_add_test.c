/*
 *  C Tester Program for CSCI-3753 - Operating Systems : Programming Assessment 1
 * 
 *  Created by Jeffrey Colgan, September 11, 2020.
 *  
 *  Just a simple test for my two system calls as per the assignment instructions.  Calls
 *  The sys_helloworld and sys_cs3753_add system calls, and tests that the sys_cs3753_add function
 *  computes the sum correctly (and correctly stores the value in the local variable passed to the system
 *  call).
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

/*
 *  addTest function.
 *
 *  Returns 0 if the test passes, and -1 if the test fails.
 */
long addTest();

/*
 *  advancedTest function.
 */
long advancedTest();

/*
 * Main entry point for the system call test program.
 */
int  main(int argc, char *argv[]) {

  //Adding test makes sure that the values are getting printed as a kernel alert, and the addition is performed properly.
  if(addTest() == 0) {
    printf("%s\n", "Add Test Passed!");
  }else {
    printf("%s\n", "Add Test Failed!");
  }

  /*
  //Advanced test performs a variety of tests to check for various issues.
  if(advancedTest() == 0) {
    printf("%s\n", "Advanced Test Passed!");
  }else {
    printf("%s\n", "Advanced Test Failed!");
    }*/
  return 0;
}

//Definition of addTest function.
long addTest() {

  long firstVal = 12;
  long secondVal = 2;
  long answer;
  
  int score = 0;
  int possible = 0;

  printf("---------------------------------------------------------------------------\n");
  printf("First, we will take a few known values, and check that the addition is correct\n");
  printf("and the value is being stored in our input user-space variable \"answer\". \n");
  printf("---------------------------------------------------------------------------\n");
  
  printf("The first value to be added is :%li, and the second value is: %li\n", firstVal, secondVal);
  syscall(334, firstVal, secondVal, &answer);

  //Verify that the addition is correct, and the result was stored in the correct paremeter.
  if( answer == firstVal + secondVal ) {
    printf("%s%li\n", "The value stored in the answer variable after the cs3753_add call: ", answer);
    printf("Thus, we have: %li + %li = %li\n", firstVal, secondVal, answer);
    score++;
  }
  possible++;

  //Formatting.
  printf("---------------------------------------------------------------------------\n");
  printf("---------------------------------------------------------------------------\n");

  //Test that 0 + 0 = 0.
  firstVal = 0;
  secondVal = 0;
  printf("The first value to be added: %li, second value: %li\n", firstVal, secondVal);
  syscall(334, firstVal, secondVal, &answer);

  //Test if the result variable was modified to the correct value by the system call
  if (answer == firstVal + secondVal) {
    printf("The value stored in the answer variable after the system call is: %li\n", answer);
    printf("Thus, we have: %li + %li = %li\n", firstVal, secondVal, answer);
    score++;
  }
  possible++;

  //Test that sc3753_add correctly computes 0 + -15 = -15.
  firstVal = 0;
  secondVal = -15;

  //Formatting.
  printf("---------------------------------------------------------------------------\n");
  printf("---------------------------------------------------------------------------\n");

  printf("The first value to be added: %li, second value: %li\n", firstVal, secondVal);
  syscall(334, firstVal, secondVal, &answer);

  if (answer == firstVal + secondVal) {
    printf("The value stored in the answer variable after the system call is: %li \n", answer);
    printf("Thus, we have: %li + %li = %li\n", firstVal, secondVal, answer);
    score++;
  }
  possible++;

  //Formatting.
  printf("---------------------------------------------------------------------------\n");
  printf("---------------------------------------------------------------------------\n");
  
  //Test that -25 + -30 = -55.
  firstVal = -25;
  secondVal = -30;

  printf("The first value to be added: %li, second value: %li\n", firstVal, secondVal);
  syscall(334, firstVal, secondVal, &answer);
  
  if(answer == firstVal + secondVal) {
    printf("The value stored in the answer variable after the system call is: %li\n", answer);
    printf("Thus, we have: %li + %li = %li\n", firstVal, secondVal, answer);
    score++;
  }
  possible++;

  //Formatting.
  printf("---------------------------------------------------------------------------\n");
  printf("---------------------------------------------------------------------------\n");

  //Test that -36756 + 36756 = 0.
  firstVal = -36756;
  secondVal = 36756;

  printf("The first value to be added: %li, second value: %li\n", firstVal, secondVal);
  syscall(334, firstVal, secondVal, &answer);
  
  if(answer == firstVal + secondVal) {
    printf("The value stored in the answer variable after the system call is: %li\n", answer);
    printf("Thus, we have: %li + %li = %li\n", firstVal, secondVal, answer);
    score++;
  }
  possible++;

  //Formatting.
  printf("---------------------------------------------------------------------------\n");
  printf("---------------------------------------------------------------------------\n");
  
  //Test that 40000 + 15000 = 55000.
  firstVal = 40000;
  secondVal = 15000;

  printf("The first value to be added: %li, second value: %li\n", firstVal, secondVal);
  syscall(334, firstVal, secondVal, &answer);

  if(answer == firstVal + secondVal){
    printf("The value stored in the answer variable after the system call is: %li\n", answer);
    printf("Thus, we have: %li + %li = %li\n", firstVal, secondVal, answer);
    score++;
  }
  possible++;

  return possible - score;
}

//Definition of advancedTest function.
long advancedTest() {

  /*
   *  Here I am just calling cs3753_add a whole bunch of times to make sure there isn't some obscure
   *  bug in my code that crashes the OS or something crazy.
   *
   *  The syslog.txt file is the information in the syslog file after a run of this test program during which this
   *  code was commented out.  Since I am running the function 1000 times, the syslog would be far too cluttered if
   *  I included this output.
   */

  long firstVal, secondVal, result;
  long score = 0;
  long possible = 0;

  for (int i = 0; i < 1000; i++) {
    firstVal = i;
    secondVal = i + 1000;

    syscall(334, firstVal, secondVal, &result);

    if(result == firstVal + secondVal) {
      score++;
    }
    possible++;
  }

  printf("Score: %li Out of: %li \n", score, possible);

  return possible - score;
  
}
