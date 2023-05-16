sudo insmod hello_driver.ko
cat /proc/devices | grep hello_driver
mknod /dev/hello_driver c 112 1
