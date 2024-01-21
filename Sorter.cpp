#include "Sorter.h"

extern vector<user> userList;
extern vector<author> authorList;
extern vector<tag> tagList;
extern vector<book> bookList;
extern vector<leiheintrag> ausleihListe;

void Sort()
{
    // Elemente in den Vectoren nach aufsteigenden IDs sortieren
    bool getauscht = true;
    tag tagsZwischenspeicher;
    if (tagList.size() > 1) {
        while (getauscht) {
            getauscht = false;
            for (int i = 0; i < tagList.size() - 1; ++i) {
                if (tagList[i].TagID > tagList[i + 1].TagID) {
                    tagsZwischenspeicher = tagList[i];
                    tagList[i] = tagList[i + 1];
                    tagList[i + 1] = tagsZwischenspeicher;
                    getauscht = true;
                }
            }
        }
    }


    getauscht = true;
    author autorenZwischenspeicher;
    if (authorList.size() > 1) {
        while (getauscht) {
            getauscht = false;
            for (int i = 0; i < authorList.size() - 1; ++i) {
                if (authorList[i].authorID > authorList[i + 1].authorID) {
                    autorenZwischenspeicher = authorList[i];
                    authorList[i] = authorList[i + 1];
                    authorList[i + 1] = autorenZwischenspeicher;
                    getauscht = true;
                }
            }
        }
    }


    getauscht = true;
    book buchZwischenspeicher;
    if (bookList.size() > 1) {

        while (getauscht) {
            getauscht = false;
            for (int i = 0; i < bookList.size() - 1; ++i) {
                if (bookList[i].bookID > bookList[i + 1].bookID) {
                    buchZwischenspeicher = bookList[i];
                    bookList[i] = bookList[i + 1];
                    bookList[i + 1] = buchZwischenspeicher;
                    getauscht = true;
                }
            }
        }
    }


    getauscht = true;
    user userZwischenspeicher;
    if (userList.size() > 1) {
        while (getauscht) {
            getauscht = false;
            for (int i = 0; i < userList.size() - 1; ++i) {
                if (userList[i].userID > userList[i + 1].userID) {
                    userZwischenspeicher = userList[i];
                    userList[i] = userList[i + 1];
                    userList[i + 1] = userZwischenspeicher;
                    getauscht = true;
                }
            }
        }
    }
}