#include "SaveData.h"

extern vector<user> userList;
extern vector<author> authorList;
extern vector<tag> tagList;
extern vector<book> bookList;
extern vector<leiheintrag> ausleihListe;

void SaveData()
{
    string datenbank = "library.txt";                                        // Libary als ofstream oeffnen
    ofstream output_stream{ datenbank };
    if (!output_stream.is_open())
        error("602 library-Datei kann nicht geschrieben werden");


    output_stream << "[tags]\n";
    for (int i = 0; i < tagList.size(); ++i) {
        output_stream << setw(5) << tagList[i].TagID << setw(20) << tagList[i].name << "\n";
    }
    output_stream << "\n";

    output_stream << "[authors]\n";
    for (int i = 0; i < authorList.size(); ++i) {
        output_stream << setw(5) << authorList[i].authorID << setw(20) << authorList[i].vorname << setw(20) << authorList[i].nachname << "\n";

    }
    output_stream << "\n";

    output_stream << "[books]\n";
    for (int i = 0; i < bookList.size(); ++i) {
        output_stream << setw(5) << bookList[i].bookID << setw(5) << bookList[i].authorID;
        string titelInProzentZeichen = "%";
        titelInProzentZeichen += bookList[i].titel;
        titelInProzentZeichen += "%";
        output_stream << setw(40) << titelInProzentZeichen << setw(20) << bookList[i].ISBN;
        for (int j = 0; j < bookList[i].tags.size(); ++j) {
            output_stream << setw(5) << bookList[i].tags[j];
        }
        output_stream << "\n";

    }
    output_stream << "\n";

    output_stream << "[users]\n";
    for (int i = 0; i < userList.size(); ++i) {
        output_stream << setw(5) << userList[i].userID << setw(20) << userList[i].vorname << setw(20) << userList[i].nachname << "\n";
    }
    output_stream << "\n";

    output_stream << "[borrowentries]\n";
    for (int i = 0; i < ausleihListe.size(); ++i) {
        output_stream << setw(5) << ausleihListe[i].userID << setw(5) << ausleihListe[i].bookID << "\n";
    }
    output_stream.close();
}