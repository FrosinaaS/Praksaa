#include <stdio.h>
#include <stdlib.h>
#include<math.h>


double function(double value, int decimals) {
        if (decimals<=0) {
        return 0;
        //ako e vneseno negativen broj ili 0 vrakja 0;
    }

    int mesta = 1;
    for (int i=0; i<decimals; i++) {
        mesta= mesta*10;
    }

    value=value*mesta;
    // ja pomestuvame za decimals mesta

    if (value-floor(value)<0.5) {
        value=floor(value);
    } else {
        value=ceil(value);
    }

    return value/mesta;
}

int main() {
   double value;
   int decimals;
   printf("Vnesete broj i broj na decimalni mesta: ");
   scanf("%lf %d", &value,&decimals);
   printf("%l f",function(value,decimals));
   //ja povikuvame funkcijata i go pecatime reziltatut.

    return 0;

}
