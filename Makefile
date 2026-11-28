rwildcard = $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $2,$d))
QEMU := qemu-system-i386
QEMU_ARGS := -m 1G -d int,cpu_reset -no-reboot # this OS will target 1GB of RAM

# Directories #
BOOTLD_DIR := ./bootloader
KRNL_DIR := ./kernel
DIST_DIR := ./dist

# Files #
BOOTLD_OUT := $(BOOTLD_DIR)/build/bootsct.bin
KERNEL_OUT := $(KRNL_DIR)/build/kernel.bin

FLOPPY_IMG := $(DIST_DIR)/yaos.img # WILL be removed later

# Ensure kernel can recompile
KRNL_C_FILES := $(call rwildcard,$(KRNL_DIR)/src/,%.c)
KRNL_ASM_FILES := $(call rwildcard,$(KRNL_DIR)/src/,%.asm)
KRNL_SRC_FILES := $(KRNL_ASM_FILES) $(KRNL_C_FILES)

.PHONY: run, clean

$(FLOPPY_IMG): $(BOOTLD_OUT) $(KERNEL_OUT)
	mkdir -p build
	mkdir -p dist
	dd if=/dev/zero of=$(FLOPPY_IMG) bs=512 count=2880
	dd if=$(BOOTLD_OUT) of=$(FLOPPY_IMG) conv=notrunc
	dd if=$(KERNEL_OUT) of=$(FLOPPY_IMG) bs=512 seek=1 conv=notrunc

$(BOOTLD_OUT): $(BOOTLD_DIR)/src/main.asm
	@$(MAKE) -C $(BOOTLD_DIR)

$(KERNEL_OUT): $(KRNL_SRC_FILES)
	@$(MAKE) -C $(KRNL_DIR)

clean:
	@$(MAKE) -C $(BOOTLD_DIR) clean
	@$(MAKE) -C $(KRNL_DIR) clean
	-rm -r dist
	mkdir -p dist

run: $(FLOPPY_IMG)
	$(QEMU) $(QEMU_ARGS) -fda $(FLOPPY_IMG)