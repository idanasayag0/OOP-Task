#ifndef SRC_PLAYLIST_H_
#define SRC_PLAYLIST_H_
#include <vector>
#include <typeinfo>
#include "Q1.h"

using namespace std;

class PlayList : public Item{
public:
	vector<Item*> play;
	vector<string> DeepListOfSongs;
	PlayList(string name) :Item(name){}
	
	void operator += (Item* item) {
		play.push_back(item);
	}
	void PlayDeep(vector<string>& list) {
		if (play.size() == 0) {
			return;
		}
		else {
			for (int i = 0; i < play.size(); i++) {
				if (typeid(*play[i]) == typeid(PlayList)) {
					PlayList* temp = (PlayList*)play[i];
					temp->PlayDeep(list);
				}
				else {
					list.push_back(play[i]->name);
				}
			}
		}
	}
	vector<string>::iterator begin() {
		PlayList* temp = this;
		temp->PlayDeep(DeepListOfSongs);
		return DeepListOfSongs.begin();
	}
	vector<string>::iterator end() {
		return DeepListOfSongs.end();
	}
};

#endif /* SRC_PLAYLIST_H_ */
