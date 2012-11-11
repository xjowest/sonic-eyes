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
CFLAGS = -c -g -Wall $(SDL_CFLAGS)

# SDL compiler flags
SDL_FLAGS = $(SDL_LDFLAGS) $(SDL_CFLAGS)
SDL_CFLAGS := $(shell sdl-config --cflags) 
SDL_LDFLAGS := $(shell sdl-config --libs) 

# Main target
SONIC = SonicEyes

# Build rules
all : $(SONIC)
	@echo Finished compiling and linking SonicEyes

$(SONIC) : $(OBJECTS)
	@echo Linking...
	$(CC) -o bin/$(SONIC) $(OBJECTS) $(SDL_FLAGS)

# Linking rules
obj/%.o : %.cc
	@echo $<
	$(CC) -c $< -o obj/$(patsubst src/%.cc,%.o,$<) $(CFLAGS)

# Clean target
clean:
	rm -f bin/SonicEyes $(OBJECTS) src/*~