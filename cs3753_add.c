/*
 *  Definition of sys_cs3753_add system call function.
 *
 *  Component file to CSCI 3753 - Operating Systems : Programming Assesment 1.
 *  Created by Jeffrey Colgan, September 10, 2020.
 *  
 *  As per assignment instructions, the system call defines number1, number2, and 
 *  a pointer to result as arguments.  The function the uses printk() to log both
 *  number1 and number2.  The function adds the two numbers, stores the result in
 *  the result variable, and uses printk to log the result.
 * 
 *  Since the assignment instructions only specified that the function should return
 *  "an appropriate value", I interpreted this as such: I will stick with the return
 *  value scheme that seems to be in place from the existing system calls we used in 
 *  this assignment.  As such, the function returns 0 if the operation was successful,
 *  return -1 otherwise.
 */

#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/uaccess.h>


asmlinkage long sys_cs3753_add(long number1, long number2, long *result) {
  
  long answer = number1 + number2;

  //Log the first value to be added.  Also log if unsuccessful for debugging purposes.
  if( printk(KERN_ALERT "The first value passed was: \"%li\" \n", number1) == -1) {

    printk(KERN_ALERT "The first value was not successfully passed into the function!");
    return -1;
  }

  //Log the second value to be added.  Also log if unsuccessful for debugging purposes.
  if( printk(KERN_ALERT "The second value passed was: \"%li\" \n", number2) == -1 ) {
    
    printk(KERN_ALERT "The second value was not successfully passed into the function!");
    return -1;
  }

  //Store the anser to number1 + number2 in the variable result with kernel-memory access function put_user(x, ptr).
  if ( put_user(answer, result ) == 0 ) {

    /* 
     *  Here I log the result of the addition.  In the tester program I will be testing that the user memory is
     *  correctly modified by the operation.  Once this has been logged, we return 0, as the function was a success.
     */
    printk(KERN_ALERT "The result of the addition operation was: \"%li\" \n", answer);
    return 0;
    
  }else {

    printk(KERN_ALERT "The operation failed!");
    return -1;
  }
}
