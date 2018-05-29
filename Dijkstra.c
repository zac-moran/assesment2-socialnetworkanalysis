// Dijkstra ADT interface for Ass2 (COMP2521)
#include "Dijkstra.h"
#include "PQ.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#define INFINITY 9999

ShortestPaths init(Graph g, Vertex v);

ShortestPaths dijkstra(Graph g, Vertex v) {

	ShortestPaths sp = init(g,v);

	PQ pq = newPQ();
    ItemPQ new;
    for (int i = 0; i < sp.noNodes; i++) {
    	if(i!=v){
    		new.key = i;
    		new.value = INFINITY;
    		addPQ(pq,new);
    	}
    }
    new.key = v;
    new.value = 0;
    //addPQ(pq,new);
    showPQ(pq);

	/*for (int i = 0; i < sp.noNodes; i++) {
		if (i!=v) {
			sp.dist[i] = INFINITY;
			new.key = i;
			new.value = INFINITY;
			addPQ(pq, new);
		}
		sp.pred[i] = NULL;
	}
	//showPQ(pq);
	sp.dist[v] = 0;
	new.key = v;
	new.value = 0;
	addPQ(pq, new);
	showPQ(pq);
	//int newDist;*/
	/*while (PQEmpty(pq)==0) {
		item = dequeuePQ(pq);
		printf("Item dequeded:  ");
		printf("| key: %d | value: %d |\n",item.key, item.value);
		int src = item.key;
		AdjList verts = outIncident(g, src);
		//printf("_____________________ %d ____________\n\n", src);
		while(verts!=NULL){
			int dest = verts->w;
			newDist = sp.dist[src] + verts->weight;
			if (newDist < sp.dist[dest]) {
				item.key = dest;
				item.value = newDist;
				updatePQ(pq, item);
				sp.dist[dest] = newDist;
				PredNode *new = malloc(sizeof(PredNode));
				new->v = src;
				new->next = NULL;
				sp.pred[dest] = new; 
			}
			//for (int i = 0; i < sp.noNodes; i++) {
			//	printf(" [%d] ",sp.dist[i]);
			//}
			//printf("\n");
			verts = verts->next;
		}
		showPQ(pq);
	}*/

	//for (int i = 0; i < sp.noNodes; i++) {
	//	printf(" [%d] ",sp.dist[i]);
	//}
	//printf("\n");

	return sp;
}

void showShortestPaths(ShortestPaths paths) {

}


void  freeShortestPaths(ShortestPaths paths) {

}

ShortestPaths init(Graph g, Vertex v) {
	ShortestPaths *sp = malloc(sizeof(ShortestPaths));
	sp->src = v;
	sp->noNodes = numVerticies(g);
	sp->dist = malloc(sizeof(int)*numVerticies(g));
	sp->pred = malloc(sizeof(PredNode)*numVerticies(g));
	return *sp;
}