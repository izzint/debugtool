all: MANDARINDEBUGGER.z64
.PHONY: all

SOURCE_DIR = src
BUILD_DIR = build
include $(N64_INST)/include/n64.mk

SRC = main.c
OBJS = $(SRC:%.c=$(BUILD_DIR)/%.o)
DEPS = $(SRC:%.c=$(BUILD_DIR)/%.d)

MANDARINDEBUGGER.z64: N64_ROM_TITLE = "MANDARIN DEBUGGER"
MANDARINDEBUGGER.z64: $(BUILD_DIR)/MANDARINDEBUGGER.dfs

$(BUILD_DIR)/MANDARINDEBUGGER.dfs: $(wildcard filesystem/*)
$(BUILD_DIR)/MANDARINDEBUGGER.elf: $(OBJS)

clean:
	rm -rf $(BUILD_DIR) *.z64
.PHONY: clean

-include $(DEPS)
