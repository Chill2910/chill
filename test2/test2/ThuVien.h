#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include <stdexcept>
#include <fstream>
#include<sstream>
using namespace std;

typedef struct nhanvien* staff;
struct Thongtinnhanvien
{
	char manv[10];
	char hoten[50];
	char chucvu[10];
	char luong[10];
	char sdt[15];
	char scccd[20];
	char diachi[100];
};
struct nhanvien
{
	Thongtinnhanvien data;
	staff link;
};
void khoiTao(staff& list);
int isEmpTy(staff list);
void giaiPhong(staff& list);
staff taoNodeNhanVien(Thongtinnhanvien x);
staff themDau(staff& list, Thongtinnhanvien x);
bool kiemtra_Trung(staff& list,const char* ma);
void nhapThongtinnhanvien(staff& list);
void xuatThongtinnhanvien(staff list);
void xuatThongtinmotnhanvien(staff list);
bool suaThongTinNhanVien(staff& list, const char* ma);
bool xoaNhanVien(staff& list, const char* ma);
void timThongTinNhanVienTheoMa(staff list, const char* ma);
void timThongTinNhanVienTheoTen(staff list, const char* ten);
void timThongTinNhanVienTheoChucVu(staff list, const char* chucvu);
void luuFileTxt(staff list, const char* filename);
void docFileTxt(staff& list, const char* filename);