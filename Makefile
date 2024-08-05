obj-m += test1.o
 
PWD := $(CURDIR)
 
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
 
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:
	sudo dmesg -C
	sudo insmod test.ko
	sudo rmmod test.ko
	sudo dmesg
