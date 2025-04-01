#include <stdio.h>
#include <stdlib.h>
#include<math.h>


double function(double value, int decimals){
    int mesta= 1;

    if(decimals<=0)
        return 0;

    for(int i=0; i<decimals; i++){
        mesta= mesta*10;
    }

    value=value*mesta;

    if(value-floor(value)<0.5)
        value=floor(value);
     else
        value=ceil(value);

    return value/mesta;
}

int main(){

    printf("%lf\n",function(1.786,2));
    printf("%lf\n",function(3.14,3));
    printf("%lf\n",function(783.9823749,4));
    printf("%lf\n",function(92.1823,0));

   /*
   double value;
   int decimals;

   printf("Vnesete broj i broj na decimalni mesta:\n");
   scanf("%lf %d", &value,&decimals);
   printf("%lf",function(value,decimals));
   */

    return 0;
}
