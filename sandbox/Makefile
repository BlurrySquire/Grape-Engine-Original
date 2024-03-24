CC := g++
CFLAGS := -Wall -Wextra -std=c++20
LDFLAGS := -L../bin -lGrapeEngine
INCLUDE_DIR := -I../engine/source
BIN_DIR := ../bin
TARGET := sandbox
DEFINES := -DGRAPE_IMPORT -D_DEBUG

SOURCE_FILES = $(wildcard source/*.cpp) $(wildcard source/*/*.cpp)

build_sandbox: $(SOURCE_FILES)
	$(CC) $(SOURCE_FILES) $(CFLAGS) $(DEFINES) $(INCLUDE_DIR) $(LDFLAGS) -o $(BIN_DIR)/$(TARGET).exe