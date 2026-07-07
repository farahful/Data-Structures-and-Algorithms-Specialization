#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    char type;
    int position;
};

int main() {
    string input;
    getline(cin, input);

    stack<Bracket> st;
    int position = 0;

    for(char c : input) {
        position++;
        if(c == '(' || c == '[' || c == '{') {
            st.push({c, position});
        }
        else if(c == ')' || c == ']' || c == '}') {
            if(st.empty()) {
                cout << position << endl;
                return 0;
            }
            char top = st.top().type;
            if(c == ')' && top == '(' ||
               c == ']' && top == '[' ||
               c == '}' && top == '{') {
                st.pop();
            } else {
                cout << position << endl;
                return 0;
            }
        }
    }
    if(st.empty()) {
        cout << "Success" << endl;
    } else {
        cout << st.top().position << endl;
    }
    return 0;
}


