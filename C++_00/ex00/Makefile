
CC = c++
 
  # compiler flags:
  #  -g     - this flag adds debugging information to the executable file
  #  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -Wall -Wextra -Werror -std=c++98
 
  # The build target 
TARGET = megaphone
 
all: $(TARGET)
 
$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp
 
clean:
	$(RM) $(TARGET)
