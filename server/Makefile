CXX = g++

CXXFLAGS = -std=c++11

TARGET = server

SRCS = main.cpp server.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)


clean:
	rm -f $(TARGET)

