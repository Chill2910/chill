#include"ThuVien.h"
void khoiTao(staff& list)
{
	list = NULL;
}
int isEmpTy(staff list)
{
	return list == NULL ? 1 : 0;
}
void giaiPhong(staff& list)
{
	staff p = list;
	while (p != NULL)
	{
		list = list->link;
		delete p;
		p = list;
	}
}
staff taoNodeNhanVien(Thongtinnhanvien x)
{
	staff p;
	p = new nhanvien;
	p->data = x;
	p->link = NULL;
	return p;
}
staff themDau(staff& list, Thongtinnhanvien x)
{
	staff p = taoNodeNhanVien(x);
	p->link = list;
	list = p;
	return p;
}
bool kiemtra_Trung(staff& list, const char* ma)
{
	staff p = list;
	while (p != NULL)
	{
		if (strcmp(p->data.manv, ma) == 0)
			return true;
		p = p->link;
	}
	return false;
}
void nhapThongtinnhanvien(staff& list)
{
	Thongtinnhanvien nv;
	do {
		cout << "Nhap ma nhan vien: ";
		cin >> nv.manv;
		if (kiemtra_Trung(list, nv.manv))
			cout << "Ma nhan vien da ton tai!" << endl;
	} while (kiemtra_Trung(list, nv.manv) != 0);
	cin.ignore();
	cout << "Nhap ho ten nhan vien: ";
	cin.getline(nv.hoten, 50);
	cout << "Nhap chuc vu: ";
	cin.getline(nv.chucvu, 10);
	cout << "Nhap luong: ";
	cin >> nv.luong;
	cout << "Nhap so dien thoai: ";
	cin >> nv.sdt;
	cin.ignore();
	cout << "Nhap so CCCD: ";
	cin >> nv.scccd;
	cin.ignore();
	cout << "Nhap dia chi: ";
	cin.getline(nv.diachi, 100);
	themDau(list, nv);
	cout << "Nhan vien da duoc them." << endl;
}
void xuatThongtinmotnhanvien(staff list)
{
	cout << left << setw(10) << "Ma NV"
		<< setw(20) << "Ho Ten"
		<< setw(10) << "Chuc Vu"
		<< setw(15) << "Luong"
		<< setw(15) << "So Dien Thoai"
		<< setw(20) << "CCCD"
		<< "Dia Chi" << endl;
	cout << left << setw(10) << list->data.manv
		<< setw(20) << list->data.hoten
		<< setw(10) << list->data.chucvu
		<< setw(15) << list->data.luong
		<< setw(15) << list->data.sdt
		<< setw(20) << list->data.scccd
		<< list->data.diachi << endl;
}
void xuatThongtinnhanvien(staff list)
{
	cout << left << setw(10) << "Ma NV"
		<< setw(25) << "Ho Ten"
		<< setw(10) << "Chuc Vu"
		<< setw(15) << "Luong"
		<< setw(15) << "So Dien Thoai"
		<< setw(20) << "CCCD"
		<< "Dia Chi" << endl;
	while (list != NULL) {
		cout << left << setw(10) << list->data.manv
			<< setw(25) << list->data.hoten
			<< setw(10) << list->data.chucvu
			<< setw(15) << list->data.luong
			<< setw(15) << list->data.sdt
			<< setw(20) << list->data.scccd
			<< list->data.diachi << endl;
		list = list->link;
	}
}
bool suaThongTinNhanVien(staff& list, const char* ma) {
	staff p = list;
	while (p != NULL) {
		if (strcmp(p->data.manv, ma) == 0) {
			cout << "Nhap thong tin moi cho nhan vien " << ma << ":" << endl;
			cout << "Nhap ho ten nhan vien: ";
			cin.getline(p->data.hoten, 50);
			cout << "Nhap chuc vu: ";
			cin.getline(p->data.chucvu, 10);
			cout << "Nhap luong: ";
			cin >> p->data.luong;
			cout << "Nhap so dien thoai: ";
			cin >> p->data.sdt;
			cout << "Nhap so CCCD: ";
			cin >> p->data.scccd;
			cin.ignore();
			cout << "Nhap dia chi: ";
			cin.getline(p->data.diachi, 100);
			cout << "Thong tin nhan vien da duoc cap nhat." << endl;
			return true;
		}
		p = p->link;
	}
	cout << "Khong tim thay nhan vien voi ma: " << ma << endl;
	return false;
}
bool xoaNhanVien(staff& list, const char* ma) {
	if (isEmpTy(list)) {
		cout << "Danh sach nhan vien rong." << endl;
		return false;
	}
	staff p = list, prev = NULL;
	while (p != NULL) {
		if (strcmp(p->data.manv, ma) == 0) {
			if (prev == NULL) {
				list = p->link;
			}
			else {
				prev->link = p->link;
			}

			delete p;
			cout << "Nhan vien voi ma " << ma << " da bi xoa." << endl;
			return true;
		}
		prev = p;
		p = p->link;
	}
	cout << "Khong tim thay nhan vien voi ma: " << ma << endl;
	return false;
}
void timThongTinNhanVienTheoMa(staff list, const char* ma) {
	staff p = list;
	while (p != NULL) {
		if (strcmp(p->data.manv, ma) == 0) {
			xuatThongtinmotnhanvien(p);
			return;
		}
		p = p->link;
	}
	cout << "Khong tim thay nhan vien voi ma: " << ma << endl;
}
void timThongTinNhanVienTheoTen(staff list, const char* ten)
{
	if (isEmpTy(list))
	{
		cout << "Danh sach nhan vien rong!" << endl;
	}
	while (list != NULL)
	{
		if (strcmp(list->data.hoten, ten) == 0)
			xuatThongtinmotnhanvien(list);
		list = list->link;
	}
	if (list == NULL)
		cout << "Khong tim thay nhan vien!" << endl;
}
void timThongTinNhanVienTheoChucVu(staff list, const char* chucvu)
{
	if (isEmpTy(list))
	{
		cout << "Danh sach nhan vien rong!" << endl;
	}
	while (list != NULL)
	{
		if (strcmp(list->data.chucvu, chucvu) == 0)
			xuatThongtinmotnhanvien(list);
		list = list->link;
	}
	if (list == NULL)
		cout << "Khong tim thay nhan vien!";
}
void luuFileTxt(staff list, const char* filename) {
	ofstream file(filename);
	if (!file) {
		cout << "Khong the mo file!" << endl;
		return;
	}
	file << left << setw(10) << "Ma NV" << setw(20) << "Ho Ten" << setw(10) << "Chuc Vu"
		<< setw(15) << "Luong" << setw(15) << "So Dien Thoai" << setw(20) << "CCCD" << "Dia Chi" << endl;
	staff p = list;
	while (p != NULL) {
		file << left << setw(10) << p->data.manv << setw(20) << p->data.hoten << setw(10) << p->data.chucvu
			<< setw(15) << p->data.luong << setw(15) << p->data.sdt << setw(20) << p->data.scccd
			<< p->data.diachi << endl;
		p = p->link;
	}
	file.close();
	cout << "Da luu danh sach nhan vien vao file!" << endl;
}
void docFileTxt(staff& list, const char* filename) {
	ifstream file(filename);
	if (!file) {
		cout << "Khong the mo file!" << endl;
		return;
	}
	string line;
	getline(file, line);
	while (getline(file, line)) {
		Thongtinnhanvien nv;
		stringstream ss(line);
		string temp;
		ss >> setw(10) >> nv.manv;
		ss >> setw(20) >> nv.hoten;
		ss >> setw(10) >> nv.chucvu;
		ss >> setw(15) >> nv.luong;
		ss >> setw(15) >> nv.sdt;
		ss >> setw(20) >> nv.scccd;
		ss.ignore();
		getline(ss, temp);
		strcpy(nv.diachi, temp.c_str());
		themDau(list, nv);
	}
	file.close();
	cout << "Da doc danh sach nhan vien tu file!" << endl;
}