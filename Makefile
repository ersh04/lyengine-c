CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11 -g
SRCDIR = src
BINDIR = bin
SRCS = $(SRCDIR)/main.c $(SRCDIR)/engine/entity/entity.c $(SRCDIR)/engine/math/vectors/vector2.c $(SRCDIR)/engine/scene/scene.c $(SRCDIR)/utils/json/json_loader.c $(SRCDIR)/utils/json/json_parser.c
TARGET = $(BINDIR)/c-project
LDLIBS = -lcjson

TEST_DIR = tests
TEST_TARGET = $(BINDIR)/test_main
TEST_SRCS = $(TEST_DIR)/test_main.c

.PHONY: all clean test run

all: $(TARGET)

$(BINDIR):
	mkdir -p $(BINDIR)

$(TARGET): | $(BINDIR)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDLIBS)

test: $(TEST_TARGET)
	$(TEST_TARGET)

run: $(TARGET)
	$(TARGET)

$(TEST_TARGET): | $(BINDIR)
	$(CC) $(CFLAGS) $(TEST_SRCS) -o $(TEST_TARGET) $(LDLIBS)

clean:
	rm -rf $(BINDIR)
