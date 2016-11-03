# JJ_project

Files:

queue.h-queue.cpp: queue to use for frontiers/explored in BFS

qtest.cpp: tests queue functions on example queue

main.cpp: so far, takes input from text files, exits with errors if there are mistakes, else puts input in variables to be used by the rest of the program

bfs.cpp: has a getPathSize function that returns the length of the path between two nodes once the two BFS searches have met (using the explored set and the two parents of the node where the searches met)

