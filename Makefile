CXX = g++
CXXFLAGS = -O2 -std=c++17
SOURCES = main.cpp Game.cpp Words.cpp Hangman.cpp

ifeq ($(OS),Windows_NT)
	TARGET = hangman.exe
	LIBS = -lraylib
else
	TARGET = hangman
	LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
