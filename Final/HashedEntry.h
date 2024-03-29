#ifndef _HASHED_ENTRY
#define _HASHED_ENTRY

#include "Entry.h"

template<class KeyType, class ItemType>
class HashedEntry : public Entry<KeyType, ItemType>
{
private:
   HashedEntry<KeyType, ItemType>* nextPtr;
   int count;
   
public:
   HashedEntry();
   HashedEntry(ItemType newEntry, KeyType searchKey);
   HashedEntry(ItemType newEntry, KeyType searchKey,
               HashedEntry<KeyType, ItemType>* nextEntryPtr);
   void setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr);
   HashedEntry<KeyType, ItemType>* getNext() const;
   int getCount() const;
   void setCount(const int& newCount);
   void countUp();
   void countDown();

}; // end HashedEntry

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry():nextPtr(nullptr)
{
}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry, KeyType searchKey):nextPtr(nullptr), count(1)
{
	setItem( newEntry );
	setKey( searchKey ); 
}

template<class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr)
{
	nextPtr = nextEntryPtr;
}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>* HashedEntry<KeyType, ItemType>::getNext() const
{
	return nextPtr;
}

template <class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::setCount(const int& newCount)
{
	count = newCount;
}

template <class KeyType, class ItemType>
int HashedEntry<KeyType, ItemType>::getCount() const
{
	return count;
}

template <class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::countUp()
{
	count++;
}

template <class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::countDown()
{
	count--;
}
#endif
