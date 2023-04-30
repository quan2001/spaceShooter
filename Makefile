CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra
SRC=Test.cpp
EXE=Test

# Paths to include directories
INCLUDE_DIRS=/opt/homebrew/Cellar/freeglut/3.4.0/include/ /opt/homebrew/Cellar/glfw/3.3.8/include/

# Paths to library directories
LIB_DIRS=/opt/homebrew/lib/

# Libraries to link
LIBS=-framework glut -framework opengl -framework IOKit -framework Cocoa -framework Carbon -lglfw

all: $(EXE)

$(EXE): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(SRC) $(addprefix -I,$(INCLUDE_DIRS)) $(addprefix -L,$(LIB_DIRS)) $(LIBS)

clean:
	rm -f $(EXE)
