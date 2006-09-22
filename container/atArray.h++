
#ifndef AT_ARRAY_H
#define AT_ARRAY_H


// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "atNotifier.h++"
#include "atItem.h++"


class atArray : public atNotifier
{
   protected:
      atItem **       array_items;
      
      u_long          num_entries;
      u_long          current_capacity;

      virtual bool    ensureCapacity(u_long capacity);

   public:
      atArray();
      atArray(u_long capacity);
      virtual ~atArray();

      virtual u_long     getNumEntries();

      virtual bool       addEntry(atItem * item);
      virtual atItem *   setEntry(u_long index, atItem * item);
      virtual bool       insertEntry(u_long index, atItem * item);
      virtual bool       removeEntry(u_long index);
      virtual bool       removeEntry(atItem * item);
      virtual bool       removeAllEntries();

      virtual atItem *   getEntry(u_long index);
      virtual long       getIndexOf(atItem * item);
};

#endif
