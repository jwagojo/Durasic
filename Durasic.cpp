#include "Durasic.hpp"

musicListener::musicListener() {
    songs = vector<song>();
    artists = vector<artist>();
}
musicListener::musicListener(string sHistory) {
    songs = vector<song>();
    artists = vector<artist>();
    for(int i; i < )
    ifstream file(sHistory + "/StreamingHistory_music_" + i + ".json");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            song nSong;
            artist nArtist;
            nSong.setTitle(line);
            nArtist.setName(line);
            nArtist.addSong(nSong);
            songs.push_back(nSong);
            artists.push_back(nArtist);
        }
        file.close();
    }
}