/*
 * example_jiffies.c
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>
#include<linux/init.h>
/* Needed by all modules */
/* Needed for KERN_INFO */
int init_module(void)
{
	printk(KERN_INFO "Entering Jiffies Example\n");
	printk(KERN_INFO "The jiffies value=%ld\n",jiffies);
	return 0;
}
void cleanup_module(void)
{
	printk(KERN_INFO "Exiting Jiffies Example\n");
}





