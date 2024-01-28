# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Source files
SOURCE = main.c
SOURCE1 = basicClassification.c
SOURCE2 = advancedClassificationLoop.c
SOURCE3 = advancedClassificationRecursion.c

# Object files
OBJECT = main.o
OBJECT1 = basicClassification.o
OBJECT2 = advancedClassificationLoop.o
OBJECT3 = advancedClassificationRecursion.o

# Targets
TARGET1 = mains
TARGET2 = maindloop
TARGET3 = maindrec

# Header file
HEADER = NumClass.h

# Static library
loops: $(OBJECT1) $(OBJECT2)
	ar rcs libclassloops.a $(OBJECT1) $(OBJECT2)

# Dynamic library
loopd: $(OBJECT1) $(OBJECT2)
	$(CC) -shared -o libclassloops.so $(OBJECT1) $(OBJECT2)

# Static library
recursives: $(OBJECT3) $(OBJECT1)
	ar rcs libclassrec.a $(OBJECT3) $(OBJECT1)

# Dynamic library
recursived: $(OBJECT1) $(OBJECT3)
	$(CC) -shared -o libclassrec.so $(OBJECT1) $(OBJECT3)

# Main executables
mains: libclassrec.a $(HEADER) $(SOURCE) $(SOURCE1) $(SOURCE3)
	$(CC) $(CFLAGS) -o mains $(SOURCE) $(SOURCE1) $(SOURCE3) -L. -lclassrec -lm

maindloop: libclassloops.so $(HEADER) $(SOURCE) $(SOURCE1) $(SOURCE2)
	$(CC) $(CFLAGS) -o maindloop $(SOURCE) $(SOURCE1) $(SOURCE2) -L. -lclassloops -lm

maindrec: libclassrec.so $(HEADER) $(SOURCE) $(SOURCE1) $(SOURCE3)
	$(CC) $(CFLAGS) -o maindrec $(SOURCE) $(SOURCE1) $(SOURCE3) -L. -lclassrec -lm

.PHONY: all clean

clean:
	rm -f libclassloops.a libclassrec.a libclassloops.so libclassrec.so $(OBJECT) $(TARGET1) $(TARGET2) $(TARGET3) $(OBJECT1) $(OBJECT2) $(OBJECT3)
