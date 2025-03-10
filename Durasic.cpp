#include "Durasic.hpp"

int countFiles(string sPath) {
    int i = 0;
    for (const auto& entry : filesystem::directory_iterator(sPath)) {
        i++;
    }
    return i;
}

bool uniqueSong(song nSong, string nTitle, string nArtist) {
    return nSong.getTitle() == nTitle && nSong.getArtist() == nArtist;
}

musicListener::musicListener() {
    songs = vector<song>();
    artists = vector<artist>();
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
istream& operator>>(istream& in, musicListener& listener) {
    nlohmann::json jsonData;
    in >> jsonData;
    for(auto& songData : jsonData) {
        string endTime = songData["endTime"];
        string artistName = songData["artistName"];
        string trackName = songData["trackName"];
        double msPlayed = songData["msPlayed"];
        pair<string, string> tSong = make_pair(trackName, artistName);
        if(find_if(listener.songs.begin(), listener.songs.end(), [&tSong](const song& nSong) {
            return uniqueSong(nSong, tSong.first, tSong.second);
        }) != listener.songs.end()) {
            
        } else {
            
        }
        
    }
    return in;
}
