/*
const int MAX_NV = 100; // maximum number of vertex
typedef int graph_weight_t;

struct graph_t {
    int nv; // number of vertex
    int ne; // number of edge;
    graph_weight_t matrix[MAX_NV][MAX_NV]; // adjacent matrix
};
*/

/*
 * DFS for edge
 * @param[in] g graph
 * @param[in] u current vertex
 * @param[in] visited record of visited edges
 * @return void
 */
void dfs(const graph_t &g, int u, bool visited[][MAX_NV]) {
    for(int v = 0; v < g.nv; v++) {
        if(g.matrix[u][v] && !visited[u][v]) {
            visited[u][v] = visited[v][u] = true; // undirected graph
            // visited[u][v] = true; // directed graph

            dfs(g, v, visited);
            // process
        }
    }
}

/*
 * DFS for vertex
 * @param[in] g graph
 * @param[in] u current vertex
 * @param[in] visited record of visited vertices
 * @return void
 */
 void dfs(const graph_t &g, int u, bool visited[MAX_NV]) {
    visited[u] = true;
    for(int v = 0; v < g.nv; v++) {
        if(g.matrix[u][v] && !visited[v]) {
            dfs(g, v, visited);
            // process
        }
    }
 }
