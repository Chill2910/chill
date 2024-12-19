#include"ThuVien.h"
int n = 1;
bool isInteger(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c) && c != '-')
            return false;
    }
    return true;
}
void main()
{
	staff dsnv{};
    int n = 1;
    khoiTao(dsnv);
    while (n != 0)
    {
        system("cls");
        cout << "\n=================NHAN VIEN================\n";
        cout << "1. Doc danh sach nhan vien tu file" << endl;
        cout << "2. Them nhan vien" << endl;
        cout << "3. Sua thong tin nhan vien" << endl;
        cout << "4. Xoa nhan vien" << endl;
        cout << "5. Tim kiem nhan vien" << endl;
        cout << "6. Xem danh sach nhan vien" << endl;
        cout << "7. Luu danh sach nhan vien" << endl;
        cout << "0. Thoat" << endl;
        cout << "Chon chuc nang: ";
        cin >> n;
        cout << endl;
        switch (n)
        {
            case 0:
               break;
            case 1:
                docFileTxt(dsnv, "DanhSachNhanVien.txt");
                system("pause");
                break;  
            case 2:
                nhapThongtinnhanvien(dsnv);
                system("pause");
                break;
            case 3: 
                char ma[10];
                cin.ignore();
                cout << "Nhap ma nhan vien can sua: ";
                cin.getline(ma, 10);
                if (suaThongTinNhanVien(dsnv, ma)) {
                    cout << "Sua thong tin nhan vien thanh cong!" << endl;
                }
                else {
                    cout << "Khong tim thay nhan vien!" << endl;
                }
                system("pause");
                break;
            case 4:
                cin.ignore();
                cout << "Nhap ma nhan vien can xoa: ";
                cin.getline(ma, 10);
                if (xoaNhanVien(dsnv, ma))
                    cout << "Xoa thong tin nhan vien thanh cong!" << endl;
                else
                    cout << "Khong tim thay nhan vien" << endl;
                system("pause");
                break;
            case 5:
            {
                system("cls");
                string c;
                int m;
                do
                {
                    cout << "Ban muon tim nhan vien theo:" << endl;
                    cout << "1.Ma nhan vien." << endl;
                    cout << "2.Ho va ten nhan vien." << endl;
                    cout << "3.Chuc vu." << endl;
                    cout << "0.Thoat" << endl;
                    while (true) {
                        cin >> c;
                        if (isInteger(c)) {
                            try {
                                m = stoi(c);
                                break;
                            }
                            catch (const out_of_range&) {
                                m = 7;
                                break;
                            }
                        }
                        else {
                            m = 7;
                            break;
                        }
                    }
                    switch (m)
                    {
                    case 1:
                        cin.ignore();
                        cout << "Hay nhap ma nhan vien:" << endl;
                        cin >> ma;
                        cin.ignore();
                        timThongTinNhanVienTheoMa(dsnv, ma);
                        break;
                    case 2:
                        cin.ignore();
                        char ten[50];
                        cout << "Hay nhap ten nhan vien:" << endl;
                        cin.getline(ten, 50);
                        timThongTinNhanVienTheoTen(dsnv, ten);
                        break;
                    case 3:
                        cin.ignore();
                        char chucvu[10];
                        cout << "Hay nhap chuc vu:" << endl;
                        cin.getline(chucvu, 10);
                        timThongTinNhanVienTheoChucVu(dsnv, chucvu);
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Vui long chon lai!" << endl;
                    }
                    system("pause");
                    system("cls");
                } while (m != 0);
                break;
            }
            case 6:
                xuatThongtinnhanvien(dsnv);
                system("pause");
                break;
            case 7:
                luuFileTxt(dsnv, "DanhSachNhanVien.txt");
                system("pause");
            default:
                break;
        }
    };
}