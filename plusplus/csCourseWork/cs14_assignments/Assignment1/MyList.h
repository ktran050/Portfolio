#include <iostream>
#include <string>

using namespace std;

class Node{
    private:
        
    public:
        char value;
        Node* next;
        Node* pred;
        
        Node(){
            next = 0;
            pred = 0;
        }
        
        Node( char val ){
            value = val;
            next = 0;
            pred = 0;
        }
    
};


class MyList{
    private:
    
    public:
        Node* head;
    
        // ~Constructors/Deconstructors~
        MyList(){
            head = 0;
        }
        // Constructor
        
        MyList( const MyList& str){
            if( str.size() != 0){
                head = 0;
                Node* listHead = str.head;
                bool PassedHead = 0;
                while(PassedHead != 1){
                    push_back( listHead->value );
                    listHead = listHead->next;
                    if( listHead == str.head ){
                        PassedHead++;
                    }
                }
            }
            head = 0;
        }
        // Creates a list from a passed in MyList object
        /// Make a pointer to keep track while going through the MyList object
        
        MyList( const string& str ){
            head = 0;
            for( int q = 0; q < str.size(); ++q ){
                push_back( str.at( q ) );
            }
        }
        // Creates a list from a passed-in string object
        /// (e.g string name = "Jake"; MyList l1(name);
        /// Each character of the string gets a separate node
        
        MyList( const char* str ){
            head = 0;
            unsigned i = 0;
            for(char c = str[0]; str[i] != '\0'; ++i){
                c = str[i];
                push_back( c );
            }
        }
        // Creates a list from a passed in string literal
        
        ~MyList(){
            while( head != 0){
                pop_front();
            }
        }
        // Deconstructor
        
        
        // ~Mutators~
        void push_front( char value ){
            if( head == 0 ){
                // If the list is empty
                Node* temp = new Node( value );
                head = temp;
                temp->next = temp;
                temp->pred = temp;
            }
            else{
                Node* temp = new Node( value );
                temp->next = head;
                temp->pred = head->pred;
                head->pred->next = temp;
                head->pred = temp;
                head = temp;
            }
        }
        // Add a value to the front
        /// Same as push_back pretty much
        
        void push_back( char value ){
            if( head == 0){
                Node *temp = new Node( value );
                head = temp;
                head->next = head;
                head->pred = head;
                return;
            }
            else{
                Node *temp = new Node( value );
                temp->next = head;
                temp->pred = head-> pred;
                head->pred->next = temp;
                head->pred = temp;
            }
        }
        // Add a value to the back of the list
        /// If it is empty
        /// Make the new node
        /// Set it to head and make it circular
        
        /// If it's not empty
        /// Create a new node
        /// Set the new node's next to head
        /// Set the new node's pred to head's pred
        /// Set head's pred's next to new node
        /// Set head's pred to new node
        
        void pop_front(){
            if( head == 0 ){
                return;
            }
            else if( head->next == head ){
                delete head;
                head = 0;
            }
            else if( head->next != head ){
                Node *temp = head;
                temp->next->pred = temp->pred;
                temp->pred->next = temp->next;
                head = head->next;
                delete temp;
            }
            return;
        }
        // Delete the value at the front
        
        void pop_back(){
            if( head == 0 ){
                return;
            }
            else if( head->next == head ){
                delete head;
                head = 0;
            }
            else if( head->next != head){
                Node* temp = head->pred;
                temp->next->pred = temp->pred;
                temp->pred->next = temp->next;
                delete temp;
            }
            return;
        }
        // Delete the value at the back
        
        void swap( int i, int j){
            if(head != 0){
                int holdI; int holdJ;
                if( ( i > size() - 1) || (j > size() - 1) || (i < 0) || (j < 0) ){
                    cout << "Error: Indexes entered are invalid." << endl;
                }
                else{
                    Node* traveler = head;
                    for( int q = 1; q < i; ++q) {
                        traveler = traveler->next;
                    }
                    holdI = traveler->value;
                    // Set holdI to the value at i
                    
                    traveler = head;
                    for( int q = 1; q < j; ++q) {
                        traveler = traveler->next;
                    }
                    holdJ = traveler->value;
                    traveler->value = holdI;
                    // Set holdJ to value at J
                    // Set value at J to holdI
                    
                    traveler = head;
                    for( int q = 1; q < i; ++q) {
                        traveler = traveler->next;
                    }
                    traveler->value = holdJ;
                    // Value at i becaoomes holdJ
                }
            }
        }
        // Swaps the value of the node at position i with the value at position j
        /// **CARE OUT OF RANGE**
        
        void insert_at_pos( int i, char val){
            if(head != 0){
                // If head is invalid end
                if( (i < 0) || (i > size() - 1) ){
                    cout << "Error: Invalid index" << endl;
                    return;
                }
                // If I is invalid end
                else{
                    Node* traveler = head;
                    Node* toAdd = new Node( val );
                    
                    for( int q = 1; q < i - 1; ++q ){
                        traveler = traveler->next;
                    }
                    // Travel to the index before the index you want I to be at
                    
                    toAdd->pred = traveler;
                    toAdd->next = traveler->next;
                    // Set toAdd's pointers to their would be positions
                    
                    traveler->next = toAdd;
                    // Set traveler's next to Add
                    
                    toAdd->next->pred = toAdd;
                    // Set toAdd's next's pred to to Add finishing the addition
                }
            }
            return;
        }
        // Insert a node with value at position i in the list
        
