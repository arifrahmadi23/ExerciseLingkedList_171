#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** rahmadi, Node** arif);
	bool listEmpty();
	bool delNode(int rollNo);
	void traverse();
	void hapus();
};
void CircularLinkedList::addNode() { //write your answer here
	int nim;
	string nm;
	cout << "Masukan NIM :" << endl;
	cin >> nim;
	cout << "Masukan Nama :" << endl;
	cin >> nm;
	Node* newNode = new Node();
	newNode->rollNumber = nim;
	newNode->name = nm;
	// begining of the list
	if (LAST == NULL) { //step a
		newNode->next = newNode;// step a.1,a.2,a.3
		LAST = newNode;//step a.4
		return;
	}
	// end of the list
	if (nim <= LAST->next->rollNumber) { // step c
		if (nim == LAST->next->rollNumber) {
			cout << "\nNIM sudah ada" << endl;
			return;
		}
		newNode->next = LAST->next;
		LAST->next = newNode;
		LAST = newNode;
		return;
	}
	// between two node in the list
	Node* arif = LAST->next; //step b
	Node* rahmadi = LAST;
	while (arif->next != LAST->next && arif->next->rollNumber < nim) {
		rahmadi = arif;
		arif = arif->next;
	}

	if (arif->next != LAST->next && nim == arif->next->rollNumber) {
		cout << "\nNIM sudah ada" << endl;
		return;
	}

	newNode->next = arif->next;
	arif->next = newNode;
	LAST = newNode;
}

bool CircularLinkedList::search(int rollno, Node** rahmadi, Node** arif) {
	*rahmadi = LAST->next;
	*arif = LAST->next;
	while (*arif != LAST) {
		if (rollno == (*arif)->rollNumber) {
			return true;
		}
		*rahmadi = *arif;
		*arif = (*arif)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode(int rollNo) { //write your answer here
	if (listEmpty()) {
		return false;
	}

	Node* rahmadi = LAST;
	Node* arif = LAST->next;

	// begining of the list
	if (arif->rollNumber == rollNo) { // step a
		if (arif->next == arif) { // step1.a
			LAST = NULL;
		}
		else { // step 1.b
			LAST->next = arif->next; // step 3
		}
		delete arif; // step 4
		return true;
	}
	// menghapus diantara 2 node
	while (arif->next != LAST->next && arif->rollNumber != rollNo) {
		rahmadi = arif;
		arif = arif->next;
	}
	// menghapus diakhir node
	rahmadi->next = arif->next;
	if (arif == LAST) {
		LAST = rahmadi;
	}
	delete arif;
	return true;
}

void CircularLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}
	cout << "\nMasukan NIM yang akan dihapus: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (CircularLinkedList::delNode(rollNo) == false)
		cout << "Data tidak ditemukan" << endl;
	else
		cout << "Data" << rollNo << "Telah dihapus" << endl;

}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.hapus();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}