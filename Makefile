CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET   = calculator
SRCS     = main.cpp Calculator.cpp

all: $(TARGET)

$(TARGET): $(SRCS) Calculator.h
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
