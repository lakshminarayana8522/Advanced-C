PWD   := $(shell pwd)
obj-m += params_to_module.o jiffies.o


all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD)
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
