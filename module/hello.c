#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<sys/utsname.h>

static int __init init_hello(void) {
	struct utsname name;
	int a = uname(&name);
	printk("Hello My name is Jinseob\n");
	printk("version: %s.%s\n",name.sysname,name.release);

	return 0;
}

static void __exit exit_hello(void) {
		printk("Jinseob: Good bye Kernel\n");
}

module_init(init_hello);
module_exit(exit_hello);
MODULE_LICENSE("GPL");
