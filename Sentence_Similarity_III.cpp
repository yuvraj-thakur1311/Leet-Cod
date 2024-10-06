Intuition:
      The idea is to check whether one sentence is a subsequence of the other by either prefixing or suffixing some words, while maintaining the original order of the sentences. 
      The problem can be reduced to removing matching words from both the front and the back of the two sentences and seeing if all words in the smaller sentence are fully consumed.

Approach:
    - If one sentence is shorter, swap them so that s1 is always the longer sentence.
    - Split both sentences into words and store them in two deques (deq1 for s1 and deq2 for s2).
   - Remove matching words from the front and back of both deques.
   - If deq2 (representing the smaller sentence) is empty after this, the sentences are similar. Otherwise, they are not.


CODE:- 

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()) {
            swap(s1, s2);
        }

        deque<string> deq1, deq2;
        stringstream ss1(s1);
        string token;
        while(ss1 >> token) {
            deq1.push_back(token);
        }

        stringstream ss2(s2);
        while(ss2 >> token) {
            deq2.push_back(token);
        }

        while(!deq1.empty() && !deq2.empty() && deq1.front() == deq2.front()) {
            deq1.pop_front();
            deq2.pop_front();
        }

        while(!deq1.empty() && !deq2.empty() && deq1.back() == deq2.back()) {
            deq1.pop_back();
            deq2.pop_back();
        }
        
        return deq2.empty();

    }
};
