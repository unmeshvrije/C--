#include <stdio.h>

#include "shapes.h"

int main()
{
   CIRCLE c = {TYPE_CIRCLE, 1,1, 1};
   RECT r = {TYPE_RECT, 4,5};
   SHAPE s;

   s.type = TYPE_CIRCLE;
   s.c = c;

   printf("\nCircle Area = %f\n",Compute_Area(&s));

   s.type = TYPE_RECT;
   s.r = r;
   printf("\nRect Area = %f\n",Compute_Area(&s));
   return 0;
}
