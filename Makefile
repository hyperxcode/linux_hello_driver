obj-m += hello_driver.o
obj-m += call_driver2.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
	gcc -o app app.c

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean



	
	
