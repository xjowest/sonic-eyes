# Source files
vpath %cc src
SRC = main.cc \
	filterBaseClass.cc \
	highPassFilter.cc \
	cameraInterface.cc \
	screenInterface.cc \
	speakerInterface.cc \
	sonarInterface.cc \
	clusterAlgorithm.cc \
	analysisAlgorithm.cc

# Object files
OBJECTS = $(patsubst %.cc,obj/%.o,$(SRC))

# Compiler
CC = g++

# Compiler flags
CFLAGS = -c -g $(SDL_CFLAGS) $(SDL_LDFLAGS) -Wall

# SDL compiler flags
SDL_CFLAGS := $(shell sdl-config --cflags) 
SDL_LDFLAGS := $(shell sdl-config --libs) 

# Main target
SONIC = SonicEyes

# Build rules
all : $(SONIC)
	@echo Finished compiling and linking SonicEyes

$(SONIC) : $(OBJECTS)
	@echo Linking...
	$(CC) $(SDL_CFLAGS) $(SDL_LDFLAGS) -o bin/$(SONIC) $(OBJECTS)

# Linking rules
obj/%.o : %.cc
	@echo $<
	$(CC) $(CFLAGS) -c $< -o obj/$(patsubst src/%.cc,%.o,$<)

# Clean target
clean:
	rm -f bin/SonicEyes $(OBJECTS) src/*~