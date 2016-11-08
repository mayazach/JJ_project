OBJS 	= main.o Buffer.o Ptr.o NodeIndex.o 
SOURCE	= main.cpp Buffer.cpp Ptr.cpp NodeIndex.cpp 
HEADERS  = Buffer.h NodeIndex.h
HEADERS2 = Buffer.h NodeIndex.h HashNode.h ListNode.h
OUT  	= project
CC	= g++
FLAGS   = -g -c 


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

main.o: main.cpp $(HEADERS)
	$(CC) $(FLAGS) main.cpp

Buffer.o: Buffer.cpp Buffer.h ListNode.h Ptr.h
	$(CC) $(FLAGS) Buffer.cpp

Ptr.o: Ptr.cpp Ptr.h HashNode.h ListNode.h
	$(CC) $(FLAGS) Ptr.cpp
	
NodeIndex.o: NodeIndex.cpp $(HEADERS2)
	$(CC) $(FLAGS) NodeIndex.cpp
	

clean:
	rm -f $(OBJS) $(OUT)