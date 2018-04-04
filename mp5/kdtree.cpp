/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    if (curDim >= Dim || curDim < 0)
      return false;
    if (first[curDim] == second[curDim])
      return (first < second);
    else
      return (first[curDim] < second[curDim]);
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    int dist1 = get_distance(potential, target);
    int dist2 = get_distance(currentBest, target);

    if (dist1 == dist2)
      return (potential < currentBest);
    else
      return (dist1 < dist2);
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
     if (newPoints.empty())
     {
       root = NULL;
       size = 0;
     }
     else
     {
       list = newPoints;
       root = kdtree(0, list.size() - 1, 0);
       size = list.size();
     }
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree& other) {
  /**
   * @todo Implement this function!
   */
   if (other.list.empty())
   {
     root = NULL;
     size = 0;
   }
   else
   {
     list = other.list;
     root = kdtree(0, list.size() - 1, 0);
     size = list.size();
   }
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree& rhs) {
  /**
   * @todo Implement this function!
   */

  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
   clear(root);
   size = 0;
  // delete[] list;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    KDTreeNode * curr = root;
    Point<Dim> pt;
    KDTreeNode currentBest(pt);
    nearest(curr, query, 0, &currentBest);
    return currentBest.point;
}

template <int Dim>
int KDTree<Dim>::partition(int left, int right, int pivotIndex, int d)
{
    Point<Dim> pivotValue = list[pivotIndex];
    // swap list[pivotIndex] and list[right]  // Move pivot to end
    Point<Dim> temp = list[pivotIndex];
    list[pivotIndex] = list[right];
    list[right] = temp;
    int storeIndex = left;
    for (int i = left; i < right; i++)
    {
       if (smallerDimVal(list[i], pivotValue, d))
       {
           // swap list[storeIndex] and list[i]
           temp = list[storeIndex];
           list[storeIndex] = list[i];
           list[i] = temp;
           storeIndex++;
        }
    }
    // swap list[right] and list[storeIndex]  // Move pivot to its final place
    temp = list[storeIndex];
    list[storeIndex] = list[right];
    list[right] = temp;
    return storeIndex;
}

template <int Dim>
Point<Dim> KDTree<Dim>::quickselect(int left, int right, int k, int d)
{
  if (left >= right)
    return list[left];
  int pivotIndex = (left + right) / 2; // select a pivotIndex between left and right
  pivotIndex = partition(left, right, pivotIndex, d);
  // The pivot is in its final sorted position
  if (k == pivotIndex)
    return list[k];
  else if (k < pivotIndex)
    return quickselect(left, pivotIndex - 1, k, d);
  else
    return quickselect(pivotIndex + 1, right, k, d);
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::kdtree(int left, int right, int d) // d is depth, current dimension - pass in axis
{
  int axis = d % Dim;
  int med_idx = floor( (double) (left + right) / 2 );
  Point<Dim> pt = quickselect(left, right, med_idx, axis);
  KDTreeNode * top = new KDTreeNode(pt);
  if (left <= med_idx - 1)
    top->left = kdtree(left, med_idx - 1, d+1);
  if (right >= med_idx + 1)
    top->right = kdtree(med_idx + 1, right, d+1);
  return top;
}

template <int Dim>
void KDTree<Dim>::nearest(KDTreeNode * node, const Point<Dim> query, int d, KDTreeNode * currentBest) const
{
  int axis = d % Dim;
  int radius = 0;

  // traversing down into tree recursively
  if (smallerDimVal(query, node->point, axis))
  {
    if (node->left == NULL) // at left most leaf
    {
      currentBest->point = node->point;
      return;
    }
    else
      nearest(node->left, query, d+1, currentBest);
  }
  else
  {
    if (node->right == NULL) // at right most leaf
    {
      currentBest->point = node->point;
      return;
    }
    else
      nearest(node->right, query, d+1, currentBest);
  }

  // recursing back out
  if (shouldReplace(query, currentBest->point, node->point))
  {
    currentBest->point = node->point;
  }

  radius = get_distance(query, currentBest->point);
  int split_dist = pow( (query[axis] - node->point[axis]) , 2);

  if (split_dist <= radius)
  {
    // if (split_dist == radius)
    // {
    //   if (node->point < currentBest->point)
    //   {
    //     currentBest->point = node->point;
    //   }
    // }
    KDTreeNode temp(currentBest->point);
    if (smallerDimVal(query, currentBest->point, axis))
    {
      if (node->right == NULL) // at right most leaf
      {
        temp.point = node->point;
        return;
      }
      else
        nearest(node->right, query, d+1, &temp);
    }
    else
    {
      if (node->left == NULL) // at left most leaf
      {
        temp.point = node->point;
        return;
      }
      else
        nearest(node->left, query, d+1, &temp);
    }
    if (shouldReplace(query, currentBest->point, temp.point))
    {
      currentBest->point = temp.point;
    }
  }
  return;
}

template <int Dim>
void KDTree<Dim>::copy()
{

}

template <int Dim>
void KDTree<Dim>::clear(KDTreeNode * node)
{
  KDTreeNode * curr = node;
  if (curr == NULL)
    return;
  if (curr->left != NULL)
    clear(curr->left);
  if (curr->right != NULL)
    clear(curr->right);
  node = NULL;
}

template <int Dim>
int KDTree<Dim>::get_distance(const Point<Dim>& point1, const Point<Dim>& point2) const
{
  int dist1 = 0;
  for (int i = 0; i < Dim; i++)
  {
    dist1 += pow( (point1[i] - point2[i]), 2 );
  }
  return dist1;
}
