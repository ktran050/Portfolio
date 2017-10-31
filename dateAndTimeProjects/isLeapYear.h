bool isLeapYear(unsigned year){
   if(year%4){		// if year is not divisible by 4
	return false;
   }
   else{
        if(!(year%100)){	// if year is divisible by 100
            if(!(year%400)){	// if year is divisible by 400
                return true;
	    } 
	    else{
		return false;
	    }
	}
	else{
	    return true;
	}
   }
}
