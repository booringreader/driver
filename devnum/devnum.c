#include<linux/module.h> // to handle module loading and unloading by the kernel
#include<linux/init.h> // to handle module initialisation
#include<linux/fs.h> // to handle filesystem
// the device is plugged in the port (enumeration is performed)
// the kernel then calls the appropriate driver based on the enumeration data
// the kernel also creates the device file, which has all the possible operations that can be perfomed on the device
// the driver module when loaded in the kernel, allows the user to perform some or all (as defined in the driver) of the operations
// that are possible on the device and hence listed in the device file


// Meta data
MODULE_LICENSE("GPL");
MODULE_AUTHOR("SHUBHAM");
MODULE_DESCRIPTION("test program");


// @brief called when the device file is opened
static int devfile_open(struct inode *device_file, struct file *instance){
    printk("device file has been accessed by the driver\n");
    return 0;
}

// @brief called when the device file is closed
static int devfile_close(struct inode *device_file, struct file *instance){
    printk("device file access has been revoked by the driver\n");
    return 0;
}

static struct file_operations fops={
    .owner = THIS_MODULE,
    .open = devfile_open,
    .release = devfile_close
};


# define HARD_MAJOR 64

// @brief function to be called when module is loaded in the kernel
static int __init moduleload(void){
    printk("module loaded\n"); // logs that the module is successfullly loaded
    int return_val;
    return_val = register_chrdev(HARD_MAJOR, "devnum", &fops); // hard coded major number, the name of device file, pointer to structure that permits device operations

    if(return_val >0){ // there is already a device with major '64'
        printk("devnum - registered with major number: %d and minor number: %d\n", return_val>>20, return_val&0xfffff); // return_val has both major and minor number, which are extracted using right shift and & operation
    }else if(return_val == 0){
        printk("devnum-registered with major: %d and minor: %d\n", HARD_MAJOR, 0);
    }else{
        printk("device number could not be registered\n");
        return -1;
    }
    return 0;
}

// @brief function to be called when moduel is unlaoded
static void __exit moduleUnload(void){
    unregister_chrdev(HARD_MAJOR, "devnum");
    printk("module unloaded\n");
}

module_init(moduleload);
module_exit(moduleUnload);
