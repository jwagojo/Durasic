#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <nlohmann/json.hpp>

using namespace std;

int countFiles(string sPath);
template<class InputIterator, class T>
InputIterator findSong (InputIterator first, InputIterator last, const string& val);

class musicListener {
    public:
        musicListener();
        musicListener(string sHistory);
        void addSong(song nSong);
        void addArtist(artist nArtist);
        friend istream& operator>>(istream& in, musicListener& listener);
    private:
        vector<song> songs;
        vector<artist> artists;
};

class song {
    public:
        song();
        song(string nTitle, string nArtist, int nSeconds, int nYear);
        string getTitle();
        string getArtist();
        int getSeconds();
        void setTitle(string nTitle);
        void setArtist(string nArtist);
        double setSeconds(double nSeconds);
        int getYear();
        void setYear(int nYear);
    private:
        string title;
        string artist;
        int year;
        double seconds;
};

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