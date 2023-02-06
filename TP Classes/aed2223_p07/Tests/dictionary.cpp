#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m) : word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
    return words;
}

void Dictionary::addWord(WordMean wm) {
    words.insert(wm);
}

// ---------------------------------------------

//TODO
bool WordMean::operator<(const WordMean &wm2) const {
    return getWord() < wm2.getWord();
}


//TODO
void Dictionary::readFile(ifstream &f) {
    string word;
    string meaning;
    while (!f.eof()) {
        getline(f, word);
        getline(f, meaning);
        WordMean found = *words.find(WordMean(word, meaning));
        if (found == WordMean("", ""))
            words.insert(WordMean(word, meaning));
    }
}

//TODO
string Dictionary::consult(string w1, WordMean &previous, WordMean &next) const {
    WordMean res = WordMean(w1, "");
    for (auto itr = words.begin(); itr != words.end(); itr++) {
        if (itr->getWord() == res.getWord()) {
            return itr->getMeaning();
        }
        auto it_next = words.lower_bound(res);
        auto it_prev = it_next;
        it_prev--;
        if (it_next == words.begin()) {
            previous.setWord("");
            previous.setMeaning("");
        }
        if (it_next == words.end()) {
            previous.setWord("");
            previous.setMeaning("");
            next.setWord("");
            next.setMeaning("");
        } else {
            previous.getWord() = it_prev->getWord();
            previous.getMeaning() = it_prev->getMeaning();
            next.getWord() = it_next->getWord();
            next.getMeaning() = it_next->getMeaning();
        }
    }
    return "word not found";
}

//TODO
bool Dictionary::update(string w1, string m1) {
    WordMean res = WordMean(w1, "");
    auto itr = words.find(res);
    if (itr != words.end()) {
        words.erase(itr);
        words.insert(WordMean(w1, m1));
        return true;
    }
    words.insert(WordMean(w1,m1));
    return false;
}

//TODO
void Dictionary::print() const {
}
