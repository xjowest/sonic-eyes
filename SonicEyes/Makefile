# Source files
vpath %cc src
SRC = main.cc \
	filterBaseClass.cc \
	highPassFilter.cc \
	cameraInterface.cc \
	screenInterface.cc \
	speakerInterface.cc \
	sonarInterface.cc

# Object files
OBJECTS = $(patsubst %.cc,obj/%.o,$(SRC))

# Compiler
CC = g++

# Compiler flags
CFLAGS = -c -g -Wall

# Main target
SONIC = SonicEyes

# Build rules
all : $(SONIC)
	@echo Finished compiling and linking SonicEyes

$(SONIC) : $(OBJECTS)
	@echo Linking...
	$(CC) -o bin/$(SONIC) $(OBJECTS)

# Linking rules
obj/%.o : %.cc
	@echo $<
	$(CC) $(CFLAGS) -c $< -o obj/$(patsubst src/%.cc,%.o,$<)

# Clean target
clean:
	rm -f bin/SonicEyes $(OBJECTS) src/*~