ROOT = ./
PROJECT_DIR = $(ROOT)UbiGame

TARGET_DIR = $(ROOT)

HEADERS = $(shell find ./ -name "*.h")
SOURCES = $(shell find ./ -name "*.cpp") 
OBJECTS = $(SOURCES:.cpp=.o)

CXX = clang++ 
CXXFLAGS = -std=c++17 -O2 -Wall

INCLUDES =  -I$(ROOT)Source -I$(ROOT)../SFML-2.5.0/include
LDFLAGS = -L$(ROOT)../SFML-2.5.0/lib -rpath $(ROOT)../SFML-2.5.0/lib

LIBS = -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-window

TARGET = $(TARGET_DIR)output

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

all: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

clean:
	-rm $(OBJECTS)
	-rm $(TARGET)
