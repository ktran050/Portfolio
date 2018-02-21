// URL: http://www.cprogramming.com/challenges/celsius_converter_table.html
// Date/Time: 6/29/2016 5:36 PM
#include <iostream>

int main(){
    int lowerLim, higherLim, step;
    
    // Prompt user
    cout<<"Please give in a lower limit, limit >= 0: ";
    cin>>lowerLim;
    cout<<"Please give in a higher limit, 10 > limit <= 50000: ";
    cin>>higherLim;
    cout<<"Please give in a step, 0 < step <= 10: ";
    cin>>step;
    
    // Validation
    if(lowerLim<0 || higherLim higherLim>50000 || step<=0 || step>10 || lowerLim<higherLim)
    
    return 0;
}