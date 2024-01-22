#include "ID_Generation.h"
extern vector<author> authorList;
extern vector<book> bookList;
extern vector<user> userList;
extern vector<tag> tagList;

int idGeneration(const string Klasse)
{
	if (Klasse == "User")
	{
		if (!userList.empty())
		{
			user tempUser = userList[userList.size() - 1];

			//Möglich, da Sorted nach ID
			return tempUser.userID + 1;
		}
		else
		{
			return 0;
		}
	}
	else if (Klasse == "Author")
	{
		if (!authorList.empty())
		{
			author tempAuthor = authorList[authorList.size() - 1];

			//Möglich, da sorted nach ID
			return tempAuthor.authorID + 1;
		}
		else
		{
			return 0;
		}
	}
	else if (Klasse == "Tag")
	{
		if (!tagList.empty())
		{
			tag tempTag = tagList[tagList.size() - 1];

			//Möglich, da sorted nach ID
			return tempTag.TagID + 1;
		}
		else
		{
			return 0;
		}
	}
	else if (Klasse == "Book")
	{
		if (!bookList.empty())
		{
			book tempBook = bookList[bookList.size() - 1];

			//Möglich, da sorted nach ID
			return tempBook.bookID + 1;
		}
		else
		{
			return 0;
		}
	}
}