CXX := clang++ # This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := Source
BUILDDIR := Objects
TARGET := smashing
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CXXFLAGS := -g -std=c++11 # -Wall
INC := -I/usr/local/include -I/usr/local/include/SDL2
LIB := -L/usr/local/lib -lSDL2 -lSDL2_image

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	$(CXX) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " Building"
	mkdir -p Objects/{Graphics,States}
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	$(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean
