#ifndef _DICTIONARY_INTERFACE
#define _DICTIONARY_INTERFACE

#include "NotFoundException.h"

template<class ItemType, class KeyType>
class DictionaryInterface 
{
public:   
   /** Sees whether this dictionary is empty.
    @return True if the dictionary is empty;
       otherwise returns false. */
   virtual bool isEmpty() const = 0;
   
   /** Gets the number of items in this dictionary.
    @return The number of items in the dictionary. */
   virtual int getNumberOfItems() const = 0;
  
   virtual bool add(const KeyType& searchKey, const ItemType& newItem) = 0;
   
   virtual bool remove(const KeyType& searchKey) = 0;
   

   virtual void clear() = 0;
   
 
   virtual ItemType getItem(const KeyType& searchKey) const throw (NotFoundException) = 0;
   

   virtual bool contains(const KeyType& searchKey) const = 0;
   
 
   virtual void traverse(void visit(ItemType&)) const = 0;
}; // end DictionaryInterface

#endif
