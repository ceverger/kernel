#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static short myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char *mystring = "blah";
static int myintarray[2] = { 420, 420 };
static int arr_argc = 0;

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");
module_param_array(myintarray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintarray, "An array of integers");

static int __init test_init(void) 
{
	int i;

	pr_info("Hello, world 5\n===========\n");
	pr_info("myshort is a short integer: %hd\n", myshort);
	pr_info("myint is an integer: %d\n", myint);
	pr_info("mylong is a long integer: %ld\n", mylong);
	pr_info("mystring is a string: %s\n", mystring);

	for(i = 0; i < ARRAY_SIZE(myintarray); ++i)
		pr_info("myintarray[%d] = %d\n", i, myintarray[i]);

	pr_info("got %d argumets for myintarray.\n", arr_argc);

	return 0;
}

static void __exit test_exit(void)
{
	pr_info("Goodbye, World!\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
