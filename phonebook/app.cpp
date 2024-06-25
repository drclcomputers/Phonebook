#include "app.h"

int appx::contacte() {
	ifstream fin("./files/nr_contacte.pb");
	int nr; fin >> nr;
	fin.close();
	return nr;
}

void appx::add() {
	int nr = contacte() + 1;
	char linie[300] = "./files/";
	char nrarray[20];
	sprintf(nrarray, "%ld", nr);
	strcat(linie, nrarray);
	strcat(linie, ".pb");
	ofstream fout(linie);

	char nume[101], prenume[101], number[51], description[501];
	cin.ignore();
	cout << "Enter first name: ";
	cin.getline(nume, 100);
	cout << "Enter last name: ";
	cin.getline(prenume, 100);
	cout << "Enter phone number: ";
	cin.getline(number, 50);
	cout << "Enter a short description: ";
	cin.getline(description, 500);

	fout << nume << "  ,  " << prenume << "  ,  " << number << "  ,  " << description << '\n';
	fout.close();

	ofstream fin("./files/nr_contacte.pb", ios::trunc);
	fin << nr;
	fin.close();
	
}

void appx::show(){
	int nr = contacte(), dele;
	ifstream fin1("./files/deleted.pb");
	fin1 >> dele;
	fin1.close();
	cout << YELLOW << "\nTotal: " << nr << " Contacts         Deleted: " << dele << '\n';
	cout << GREEN << "\nFirst Name  ,  Last Name  ,  Number  ,  Description\n\n" << WHITE;
	for (int i = 1; i <= nr; i++) {
		cout << i << ". ";
		char linie[300] = "./files/";
		char nrarray[20];
		sprintf(nrarray, "%ld", i);
		strcat(linie, nrarray);
		strcat(linie, ".pb");
		char text[1001];
		ifstream fout(linie);
		fout.getline(text, 1000);
		cout << text << '\n';
		fout.close();
	}
	cout << "\n\nPress enter to continue . . .";
	cin.ignore();
	cin.get();
}

void appx::deleteperson(){
	cin.ignore();
	cout << "Enter contact index to delete: ";
	int dele; cin >> dele;
	int nr = contacte();
	while (dele<1 || dele>nr) {
		cout << "Enter correct index: ";
		cin >> dele;
	}
	char linie[300] = "./files/";
	char nrarray[20];
	sprintf(nrarray, "%ld", dele);
	strcat(linie, nrarray);
	strcat(linie, ".pb");
	char text[1001];
	ofstream fout(linie, ios::trunc);
	fout << "Deleted\n";
	fout.close();

	ifstream fin1("./files/deleted.pb");
	fin1 >> dele;
	fin1.close();

	ofstream fin("./files/deleted.pb", ios::trunc);
	fin << dele+1;
	fin.close();

}

void appx::search(){
	cin.ignore();
	cout << "\nEnter person's first name to search: ";
	char name[101]; cin.getline(name, 100);
	int nr = contacte();
	for (int i = 1; i <= nr; i++) {
		char linie[300] = "./files/";
		char nrarray[20];
		sprintf(nrarray, "%ld", i);
		strcat(linie, nrarray);
		strcat(linie, ".pb");
		char text[1001];
		ifstream fout(linie);
		fout.getline(text, 1000);
		char text1[1001];
		strcpy(text1, text);
		char* p = strtok(text, "  ,  ");
		if (p != NULL) {
			if (strcmp(p, name) == 0 || strcmp(p, name) == 1)
				cout << i << ". " << text1 << '\n';
		}
	}
	cout << "\n\nPress enter to continue . . .";
	cin.get();
}

void appx::start(){
	cout << WHITE << "Phone Book ver 0.2\n\n1. Add Contact\n2. Show Phone Book\n3. Search\n4. Delete contact\n5. Exit\n\n" << "Enter option: " << BLUE;
	char opt[10]; cin.getline(opt, 9);
	int n = atoi(opt);
	cout << WHITE;
	while (n < 1 || n > 5) {
		cout << "Enter correct option: " << BLUE;
		cin.getline(opt, 9);
		n = atoi(opt);
		cout << WHITE;
	}
	switch (n) {
	case 1:
		add();
		break;
	case 2:
		show();
		break;
	case 4:
		deleteperson();
		break;
	case 3:
		search();
		break;
	case 5:
		return;
		break;
	}
	system(CLEAR_SCREEN);
	start();
}

void appx::reset() {
	int nr = contacte();
	for (int i = 1; i <= nr; i++) {
		char linie[300] = "./files/";
		char nrarray[20];
		sprintf(nrarray, "%ld", i);
		strcat(linie, nrarray);
		strcat(linie, ".pb");
		remove(linie);
	}
	ofstream fin("./files/nr_contacte.pb", ios::trunc);
	fin << 0;
	fin.close();

	ofstream fin1("./files/deleted.pb", ios::trunc);
	fin1 << 0;
	fin1.close();

	ofstream fin2("./files/login/user.pbg", ios::trunc);
	fin2.close();

	ofstream fin3("./files/login/pass.pbg", ios::trunc);
	fin3.close();
}