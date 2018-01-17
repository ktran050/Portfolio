#include <iostream>
#include <string.h>
#include <vector.h>

class baseTemplate{
    public:
        std::string name;
        void add(std::string toAdd);
        void rm(std::string toRemove);
};

class Library: public baseTemplate{
    public:
        Library();
        Libary(std::string passedName){
          name = passedName;
        }
    private:
};

class Artist: public baseTemplate{
    public:
        Artist();
        Artist(std::string passedName){
            name = passedName;
        }
    private:
        vector<Song> songList;
        vector<Album> albumList;
        vector<Album> featuredList;
};

class Album: public baseTemplate{
    public:
        Album();
        Album(std::string passedName){
            name = passedName;
        }
    private:
};

class Song: public baseTemplate{
    public:
        Song();
        Song(std::string songName, std::string albumName, std::string){
            name = passedName;
        }
    private:
};

int main(){
    
    return 0;
}