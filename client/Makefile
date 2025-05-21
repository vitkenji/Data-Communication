CXX = g++

CXXFLAGS = -std=c++11

TARGET = client

SRCS = main.cpp client.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

