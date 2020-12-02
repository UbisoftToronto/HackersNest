ROOT = ./
PROJECT_DIR = $(ROOT)UbiGame

TARGET_DIR = $(ROOT)

HEADERS = $(shell find ./UbiGame -name "*.h")
SOURCES = $(shell find ./UbiGame -name "*.cpp") 
OBJECTS = $(SOURCES:.cpp=.o)

CXX = clang++ 
CXXFLAGS = -std=c++17 -O2 -Wall

INCLUDES = -I$(ROOT)UbiGame -I$(ROOT)UbiGame/Source 

OS := $(shell uname)
ifeq ($(OS),Windows_NT)
	INCLUDES += -I$(ROOT)SFML-2.5.0/include
	LDFLAGS = -L$(ROOT)SFML-2.5.0/lib -rpath $(ROOT)SFML-2.5.0/lib
else ($(OS) Darwin)
	INCLUDES += -I$(ROOT)SFML-2.5.0-macOS-clang/include
	LDFLAGS = -L$(ROOT)SFML-2.5.0-macOS-clang/lib -rpath $(ROOT)SFML-2.5.0-macOS-clang/lib
endif

LIBS = -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-window

TARGET = $(TARGET_DIR)output

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

all: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

clean:
	-rm $(OBJECTS)
	-rm $(TARGET)
