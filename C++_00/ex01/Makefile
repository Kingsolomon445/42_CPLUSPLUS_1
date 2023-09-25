CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
TARGET = phonebook

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJS)
