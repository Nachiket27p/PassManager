#pragma once
#include "Entry.cpp"
#include <cliext/map>

ref class EntryList
{
private:
	cliext::map<String^, Entry^> list;

public:
	bool hasEntry(String^ name) {
		if (list.find(name) == list.end()) {
			return false;
		}
		else {
			return true;
		}
	}

	Entry^ getEntry(String^ name) {
		if (list.find(name) != list.end()) {
			return list[name];
		}
		else {
			return nullptr;
		}
	}

	int size() {
		return list.size();
	}

	bool deleteEntry(String^ name) {
		return list.erase(name);
	}

	bool modifyEntry(String^ plainName, String^ name, String^ userName, String^ password, String^ notes) {
		cliext::map<String^, Entry^>::iterator i = list.find(plainName);
		if (i == list.end()) {
			return false;
		} 
		else {
			list[plainName]->setUserName(userName);
			list[plainName]->setPassword(password);
			list[plainName]->setNotes(notes);
			return true;
		}
	}

	bool addEntry(String^ plainName, String^ name, String^ userName, String^ password, String^ notes) {
		if (list.find(plainName) == list.end()) {
			Entry^ n = gcnew Entry(name, userName, password, notes);
			list.insert(cliext::map<String^, Entry^>::make_value(plainName, n));
			return true;
		}
		else {
			return false;
		}
	}

	array<String^>^ getEntryNames() {
		int siz = list.size();
		array<String^>^ n = gcnew array<String^>(siz);
		int idx = 0;
		for each (cliext::map<String^, Entry^>::value_type elem in list) {
			n[idx++] = elem->first;
		}
		return n;
	}

	array<String^>^ getAllEntries() {
		int siz = list.size();
		array<String^>^ n = gcnew array<String^>(siz);
		int idx = 0;
		for each (cliext::map<String^, Entry^>::value_type elem in list) {
			n[idx++] = elem->second->toString();
		}
		return n;
	}
};
