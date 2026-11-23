ASM := nasm # This project builds with NASM

# Directories #
BUILD_DIR := ./build
SRC_DIR := ./src

## STAGE 1 ##
# Paths #
OUTPUT_STG1 := $(BUILD_DIR)/bootsct.bin
MAIN_ASM_STG1 := $(SRC_DIR)/main.asm

# Creation #

.PHONY: clean

$(OUTPUT_STG1): $(MAIN_ASM_STG1)
	mkdir -p build
	nasm -f bin -o $(OUTPUT_STG1) $(MAIN_ASM_STG1)

clean:
	-rm -r build
	mkdir -p  build