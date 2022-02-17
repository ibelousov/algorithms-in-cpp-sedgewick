#include <iostream>
#include <string.h>

bool isPalindrome(char * string)
{
    int len = strlen(string);

    for(int i = 0, j = len-1; i < j; i++, j--){
        while(string[i] == ' ' && i < len)
            i++;
        while(string[j] == ' ' && j > 0)
            j--;
        if(string[i] != string[j])
            return false;
    }

    return true;
}

int main(int argc, char ** argv)
{
    std::cout << '"' << argv[1] << '"' << " is " << (isPalindrome(argv[1]) ? "palindrome" : "not palindrome");

    return 0;
}