// Absolute path to copy this file into once I have finished: "/home/kernel/linux-hwe-4.15.0/arch/x86/kernel"

/*  Created by Jeffrey Colgan, September 7, 2020.
 *  Source code for my solution to Programming Assessment 1, CSCI-3753 Operating Systems,
 *  helloworld code is provided in the assignment instructions.
 */

#include <linux/kernel.h>
#include <linux/linkage.h>

asmlinkage long sys_helloworld(void) {
  
  printk(KERN_ALERT "hello world\n");
  return 0;
}
