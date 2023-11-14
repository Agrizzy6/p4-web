#ifndef LIST_HPP
#define LIST_HPP
/* List.hpp
 *
 * doubly-linked, double-ended list with Iterator interface
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

  List()
  {
    first = nullptr;
    last = nullptr;
  }
  List (List<T> &copy)
  {
    copy_all(copy);
  }
  ~List()
  {
    clear();
  }
  //EFFECTS:  returns true if the list is empty
  bool empty() const
  {
    if (list_size == 0)
    {
      return true;
    }
    return false;
  }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const
  {
    return list_size;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front()
  {
    assert(!empty());
    return first->datum;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back()
  {
    assert(!empty());
    return last->datum;
  }

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum)
  {
    Node *newNode = new Node;
    newNode->datum = datum;
    newNode->next = first;
    newNode->prev = nullptr;
    if (empty())
    {
      last=newNode;
    }
    else
    {
      first->prev = newNode;
    }
    first = newNode;
    list_size++;

  }

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum)
  {
    Node *newNode = new Node;
    newNode->datum = datum;
    newNode->next = nullptr;
    newNode->prev = last;
    if (empty())
    {
      first=newNode;
    }
    else
    {
      last->next = newNode;
    }

    last = newNode;
    list_size++;
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front()
  {
    assert(!empty());
    Node *deleted = first;
    first = first->next;
    delete deleted;
    if (empty())
    {
      first = nullptr;
      last = nullptr;
    }
   
    list_size--;
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back()
  {
    assert(!empty());
    Node *tempLast = last->prev;
    delete last;
    last = tempLast;
    if (empty())
    {
      first = nullptr;
      last = nullptr;
    }
    else
    {
      last = tempLast;
    }
    list_size--;
  }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear()
  {
    int initialSize = list_size;
    for (int i = 0; i < initialSize; ++i)
    {
      pop_back();
    }
  }


  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };
  
  int list_size = 0;
  friend class Iterator;

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other)
  {
    assert(this->empty());
    Iterator itBegin = other.begin();
    for (int i = 0; i < other.list_size; ++i)
    {
      int datum = itBegin.get_node()->datum;
      push_back(datum);
      ++itBegin;
    }
    
  }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty
  

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List
    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.
    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.
  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }
    
    Iterator& operator++() {
      assert(node_ptr);
      node_ptr = node_ptr->next;
      return *this;
    }

    T & operator*() const{
      assert(node_ptr);
      return node_ptr->datum;
    }

    bool operator==(Iterator rhs) const{
      assert(node_ptr);
      if(node_ptr == rhs.node_ptr){
        return true;
      }
      else{
        return false;
      }
    }

    bool operator!=(Iterator rhs) const{
      assert(node_ptr);
      if(node_ptr != rhs.node_ptr){
        return true;
      }
      else{
        return false;
      }
    }
    
    
    Iterator()
    : node_ptr(this->first){}

    Iterator(Node *p) 
    : node_ptr(p){}

    Node* get_node()
    {
      return node_ptr;
    }

  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here
    // add any friend declarations here
    // construct an Iterator at a specific position
 
   

  };//List::Iterator
  ////////////////////////////////////////
  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }
  // return an Iterator pointing to "past the end"
  Iterator end() const{
    return Iterator(last);
  }
  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i){
    return;
    
  }
  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum)
  {
    return;
  }



};//List
////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.
#endif // Do not remove this. Write all your code above this line.
