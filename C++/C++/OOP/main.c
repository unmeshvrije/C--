#include <stdio.h>

#include "shapeobj.h"

int main()
{
   int i;
   double area;
   OBJECT *arrShapes[3]; 
//    Base *ptr[3];

   arrShapes[0] = newCircle(4,5,1);
   arrShapes[1] = newRectangle(14,35,16,7);
//   arrShapes[1] = newRect(5,6,4,3,);

   for (i = 0; i < 2; ++i)
   {
      send_message(arrShapes[i], COMPUTE_AREA, &area);
      printf("\nArea of shapes (%d) = %f", i, area);
   }

   printf("\n\n");

   OBJECT *ptr;
   ptr = newCircle(1,2,3);
   send_message(ptr, COMPUTE_AREA, &area);
   printf("\nArea of circle  = %f\n", area);


   /*for (i = 0; i < 2; ++i)
   {
      send
   }*/
   return 0;
}
