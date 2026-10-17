#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    Song* next;
};

class MusicPlaylist {
    Song* head;
    Song* current;

public:
    MusicPlaylist() {
        head = nullptr;
        current = nullptr;
    }

    ~MusicPlaylist() {
        if (head == nullptr) return;

        Song* temp = head->next;
        while (temp != head) {
            Song* nextSong = temp->next;
            delete temp;
            temp = nextSong;
        }
        delete head;
    }

    void addSong(const string& songName) {
        Song* newSong = new Song{songName, nullptr};

        if (head == nullptr) {
            head = newSong;
            newSong->next = head;
            current = head;
        } else {
            Song* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newSong;
            newSong->next = head;
        }

        cout << "Song added successfully!\n";
    }

    void displayPlaylist() const {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        Song* temp = head;
        cout << "\nMusic Playlist:\n";
        do {
            cout << "- " << temp->name << '\n';
            temp = temp->next;
        } while (temp != head);
    }

    void playCurrentSong() const {
        if (current == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }
        cout << "Now Playing: " << current->name << '\n';
    }

    void playNextSong() {
        if (current == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }
        current = current->next;
        cout << "Now Playing: " << current->name << '\n';
    }

    void deleteSong(const string& songName) {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        Song* temp = head;
        Song* prev = nullptr;

        do {
            if (temp->name == songName) {
                if (temp->next == temp) {
                    head = nullptr;
                    current = nullptr;
                } else {
                    Song* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }

                    if (temp == head) {
                        head = head->next;
                        last->next = head;
                    } else {
                        prev->next = temp->next;
                    }

                    if (current == temp) {
                        current = temp->next;
                    }
                }

                delete temp;
                cout << "Song deleted successfully!\n";
                return;
            }

            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Song not found!\n";
    }
};

int main() {
    MusicPlaylist playlist;
    int choice = 0;
    string songName;

    do {
        cout << "\n===== MUSIC PLAYLIST MENU =====\n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Play Current Song\n";
        cout << "4. Play Next Song\n";
        cout << "5. Delete Song\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            return 1;
        }

        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin >> ws, songName);
                playlist.addSong(songName);
                break;
            case 2:
                playlist.displayPlaylist();
                break;
            case 3:
                playlist.playCurrentSong();
                break;
            case 4:
                playlist.playNextSong();
                break;
            case 5:
                cout << "Enter song name to delete: ";
                getline(cin >> ws, songName);
                playlist.deleteSong(songName);
                break;
            case 6:
                cout << "Exiting Music Playlist...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
