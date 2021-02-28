#include "HashTable.h"

//good
HashTable:: HashTable()
{
	max=101;
	obj=new string[max];
	count=0;
	key=nextPrime((max/2)+1);
}

//good
HashTable:: HashTable(int n)
{
	max=nextPrime(2*n);
	obj=new string[max];
	count=0;
	key=nextPrime((max/2)+1);
}

//good
HashTable:: HashTable(const HashTable &copy)
{
	count=copy.count;
	key=copy.key;
	max=copy.max;
	obj=new string[max];
	for(int i=0;i<max;i++)
		obj[i]=copy.obj[i];
	
}

//good
int HashTable:: Hash_func(string send) const
{
	double string_value=0;
	
	//unsigned long long int string_value=0;
	int power=send.length()-1;
	for(int i=0;i<send.length();i++)
		string_value+=(send[i]%96)*pow(32,float(power--));
	//cout<<string_value<<" ";

	return fmod(string_value,max);
	//return string_value%max;
}
//good
int HashTable:: Hash_func_2(int val) const
{
	return key-(val%key);
}

//good
int HashTable:: nextPrime(int n)
{
	for(int i=n;;i++)
	{
		if(ISprime(i)==1)
			return i;
	}
}

//good
bool HashTable::ISprime(int n) const
{
	int count=0;
	for(int i=2;i<n;i++)
		if(n%i==0)
			count++;
	if(count==0)
		return true;
	else 
		return false;
}

//good
HashTable:: ~HashTable()
{
	delete [] obj;
}

void HashTable::insert(string alloc)
{
	if(find(alloc)==true)
		return;

	if(loadFactor()>0.67)
	{
		int oldmax=max;
		max=nextPrime(2*max);
		string *temp=new string[max];
		key=nextPrime((max/2)+1);
		for(int i=0;i<oldmax;i++)
		{
			temp[i]=obj[i];
		}
		string *discard=obj;
		obj=temp;
		delete [] discard;
	}
	int h1=Hash_func(alloc);
	if(obj[h1]!=""){
		int add=Hash_func_2(h1);
		while(obj[(h1+add)%max]!="")
			add+=add;
		obj[(h1+add)%max]=alloc;
		count++;
	}
	else
	{
		obj[h1]=alloc;
		count++;
	}
}

bool HashTable::find(string target) const
{
	int h1=Hash_func(target);
	if(obj[h1]==target)
		return true;
	int add=Hash_func_2(h1);
	for(int i=0;i<max;i++){
		if(obj[(h1+(add*i))%max]==target)
			return true;
	}
	return false;
}

int HashTable:: size() const
{
	return count;
}
int HashTable::maxSize() const
{
	return max;
}

float HashTable::loadFactor() const
{
	return float(count)/max;
}

void HashTable:: Test()
{
	cout<<"size of object is "<<max<<endl;
	cout<<"Number of items in object is "<<count<<endl;
	for(int i=0;i<max;i++){
		if(obj[i]!="")
			cout<<"Index "<<i<<" is "<< obj[i];
		else
		{
			cout<<"Index "<<i<<" is \t";
		}
		cout<<"\t\tHash1 value is: "<<Hash_func(obj[i]);
		cout<<"\t\tHash2 value is: "<<Hash_func_2(Hash_func(obj[i]))<<endl;
	}
	cout<<"Load factor is "<<loadFactor()<<endl;
	cout<<"P2 value: "<<key<<endl;
}



