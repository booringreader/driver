#include<linux/module.h> // to handle module loading and unloading by the kernel
#include<linux/init.h> // to handle module initialisation

// Meta data
MODULE_LICENSE("GPL");
MODULE_AUTHOR("SHUBHAM");
MODULE_DESCRIPTION("test program");


// @brief function to be called when module is loaded
static int __init moduleload(){
    printk("module loaded\n");
    return 0;
}

// @brief function to be called when moduel is unlaoded
static void __exit moduleUnload(){
    printk("module unloaded\n");
}

module_init(moduleload);
module_exit(moduleUnload);
