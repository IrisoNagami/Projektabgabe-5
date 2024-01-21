#include "parameter_reader.h"
#include "ID_Generation.h"
#include "Classes.h"
#include "GetData.h"
#include "SaveData.h"
#include "CommandHandler.h"
#include "Sorter.h"

extern vector<user> userList;
extern vector<author> authorList;
extern vector<tag> tagList;
extern vector<book> bookList;
extern vector<leiheintrag> ausleihListe;


int main(int argc, char** argv)
{
    GetData();
    Sort();
    stringstream arguments = make_string_stream(argc, argv);
    HandleCommand(arguments);
    SaveData();


    return 0;
}