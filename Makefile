# ------------------------------
# Compiler and flags
# ------------------------------
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -Iinclude -MMD -MP

# Target executable
TARGET = app

# Directories
SRC_DIR = src
OBJ_DIR = build

# Find all .cpp files recursively
SRCS = $(shell find $(SRC_DIR) -name '*.cpp')
# Map source files to object files in build dir, preserving folder structure
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

# Docker image name
DOCKER_IMAGE = cpp-build

# ------------------------------
# Default target (local build)
# ------------------------------
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o (create intermediate directories if needed)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Include dependency files
-include $(DEPS)

# ------------------------------
# Docker commands
# ------------------------------

# Build Docker image
build:
	docker build -t $(DOCKER_IMAGE) .

# Build & run inside Docker (Linux)
run: build
	docker run --rm -it -v $(PWD):/app $(DOCKER_IMAGE) bash -c "make && ./$(TARGET)"

# Delete everything: artifacts + Docker image
delete: clean
	-docker rmi $(DOCKER_IMAGE) || true

# ------------------------------
# Phony targets
# ------------------------------
.PHONY: all clean docker-build docker-run delete

