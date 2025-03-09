#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <istream>
#include <ostream>
#include <istream>

using namespace std;

class musicListener {
    public:
        musicListener();
        musicListener(string sHistory);
        void addSong(song nSong);
        void addArtist(artist nArtist);
        friend istream operator>>(istream& in, musicListener& listener);
    private:
        vector<song> songs;
        vector<artist> artists;
};

class song {
    public:
        song();
        song(string nTitle, string nArtist, int nSeconds);
        string getTitle();
        string getArtist();
        int getSeconds();
        void setTitle(string nTitle);
        void setArtist(string nArtist);
        void setSeconds(int nSeconds);
    private:
        string title;
        string artist;
        int seconds;
};

class artist {
    public:
        artist(string nName);
        string getName();
        int getSeconds();
        void addSong(song nSong);
        void updateSeconds(int nSeconds);
        void updatesong();
    private:
        string name;
        vector<song> songs;
        int seconds;
};