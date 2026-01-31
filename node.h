/***********************************************************************
 * Header:
 *    NODE
 * Summary:
 *    One node in a linked list (and the functions to support them).
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *        Node         : A class representing a Node
 *    Additionally, it will contain a few functions working on Node
 * Author
 *    Michael, James, Brayden
 ************************************************************************/

#pragma once

#include <cassert>     // for ASSERT
#include <iostream>    // for NULL

/*************************************************
 * NODE
 * the node class.  Since we do not validate any
 * of the setters, there is no point in making them
 * private.  This is the case because only the
 * List class can make validation decisions
 *************************************************/
template <class T>
class Node
{
public:
   //
   // Construct
   //

   // ------- Michael code to complete --------
   //

   // Default constructor
   Node() : data(), pNext(nullptr), pPrev(nullptr) {}

   // Copy constructor (construct node from a value)
   Node(const T& data) : data(data), pNext(nullptr), pPrev(nullptr) {}

   // Move constructor (construct node from an r-value)
   Node(T&& data) : data(std::move(data)), pNext(nullptr), pPrev(nullptr) {}

   //
   // Member variables
   //
   T data;
   Node <T>* pNext;
   Node <T>* pPrev;
};

/***********************************************
 * COPY
 * Copy the list from the pSource and return
 * the new list
 *   INPUT  : the list to be copied
 *   OUTPUT : return the new list
 *   COST   : O(n)
 **********************************************/
 // ------- Michael code to complete --------
template <class T>
inline Node <T>* copy(const Node <T>* pSource)
{
   if (!pSource)
       return nullptr;

   // create the head
   Node<T>* pHead = new Node<T>(pSource->data);
   pHead->pPrev = nullptr;
   pHead->pNext = nullptr;

   // create the remainder
   Node<T>* pDes = pHead;
   for (const Node<T>* pSrc = pSource->pNext; pSrc != nullptr; pSrc = pSrc->pNext)
   {
       Node<T>* pNew = new Node<T>(pSrc->data);
       pNew->pPrev = pDes;
       pNew->pNext = nullptr;
       pDes->pNext = pNew;
       pDes = pNew;
   }

   return pHead;
}

/***********************************************
 * Assign
 * Copy the values from pSource into pDestination
 * reusing the nodes already created in pDestination if possible.
 *   INPUT  : the list to be copied
 *   OUTPUT : return the new list
 *   COST   : O(n)
 **********************************************/
 // ------- James code to complete --------
template <class T>
inline void assign(Node <T>*& pDestination, const Node <T>* pSource)
{
   // Initialize
   const Node<T>* pSrc = pSource;
   Node<T>* pDes = pDestination;
   Node<T>* pTail = pDes;
   // Copy
   while (pSrc && pDes)
   {
      pDes->data = pSrc->data;
      pTail = pDes;
      pDes = pDes->pNext;
      pSrc = pSrc->pNext;
    
   }
   // Assign
   if (pSrc)
   {
      pDes = pTail;
      while (pSrc)
      {
         pDes = insert(pDes, pSrc->data, true);
         if (!pDestination)
            pDestination = pDes;
         pSrc = pSrc->pNext;
      }
   }
   // Delete
   if (!pSrc && pDes){
      bool setToNull = false;
         if (pDes->pPrev)
            pDes->pPrev->pNext = nullptr;
         else
            setToNull = true;
            
         clear(pDes);

         if (setToNull)
            pDestination = nullptr;
   }
}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
 // ------- Michael code to complete --------
template <class T>
inline void swap(Node <T>*& pLHS, Node <T>*& pRHS)
{
   std::swap(pLHS, pRHS);
}

/***********************************************
 * REMOVE
 * Remove the node pSource in the linked list
 *   INPUT  : the node to be removed
 *   OUTPUT : the pointer to the parent node
 *   COST   : O(1)
 **********************************************/
 // ------- Brayden code to complete --------
template <class T>
inline Node <T>* remove(const Node <T>* pRemove)
{
   return nullptr;
}


/**********************************************
 * INSERT 
 * Insert a new node the the value in "t" into a linked
 * list immediately before the current position.
 *   INPUT   : t - the value to be used for the new node
 *             pCurrent - a pointer to the node before which
 *                we will be inserting the new node
 *             after - whether we will be inserting after
 *   OUTPUT  : return the newly inserted item
 *   COST    : O(1)
 **********************************************/
 // ------- Brayden code to complete --------
template <class T>
inline Node <T>* insert(Node <T>* pCurrent,
   const T& t,
   bool after = false)
{

   return nullptr;
}

/******************************************************
 * SIZE
 * Find the size an unsorted linked list.  
 *  INPUT   : a pointer to the head of the linked list
 *            the value to be found
 *  OUTPUT  : number of nodes
 *  COST    : O(n)
 ********************************************************/
 // ------- James code to complete --------
template <class T>
inline size_t size(const Node <T>* pHead)
{
   // Create a new count of size_t
   size_t count = 0;

   // Loop through the linked list and iterate
   for (const Node <T> * p = pHead; p; p = p->pNext)
      count++;
   return count;
}


/***********************************************
 * DISPLAY
 * Display all the items in the linked list from here on back
 *    INPUT  : the output stream
 *             pointer to the linked list
 *    OUTPUT : the data from the linked list on the screen
 *    COST   : O(n)
 **********************************************/
 // ------- Brayden code to complete --------
template <class T>
inline std::ostream& operator << (std::ostream& out, const Node <T>* pHead)
{
   return out;
}

/*****************************************************
 * FREE DATA
 * Free all the data currently in the linked list
 *   INPUT   : pointer to the head of the linked list
 *   OUTPUT  : pHead set to NULL
 *   COST    : O(n)
 ****************************************************/
 // ------- Michael code to complete --------
template <class T>
inline void clear(Node <T>*& pHead)
{
   while (pHead != nullptr)
   {
       Node<T>* pNext = pHead->pNext;
       delete pHead;
       pHead = pNext;
   }
}


