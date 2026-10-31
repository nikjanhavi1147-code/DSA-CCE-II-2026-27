#include <iostream>
#include <cstring>     
using namespace std;

const int MAX = 50;
const int NAME_LEN = 30;

class SocialNetwork {
    char names[MAX][NAME_LEN];
    int adj[MAX][MAX];
    int n;

    void readName(char* buf) {
        cin.width(NAME_LEN);         
        cin >> buf;
    }

    int findIndex(const char* name) {            
        for (int i = 0; i < n; i++)
            if (strcmp(names[i], name) == 0) return i;
        return -1;
    }

public:
    SocialNetwork() : n(0) {                     
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++) adj[i][j] = 0;
    }

    void addPerson() {
        if (n == MAX) { cout << "Network is full.\n"; return; }
        char name[NAME_LEN];
        cout << "Enter name: ";
        readName(name);
        if (findIndex(name) != -1) {
            cout << "Person already exists.\n";
            return;
        }
        strcpy(names[n++], name);
        cout << name << " added successfully.\n";
    }

    void addFriendship() {
        char a[NAME_LEN], b[NAME_LEN];
        cout << "Enter two names: ";
        readName(a); readName(b);
        int i = findIndex(a), j = findIndex(b);
        if (i == -1 || j == -1) { cout << "One or both people not found.\n"; return; }
        if (i == j) { cout << "A person cannot befriend themselves.\n"; return; }
        if (adj[i][j]) { cout << "Already friends.\n"; return; }
        adj[i][j] = adj[j][i] = 1;
        cout << "Friendship added between " << a << " and " << b << ".\n";
    }

    void removeFriendship() {
        char a[NAME_LEN], b[NAME_LEN];
        cout << "Enter two names: ";
        readName(a); readName(b);
        int i = findIndex(a), j = findIndex(b);
        if (i == -1 || j == -1) { cout << "One or both people not found.\n"; return; }
        if (!adj[i][j]) { cout << "They are not friends.\n"; return; }
        adj[i][j] = adj[j][i] = 0;
        cout << "Friendship removed.\n";
    }

    void displayNetwork() {
        if (n == 0) { cout << "Network is empty.\n"; return; }
        for (int i = 0; i < n; i++) {
            cout << names[i] << " -> ";
            bool any = false;
            for (int j = 0; j < n; j++)
                if (adj[i][j]) { cout << names[j] << " "; any = true; }
            if (!any) cout << "(no friends)";
            cout << "\n";
        }
    }

    void searchPerson() {
        char name[NAME_LEN];
        cout << "Enter name to search: ";
        readName(name);
        int i = findIndex(name);
        if (i == -1) { cout << "Person not found.\n"; return; }
        cout << "Found: " << names[i] << "\nFriends: ";
        bool any = false;
        for (int j = 0; j < n; j++)
            if (adj[i][j]) { cout << names[j] << " "; any = true; }
        if (!any) cout << "(none)";
        cout << "\n";
    }

    void findMutualFriends() {
        char a[NAME_LEN], b[NAME_LEN];
        cout << "Enter two names: ";
        readName(a); readName(b);
        int i = findIndex(a), j = findIndex(b);
        if (i == -1 || j == -1) { cout << "One or both people not found.\n"; return; }
        bool found = false;
        for (int k = 0; k < n; k++) {
            if (adj[i][k] && adj[j][k]) {
                if (!found) cout << "Mutual friends: ";
                cout << names[k] << " ";
                found = true;
            }
        }
        if (!found) cout << "No mutual friends.";
        cout << "\n";
    }

    void findConnectionPath() {                  
        char a[NAME_LEN], b[NAME_LEN];
        cout << "Enter source and destination: ";
        readName(a); readName(b);
        int s = findIndex(a), d = findIndex(b);
        if (s == -1 || d == -1) { cout << "One or both people not found.\n"; return; }

        bool visited[MAX];
        int parent[MAX];
        int q[MAX], front = 0, rear = 0;         
        for (int i = 0; i < n; i++) { visited[i] = false; parent[i] = -1; }

        visited[s] = true;
        q[rear++] = s;

        while (front < rear) {
            int u = q[front++];
            if (u == d) break;
            for (int v = 0; v < n; v++) {
                if (adj[u][v] && !visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q[rear++] = v;
                }
            }
        }

        if (!visited[d]) { cout << "No connection path exists.\n"; return; }

        int path[MAX], len = 0;
        for (int x = d; x != -1; x = parent[x]) path[len++] = x;

        cout << "Shortest path: ";
        for (int i = len - 1; i >= 0; i--) {     
            cout << names[path[i]];
            if (i > 0) cout << " -> ";
        }
        cout << "  (" << len - 1 << " hops)\n";
    }

    void checkConnectivity() {                   
        if (n == 0) { cout << "Network is empty.\n"; return; }
        bool visited[MAX];
        int q[MAX], front = 0, rear = 0;
        for (int i = 0; i < n; i++) visited[i] = false;

        visited[0] = true;
        q[rear++] = 0;
        int count = 1;
        while (front < rear) {
            int u = q[front++];
            for (int v = 0; v < n; v++)
                if (adj[u][v] && !visited[v]) {
                    visited[v] = true;
                    count++;
                    q[rear++] = v;
                }
        }
        if (count == n) cout << "Network is fully connected.\n";
        else {
            cout << "Network is NOT connected. Unreachable from "
                 << names[0] << ": ";
            for (int i = 0; i < n; i++)
                if (!visited[i]) cout << names[i] << " ";
            cout << "\n";
        }
    }
};

int main() {
    SocialNetwork net;
    int choice;
    do {
        cout << "\n===== Social Network Connectivity Analyzer =====\n"
             << "1. Add Person\n2. Add Friendship\n3. Display Network\n"
             << "4. Search Person\n5. Find Mutual Friends\n"
             << "6. Find Connection Path\n7. Check Network Connectivity\n"
             << "8. Remove Friendship\n9. Exit\nEnter choice: ";
        if (!(cin >> choice)) {                  
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }
        switch (choice) {
            case 1: net.addPerson(); break;
            case 2: net.addFriendship(); break;
            case 3: net.displayNetwork(); break;
            case 4: net.searchPerson(); break;
            case 5: net.findMutualFriends(); break;
            case 6: net.findConnectionPath(); break;
            case 7: net.checkConnectivity(); break;
            case 8: net.removeFriendship(); break;
            case 9: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 9);
    return 0;
}