#pragma once
#include "EntryList.cpp"

ref struct Globals {
	// array of bytes used as the key
	static array<Byte>^ key;
	// injection vector
	static array<Byte>^ iv = System::Text::Encoding::ASCII->GetBytes("0123456789012345");
	// first line from the file after decryption should be
	static System::String^ validation = "TheFirstLineShouldMatchThisAfterDecryption!";
	// entry list containing the data
	static EntryList^ data = gcnew EntryList;
	// the hash used to encrypt/decrypt
	System::String^ hashKey;
	// default file name
	static System::String^ fileName = "PassManagerData";
	static System::String^ tempFileName = "TempPassManagerData";
};

bool OpenDataFile();
bool DataFileExists();

String^ encryptString(String^);
String^ decryptString(String^);
bool DataFileExists();

bool writeEntryToFile(String^);

void writeAllDataToFile();

