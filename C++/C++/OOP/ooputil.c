#include <stdio.h>

#include "shapeobj.h"

int send_message(OBJECT *pObj, int msgid, ...)
{
   int status;
   va_list argp;
   va_start(argp, msgid);
   status = class_message(pObj->pClass, pObj, msgid, argp);
   va_end(argp);
   return status;
}

int class_message(CLASS *pClass, OBJECT *pObj, int msgid, va_list argp)
{
   int i, status;
   if (pClass == NULL)
   {
    return 0;
   }

   if (pClass->messages != NULL)
   {
      for (i = 0; i < pClass->NumMessages; ++i)
      {
         if (pClass->messages[i].msgid == msgid)
	 {
	    return ((*pClass->messages[i].msg_handler)(pObj, argp));
	 }
      }

      status = class_message(pClass->base_class, pObj, msgid, argp);
   }

   return status;

}


void* allocate_memory(size_t bytes)
{
   void *ptr;
   if ((ptr = calloc(1, bytes)) == NULL)
   {
      printf("alloc memory error\n");
      exit(1);
   }

   return ptr;
}


int get_offset(CLASS *pClass)
{
   CLASS *p_ct;
   int size = 0;
   for (pClass = pClass->base_class; pClass != NULL; pClass = pClass->base_class)
   {
      size += pClass->DataSize;
   }

   return size;
}
