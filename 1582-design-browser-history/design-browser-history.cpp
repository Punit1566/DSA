class BrowserHistory {
private:
    vector<string> history; // Single stack to store all pages
    int current; // Index to track the current page

public:
    // Constructor that initializes the homepage
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        current = 0;
    }

    // Adds a new page to the history and clears the forward history
    void visit(string url) {
        // Erase all forward pages
        history.erase(history.begin() + current + 1, history.end());
        history.push_back(url);
        current++;
    }

    // Moves the user back a certain number of pages in the history
    string back(int steps) {
        current = max(0, current - steps); // Move back by steps but not beyond the first page
        return history[current];
    }

    // Moves the user forward a certain number of pages in the history
    string forward(int steps) {
        current = min((int)history.size() - 1, current + steps); // Move forward by steps but not beyond the last page
        return history[current];
    }
};