#include "shapeobj.h"

static int AllocateData(OBJECT *pObj, va_list argp);

static MESSAGE messages[] =
{
  {ALLOCATE_DATA, AllocateData},
};

CLASS generic_shape =
{
   NULL,
   0,
   sizeof(messages) / sizeof(MESSAGE),
   messages
};

static int AllocateData(OBJECT *pObj, va_list argp)
{
   CLASS *pClass;
   int size = 0;
   for (
	pClass = pObj->pClass,size = 0; 
	pClass != NULL; 
	pClass = pClass->base_class
	)
	{
	   size += pClass->DataSize;
	}

  pObj->pData = allocate_memory(size);
  return 1;

}
