#ifndef BFS_H_
#define BFS_H_
#include "queue.h"

int getPathSize(int father1,int father2,Queue &explored);

int bidirectionalBFS(int start, int finish,NodeIndex *in,NodeIndex *out,Buffer *buffin,Buffer *buffout);

#endif
