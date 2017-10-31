#ifndef __INTEGER__
#define __INTEGER__

class Integer{
    private:
        int val;
    
    public:
        Integer();
        Integer(int);
        Integer operator+(const Integer& rhs){
            return(val + rhs.val);
        }
        Integer operator-(const Integer& rhs){
            return(val - rhs.val);
        }
        Integer operator*(const Integer& rhs){
            return(val * rhs.val);
        }
        Integer operator/(double q){
            return(val  / q);
        }
        int display(){
            return val;
        }
        
        
};
#endif
