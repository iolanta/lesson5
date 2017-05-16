#include "task2.h"
#include "algorithm"
#include "stack"
#include "iostream"
#include "set"


char opposite_bracket(char br){
    switch (br) {
    case '(': return ')';
    case ')': return '(';
    case '[': return ']';
    case ']': return '[';
    case '{': return '}';
    case '}': return '{';
    case '<': return '>';
    case '>': return '<';
    default:
        break;
    }
}

bool is_closing_bracket(char br){
    std::set<char> s = {')', ']', '}', '>'};
    if (s.find(br) != s.end())
        return true;
    return false;
}

std::string corrects_brackets(std::string & br){
    std::stack<char> st;
    auto it = br.begin();
    while(st.empty() && is_closing_bracket(*it)){
        br.insert(it, opposite_bracket(*it));
        it += 2;
    }

    while(it != br.end()){
        if (st.empty()){
            st.push(*it);
            ++it;
        }
        else
            if (is_closing_bracket(*it) && st.top() != opposite_bracket(*it)){
                br.insert(it, opposite_bracket(*it));
                it += 2;
            }
            else
            {
                if(is_closing_bracket(*it) && st.top() == opposite_bracket(*it))
                    st.pop();
            else
                    if(!is_closing_bracket(*it))
                        st.push(*it);
                ++it;
            }
    }

    while(!st.empty()){
        char op_br = st.top();
        br.push_back(opposite_bracket(op_br));
        st.pop();
    }
    return br;
}
