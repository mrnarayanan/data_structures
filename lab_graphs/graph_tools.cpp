/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"

// static variable
static unordered_map<Vertex, Vertex> parent_map;

/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph& graph)
{
    //TODO: YOUR CODE HERE
    Vertex start = graph.getStartingVertex();
    Edge minedge = BFS(graph, start, true);
    return minedge.getWeight();
}

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph& graph, Vertex start, Vertex end)
{
    //TODO: YOUR CODE HERE
    // mask warnings
//    graph.getEdge(start, end);

    int count = 0;
    parent_map.clear();
    BFS(graph, start, false);

    while (true)
    {
      Vertex parent = parent_map[end];
      graph.setEdgeLabel(parent, end, "MINPATH");
      count++;
      end = parent;
      if (start == parent)
        break;
    }
    return count;
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the dsets.h and dsets.cpp .
 * @note You may call std::sort instead of creating a priority queue.
 */
void GraphTools::findMST(Graph& graph)
{
    //TODO: YOUR CODE HERE
    Vertex start = graph.getStartingVertex();
    BFS(graph, start, true);

    DisjointSets forest;
    vector<Vertex> vert = graph.getVertices();
    unordered_map<Vertex, unsigned> krusk;
    for (unsigned i = 0; i < vert.size(); i++)
    {
      krusk.emplace(vert[i], i);
    }
    forest.addelements(vert.size());
    vector<Edge> ed = graph.getEdges();
    std::sort(ed.begin(), ed.end());
    unsigned num = 0;
    int ctor = 0;
    while (num < vert.size() - 1)
    {
      Edge mine = ed[ctor++];
      Vertex u = mine.source;
      Vertex v = mine.dest;
    //  std::cout << u << " --> " << v << std::endl;
      // if (u == "")
      //   break;
      int u_int = krusk.at(u);
      int v_int = krusk.at(v);
      std::cout << u_int << " --> " << v_int << std::endl;
      std::cout << forest.find(u_int) << " --> " << forest.find(v_int) << std::endl;
      if (forest.find(u_int) == forest.find(v_int))
      {
        graph.setEdgeLabel(u,v,"MST");
        std::cout << u << " --> " << v << std::endl;
        forest.setunion(forest.find(u_int), forest.find(v_int));
        num++;
      }
    }
}

Edge GraphTools::BFS(Graph& graph, Vertex start, bool weighted)
{
  // clear everything first
  vector<Vertex> vert = graph.getVertices();
  vector<Edge> ed = graph.getEdges();
  for (unsigned i = 0; i < vert.size(); i++)
  {
    graph.setVertexLabel(vert[i], "UNEXPLORED");
  }
  for (unsigned i = 0; i < ed.size(); i++)
  {
    Vertex src = ed[i].source;
    Vertex dest = ed[i].dest;
    graph.setEdgeLabel(src, dest, "UNEXPLORED");
  }

  // start traversal
  queue<Vertex> q;
  graph.setVertexLabel(start, "VISITED");
  q.push(start);
  int min = INT_MAX;
  Vertex min_start;
  Vertex min_end;

  while (!q.empty())
  {
    Vertex v = q.front();
    q.pop();
    vector<Vertex> adj = graph.getAdjacent(v);
    for (unsigned i = 0; i < adj.size(); i++)
    {
      Vertex w = adj[i];
      if (graph.getVertexLabel(w) == "UNEXPLORED")
      {
        graph.setEdgeLabel(v,w,"DISCOVERY");
        graph.setVertexLabel(w, "VISITED");
        q.push(w);
        parent_map.emplace(w,v);
      }
      else if (graph.getEdgeLabel(v,w) == "UNEXPLORED")
        graph.setEdgeLabel(v,w,"CROSS");
      if (weighted)
      {
        int weight = graph.getEdgeWeight(v, w);
        if (weight < min)
        {
          min_start = v;
          min_end = w;
          min = weight;
        }
      }
    }
  }
  if (weighted)
  {
    graph.setEdgeLabel(min_start, min_end, "MIN");
    return graph.getEdge(min_start, min_end);
  }
  else
    return Edge();
}
