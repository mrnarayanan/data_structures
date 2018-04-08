
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    // @TODO Update to return the index you are choosing to be your root.
    return 1; // 1-indexed
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the left child.
    return 2*currentIdx;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the right child.
    return 2*currentIdx + 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    // @TODO Update to return the index of the parent.
    return currentIdx / 2; // integer division, so floor() not needed
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    // @TODO Update to return whether the given node has a child
    if (2*currentIdx < _elems.size()) // if it has a child, it must have the left child
      return true;
    else
      return false;
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the child with highest priority
    ///   as defined by higherPriority()

    // only call if know a child exists
    size_t left = leftChild(currentIdx);
    size_t right = rightChild(currentIdx);
    if (right >= _elems.size())
      return left;
    bool cmp = higherPriority(_elems[left], _elems[right]);
    if (cmp)
      return left;
    else
      return right;
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    // @TODO Implement the heapifyDown algorithm.
    size_t left = leftChild(currentIdx);
    size_t right = rightChild(currentIdx);
    if (!hasAChild(currentIdx))
      return;
    else
    {
      unsigned priority = maxPriorityChild(currentIdx);
      if (higherPriority(_elems[priority], _elems[currentIdx]))
        std::swap(_elems[currentIdx], _elems[priority]);
      heapifyDown(priority);
    }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    // @TODO Depending on your implementation, this function may or may
    ///   not need modifying
    _elems.push_back(T()); // populate index 0 with default value so that we can start w/ 1-indexing
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
    // @TODO Construct a heap using the buildHeap algorithm
    _elems.push_back(T()); // populate index 0 with default value so that we can start w/ 1-indexing

    for (unsigned i = 0; i < elems.size(); i++)
    {
      _elems.push_back(elems[i]);
    }
    for (unsigned i = parent(_elems.size()-1); i > 0; i--)
    {
      heapifyDown(i);
    }
}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    // @TODO Remove, and return, the element with highest priority
    if (empty())
      return T();
    T min = _elems[root()];
    _elems[root()] = _elems[_elems.size()-1];
    _elems.pop_back();
    heapifyDown(root());
    return min;
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    // @TODO Return, but do not remove, the element with highest priority
    if (empty())
      return T();
    return _elems[root()];
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    // @TODO Add elem to the heap
    _elems.push_back(elem);
    heapifyUp(_elems.size()-1);
}

template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    // @TODO Determine if the heap is empty
    return _elems.empty() || (_elems.size() == 1);
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}
