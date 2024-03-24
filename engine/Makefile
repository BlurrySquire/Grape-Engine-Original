CC := g++
CFLAGS := -Wall -Wextra -std=c++20 -g -fdiagnostics-color=always
LDFLAGS := -L$(VULKAN_SDK)/Lib -lvulkan-1 -luser32
INCLUDE_DIR := -I$(VULKAN_SDK)/Include
BIN_DIR := ../bin
TARGET := GrapeEngine
DEFINES := -DGRAPE_EXPORT -D_DEBUG

SOURCE_FILES = $(wildcard source/*.cpp) $(wildcard source/*/*.cpp)

build_engine: source/*/*.cpp
	$(CC) $(SOURCE_FILES) $(CFLAGS) $(DEFINES) $(INCLUDE_DIR) $(LDFLAGS) -shared -Wl,--out-implib,$(BIN_DIR)/$(TARGET).lib -o $(BIN_DIR)/$(TARGET).dll
