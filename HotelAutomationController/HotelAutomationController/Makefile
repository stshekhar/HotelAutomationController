CC=g++
CFLAGS=-I./include
#DEPS = Corridor.h Equipment.h Floor.h Hotel.h HotelBuilder.h Motion.h PowerController.h PowerCriteria.h 
#OBJ = Corridor.o Equipment.o Floor.o Hotel.o HotelController.o 
OBJ = Corridor.cpp Equipment.cpp Floor.cpp Hotel.cpp HotelController.cpp PowerController.cpp Motion.cpp 

#%.o: %.c $(DEPS)
#	$(CC) -g -o $@ $< $(CFLAGS)

MotionController: $(OBJ)
	g++  -o  $@ $^ $(CFLAGS)

clean:
	rm -rf *.o MotionController
