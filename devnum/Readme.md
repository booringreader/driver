compile the driver into a kernel module (`.ko` file) using 
```bash
make
```
insert the module into the kernel using
```bash
sudo insmod devnum.ko
```
make a device file(manually) to be accessed by the driver using
```bash
sudo mknod /dev/[deviceName] c [major_number] [minor_number]
```
change permissions of the device file (for testing purpose)
```bash
sudo chmod 666 /dev/mydevice
```
test the interaction of driver with dev file

remove the module with
```bash
sudo rmmod mymodule
```
remove the device file with
```bash
sudo rm /dev/mydevice
```

to clean the repo run 
```bash
make clean
```
for additional information on devices and major numbers run
```bash
cat /proc/devices
```
