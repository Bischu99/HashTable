#include <iostream>
#include <list>
#include <cstring>

using namespace std;

//Hashtable 

class HashTable {
	private:
		static const int hashGroups = 10;
		list < pair<int, string>> table[hashGroups]; 

	public:
		bool isEmpty() const;
		int hashFuntion(int key);
		void insertItem(int key, string value);
		void remveItem(int key);
		string serarchTable(int key);
		void printTable();

};

bool HashTable::isEmpty() const{
	int sum{};
	for (int i{}; i < hashGroups; i++) {
		sum += table[i].size();
	}

	if (!sum) {
		return true;
	}
	return false;
}

int HashTable::hashFuntion(int key) {
	return key % hashGroups; 
}

void HashTable::insertItem(int key, string value) {
	int hashValue = hashFuntion(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool KeyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			KeyExists = true; 
			bItr->second = value;
			cout << "[WARNING] Key exists. Value replaced." << endl;
			break;
		}
	}

	if (!KeyExists) {
		cell.emplace_back(key, value);
	}

	return;
}

void HashTable::remveItem(int key) {
	int hashValue = hashFuntion(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool KeyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			KeyExists = true;
			bItr = cell.erase(bItr);
			cout << "[INFO] Item removed." << endl;
			break;
		}
	}

	if (!KeyExists) {
		cout << "[WARNIGN] key not found. Pair not removed." << endl;
	}
	return;
}

void HashTable::printTable() {
	for(int i{}; i < hashGroups; i++) {
		if (table[i].size() == 0) continue;


		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			cout << "[INFO] Key : " << bItr->first << " Value: " << bItr->second << endl;
		}
	}
	return;
}

int main() {
	HashTable HT;

	if (HT.isEmpty()) {
		cout << "Correct answer. Good job.";
	}
	else {
		cout << "Oh..oh . We need to check out code!" << endl;
	}

	HT.insertItem(911, "Jim");
	HT.insertItem(920, "Tom");
	HT.insertItem(311, "Tipen");
	HT.insertItem(411, "Kim");
	HT.insertItem(511, "Rob");
	HT.insertItem(611, "Sally");
	HT.insertItem(711, "Wendy");
	HT.insertItem(711, "Wendy");

	HT.printTable();

	HT.remveItem(332);
	HT.remveItem(511);
	return 0;
}