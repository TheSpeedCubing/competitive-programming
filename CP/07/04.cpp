#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    double n = 1, t[3];
    
    
    while(cin >> t[0] >> t[1] >> t[2]) {
        if (n) 
           n = 0;
        else printf("\n");
        
        sort(t, t + 3);
         
        double max = t[2], max2 = max*max,
               mid = t[1],
               min = t[0], comb = mid*mid+min*min;
                
        if(max >= mid + min) 
          cout<<"Not a triangle\n";
        else {
           if(max2 == comb)
              cout<<"Right triangle\n";
              
            if(max2 > comb)
              cout<<"Obtuse triangle\n";  
              
            if(max2 < comb)
              cout<<"Acute triangle\n";
              
            if(max == mid && mid == min)
              cout<<"Equilateral triangle\n";
              
            if((max == mid && mid != min)||(max != mid && mid == min))
              cout<<"Isosceles triangle\n";
        }
    }
}
