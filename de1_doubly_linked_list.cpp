#include <iostream>
#include <string>

using namespace std;

bool allDigits(const string& s) {
    if (s.size() == 0) return false;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

bool phoneValid(const string& p) {
    int len = (int)p.size();
    return (len >= 9 && len <= 11 && allDigits(p));
}

class Customer {
private:
    string id;
public:
    string name;
    string phone;
    double total;

    Customer() { id=""; name=""; phone=""; total=0; }

    string getId() const { return id; }
    void setId(const string& x) { id = x; }

    void display() const {
        cout << "Ma: " << id
             << " | Ten: " << name
             << " | SDT: " << phone
             << " | Tong: " << total << "\n";
    }
};

class Node {
public:
    Customer data;
    Node* prev;
    Node* next;
    Node(const Customer& c) {
        data = c;
        prev = NULL;
        next = NULL;
    }
};

class CustomerList {
private:
    Node* head;
    Node* tail;
    int sz;

public:
    CustomerList() { head = tail = NULL; sz = 0; }

    ~CustomerList() {
        Node* cur = head;
        while (cur != NULL) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    int size() const { return sz; }
    bool empty() const { return head == NULL; }

    Node* findById(const string& key) const {
        Node* cur = head;
        while (cur != NULL) {
            if (cur->data.getId() == key) return cur;
            cur = cur->next;
        }
        return NULL;
    }

    void pushBack(const Customer& c) {
        Node* node = new Node(c);
        if (head == NULL) head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        sz++;
    }

    void displayAll() const {
        if (empty()) { cout << "Danh sach rong!\n"; return; }
        Node* cur = head;
        while (cur != NULL) {
            cur->data.display();
            cur = cur->next;
        }
    }

    void displayMaxTotal() const {
        if (empty()) { cout << "Danh sach rong!\n"; return; }
        double mx = head->data.total;

        Node* cur = head->next;
        while (cur != NULL) {
            if (cur->data.total > mx) mx = cur->data.total;
            cur = cur->next;
        }

        cout << "Mua nhieu nhat (Tong = " << mx << "):\n";
        cur = head;
        while (cur != NULL) {
            if (cur->data.total == mx) cur->data.display();
            cur = cur->next;
        }
    }

    void displayMinTotal() const {
        if (empty()) { cout << "Danh sach rong!\n"; return; }
        double mn = head->data.total;

        Node* cur = head->next;
        while (cur != NULL) {
            if (cur->data.total < mn) mn = cur->data.total;
            cur = cur->next;
        }

        cout << "Mua it nhat (Tong = " << mn << "):\n";
        cur = head;
        while (cur != NULL) {
            if (cur->data.total == mn) cur->data.display();
            cur = cur->next;
        }
    }
};

int main() {
    CustomerList ds;

    int number;
    while (true) {
        cout << "Nhap so luong khach hang ban dau: ";
        if (cin >> number && number >= 0 && number <= 1000) break;
        cout << "Nhap lai (0..1000)\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.ignore(10000, '\n');

    for (int i = 0; i < number; i++) {
        Customer c;
        string id;

        while (true) {
            cout << "Nhap ma khach hang [" << i + 1 << "]: ";
            cin >> id;
            if (ds.findById(id) == NULL) break;
            cout << "  -> Ma bi trung. Nhap lai!\n";
        }
        c.setId(id);
        cin.ignore(10000, '\n');

        cout << "Nhap ho ten [" << i + 1 << "]: ";
        getline(cin, c.name);

        while (true) {
            cout << "Nhap so dien thoai [" << i + 1 << "]: ";
            cin >> c.phone;
            if (phoneValid(c.phone)) break;
            cout << "  -> SDT sai. Nhap lai!\n";
        }

        while (true) {
            cout << "Nhap tong gia tri mua hang [" << i + 1 << "]: ";
            if (cin >> c.total && c.total >= 0) break;
            cout << "  -> Tong sai. Nhap lai!\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore(10000, '\n');

        ds.pushBack(c);
    }

    while (true) {
        int ch;
        cout << "\n===== MENU =====\n";
        cout << "1. Them khach hang\n";
        cout << "2. Hien thi tat ca\n";
        cout << "3. Tim theo ma\n";
        cout << "4. Mua nhieu nhat\n";
        cout << "5. Mua it nhat\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";

        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(10000, '\n');

        if (ch == 0) break;

        if (ch == 1) {
            if (ds.size() >= 1000) { cout << "Danh sach day!\n"; continue; }

            Customer c;
            string id;
            while (true) {
                cout << "Nhap ma khach hang: ";
                cin >> id;
                if (ds.findById(id) == NULL) break;
                cout << "  -> Ma bi trung. Nhap lai!\n";
            }
            c.setId(id);
            cin.ignore(10000, '\n');

            cout << "Nhap ho ten: ";
            getline(cin, c.name);

            while (true) {
                cout << "Nhap so dien thoai: ";
                cin >> c.phone;
                if (phoneValid(c.phone)) break;
                cout << "  -> SDT sai. Nhap lai!\n";
            }

            while (true) {
                cout << "Nhap tong gia tri mua hang: ";
                if (cin >> c.total && c.total >= 0) break;
                cout << "  -> Tong sai. Nhap lai!\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cin.ignore(10000, '\n');

            ds.pushBack(c);
            cout << "Da them!\n";
        }
        else if (ch == 2) ds.displayAll();
        else if (ch == 3) {
            if (ds.empty()) { cout << "Danh sach rong!\n"; continue; }
            string key;
            cout << "Nhap ma can tim: ";
            cin >> key;
            cin.ignore(10000, '\n');

            Node* p = ds.findById(key);
            if (p == NULL) cout << "Khong tim thay!\n";
            else p->data.display();
        }
        else if (ch == 4) ds.displayMaxTotal();
        else if (ch == 5) ds.displayMinTotal();
    }

    cout << "Da thoat.\n";
    return 0;
}
