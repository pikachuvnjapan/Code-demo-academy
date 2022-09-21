#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_matching(char left, char right){
    bool match = false;
    if (left == '(' && right == ')'){
        match = true;
    }
    else if (left == '{' && right == '}'){
        match = true;
    }
    else if (left == '[' && right == ']'){
        match = true;
    }
    else{
        match = false;
    }
    return match;
}

bool is_valid(string expr){
    stack<char> s;
    int i = 0;
    bool valid = true;
    while(valid && i < expr.size()){
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '['){
           s.push(expr[i]);
        }
        else if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']'){
            if (s.empty()){
                valid = false;
            }
            else if (!is_matching(s.top(), expr[i])){
                valid = false;
            }
            else{
                s.pop();
            }
        }
        ++i;
    }
    if (valid && !s.empty()){
        valid = false;
    }

    return valid;


}


int main()
{
    string expr = ")a + b( ";
    if (is_valid(expr)){
        cout << "Expression is valid" << endl;
    }
    else {
        cout << "Expression is not valid" << endl;
    }
    return 0;
}
