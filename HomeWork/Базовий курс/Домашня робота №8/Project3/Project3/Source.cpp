#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
bool isLexeme(const char * const str, const char * const pLexeme, const short lenLexeme, const char * const delim)
{
	if (pLexeme - str > 0)
		if (strchr(delim, *(pLexeme - 1)) == NULL)
			return false;
	if ((strlen(str) - 1) - (pLexeme - str + lenLexeme - 1) > 0)
		if (strchr(delim, *(pLexeme + lenLexeme)) == NULL)
			return false;
	return true;
}
void repl_lex(char *&str, const short index, const short lenLex, const char * const newLexeme)
{
	const short lenTermNullByte = 1;
	short lenNewStr = strlen(str) + lenTermNullByte - lenLex + strlen(newLexeme);
	char *newStr = new char[lenNewStr];
	strcpy(newStr, "");
	strncpy(newStr, str, index);
	newStr[index] = '\0';
	strcat(newStr, newLexeme);
	strcat(newStr, str + (index + lenLex));
	delete[] str;
	str = newStr;
}
char * my_strstrr(char *str, const char *substr, char *fromHere)
{
	if (str == nullptr || substr == nullptr || fromHere == nullptr || fromHere < str || fromHere > str + (strlen(str) - 1))
		return nullptr;
	const char *j = substr + (strlen(substr) - 1);
	for (char *i = fromHere; i >= str; i--)
	{
		while (*j == *i)
		{
			j--;
			i--;
			if (j < substr || i < str)
				break;
		}
		if (j < substr)
			return i + 1;
		j = substr + (strlen(substr) - 1);
	}
	return nullptr;
}
char * findLexR(char *source, const char *const lex, const char *const delim)
{
	static char *pLex = nullptr;
	static char *pFirstItemOfSource = nullptr;
	static char *pLastItemOfSource = nullptr;
	if (lex == nullptr || delim == nullptr)
		return nullptr;
	if (source == nullptr && pLex == nullptr)
		return nullptr;
	if (source == nullptr)
	{
		pLex--;
		if (pLex < pFirstItemOfSource)
			return nullptr;
	}
	else
	{
		pLex = source + (strlen(source) - 1);
		pFirstItemOfSource = source;
		pLastItemOfSource = source + (strlen(source) - 1);
	}
	do
	{
		pLex = my_strstrr(pFirstItemOfSource, lex, pLex);
		if (pLex != nullptr)
		{
			if (isLexeme(pFirstItemOfSource, pLex, strlen(lex), delim))
				return pLex;
			else
			{
				pLex--;
				if (pLex < pFirstItemOfSource)
					return nullptr;
			}
		}
	} while (pLex != nullptr);
	return nullptr;
}
void replace(char *&line, const char * const word_1, const char * const word_2)
{
	if (line == nullptr || word_1 == nullptr || word_2 == nullptr)
		return;
	char delim[] = " .,";
	bool isFirstIteration = true;
	char *pLexeme, *pSource = line;
	char *newLine = new char[strlen(line) + 1];
	strcpy(newLine, line);
	do
	{
		pLexeme = findLexR(pSource, word_1, delim);
		if (isFirstIteration) {
			isFirstIteration = false;
			pSource = nullptr;
		}
		if (pLexeme)
			repl_lex(newLine, pLexeme - line, strlen(word_1), word_2);
	} while (pLexeme != nullptr);
	delete[]line;
	line = newLine;
}

int main()
{
	const short MAX_LEN = 200;
	char buf[MAX_LEN] = {};
	cout << "Enter the datas (max lengthes are " << MAX_LEN << "):" << endl;
	cout << "Line -> ";
	cin.getline(buf, MAX_LEN);
	char *line = new char[strlen(buf) + 1];
	strcpy(line, buf);
	cout << "word_1 -> ";
	cin.getline(buf, MAX_LEN);
	char *word_1 = new char[strlen(buf) + 1];
	strcpy(word_1, buf);
	cout << "word_2 -> ";
	cin.getline(buf, MAX_LEN);
	char *word_2 = new char[strlen(buf) + 1];
	strcpy(word_2, buf);
	replace(line, word_1, word_2);
	cout << endl;
	cout << "Result -> " << line << endl;
	delete[] word_1;
	delete[] word_2;
	delete[] line;
	system("pause");
}