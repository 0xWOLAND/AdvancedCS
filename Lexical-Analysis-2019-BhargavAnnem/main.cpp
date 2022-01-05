#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// returns count of non-overlapping occurrences of 'sub' in 'str'
bool ok(string s){
	for(int i = 0; i < s.length(); i++){
		if(!isalpha(s[i])){
			return false;
		}
	}
	return true;
}

int countSubstring(const string& str, const string& sub)
{
	if (sub.length() == 0) return 0;
	int count = 0;
	for (int offset = str.find(sub); offset != string::npos; 
		offset = str.find(sub, offset + sub.length()))
	{
		++count;
	}
	return count;
}

int wordCount(const string& str){
	int tot = 0;
	int l = 0, r = 1;
	const int n = str.length();
	for(; r < n; r++){
		if(str[r] == ' ' && str[r - 1] != ' '){
			string tmp = str.substr(l, (ispunct(str[r - 1]) ? r - 1 : r) - l);
			if(ok(tmp)){
				tot++;
			}	
			l = r + 1;			
		}
		else if(str[r] != ' ' && str[l] == ' '){
			l = r;
		}
	}

	return tot + 1;
}

int uniqueWords(const string& str){
	set<string> s;
	int tot = 0;
	int l = 0, r = 1;
	for(; r < str.length(); r++){
		if(str[r] == ' ' && str[r - 1] != ' '){
			string tmp = str.substr(l, (str[r - 1] == '.' ? r - 1 : r) - l);
			if(ok(tmp)){
				s.insert(tmp);
			}
			l = r + 1;
		}
		else if(str[r] != ' ' && str[l] == ' '){
			l = r;
		}
	}
	string tmp = str.substr(l, (str[r - 1] == '.' ? r - 1 : r) - l);
	if(ok(tmp)){
		s.insert(tmp);
	}
	return s.size();

}


float numberOfSentences(const string& str){
	int tot = 0;
	for(int i = str.find("."); i != string::npos; i = str.find(".", i + 1)){
		tot++;
	}
	return tot;
}

float lexicalDensity(const string& str){
	return ((float) (uniqueWords(str)) / wordCount(str)) * 100;
}

int main()
{




   string source = ("I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo.  I got the ramblin fever.  Said goodbye to ma and pa.   Crossed that ol red river and this is what I saw. I saw miles and miles of Texas 1000 stars up in the sky.  I saw miles and miles of Texas gonna live here till I die.");


	cout << "substring count: " << countSubstring(source, "is")        << '\n';
	cout << "word count: " << wordCount(source) << "\n";
	cout << "sentence count: " << numberOfSentences(source) << "\n";
	cout << "unique words: " << uniqueWords(source) << "\n";
	cout << "average words per sentence: " << wordCount(source) / numberOfSentences(source) << "\n";
	cout << "lexical density: " << lexicalDensity(source) << "%\n";

	return 0;
}