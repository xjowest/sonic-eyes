# Source files

vpath %.c external 

vpath %.cc src

SRC = main.cc \
	filterBaseClass.cc \
	highPassFilter.cc \
	lowPassFilter.cc \
	directionFilter.cc \
	erosionFilter.cc \
	dilationFilter.cc \
	cameraInterface.cc \
	screenInterface.cc \
	speakerInterface.cc \
	sonarInterface.cc \
	clusterAlgorithm.cc \
	analysisAlgorithm.cc \
	soundCreator.cc

EXT = camera.c \
	sonar.c

# Object files
OBJECTS = $(patsubst %.cc,obj/%.o,$(SRC)) $(EXTERNAL)
EXTERNAL = $(patsubst %.c,externalObj/%.o,$(EXT))

# Compilers
CC = g++
C = gcc

# Compiler flags
CFLAGS = -c -g -Wall $(SDL_CFLAGS)
EXTFLAGS = -c -g -Wall

# OS specific flags
OSFLAGS = -lopenal
ifeq "$(OSTYPE)" "darwin"
OSFLAGS = -framework OpenAL
endif

# SDL compiler flags
SDL_FLAGS = $(SDL_LDFLAGS) $(SDL_CFLAGS)
SDL_CFLAGS := $(shell sdl-config --cflags) 
SDL_LDFLAGS := $(shell sdl-config --libs) 

# Main target
SONIC = SonicEyes

# Linking rules
all : $(SONIC)
	@echo Finished compiling and linking SonicEyes


$(SONIC) : $(OBJECTS)
	@echo Linking SonicEyes...
	$(CC) -o bin/$(SONIC) $(OBJECTS) $(SDL_FLAGS) $(OSFLAGS)

# Build rules
obj/%.o : %.cc
	@echo $<
	$(CC) $< -c -o obj/$(patsubst src/%.cc,%.o,$<) $(CFLAGS)

externalObj/%.o : %.c
	@echo $<
	$(C) $< -c -o externalObj/$(patsubst external/%.c,%.o,$<) $(EXTFLAGS)

# Clean target
clean:
	rm -f bin/SonicEyes $(OBJECTS) src/*~ external/*~ ./*~