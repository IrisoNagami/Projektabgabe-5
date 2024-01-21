#include "GetData.h"

extern vector<user> userList;
extern vector<author> authorList;
extern vector<tag> tagList;
extern vector<book> bookList;
extern vector<leiheintrag> ausleihListe;

bool istStringEineZahl(string s) {
    bool b = true;
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i]) == false)
            b = false;
    }
    return b;
}
void NameAusProzent(string& s) {
    if (s[0] != '%') {

    }
    else if (s[s.size() - 1] != '%') {}
    else {
        string a = "";
        char b;
        for (int i = 1; i < s.size() - 1; ++i) {
            b = s[i];
            a += b;
        }
        s = a;
    }
}


void GetData()
{
    string speicher;

    string datenbank = "library.txt";                                        // Libary als ifstream oeffnen
    ifstream input_stream;
    input_stream.open(datenbank);
    if (!input_stream.is_open()) {                                       // datenbank neu erstellen falls diese nicht geoeffnet wurde
        ofstream file("library.txt");
        file << "[tags]\n\n[authors]\n\n[books]\n\n[users]\n\n[borrowentries]";
        file.close();
        input_stream.open(datenbank);
    }



    getline(input_stream, speicher);                                                 //tags einlesen beginn
    if (speicher == "[tags]") {
        while (true) {
            getline(input_stream, speicher);
            for (int i = 0; i < speicher.size(); ++i) {
                input_stream.unget();
            }
            if (speicher == "[authors]") {
                input_stream.unget();
                break;
            }
            if (speicher != "")
            {
                int  tagId;
                string tagName;
                string nachWs;
                tag t;
                input_stream >> tagId;
                input_stream >> tagName;
                getline(input_stream, speicher);

                for (int i = 0; i < speicher.size(); ++i) {
                    if (speicher[i] == ' ') {
                        nachWs += speicher[i];
                    }
                    if (speicher[i] != ' ') {
                        nachWs += speicher[i];
                        tagName = tagName + nachWs;
                        nachWs = "";
                    }
                }
                t.TagID = tagId;
                t.name = tagName;
                tagList.push_back(t);
            }
        }
    }
    else
        error("601 library-Datei existiert, kann aber nicht gelesen werden!\n");

    //tags eingelesen



    int autorID;                                        // Autoren aus txt einlesen
    string autorVorname;
    string autorNachname;
    author a;
    input_stream >> speicher;
    if (speicher != "[authors]")
        error("601 library-Datei existiert, kann aber nicht gelesen werden\n");
    while (true) {
        input_stream >> speicher;
        if (istStringEineZahl(speicher)) {
            for (int i = 0; i < speicher.size(); ++i) {
                input_stream.unget();

            }

        }
        else {
            for (int i = 0; i < speicher.size(); ++i) {
                input_stream.unget();

            }
            break;
        }
        input_stream >> autorID;
        input_stream >> autorVorname;
        input_stream >> autorNachname;
        a.authorID = autorID;
        a.vorname = autorVorname;
        a.nachname = autorNachname;
        authorList.push_back(a);

    }                                                               // autoren fertig eingelesen

    // Buecher einlesen



    input_stream >> speicher;
    if (speicher == "[books]") {
        book buch;
        int buchId;
        int autorId;
        string buchName;
        char namenSpeicher;
        string ISBN;
        stringstream buecher;
        while (true) {
            getline(input_stream, speicher);
            if (speicher == "[users]") {
                for (int i = 0; i < speicher.size() + 1; ++i) {
                    input_stream.unget();
                }
                break;
            }
            if (speicher != "") {
                vector<int> genre;
                buecher.clear();
                buecher << speicher;
                buecher >> buchId;
                buecher >> autorId;
                buchName = "";
                buecher >> namenSpeicher;
                if (namenSpeicher == '%') {
                    while (true) {
                        noskipws(buecher);
                        buecher >> namenSpeicher;
                        if (namenSpeicher == '%') {
                            break;
                        }
                        buchName += namenSpeicher;
                    }
                }
                skipws(buecher);
                buecher >> ISBN;
                while (!buecher.eof()) {
                    int buchtag;
                    buecher >> buchtag;
                    genre.push_back(buchtag);
                }
                buch.bookID = buchId;
                buch.authorID = autorId;
                buch.titel = buchName;
                buch.ISBN = ISBN;
                buch.tags = genre;
                bookList.push_back(buch);
            }


        }
    }
    else {
        error("601 library-Datei existiert, kann aber nicht gelesen werden!");

    }


    input_stream >> speicher;                                     //User einlesen
    if (speicher == "[users]")
    {
        while (true) {
            user Person;
            int PersonNr;
            string PersonVorname;
            string PersonNachname;
            input_stream >> speicher;
            if (speicher == "[borrowentries]") {
                for (int i = 0; i < speicher.size(); ++i) {
                    input_stream.unget();

                }
                break;
            }
            for (int i = 0; i < speicher.size(); ++i) {
                input_stream.unget();
            }
            input_stream >> PersonNr;
            input_stream >> PersonVorname;
            input_stream >> PersonNachname;
            Person.userID = PersonNr;
            Person.vorname = PersonVorname;
            Person.nachname = PersonNachname;
            userList.push_back(Person);

        }
    }
    else {
        error("601 library-Datei existiert, kann aber nicht gelesen werden\n");

    }                                                                              // user eingelesen


                                                                                //Leiheintraege einlesen
    input_stream >> speicher;
    if (speicher == "[borrowentries]") {
        while (!input_stream.eof()) {
            speicher = "";
            input_stream >> speicher;
            if (speicher == "") {
                break;
            }
            else
            {
                for (int i = 0; i < speicher.size(); ++i) {
                    input_stream.unget();
                }
            }
            leiheintrag eintrag;
            int uID;
            int bID;
            input_stream >> uID;
            input_stream >> bID;
            eintrag.userID = uID;
            eintrag.bookID = bID;
            ausleihListe.push_back(eintrag);
        }
    }
    else {
        cerr << "601 library-Datei existiert, kann aber nicht gelesen werden\n";
    }                                                                           //Datei zuende eingelesen

    input_stream.close();
}