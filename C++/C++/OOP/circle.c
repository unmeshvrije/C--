#include <stdio.h>
#include "shapeobj.h"

typedef double *pDouble;

typedef struct CIRCLE_DATA
{
   double x,y,radius;

}  CIRCLE_DATA;


static int circle_offset = -1;

extern CLASS generic_shape;
static int compute_area(OBJECT *pObj, va_list argp);

static MESSAGE messages[] =
{
  {COMPUTE_AREA, compute_area},
};

CLASS Circle_class =
{
   &generic_shape, // CLASS *base_class
   sizeof(CIRCLE_DATA), // Size
   sizeof(messages) / sizeof(MESSAGE),
   messages
};


OBJECT * newCircle(double x, double y, double r)
{
   OBJECT *pObj;
   CIRCLE_DATA *pData;

   pObj = (OBJECT*)allocate_memory(sizeof(OBJECT));
   pObj->pClass = &Circle_class;

  send_message(pObj, ALLOCATE_DATA, 0);
  if (circle_offset < 0 )
  {
     circle_offset = get_offset(&Circle_class);
  }

  pData = (CIRCLE_DATA *)((char*) pObj->pData + circle_offset);
  pData->x = x;
  pData->y = y;
  pData->radius = r;

  return pObj;
}

static int compute_area(OBJECT *pObj, va_list argp)
{
   int status = 0;
   double *pArea;

   CIRCLE_DATA *pData;
   pData = (CIRCLE_DATA*)((char*)pObj->pData + circle_offset);

   pArea = va_arg(argp, pDouble);

//  va_arg(argp, type)

   //printf("\nEbfore check");
   if (pArea != NULL)
   {
     *pArea = M_PI * pData->radius * pData->radius;
     status = 1;
   }

   return status;

}
