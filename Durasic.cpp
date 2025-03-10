#include "Durasic.hpp"

int countFiles(string sPath) {
    int i = 0;
    for (const auto& entry : filesystem::directory_iterator(sPath)) {
        i++;
    }
    return i;
}

template<class InputIterator>
InputIterator findSong(InputIterator first, InputIterator last, const string& val)
{
  while (first!=last) {
    if (first->title==val) return first;
    ++first;
  }
  return last;
}

template <class InputIterator, class T>
  int countSong(InputIterator first, InputIterator last, const string& val)
{
  int ret = 0;
  while (first!=last) {
    if (first->a == val) ++ret;
    ++first;
  }
  return ret;
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
        if(countSong(listener.songs.begin(), listener.songs.end(), trackName)) {
            
        }else {
            listener.addSong(song(trackName, artistName, msPlayed, stoi(endTime.substr(0, 4))));
        }
    }
    return in;
}
