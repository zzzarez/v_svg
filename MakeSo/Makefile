CXX   = g++ 
CC    = g++14
LDFLAGS += -pthread  -shared -fPIC
debug: CFLAGS  = -g -MD -Wall -fPIC  
release: CFLAGS  = 
debug: exec
release: exec



OBJS =  v_svg.o 
TARGET = v_svg.so



all: exec
exec: $(TARGET)

.cpp.o:
	$(CXX) $(CFLAGS) $(INC) -c $< -o $@ 2> sk
.c.o:
	$(CC) $(CFLAGS) $(INC) -c $< -o $@ 2> sk


$(TARGET):  $(OBJS) 
	$(CXX) -o $@  $(OBJS) $(INC) $(LDFLAGS) 2>sk
 
