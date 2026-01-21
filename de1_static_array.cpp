#include <iostream>
#include <string>
using namespace std;

class individual {
private:
    int phone;
    string name;
    int num;
    int id;

public:
    int getid() const {
        return id;
    }

    void input(int index) {
        cout << "ma khach hang: " << endl;
        cin >> id;

        cout << "Nhap ten khach hang #" << index + 1 << ": " << endl;
        getline(cin >> ws, name); // ws=white space, khi dung \n se ko bi rong

        cout << "Nhap so dien thoai cua khach hang #" << index + 1 << ": " << endl;
        cin >> phone;

        cout << "Nhap tong gia tri mua hang cua khach hang #" << index + 1 << ": " << endl;
        cin >> num;
    }

    void output() {
        cout << " Ma khach hang: " << id << endl;
        cout << " Ten khach hang: " << name << endl;
        cout << " so dien thoai: " << phone << endl;
        cout << " tong gia tri mua hang: " << num << endl;
    }

    int max() {
        return num;
    }

    int min() {
        return num;
    }

    string getName() {
        return name;
    }
};

int main() {
    const int MAXN = 1000;
    individual individuals[MAXN];
    int n = 0;

    int in;
    cout << "Nhap so luong khach hang can nhap : " << endl;
    cin >> in;

    if (in < 0) in = 0;
    if (in > MAXN) in = MAXN;

    for (int i = 0; i < in; i++) {
        individuals[n].input(n);
        n++;
    }

    int choice;
    do {
        cout << "***muc luc***" << endl;
        cout << "1.Hien thi tat ca khach hang " << endl;
        cout << "2.Tim khach hang theo ma khach hang " << endl;
        cout << "3.Nhap them khach hang " << endl;
        cout << "4.Khach hang co tong gia tri mua hang cao nhat " << endl;
        cout << "5.Khach hang co tong gia tri mua hang thap nhat  " << endl;
        cout << "6.Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                for (int i = 0; i < n; i++) {
                    individuals[i].output();
                }
                break;
            }

            case 2: {
                int id;
                cout << "Nhap ma so khach hang: " << endl;
                cin >> id;

                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (individuals[i].getid() == id) {
                        individuals[i].output();
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "khong tim thay id cua khach hang " << endl;
                }
                break;
            }

            case 3: {
                if (n >= MAXN) {
                    cout << "Danh sach day, khong the nhap them!\n";
                    break;
                }
                individuals[n].input(n);
                n++;
                break;
            }

            case 4: {
                if (n == 0) {
                    cout << "Danh sach rong!\n";
                    break;
                }

                individual maxD = individuals[0];
                int maxVal = maxD.max();

                for (int i = 0; i < n; i++) {
                    if (individuals[i].max() > maxVal) {
                        maxVal = individuals[i].max();
                        maxD = individuals[i];
                    }
                }

                maxD.output();
                break;
            }

            case 5: {
                if (n == 0) {
                    cout << "Danh sach rong!\n";
                    break;
                }

                int min;
                bool first = true;
                individual minD;

                for (int i = 0; i < n; i++) {
                    if (first) {
                        min = individuals[i].min();
                        minD = individuals[i];
                        first = false;
                    } else if (individuals[i].min() < min) {
                        min = individuals[i].min();
                        minD = individuals[i];
                    }
                }

                minD.output();
                break;
            }

            case 6: {
                break;
            }

            default: {
                cout << "hay nhap lua chon cua ban tu 1 den 6" << endl;
            }
        }

    } while (choice != 6);
}
