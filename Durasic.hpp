#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <nlohmann/json.hpp>

using namespace std;

int countFiles(string sPath);


class artist {
    public:
        artist(string nName);
        string getName();
        double getSeconds();
        void addSong(song nSong);
        void updateSeconds(double nSeconds);
        void updatesong();
    private:
        string name;
        vector<song> songs;
        double seconds;
};


class song {
    public:
        song(string nTitle, string nArtist, int nSeconds, int nYear);
        string getTitle();
        string getArtist();
        int getSeconds();
        void setTitle(string nTitle);
        void setArtist(string nArtist);
        void setSeconds(double nSeconds);
        int getYear();
        void setYear(int nYear);
        void updateSeconds(double nSeconds);
    private:
        string title;
        string artist;
        int year;
        double seconds;
};

class musicListener {
    public:
        musicListener();
        musicListener(string sHistory);
        void addSong(song nSong);
        //void addArtist(artist nArtist);
        vector<song>& getSongs();
        friend void getSongMinutes(musicListener listener);
        friend istream& operator>>(istream& in, musicListener& listener);
        friend void print_Sorted(musicListener listener);
    private:
        vector<song> songs;
        //vector<artist> artists;
};