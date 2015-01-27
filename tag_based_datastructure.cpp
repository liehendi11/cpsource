#include <stdio.h>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Item
{
public:
	int value;
	Item (int x)
	{
		value = x;
	}
};

// typedef vector<Item*> VectorOfItems;

class KeyBasedStorage
{
private:
	vector<Item> items;
	unordered_map<string, map<string, vector<int> > > objectMaps;

public:
	void insert(int val, vector<pair<string, string> > keys)
	{
		items.push_back(Item(val));
		int idx = items.size()-1;
		
		for (int i=0; i<keys.size(); i++)
		{
			pair<string, string> key = keys[i];

			if (objectMaps.count(key.first) == 0) objectMaps.insert(pair<string, map<string, vector<int> > > (key.first, map<string, vector<int> > ()));
			if (objectMaps[key.first].count(key.second) == 0) objectMaps[key.first].insert(pair<string, vector<int> > (key.second, vector<int> ()));

			objectMaps[key.first][key.second].push_back(idx);
		}
	}

	void traverse()
	{
		printf("ITEMS\n");
		for (int i=0; i<items.size(); i++) printf("%d %d\n", i, items[i].value);

		printf("INDEXES\n");

		for (auto itKeyType=objectMaps.begin(); itKeyType != objectMaps.end(); ++itKeyType)
		{
			printf("Key type %s\n", itKeyType->first.c_str());

			for (auto itKeyValue=itKeyType->second.begin(); itKeyValue != itKeyType->second.end(); ++itKeyValue)
			{
				printf("Key value %s: ", itKeyValue->first.c_str());
				for (int i=0; i<itKeyValue->second.size(); i++)
					printf("%d ", itKeyValue->second[i]);
				printf("\n");
			}
			
		}

	}

	vector<Item> search(string keyType, string keyValue)
	{
		vector<Item> res;

		if (objectMaps.count(keyType) == 0) return res;
		if (objectMaps[keyType].count(keyValue) == 0) return res;

		for (int i=0; i<objectMaps[keyType][keyValue].size(); i++)
		{
			res.push_back(items[objectMaps[keyType][keyValue][i]]);
		}

		return res;
	}
};

int main()
{
	KeyBasedStorage storage;

	while (true)
	{
		string command;
		getline(cin, command);

		if (command == "insert")
		{
			int val, n;

			scanf("%d%d", &val, &n);
			vector<pair<string, string> > keys;

			string a,b;

			for (int i=0; i<n; i++)
			{
				cin >> a >> b;
				keys.push_back(pair<string, string> (a,b));
			}

			storage.insert(val, keys);
			storage.traverse();
		}
		else
			if (command == "search")
			{
				string a,b;

				cin >> a >> b;
				vector<Item> res = storage.search(a,b);

				for (int i=0; i<res.size(); i++) printf("%d\n", res[i].value);
			}
	}
	return 0;
}