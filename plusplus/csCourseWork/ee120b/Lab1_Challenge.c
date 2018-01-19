/*
(Challenge) An amusement park kid ride cart has three seats, with 8-bit weight sensors 
connected to ports A, B, and C (measuring from 0-255 kilograms). Set PD0 to 1 if the cart's total 
passenger weight exceeds the maximum of 140 kg. Also, the cart must be balanced: Set port PD1 to 1 
if the difference between A and C exceeds 80 kg. Can you also devise a way to inform the ride operator 
of the approximate weight using the remaining bits on D? (Interesting note: Disneyland recently redid 
their "It's a Small World" ride because the average passenger weight has increased over the years, 
causing more boats to get stuck on the bottom).
(Hint: Use two intermediate variables to keep track of weight, one of the actual value
and another being the shifted weight. Binary shift right by one is the same as dividing by 
two and binary shift left by one is the same as multiplying by two.)
*/

int main(){
  // Set up A, B, and C as inputs and initialize to 0s.
  // Set D as an output and also initialize to 0.
  DDRA = 0x00; PORTA = 0x00;
  DDRB = 0x00; PORTB = 0x00;
  DDRC = 0x00; PORTC = 0x00;
  DDRD = 0xFF; PORTD = 0x00;
  
  // Initialize variables for sensor input
  unsigned char tmpA = 0x00;
  unsigned char tmpB = 0x00;
  unsigned char tmpC = 0x00;
  unsigned char tmpD = 0x00;
  
  // Initialize variables for weight management
  unsigned char weight1 = 0x00;
  unsigned char weight2 = 0x00;
  
  while(1){
    // Read sensor input
    tmpA = PINA;
    tmpB = PINB;
    tmpC = PINC;
    
    
    
    // If the cart's total weight > 140 set PD0=1
    if(tmpA > 0x8c || tmpB > 0x8c || tmpC > 0x8c){
      tmpD = (tmpD & 0xFE) | 0x01; // Clears the right most bit and sets it to 1
    }
    
    // If A - C > 80kg set PD1=1
    if( tmpA-tmpC > 0x50 || tmpC - tmpA > 0x50 ){
      tmpD = tmp
    }
    
    
    
    weight2 = (tmpA & 0x80) + (tmpB & 0x80) + (tmpC & 0x80);
    weight1 = 
    weight2 = weight2 + (weight1 & 0x80) 
    
  }

124
267

391
  
  return 0;
}