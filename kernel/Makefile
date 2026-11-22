NASM := nasm
AS_FLAGS := -f elf32

CC_FLAGS := -ffreestanding --target=i386-binary -Wall -Wextra

rwildcard = $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $2,$d))
# Directories #
BUILD_DIR := build
SRC_DIR := src

# Paths #
OUTPUT := $(BUILD_DIR)/kernel.bin
C_FILES := $(call rwildcard,$(SRC_DIR)/,%.c)
ASM_FILES := $(call rwildcard,$(SRC_DIR)/,%.asm)
SRC_FILES := $(ASM_FILES) $(C_FILES)
OBJS := $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(basename $(SRC_FILES))))

$(OUTPUT): $(OBJS)
	ld.lld -T $(SRC_DIR)/linker.ld $(OBJS) -o $(OUTPUT)

$(BUILD_DIR)/%.o: %.asm
	mkdir -p $(dir $@)
	$(NASM) $(AS_FLAGS) $< -o $@

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) $< -c -o $@

clean:
	-rm -r build
	mkdir -p build