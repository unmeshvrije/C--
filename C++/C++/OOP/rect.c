#include <stdio.h>
#include "shapeobj.h"

typedef double *pDouble;

typedef struct RECT_DATA
{
   double x,y,l,b;

}  RECT_DATA;


static int rect_offset = -1;

extern CLASS generic_shape;
static int compute_area(OBJECT *pObj, va_list argp);

static MESSAGE messages[] =
{
  {COMPUTE_AREA, compute_area},
};

CLASS rect_class =
{
   &generic_shape,
   sizeof(RECT_DATA),
   sizeof(messages) / sizeof(MESSAGE),
   messages
};


OBJECT * newRectangle(double x, double y, double l, double b)
{
   OBJECT *pObj;
   RECT_DATA *pData;

   pObj = (OBJECT*)allocate_memory(sizeof(OBJECT));
   pObj->pClass = &rect_class;

  send_message(pObj, ALLOCATE_DATA, 0);
  if (rect_offset < 0 )
  {
     rect_offset = get_offset(&rect_class);
  }

  pData = (RECT_DATA *)((char*) pObj->pData + rect_offset);
  pData->x = x;
  pData->y = y;
  pData->l = l;
  pData->b = b;

  return pObj;
}

static int compute_area(OBJECT *pObj, va_list argp)
{
   int status = 0;
   double *pArea;

   RECT_DATA *pData;
   pData = (RECT_DATA*)((char*)pObj->pData + rect_offset);

   pArea = va_arg(argp, pDouble);

//  va_arg(argp, type)

   //printf("\nEbfore check");
   if (pArea != NULL)
   {
     *pArea = pData->l * pData->b;
     status = 1;
   }

   return status;

}
