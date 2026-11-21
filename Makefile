QEMU := qemu-system-i386
QEMU_ARGS := -m 1G # this OS will target 1GB of RAM

# Directories #
BOOTLD_DIR := ./bootloader
DIST_DIR := ./dist

# Files #
BOOTLD_OUT := $(BOOTLD_DIR)/build/bootsct.bin

FLOPPY_IMG := $(DIST_DIR)/yaos.img # WILL be removed later

.PHONY: run, clean

$(FLOPPY_IMG): $(BOOTLD_OUT)
	dd if=/dev/zero of=$(FLOPPY_IMG) bs=512 count=2880
	@# add a bootloader
	dd if=$(BOOTLD_OUT) of=$(FLOPPY_IMG) conv=notrunc

$(BOOTLD_OUT): $(BOOTLD_DIR)/src/main.asm
	@$(MAKE) -C $(BOOTLD_DIR)

clean:
	@$(MAKE) -C $(BOOTLD_DIR) clean
	-rm -r dist

run: $(FLOPPY_IMG)
	$(QEMU) $(QEMU_ARGS) -fda $(FLOPPY_IMG)