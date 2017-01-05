/*
 * STL_datastructure.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: songjiguo
 */

/*

0) STL is designed to be
    -- generic (can be used with any kind of object) and
    -- efficient (does not incur time overhead compared to alternatives).

To achieve these two design goals, STL containers store their objects by value.
This means that if you have an STL container that stores objects of class Base,
it cannot store of objects of classes derived from Base.

1) 
Probably the two most common self balancing tree algorithms are
Red-Black trees and AVL trees. To balance the tree after an
insertion/update both algorithms use the notion of rotations where the
nodes of the tree are rotated to perform the re-balancing.

While in both algorithms the insert/delete operations are O(log n), in
the case of Red-Black tree re-balancing rotation is an O(1) operation
while with AVL this is a O(log n) operation, making the Red-Black tree
more efficient in this aspect of the re-balancing stage and one of the
possible reasons that it is more commonly used.

Red-Black trees are used in most collection libraries, including the
offerings from Java and Microsoft .NET Framework.

AVL trees generally have a lower total runtime when there are many
more lookups than inserts/deletes. RB trees have a lower total runtime
when there are many more inserts/deletes.

It really depends on the usage. AVL tree has higher complexity of rebalancing.
So if your application doesn't have too many insertion and deletion operations, 
but weights heavily on searching, then AVL tree probably is a good choice.

std::map uses Red-Black tree as it gets a reasonable trade-off between
the complexity of node insertion/deletion and searching.

2) 
std::set is implemented can vary -- the C++ standard simply specifies
an abstract data type. In other words, the standard does not specify
how a container should be implemented, just what operations it is
required to support. However, most implementations of the STL do, as
far as I am aware, use red-black trees or other balanced binary search
trees of some kind (GNU libstdc++, for instance, uses red-black
trees).

3) The 2011 standard says (23.2.5 para 8), "The elements of an
unordered associative container are organized into buckets. Keys with
the same hash code appear in the same bucket."

Within each bucket, the elements are in a linked list (a separate list
for each bucket, not one big list for the whole container). When the
container is rehashed, the elements will be assigned to new buckets,
but the pointers to each element remain valid. The linked list in each
new bucket is assembled from pointers to the existing elements that
end up in that bucket.

Iterators are invalidated by a rehash, since an iterator needs to hold
pointers to both the element and its bucket (so it can be stepped from
the last element of one bucket to the first element of the next). The
element pointer remains valid, so existing pointers and references to
an element are still valid, but the bucket pointer is invalidated by a
rehash, so the iterator isn't usable.

This is also why unordered containers only support forward iterators, 
instead of the bidirectional iterators supported by the ordered associative containers. 
The elements of each bucket are in a singly linked list, so you can't step backwards 
through them

4) queue and stack are higher level containers. than deque or list or
vector. By this I mean that you can build a queue or stack out of the
lower level containers.

For example:

  std::stack<int, std::deque<int> > s;
  std::queue<double, std::list<double> > q;

Will build a stack of ints using a deque as the underlying container
and a queue of doubles using a list as the underlying container.

You can think of s as a restricted deque and q as a restricted list.

In the C++ library, both std::stack and std::queue are implemented as
container adapters. That means they provide the interface of a stack
or a queue respectively, but neither is really a container in itself.

5) Deque is typically implemented as a vector of vectors (a list of
vectors gives the constant time random access). The size of the
secondary vectors is implementation dependent, a common algorithm is
to use a constant size in bytes.  A deque is somewhat recursively
defined: internally it maintains a double-ended queue of chunks
(“blocks” in the graphic below) of fixed size. Each chunk is a vector,
and the queue (“map” in the graphic below) of chunks itself is also a
vector.

https://i.stack.imgur.com/XEtXc.png

6) std::list is a doubly linked list (C++11 introduces
std::forward_list which is a singly linked list). std::list is a
container that supports constant time insertion and removal of
elements from anywhere in the container. Fast random access is not
supported. It is usually implemented as a doubly-linked list. Compared
to std::forward_list this container provides bidirectional iteration
capability while being less space efficient.

Addition, removal and moving the elements within the list or across
several lists does not invalidate the iterators or references. An
iterator is invalidated only when the corresponding element is
deleted.

6)
std::array           	a container that encapsulates fixed size arrays
std::vector          	a sequence container that encapsulates dynamic size arrays, implemented by using an underlying array
std::deque 		     	typically implemented as a vector of vectors
std::map 		     	typically implemented as a red-black tree
std::unordered_map   	implemented as a hash table and linked list
std::multimap        	an associative container that contains a sorted list of key-value pairs
std::unordered_multimap an unordered associative container that supports equivalent keys
std::set 		     	an associative container, typically implemented as a red-black tree
std::unordered_set   	an associative container that contains a set of unique objects of type Key
std::multiset        	an associative container (multiple keys with equivalent values are allowed)
std::unordered_multiset an associative container that contains set of possibly non-unique objects of type Key
std::list 		     	typically implemented as a doubly-linked list
std::forward_list    	singly linked list

std::stack           	a container adapter, typically using deque/list/vector
std::queue           	a container adapter, typically using deque/list
std::priority_queue  	a container adaptor, typically using deque/vector

http://www.cs.northwestern.edu/~riesbeck/programming/c++/stl-summary.html

*/
