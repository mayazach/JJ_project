OBJS 	= main.o Buffer.o Ptr.o NodeIndex.o bfs.o queue.o Hashtable.o Parse.o
SOURCE	= main.cpp Buffer.cpp Ptr.cpp NodeIndex.cpp bfs.cpp queue.cpp Hashtable.cpp Parse.cpp
HEADERS  = Buffer.h NodeIndex.h
HEADERS2 = Buffer.h NodeIndex.h HashNode.h ListNode.h Ptr.h Task.h Edge.h
BUFFERHEADERS =Buffer.h ListNode.h Ptr.h Parse.h Task.h Edge.h
OUT  	= project
CC	= g++
FLAGS   = -g -c 


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

main.o: main.cpp $(HEADERS)
	$(CC) $(FLAGS) main.cpp

Buffer.o: Buffer.cpp $(BUFFERHEADERS)
	$(CC) $(FLAGS) Buffer.cpp

Ptr.o: Ptr.cpp Ptr.h HashNode.h ListNode.h Hashtable.h
	$(CC) $(FLAGS) Ptr.cpp
	
Parse.o: Parse.cpp Parse.h 
	$(CC) $(FLAGS) Parse.cpp
	
Hashtable.o: Hashtable.cpp Hashtable.h HashNode.h 
	$(CC) $(FLAGS) Hashtable.cpp
	
NodeIndex.o: NodeIndex.cpp $(HEADERS2)
	$(CC) $(FLAGS) NodeIndex.cpp

bfs.o: bfs.cpp Buffer.h NodeIndex.h bfs.h queue.h
	$(CC) $(FLAGS) bfs.cpp

queue.o: queue.cpp queue.h
	$(CC) $(FLAGS) queue.cpp
	
clean:
	rm -f $(OBJS) $(OUT)