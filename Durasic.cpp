#include "Durasic.hpp"

int countFiles(string sPath) {
    int i = 0;
    for (const auto& entry : filesystem::directory_iterator(sPath)) {
        i++;
    }
    return i;
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
    }
    return in;
}
