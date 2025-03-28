#include "Durasic.hpp"

int countFiles(string sPath) {
    int i = 0;
    for (const auto& entry : filesystem::directory_iterator(sPath)) {
        if (entry.path().filename().string().find("StreamingHistory_music_") != string::npos) {
            i++;
        }
    }
    return i;
}

bool uniqueSong(song nSong, string nTitle, string nArtist) {
    return nSong.getTitle() == nTitle && nSong.getArtist() == nArtist;
}

musicListener::musicListener() {
    songs = vector<song>();
}
musicListener::musicListener(string sHistory) {
    for(int i = 0; i < countFiles(sHistory); i++) {
        ifstream file(sHistory + "/StreamingHistory_music_" + to_string(i) + ".json");
        if (file.is_open()) {
            file >> *this;
            file.close();
        }
    }
}
vector<song>& musicListener::getSongs() {
    return songs;
}

istream& operator>>(istream& in, musicListener& listener) {
    nlohmann::json jsonData;
    in >> jsonData;
    for(auto& songData : jsonData) {
        string endTime = songData["endTime"];
        string artistName = songData["artistName"];
        string trackName = songData["trackName"];
        double msPlayed = songData["msPlayed"];
        double secondsPlayed = msPlayed / 1000;
        pair<string, string> tSong = make_pair(trackName, artistName);
        auto iSong = find_if(listener.songs.begin(), listener.songs.end(), [tSong](song nSong) {
            return uniqueSong(nSong, tSong.first, tSong.second);
        });
        if(iSong != listener.songs.end()) {
            iSong->updateSeconds(secondsPlayed);
        } else {
            listener.addSong(song(trackName, artistName, secondsPlayed, stoi(endTime.substr(0, 4))));
        }
    }
    return in;
}

void musicListener::addSong(song nSong) {
    songs.push_back(nSong);
}

song::song(string nTitle, string nArtist, int nSeconds, int nYear) {
    title = nTitle;
    artist = nArtist;
    year = nYear;
    seconds = nSeconds;
}

string song::getTitle() {
    return title;
}
string song::getArtist() {
    return artist;
}
int song::getSeconds() {
    return seconds;
}
void song::setTitle(string nTitle) {
    title = nTitle;
}
void song::setArtist(string nArtist) {
    artist = nArtist;
}
void song::setSeconds(double nSeconds) {
    seconds = nSeconds;
}
int song::getYear() {
    return year;
}
void song::setYear(int nYear) {
    year = nYear;
}
void song::updateSeconds(double nSeconds) {
    seconds += nSeconds;
}

void print_Sorted(musicListener listener) {
    int counter = 1;
    sort(listener.getSongs().begin(), listener.getSongs().end(), [](song a, song b) {
        return a.getSeconds() > b.getSeconds();
    });
    cout << endl;
    for(auto& List : listener.songs) {
        if(counter == 11) {
            break;
        }
        cout << counter << ". " << List.getTitle() << " by " << List.getArtist() << " (" << List.getSeconds()/60 << " minutes played)" << endl << endl;
        counter++;
    }
}
void getSongMinutes(musicListener listener) {
    while(1){
        string title;
        cout << "Enter the song title to check the minutes played: ";
        getline(cin, title);
        auto iSong = find_if(listener.songs.begin(), listener.songs.end(), [title](song nSong) {
            return nSong.getTitle() == title;
        });
        while(iSong == listener.songs.end()){
            cout << "Song not found." << endl;
            cout << "Enter the song title to check the minutes played: ";
            getline(cin, title);
            iSong = find_if(listener.songs.begin(), listener.songs.end(), [title](song nSong) {
                return nSong.getTitle() == title;
            });
        }
        cout << endl << iSong->getTitle() << " by " << iSong->getArtist() << " (" << iSong->getSeconds()/60 << " minutes played)" << endl << endl;
    };    
}


