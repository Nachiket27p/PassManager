#pragma once
using namespace System;

ref class Entry
{
private:
	String^ name;
	String^ userName;
	String^ password;
	String^ notes;

public:
	Entry(String^ n, String^ uN, String^ p, String^ no) {
		name = n;
		userName = uN;
		password = p;
		notes = no;
	}

	String^ getName() { return name; }

	String^ getUserName() { return userName; }

	String^ getPassword() { return password; }

	String^ getNotes() { return notes; }

	void setName(String^ s) { name = s; }

	void setUserName(String^ s) { userName = s; }

	void setPassword(String^ s) { password = s; }

	void setNotes(String^ s) { notes = s; }

	String^ toString() {
		return (name + " " + userName + " " + password + " " + notes);
	}
};