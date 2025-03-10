# candh
# set compiler
CC = gcc
LINFLAGS = -lm -lGL -lSOIL -lGLU -lglut

TARGET = main

linux:
	$(CC) $(TARGET).cpp -o $(TARGET) $(LINFLAGS)

run:
	./$(TARGET)
	
clean:
	$(RM) $(TARGET)