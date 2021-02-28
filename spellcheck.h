void insert(const HashTable & ht,vector<string> &target, string temp)
{
	if(ht.find(temp)==1)
		target.push_back(temp);
}


vector<string> extraLetter(const HashTable & ht, string word)
{
	vector<string> target;//Array of strings we might return
	int len=word.length();
	if(ht.find(word)==1)//Seaches Hashtable returns word if found
	{
		target.push_back(word);
		return target;
	}
	for(int j=0;j<len;j++)
	{
		string temp;
		for(int i=0;i<len;i++)
		{
			if(i==j)
				continue;
			temp+=word[i];
		}
		insert(ht,target, temp);
	}
	return target;
}

vector<string> transposition(const HashTable & ht, string word)
{
	vector<string> target;//Array of strings we might return
	string temp=word;
	int len=word.length();
	if(ht.find(word)==1)//Seaches Hashtable returns word if found
	{
		target.push_back(word);
		return target;
	}
	for(int i=0;i<len-1;i++)
	{
		temp[i]=word[i+1];
		temp[i+1]=word[i];
		insert(ht,target, temp);
		temp=word;
	}
	return target;
}

vector<string> missingSpace(const HashTable & ht, string word)
{
	vector<string> target;//Array of strings we might return
	string temp;
	string temp2;
	int count=0;
	int len=word.length();
	if(ht.find(word)==1)//Seaches Hashtable returns word if found
	{
		target.push_back(word);
		return target;
	}
	for(int i=0;i<len;i++)
	{
		temp+=word[i];
		if(ht.find(temp)==1){
		temp+=" ";
		temp2+=temp;
		temp="";
		count++;
		}
	}
	if(count!=2)
			return target;
	target.push_back(temp2);
	return target;
}