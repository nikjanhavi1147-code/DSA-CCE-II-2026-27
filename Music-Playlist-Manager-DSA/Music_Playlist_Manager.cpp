#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Node {
public:
    string title;
    string artist;
    Node* prev;
    Node* next;

    Node(string t, string a) {
        title = t;
        artist = a;
        prev = nullptr;
        next = nullptr;
    }
};


class MusicPlaylist {
private:
    Node* head;

public:
    Node* current;

    MusicPlaylist() {
        head = nullptr;
        current = nullptr;
    }

   
    void addSong(string title, string artist) {
        Node* p = new Node(title, artist);

        if (head == nullptr) {
            head = p;
            current = head;
        } else {
            Node* q = head;

            while (q->next != nullptr) {
                q = q->next;
            }

            q->next = p;
            p->prev = q;
        }

        cout << "Song added successfully!\n";
    }

    void deleteSong(string title) {
        Node* q = head;

        while (q != nullptr && q->title != title) {
            q = q->next;
        }

        if (q == nullptr) {
            cout << "Song not found!\n";
            return;
        }

        if (q->prev != nullptr)
            q->prev->next = q->next;
        else
            head = q->next;

        if (q->next != nullptr)
            q->next->prev = q->prev;

        if (current == q) {
            if (q->next != nullptr)
                current = q->next;
            else
                current = q->prev;
        }

        delete q;

        if (head == nullptr)
            current = nullptr;

        cout << "Song deleted successfully!\n";
    }

    
    void displayPlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        Node* q = head;

        cout << "\nForward Playlist:\n";

        while (q != nullptr) {
            cout << q->title << " - "
                 << q->artist << "\n";
            q = q->next;
        }
    }

    void displayReverse() {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        Node* q = head;

        while (q->next != nullptr) {
            q = q->next;
        }

        cout << "\nReverse Playlist:\n";

        while (q != nullptr) {
            cout << q->title << " - "
                 << q->artist << "\n";
            q = q->prev;
        }
    }

    
    void playCurrent() {
        if (current == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        cout << "Playing: " << current->title
             << " - " << current->artist << "\n";
    }

   
    void playNext() {
        if (current == nullptr) {
            cout << "Playlist is empty!\n";
        } else if (current->next == nullptr) {
            cout << "Already at the last song!\n";
        } else {
            current = current->next;
            playCurrent();
        }
    }

    void playPrevious() {
        if (current == nullptr) {
            cout << "Playlist is empty!\n";
        } else if (current->prev == nullptr) {
            cout << "Already at the first song!\n";
        } else {
            current = current->prev;
            playCurrent();
        }
    }

    void playCompletePlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        Node* q = head;

        while (q != nullptr) {
            cout << "Playing: " << q->title
                 << " - " << q->artist << "\n";
            q = q->next;
        }

        current = head;
    }

    
    void repeatAll(int repetitions) {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        if (repetitions <= 0) {
            cout << "Enter a positive number of repetitions!\n";
            return;
        }

        for (int i = 1; i <= repetitions; i++) {
            cout << "\nRepetition " << i << ":\n";

            Node* q = head;

            while (q != nullptr) {
                cout << "Playing: " << q->title
                     << " - " << q->artist << "\n";
                q = q->next;
            }
        }

        current = head;
    }

    void showCurrent() {
        playCurrent();
    }


    ~MusicPlaylist() {
        Node* q = head;

        while (q != nullptr) {
            Node* temp = q;
            q = q->next;
            delete temp;
        }
    }
};

int main() {
    MusicPlaylist playlist;

    
    playlist.addSong("Believer", "Imagine Dragons");
    playlist.addSong("Faded", "Alan Walker");
    playlist.addSong("Perfect", "Ed Sheeran");
    playlist.addSong("Shape of You", "Ed Sheeran");

    int choice, repetitions;
    string title, artist;

    do {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Display Playlist in Reverse\n";
        cout << "5. Play Current Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Play Previous Song\n";
        cout << "8. Play Complete Playlist\n";
        cout << "9. Repeat All\n";
        cout << "10. Show Current Song\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";

        
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );
            continue;
        }

        cin.ignore(
            numeric_limits<streamsize>::max(), '\n'
        );

        switch (choice) {

        case 1:
            cout << "Enter song title: ";
            getline(cin, title);

            cout << "Enter artist name: ";
            getline(cin, artist);

            playlist.addSong(title, artist);
            break;

        case 2:
            cout << "Enter song title to delete: ";
            getline(cin, title);

            playlist.deleteSong(title);
            break;

        case 3:
            cout<<"Choice 3 selected!\n";
            playlist.displayPlaylist();
            break;

        case 4:
            cout<<"Choice 4 selected!\n";
            playlist.displayReverse();
            break;

        case 5:
            cout<<"Choice 5 selected!\n";
            playlist.playCurrent();
            break;

        case 6:
            playlist.playNext();
            break;

        case 7:
            playlist.playPrevious();
            break;

        case 8:
            playlist.playCompletePlaylist();
            break;

        case 9:
            cout << "Enter number of repetitions: ";

            if (!(cin >> repetitions)) {
                cout << "Invalid input! Enter a number.\n";
                cin.clear();
                cin.ignore(
                    numeric_limits<streamsize>::max(), '\n'
                );
                break;
            }

            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );

            playlist.repeatAll(repetitions);
            break;

        case 10:
            playlist.showCurrent();
            break;

        case 11:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 11);

    return 0;
}