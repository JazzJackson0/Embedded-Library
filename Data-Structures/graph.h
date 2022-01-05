#pragma once


typedef struct edge {
    int vertex_id;
    int edge_weight;
}Edge;
//--------------------------------------------------------------------------
typedef struct hub {
    Vertex *vertices;
    int vertexNum;
}VertexHub;
//--------------------------------------------------------------------------
class Vertex {
    private:
        int data;
        Edge *edges;
        int currentEdgeSize;
        int hub_index;
    public:
        Vertex(int newData);

        int Get_Data() { return data; }

        void Add_Edge(Vertex new_vertex, int weight);

        void Get_Edges();

        void Set_HubIndex(int index);

        int Get_HubIndex() { return hub_index; }
};

//----------------------------------------------------------------------------

class Graph {
    private:
        bool directed;
        VertexHub vHub;
    public:

        Graph(bool state);

        bool isDirected() { return directed; }

        void Add_Vertex(Vertex new_vertex);

        void Add_Edge(Vertex from_vertex, Vertex to_vertex, int weight);

        void Get_Vertices();

        void Get_Edges();

        void DFS(Vertex starting_vertex, Vertex target_vertex, Vertex *visited);

        void BFS(Vertex starting_vertex, Vertex target_vertex);

};




