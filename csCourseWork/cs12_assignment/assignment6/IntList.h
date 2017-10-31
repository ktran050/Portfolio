#ifndef __IntList__
#define __IntList__

struct IntNode{
    public:
        int data;
        IntNode *next;
        IntNode (int data): data(data), next(0) {};
        
    private:
    
};

class IntList{
    public:
        IntList();
        ~IntList();
        void display() const;
        void push_front(int value);
        void pop_front();
        void push_back(int value);
        void select_sort();
        void insert_sorted(int value);
        void remove_duplicates();
        
    private:
        IntNode *head;
        IntNode *tail;
    
};

#endif