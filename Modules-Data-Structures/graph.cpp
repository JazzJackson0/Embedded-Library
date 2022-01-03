#include <iostream>
#include "graph.h"



Vertex::Vertex(int newData) {
    currentEdgeSize = 0;
    data = newData;
}

int Vertex::Get_Data() {
    return data;
}


void Vertex::Add_Edge(Vertex new_vertex, int weight) {
    edges[currentEdgeSize - 1].vertex_id = new_vertex.Get_Data();
    edges[currentEdgeSize - 1].edge_weight = weight;
    currentEdgeSize++;
}

void Vertex::Get_Edges() {
    for (int i = 0; i < currentEdgeSize; i++) {

        std::cout << edges[i].vertex_id << std::endl;
    }
}

void Vertex::Set_HubIndex(int index) {
    hub_index = index;
}

int Vertex::Get_HubIndex() {
    return hub_index;
}

//-------------------------------------------------------------------------------


Graph::Graph(bool state) {
    directed = state;
    vHub.vertexNum = 0;
}

bool Graph::isDirected() {
    return directed;
}

void Graph::Add_Vertex(Vertex new_vertex) {
    new_vertex.Set_HubIndex(vHub.vertexNum);
    vHub.vertices[vHub.vertexNum] = new_vertex;
    vHub.vertexNum++;
}

void Graph::Add_Edge(Vertex from_vertex, Vertex to_vertex, int weight) {
    vHub.vertices[from_vertex.Get_HubIndex()].Add_Edge(to_vertex, weight);

    if (!directed) {
        vHub.vertices[to_vertex.Get_HubIndex()].Add_Edge(from_vertex, weight);
    }
}

void Graph::Get_Vertices() {

    for (int i = 0; i < vHub.vertexNum; i++) {

        std::cout << vHub.vertices[i].Get_Data() << std::endl;
    }
}

void Graph::Get_Edges() {
    
    for (int i = 0; i < vHub.vertexNum; i++) {

        vHub.vertices[i].Get_Edges();
        std::cout << "\n";
    }
}

void Graph::DFS(Vertex starting_vertex, Vertex target_vertex, Vertex *visited) {

    // Implement
    if (visited == ) {

    }

    visited
}

void Graph::BFS(Vertex starting_vertex, Vertex target_vertex) {

    // Implement
    Vertex *path;
}



/*
 * 			TO-DO
 * 			-----
 *  - Test Code
 *
 *  - 
 *  
 *  - 
 *  */