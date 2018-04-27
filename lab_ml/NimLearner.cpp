/**
 * @file NimLearner.cpp
 * CS 225: Data Structures
 */

#include "NimLearner.h"
#include <ctime>

using namespace std;

/**
 * Constructor to create a game of Nim with `startingTokens` starting tokens.
 *
 * This function creates a graph, `g_` representing all of the states of a
 * game of Nim with vertex labels "p#-X", where:
 * - # is the current player's turn; p1 for Player 1, p2 for Player2
 * - X is the tokens remaining at the start of a player's turn
 *
 * For example:
 *   "p1-4" is Player 1's turn with four (4) tokens remaining
 *   "p2-8" is Player 2's turn with eight (8) tokens remaining
 *
 * All legal moves between states are created as edges with initial weights
 * of 0.
 *
 * @param startingTokens The number of starting tokens in the game of Nim.
 */
NimLearner::NimLearner(unsigned startingTokens) : g_(true, true)
{
    /* Your code goes here! */
    for (int i = startingTokens; i >= 0; i--)
    {
      string p1 = "p1-" + to_string(i);
      string p2 = "p2-" + to_string(i);
      g_.insertVertexByLabel(p1);
      g_.insertVertexByLabel(p2);
    }
    string start = "p1-" + to_string(startingTokens);
    startingVertex_ = g_.getVertexByLabel(start);
    for (unsigned i = startingTokens; i >= 2; i--)
    {
      string p1 = "p1-" + to_string(i);
      string p2 = "p2-" + to_string(i);
      string p1_plus1 = "p1-" + to_string(i-1);
      string p2_plus1 = "p2-" + to_string(i-1);
      string p1_plus2 = "p1-" + to_string(i-2);
      string p2_plus2 = "p2-" + to_string(i-2);
      Vertex v1 = g_.getVertexByLabel(p1);
      Vertex v2 = g_.getVertexByLabel(p2);
      Vertex v11 = g_.getVertexByLabel(p1_plus1);
      Vertex v21 = g_.getVertexByLabel(p2_plus1);
      Vertex v12 = g_.getVertexByLabel(p1_plus2);
      Vertex v22 = g_.getVertexByLabel(p2_plus2);
      g_.insertEdge(v1,v21);
      g_.setEdgeWeight(v1,v21,0);
      g_.insertEdge(v1,v22);
      g_.setEdgeWeight(v1,v22,0);
      g_.insertEdge(v2,v11);
      g_.setEdgeWeight(v2,v11,0);
      g_.insertEdge(v2,v12);
      g_.setEdgeWeight(v2,v12,0);
    }
    // special case for 1 Token
    Vertex v11 = g_.getVertexByLabel("p1-1");
    Vertex v21 = g_.getVertexByLabel("p2-1");
    Vertex v10 = g_.getVertexByLabel("p1-0");
    Vertex v20 = g_.getVertexByLabel("p2-0");
    g_.insertEdge(v11,v20);
    g_.setEdgeWeight(v11,v20,0);
    g_.insertEdge(v21,v10);
    g_.setEdgeWeight(v21,v10,0);
}

/**
 * Plays a random game of Nim, returning the path through the state graph
 * as a vector of `Edge` classes.  The `origin` of the first `Edge` must be
 * the vertex with the label "p1-#", where # is the number of starting
 * tokens.  (For example, in a 10 token game, result[0].origin must be the
 * vertex "p1-10".)
 *
 * @returns A random path through the state space graph.
 */
std::vector<Edge> NimLearner::playRandomGame() const
{
    vector<Edge> path;
    /* Your code goes here! */
    Vertex curr = startingVertex_;
    while (g_.getVertexLabel(curr).substr(3) != "0")
    {
      int random = rand() % 2;
      vector<Vertex> adj = g_.getAdjacent(curr);
      if (adj.size() == 1) // last edge
        random = 0;
      Vertex next = adj[random];
      Edge e = g_.getEdge(curr, next);
      path.push_back(e);
      curr = next;
    }

    return path;
}

/*
 * Updates the edge weights on the graph based on a path through the state
 * tree.
 *
 * If the `path` has Player 1 winning (eg: the last vertex in the path goes
 * to Player 2 with no tokens remaining, or "p2-0", meaning that Player 1
 * took the last token), then all choices made by Player 1 (edges where
 * Player 1 is the source vertex) are rewarded by increasing the edge weight
 * by 1 and all choices made by Player 2 are punished by changing the edge
 * weight by -1.
 *
 * Likewise, if the `path` has Player 2 winning, Player 2 choices are
 * rewarded and Player 1 choices are punished.
 *
 * @param path A path through the a game of Nim to learn.
 */
void NimLearner::updateEdgeWeights(const std::vector<Edge> & path)
{
   /* Your code goes here! */
   unsigned last = path.size() - 1;
   Edge end = path[last];
   Vertex fin = end.dest;
   if (g_.getVertexLabel(fin) == "p2-0") // player 1 won
   {
     for (unsigned i = 0; i < path.size(); i++)
     {
       Edge e = path[i];
       Vertex s = e.source;
       Vertex d = e.dest;
       string playerid = g_.getVertexLabel(s);
       if (playerid.substr(0,2) == "p1") // player 1's move
       {
         int weight = g_.getEdgeWeight(s,d);
         weight++;
         g_.setEdgeWeight(s,d,weight);
       }
       else // player 2's move
       {
         int weight = g_.getEdgeWeight(s,d);
         weight--;
         g_.setEdgeWeight(s,d,weight);
       }
     }
   }
   else // player 2 won
   {
     for (unsigned i = 0; i < path.size(); i++)
     {
       Edge e = path[i];
       Vertex s = e.source;
       Vertex d = e.dest;
       string playerid = g_.getVertexLabel(s);
       if (playerid.substr(0,2) == "p1") // player 1's move
       {
         int weight = g_.getEdgeWeight(s,d);
         weight--;
         g_.setEdgeWeight(s,d,weight);
       }
       else // player 2's move
       {
         int weight = g_.getEdgeWeight(s,d);
         weight++;
         g_.setEdgeWeight(s,d,weight);
       }
     }
   }
}

/**
 * Label the edges as "WIN" or "LOSE" based on a threshold.
 */
void NimLearner::labelEdgesFromThreshold(int threshold)
{
  for (const Vertex & v : g_.getVertices()) {
    for (const Vertex & w : g_.getAdjacent(v)) {
      int weight = g_.getEdgeWeight(v, w);

      // Label all edges with positve weights as "WINPATH"
      if (weight > threshold)           { g_.setEdgeLabel(v, w, "WIN"); }
      else if (weight < -1 * threshold) { g_.setEdgeLabel(v, w, "LOSE"); }
    }
  }
}

/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & NimLearner::getGraph() const
{
  return g_;
}
