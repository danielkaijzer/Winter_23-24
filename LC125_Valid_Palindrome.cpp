// uses two-pointer solution

#include <iostream>
#include <cctype>

bool isPalindrome(std::string s) {
    if (s.size() < 2){
        return true;
    }

    int start = 0, end = s.size()-1;

    // loop through string
    // skip past non-alphanumeric characters
    // 
    while (start < end){ // this works to not compare middle element

        if (isalnum(s[start]) && isalnum(s[end])){
            // check if start and end are lower case, if not make them lower case
            if (std::isupper(s[start])){
                s[start] = std::tolower(s[start]);
            }
            if (std::isupper(s[end])){
                s[end] = std::tolower(s[end]);
            }

            // now that both chars are normalized, compare if they are the same
            if (s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        else { // else if either first or second pointer chars are not alnum, increment start and/or decrement end
            if (!isalnum(s[start])){
                start++;
            }
            if (!isalnum(s[end])){
                end--;
            }
        }
    }
    // if we looped through entire string and every element 
    return true;
}



int main(){
    std::string s = "ann,a";
    std::string v = "annn,av";

    std::cout << isPalindrome(s) << std::endl;
    std::cout << isPalindrome(v) << std::endl;

}