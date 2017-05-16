#include "task2.h"
#include "algorithm"
#include "stack"
#include "iostream"
#include "set"
#include "vector"


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
    std::vector<char> st;
    auto it = br.begin();
    while(st.empty() && is_closing_bracket(*it)){
        br.insert(it, opposite_bracket(*it));
        it += 2;
    }

    while(it != br.end()){
        if (st.empty()){
            st.push_back(*it);
            ++it;
        }
        else
            if (is_closing_bracket(*it) &&
                    std::find(st.begin(), st.end(), opposite_bracket(*it)) == st.end())
            {
                br.insert(it, opposite_bracket(*it));
                it += 2;
            }
            else
            {
                if(is_closing_bracket(*it) &&
                        std::find(st.begin(), st.end(), opposite_bracket(*it)) != st.end())
                    st.erase(std::find(st.begin(), st.end(), opposite_bracket(*it)));
            else
                    if(!is_closing_bracket(*it))
                        st.push_back(*it);
                ++it;
            }
    }

    std::for_each(st.begin(), st.end(), [&](char s)->void{
        if (is_closing_bracket(s))
            br.insert(br.end() - 1,opposite_bracket(s));
        else
            br.push_back(opposite_bracket(s));
    });
    return br;
}
