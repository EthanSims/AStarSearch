TARGET = find_route
SRC_FILES = main.cpp PriorityQueue.cpp PriorityQueueNode.cpp

CXX = g++
CFLAGS = -Wall -g

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	DEL = del
else
	DEL = rm
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

#DEPENDENCIES
main.o: main.cpp PriorityQueue.h PriorityQueueNode.h GraphNode.h


 