
# 一、Linux字符设备驱动


## 导出符号接口、查看
导出关键字EXPORT_SYMBOL
### 导出
``` bash
EXPORT_SYMBOL(func_hello_from_kernel)
```
### 查询
``` bash
cat /proc/kallsyms | grep hello_from_kernel
```
输出
```
0000000000000000 T func_hello_from_kernel	[hello_driver]
0000000000000000 r __kcrctab_func_hello_from_kernel	[hello_driver]
0000000000000000 r __ksymtab_func_hello_from_kernel	[hello_driver]
0000000000000000 r __kstrtab_func_hello_from_kernel	[hello_driver]
```
### 另一个驱动调用
```
insmod hello_driver.ko
insmod call_driver2.ko
rmmod call_driver2.ko
rmmod hello_driver.ko
```
同dmesg | tail查看，调用消息

## 用户态和内核态通信
运行app
```bash
sudo ./app
```
驱动中，hello_charUnlockedIoctl(...)->ioctl_exec_hello(...)被调用，查看dmesg | tail

```bash
[82867.734602] In kernel func name: ioctl_exec_hello...
```

# 二、编译和运行
### 编译
生成驱动文件hello_dirver.ko和用户态程序app。
```
cd linux_hello_driver
make
```

### 运行

#### 加载驱动
``` bash
// 加载
insmod hello_driver.ko
// 可选，查看是否成功
cat /proc/devices | grep hello_driver
// 挂载
mknod /dev/hello_driver c 112 1
```
#### 测试
``` bash
sudo ./app
```

#### 查看系统消息
通过printk打印的消息
``` linux
dmesg | tail
```

#### 注销
```bash
lsmod | grep driver
rmmod hello_driver
```
