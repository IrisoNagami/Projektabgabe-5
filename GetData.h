#pragma once
#include <sstream>
#include "std_lib_inc.h"
#include "Classes.h"
#include <sstream>

extern vector<user> userList;
extern vector<author> authorList;
extern vector<tag> tagList;
extern vector<book> bookList;
extern vector<leiheintrag> ausleihListe;

bool istStringEineZahl(string s);

void NameAusProzent(string& s);

void GetData();