#include <map>
#include <iostream>

/*

std::multimap<int key, char data> g_map;

g_map.insert(std::pair<int,int>(1,1))

when you get a g_map data
data->first = key
data->second = data


*/


typedef float Priority;
template< typename Item >
class priority_queue : public std::multimap<Priority,Item> {
    public:
        Item& front(){
            // pair<float, item>()
            return dd.begin()->second;
        }
        // returns a reference to the highest priority item
        void pop(){
            if(!dd.empty() ){
                dd.erase(dd.begin());
            }
        }
        // erases the highest priority item
        void push( Priority p, Item x ){
            dd.insert( std::pair< Priority,Item >(p,x) );
        }
        // inserts Item x into the queue with Priority p
        priority_queue<Item>( const priority_queue<Item>& ee ){
            this->dd = ee.dd;
        }
        // copy constructor
        priority_queue<Item> operator=(const priority_queue<Item>& ee){
            this->dd = ee.dd;
        }
        // assignment constructor
        priority_queue(){
            
        }
        // default constructor
    private:
        std::multimap<Priority, Item> dd;
};