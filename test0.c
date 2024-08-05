#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int test_data __initdata = 3;

static int __init test_init(void) 
{
 	pr_info("Hello, World! %d\n", test_data);
 	return 0;
}

static void __exit test_exit(void)
{
	pr_info("Goodbye, World!\n");
}

module_init(test_init)
module_exit(test_exit)

MODULE_LICENSE("GPL");
