#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class documentEditor {
private:
    vector<string> docElements;
    string cachedRender; // renamed from renderdocument

public:
    void addText(string text) {
        docElements.push_back(text);
    }

    void addImage(string path) {
        docElements.push_back(path);
    }

    string renderdocument() {
        if (cachedRender.empty()) {
            string result;
            for (auto it : docElements) {
                if (it.size() > 4 &&
                    (it.substr(it.size() - 4) == ".jpg" || it.substr(it.size() - 4) == ".png")) {
                    result += "[Image: " + it + "]\n";
                } else {
                    result += it + "\n";
                }
            }
            cachedRender = result;
        }
        return cachedRender;
    }

    void saveToFile() {
        ofstream file("document.txt");
        if (file.is_open()) {
            file << renderdocument();
            file.close();
            cout << "The document is saved to document.txt" << endl;
        } else {
            cout << "Unable to open the file for writing " << endl;
        }
    }
};

int main() {
    documentEditor editor;
    editor.addText("Hello World");
    editor.addImage("picture.jpg");
    editor.addText("This is a Document Editor");
    cout << editor.renderdocument() << endl;
    editor.saveToFile();
    return 0;
}
