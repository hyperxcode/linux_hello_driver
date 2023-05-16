#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

extern int func_hello_from_kernel(void);

static int __init hello_init(void)
{
    printk("Module B, hello_init!\n");
    func_hello_from_kernel();
    printk("In Func: %s... \n", __func__);
    return 0;
}

static void __exit hello_exit(void)
{
    printk("Module B, exit!\n");
}

module_init(hello_init);
module_exit(hello_exit);