        void reverse(){
            // if(head != 0){
            //     MyList newList;
            //     // List to hold reversed values
            //     Node* traveler = head;
            //     // Pointer to travel through the list;
            //     const int thisSize = this->size();
                
            //     for( int cc = 0; cc < thisSize-1; ++cc){
            //         newList.push_front( traveler->value );
            //         cout << "i:" << cc << endl;
            //         cout << "traveler->value: " << traveler->value << endl;
            //         traveler = traveler->next;
            //     }
            //     // for loop to go through and add the first list to the second list
                
            //     while( head != 0){
            //         cout << "Head val: " << head->value << endl;
            //         pop_front();
            //         cout << "while" << endl;
            //     }
            //     // Delete the old values
                
            //     traveler = newList.head;
            //     for( int i = 0; i < newList.size() - 1; ++i){
            //         push_back( traveler->value );
            //         traveler = traveler->next;
            //         // cout << "for2" << endl;
            //     }
            //     // traverse through the new list and pushback
                
            // }
            // return;
        }
        // Reverses the items in the list
        
        
        // ~Accessors~
        int size() const{
            if( head != 0){
                int sz;
                Node* travel = head;
                bool PassedHead = 0;
                while( PassedHead != 1 ){
                    ++sz;
                    travel = travel->next;
                    if( travel == head ){
                        ++PassedHead;
                    }
                }
                return sz;
            }
            return 0;
        }
        // Returns the number of nodes in the list
        
        void print() const{
            if( head != 0){
                Node* travel = head;
                bool PassedHead = 0;
                while( PassedHead != 1 ){
                    cout << travel->value;
                    travel = travel->next;
                    if( travel == head ){
                        ++PassedHead;
                    }
                }
            }
        }
        // Print the contents of the list to cout
        /// Start at head
        /// Create a counter to see when we pass head once
        
        int find( char val ) const{
            // int index;
            // if( head != 0){
            //     Node* travel = head;
            //     bool PassedHead = 0;
            //     while( (PassedHead != 1) || (travel->value != val) ){
            //         ++index;
            //         travel = travel->next;
            //         if( travel == head ){
            //             ++PassedHead;
            //         }
            //         cout << "PassedHead: " << PassedHead << " index: " << index << " value: " << travel->value << endl;
            //     }
            //     return index;
            // }
            // else if(head->next == head){
            //     if( head->value == val ){
            //         return 0;
            //     }
            //     else{
            //         cout << "NPOS" << endl;
            //         return -1;
            //     }
            // }
            // else if(head == 0){
            //     cout << "NPOS" << endl;
            //     return -1;
            // }
            // cout << "NPOS" << endl;
            // return -1;
        }
        // Find the position of the first occurance of value. If
        /// it's not in the list return -1
        
        int find(MyList& query_str) const{
            cout << "FIXME: WRITE THIS CODE" << endl;
            return 0;
        }
        // Find the first occurance of the query_str in the list and
        /// Return the positon. If it's not on the list return -1
        
        
        // ~Operator Overloaders~
        MyList& operator=( const MyList& str ){
        //     MyList resultList;
        //     if( str.head != 0){
        //         while(head != 0){
        //             pop_front();
        //             cout << "While" << endl;
        //         }
        //         Node* traveler = str.head;
        //         for(int i = 1; i < str.size() - 1; ++i){
        //             resultList.push_back( traveler->value );
        //             cout << "str.size: " << str.size();
        //             cout << "traveler->value: " << traveler->value << endl;
        //             traveler = traveler->next;
        //         }
        //     }
        // return resultList;
        }
        
        
        
        char& operator[]( const int i ){
            if( (head != 0) || (i > 0) || (i < size() - 1) ){
                Node* traveler = head;
                for(int c = 1; c < i; ++c){
                    traveler = traveler->next;
                }
                return traveler->value;
            }
            else{
                if( (i < 0) || (i > size() - 1) ){
                    cout << "Error: Invalid index" << endl;
                }
                char s;
                return s;
            }
        }
        // Returns the character at position i
        
        MyList& operator+( const MyList& str ){
        //     if(size() == 0){
        //         MyList resultList( str );
        //         return resultList;
        //     }
        //     else if( str.size() == 0){
        //         return *this;
        //     }
        //     else{
        //         MyList resultList( *this );
        //         Node* traveler = str.head;
        //         for(int a = 0; a < str.size(); ++a){
        //             cout << "traveler->value: " << traver->value << endl;
        //             resultList.push_back( traveler->value );
        //             traveler = traveler->next;
        //         }
        //         return resultList;
        //     }
        // }
        // Concatenates two lists together
};