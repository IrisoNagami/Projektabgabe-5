#pragma once
#include "std_lib_inc.h"
#include <sstream>
#include "Classes.h"
#include "ID_Generation.h"

extern vector<user> userList;
extern vector<author> authorList;
extern vector<tag> tagList;
extern vector<book> bookList;
extern vector<leiheintrag> ausleihListe;

void HandleCommand(stringstream &inputCommand);