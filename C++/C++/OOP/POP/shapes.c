#include "shapes.h"

double
Compute_Area(
    SHAPE *pShape
    )
{
   switch(pShape->type)
   {
      case TYPE_CIRCLE:
      {
         return (3.14 *(pShape->c).radius
                     *(pShape->c).radius);
      }

      case TYPE_RECT:
      {
         return((pShape->r).l*(pShape->r).b);
      }

      default:
      {
         return 0.0;
      }
   }
}
