#pragma once
#include "SharedData.h"

using namespace System::IO;
using namespace System::Text;
using namespace System::Security::Cryptography;

void LoadData(StreamReader^);

bool DataFileExists() {
	return File::Exists(Globals::fileName);
}

bool OpenDataFile() {
	StreamReader^ sr;
	bool rtn = true;
	if (DataFileExists()) {
		File::SetAttributes(Globals::fileName, FileAttributes::Normal);
		sr = File::OpenText(Globals::fileName);
		String^ vh = sr->ReadLine();
		String^ v = decryptString(vh);
		if (v != Globals::validation) {
			rtn = false;
		}
		else {
			LoadData(sr);
		}
		sr->Close();
		File::SetAttributes(Globals::fileName, File::GetAttributes(Globals::fileName) | FileAttributes::Hidden);
		File::SetAttributes(Globals::fileName, File::GetAttributes(Globals::fileName) | FileAttributes::ReadOnly);
	}
	else {
		StreamWriter^ sw = gcnew StreamWriter(Globals::fileName);
		sw->WriteLine(encryptString(Globals::validation));
		sw->Flush();
		sw->Close();
		File::SetAttributes(Globals::fileName, File::GetAttributes(Globals::fileName) | FileAttributes::Hidden);
		File::SetAttributes(Globals::fileName, File::GetAttributes(Globals::fileName) | FileAttributes::ReadOnly);
	}
	return rtn;
}

void LoadData(StreamReader^ sr) {
	String^ s;
	String^ name;
	String^ userName;
	String^ password;
	String^ notes;
	while ((s = sr->ReadLine()) != nullptr) {
		array<String^>^ entryData;
		entryData = s->Split();
		name = decryptString(entryData[0]);
		userName = decryptString(entryData[1]);
		password = decryptString(entryData[2]);
		// check for notes
		if (entryData[3] == "\0") {
			notes = "";
		}
		else {
			notes = decryptString(entryData[3]);
		}
		Globals::data->addEntry(name, encryptString(name), encryptString(userName), encryptString(password), encryptString(notes));
	}
}

bool writeEntryToFile(String^ name) {
	if (name == nullptr) {
		return false;
	}
	// if file doesnt exist or the first three fields are of size zero
	if (!DataFileExists() || !name->Length) {
		return false;
	}
	File::SetAttributes(Globals::fileName, FileAttributes::Normal);
	StreamWriter^ sw = File::AppendText(Globals::fileName);
	
	sw->WriteLine(Globals::data->getEntry(name)->toString());
	sw->Flush();
	sw->Close();
	File::SetAttributes(Globals::fileName, File::GetAttributes(Globals::fileName) | FileAttributes::Hidden);
	File::SetAttributes(Globals::fileName, File::GetAttributes(Globals::fileName) | FileAttributes::ReadOnly);

	return true;
}

// boolean ed = true ; means encrypt, ed = false means decrypt

String^ encryptString(String^ s) {
	if (s->Length == 0) {
		return "\0";
	}
	array<Byte>^ encrypted;

	Aes^ aesAlg = Aes::Create();
	aesAlg->Key = Globals::key;
	aesAlg->IV = Globals::iv;
	aesAlg->Padding = PaddingMode::Zeros;

	ICryptoTransform^ encryptor = aesAlg->CreateEncryptor(aesAlg->Key, aesAlg->IV);

	MemoryStream^ msEncrypt = gcnew MemoryStream();

	CryptoStream^ csEncrypt = gcnew CryptoStream(msEncrypt, encryptor, CryptoStreamMode::Write);

	//StreamWriter^ swEncrypt = gcnew StreamWriter(csEncrypt);
	int l = 32 - (s->Length % 32);
	while (l--) {
		s += "\0";
	}
	array<Byte>^ enc = Encoding::ASCII->GetBytes(s);
	//int len = s->Length;
	csEncrypt->Write(enc, 0, enc->Length);

	encrypted = msEncrypt->ToArray();

	String^ encryptedText = Convert::ToBase64String(encrypted);
	return encryptedText;
}

String^ decryptString(String^ s) {
	if (s == "\0") {
		return s;
	}
	Aes^ aesAlg = Aes::Create();
	aesAlg->Key = Globals::key;
	aesAlg->IV = Globals::iv;
	aesAlg->Padding = PaddingMode::Zeros;

	ICryptoTransform^ decryptor = aesAlg->CreateDecryptor(aesAlg->Key, aesAlg->IV);

	array<Byte>^ cipherText = Convert::FromBase64String(s);
	MemoryStream^ msDecrypt = gcnew MemoryStream(cipherText);

	CryptoStream^ csDecrypt = gcnew CryptoStream(msDecrypt, decryptor, CryptoStreamMode::Read);

	StreamReader^ srDecrypt = gcnew StreamReader(csDecrypt);

	String^ plainText = srDecrypt->ReadToEnd();
	int len = plainText->Length-1;
	
	while (plainText[len--] == '\0');

	String^ rtn = plainText->Substring(0, len+2);
	return rtn;
}

void writeAllDataToFile() {
	StreamWriter^ sw = gcnew StreamWriter(Globals::tempFileName);
	array<String^>^ a = Globals::data->getAllEntries();
	int siz = a->Length;
	sw->WriteLine(encryptString(Globals::validation));
	for (int i = 0; i < siz; i++) {
		sw->WriteLine(a[i]);
	}
	sw->Flush();
	sw->Close();
	File::SetAttributes(Globals::fileName, FileAttributes::Normal);
	File::Replace(Globals::tempFileName, Globals::fileName, nullptr);
	File::SetAttributes(Globals::fileName, File::GetAttributes(Globals::fileName) | FileAttributes::Hidden);
	File::SetAttributes(Globals::fileName, File::GetAttributes(Globals::fileName) | FileAttributes::ReadOnly);
}
