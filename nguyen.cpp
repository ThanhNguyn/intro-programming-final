#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
class individual {
private:
    int phone;
    string name;
    int num;
    int id;
public:
    int getid() {
        return id;
    }
    void input(int index) {
        id=index;
        cin.ignore();
        cout<<"ma khach hang: "<<endl;
        cin>>id;
        cout<<"Nhap ten khach hang #"<<index+1<<": "<<endl;
        cin>>name;
        cout<<"Nhap so dien thoai cua khach hang #"<<index+1<<": "<<endl;
        cin>>phone;
        cout<<"Nhap tong gia tri mua hang cua khach hang #"<<index+1<<": "<<endl;
        cin>>num;
    }
    void output() {
        cout<<" Ten khach hang: "<<name<<endl;
        cout<<" so dien thoai: "<<phone<<endl;
        cout<<" tong gia tri mua hang: "<<num<<endl;
    }
    int max(){
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
    list<individual> individuals;
    int in;
    cout<<"Nhap so luong khach hang can nhap : "<<endl;
    cin>>in;
    for (int i=0;i<in;i++) {
        individual a;
        a.input(i);
        individuals.push_back(a);
    }
    int choice;
    do {
        cout<<"***muc luc***"<<endl;
        cout<<"1.Hien thi tat ca khach hang "<<endl;
        cout<<"2.Tim khach hang theo ma khach hang "<<endl;
        cout<<"3.Nhap them khach hang "<<endl;
        cout<<"4.Khach hang co tong gia tri mua hang cao nhat "<<endl;
        cout<<"5.Khach hang co tong gia tri mua hang thap nhat  "<<endl;
        cout<<"6.Exit"<<endl;
        cin>>choice;
        switch (choice) {
            case 1: {
                for (individual& a : individuals) {
                    a.output();
                }
                break;
            }
            case 2: {
                int id;
                cout<<"Nhap ma so khach hang: "<<endl;
                cin>>id;
                bool found=false;
                for (individual& a : individuals) {
                    if (a.getid()==id) {
                        a.output();
                        found=true;
                    }
                }
                if (!found) {
                    cout<<"khong tim thay id cua khach hang "<<endl;
                }
                break;
            }
            case 3: {
                individual a;
                a.input(individuals.size());
                individuals.push_back(a);
                break;
            }
            case 4: {
                int max=0;
                individual maxD = individuals.front();
                for (individual& d : individuals) {
                    if (d.max()>max) {
                        max=d.max();
                        maxD=d;
                    }
                }
                // khach hang max la Nguyen Van A, max = 12312

                maxD.output();
                break;
            }
            case 5: {
                int min;
                bool first = true;
                individual minD;
                for (individual& d : individuals) {
                    if (first) {
                        min = d.min();
                        minD = d;
                        first = false;
                    } else if (d.min() < min) {
                        min = d.min();
                        minD = d;
                    }
                }

                minD.output();
            }

            case 6: {
                break;
            }

            default: {
                cout<<"hay nhap lua chon cua ban tu 1 den 6"<<endl;
            }

        }
    }while(choice!=6);
}