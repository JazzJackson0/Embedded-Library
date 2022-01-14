#pragma once


typedef struct edge {
    int vertex_id;
    int edge_weight;
}Edge;

//--------------------------------------------------------------------------
class Vertex {
    private:
        int data;
        Edge *edges;
        int currentEdgeSize;
        int hub_index;
    public:
        /**
         * @brief 
         * 
         */
        Vertex(int newData);

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int Get_Data();

        /**
         * @brief 
         * 
         * @param new_vertex 
         * @param weight 
         * @return ** void 
         */
        void Add_Edge(Vertex new_vertex, int weight);

        /**
         * @brief 
         * 
         * @return ** void 
         */
        void Get_Edges();

        /**
         * @brief 
         * 
         * @param index 
         * @return ** void 
         */
        void Set_HubIndex(int index);

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int Get_HubIndex();
};


//--------------------------------------------------------------------------
typedef struct hub {
    Vertex *vertices;
    int vertexNum;
}VertexHub;

//----------------------------------------------------------------------------

class Graph {
    private:
        bool directed;
        VertexHub vHub;
    public:

        Graph(bool state);

        bool isDirected();

        void Add_Vertex(Vertex new_vertex);

        void Add_Edge(Vertex from_vertex, Vertex to_vertex, int weight);

        void Get_Vertices();

        void Get_Edges();

        void DFS(Vertex starting_vertex, Vertex target_vertex, Vertex *visited);

        void BFS(Vertex starting_vertex, Vertex target_vertex);

};




