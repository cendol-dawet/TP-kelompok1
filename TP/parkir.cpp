#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
using namespace std;
// Program parkir

struct Kendaraan
{
  string platNomor;
  string kode;
  string jenis;
  int waktu;
  bool penitipanHelm;
  bool kehilanganKarcis;
  bool member;
  bool sudahBayar; //diakhir
  int biaya; //diakhir
};

class Parkir
{
  private:
  int sloatAwalMotor = 50;
  int sloatAwalMobil = 50;
  string cPlat;
  string cKode;
  int jumlah = 4;
  Kendaraan kdr[100];
  public:

  void data()
  {
    kdr[0].platNomor = "AD 2183 CB";
    kdr[0].kode = "A101";
    kdr[0].jenis = "motor";
    kdr[0].waktu = 2;
    kdr[0].penitipanHelm = true;
    kdr[0].kehilanganKarcis = false;
    kdr[0].member = true;

    kdr[1].platNomor = "A 1945 SH";
    kdr[1].kode = "A102";
    kdr[1].jenis = "mobil";
    kdr[1].waktu = 10;
    kdr[1].penitipanHelm = false;
    kdr[1].kehilanganKarcis = true;
    kdr[1].member = true;

    kdr[2].platNomor = "B 2600 DSM";
    kdr[2].kode = "A103";
    kdr[2].jenis = "motor";
    kdr[2].waktu = 24;
    kdr[2].penitipanHelm = true;
    kdr[2].kehilanganKarcis = false;
    kdr[2].member = false;
    
    kdr[3].platNomor = "F 7437 UCK";
    kdr[3].kode = "A104";
    kdr[3].jenis = "motor";
    kdr[3].waktu = 5;
    kdr[3].penitipanHelm = false;
    kdr[3].kehilanganKarcis = true;
    kdr[3].member = true;


  }

  void tampilkanData()
  {

  }
  
  void login()
  {
    string user;
    string pw;
    cout << "Masukkan username : ";
    cin >> user;
    cout << "Masukkan password :";
    cin >> pw;
    if (user == "Admin" && pw == "123")
    {
      cout << "Login Berhasil!\n";
      menuAdmin();
    }

    else
    {
      cout << "Username atau Password salah!\n";
      cout << "Silahkan masukkan username atau password dengan benar\n" << endl;
      login();
    }

  }
  
  
  void cekKendaraan()
  {
    int pilihan;
    cout << "======== Menu Cek Kendaraan ==========\n";
    cout << "Pilih opsi berikut untuk mencari kendaraan: \n";
    cout << "1. Plat Nomor kendaraan\n";
    cout << "2. Kode karcis\n";
    cout << "0. Keluar\n";
    cout << "Silahkan masukkan pilihan anda: ";
    cin >> pilihan;

    switch (pilihan)
    {
      case 1:
        cekPlat();
        break;
      case 2:
        CekKarcis();
        break;
      case 0:
        return;
      default:
        cout << "Pilihan tidak valid!\n";
        cekKendaraan(); 
        break;
    }

  }
  
  void slotParkir()
  {
    int pilihan;
    cout << "==== MENU CEK SLOT ====\n";
    cout << "1. Cek Slot Motor\n";
    cout << "2. Cek Slot Mobil\n";
    cout << "0. Keluar\n";
    cout << "Masukkan pilihan : ";
    cin >> pilihan;
    
    switch (pilihan)
    {
    case 1:
      cout << "\n\n==== SLOT MOTOR ====\n";
      cout << "slot motor terpakai : ";
      cout << slotMotor();
      cout << "\nSlot motor tersedia : " << sloatAwalMotor - slotMotor() << endl << endl << endl;
      slotParkir();
      break;
      case 2:
      cout << "\n\n==== SLOT MOBIL ====\n";
      cout << "Slot mobil terpakai : ";
      cout << slotMobil();
      cout << "\nSlot mobil tersedia : " << sloatAwalMotor - slotMobil() << endl << endl << endl;
      slotParkir();
      break;
    case 0:
      menuAdmin();
      break;
    default:
      break;
    }
    
  }
  
  int slotMotor()
  {
    int motor = 0;
    for (int i = 0; i < jumlah; i++)
    {
      if (kdr[i].jenis == "motor")
      {
        motor++;
      }
      
    }
      return motor;
  }

  int slotMobil()
  {
    int mobil = 0;
    for (int i = 0; i < jumlah; i++)
    {
      if (kdr[i].jenis == "mobil")
      {
        mobil++;
      }
      
    }
      return mobil;
  }
  
  void cekPlat()
  {
    string ulang;
    bool status = false;

    cout << "Masukkan plat nomor: ";
    cin.ignore();
    getline(cin, cPlat); //ini bang
    for (int i = 0; i < jumlah; i++)
    {
      if (cPlat == kdr[i].platNomor)
      {
        cout << "\n======================================================================\n"; 
        cout << "Berikut detail kendaraanya, berdasarkan plat nomor: " << cPlat << endl;
        cout << "Plat nomor: " <<  kdr[i].platNomor << endl;
        cout << "Kode karcis: " <<  kdr[i].kode << endl;
        cout << "Jenis kendaraan: " <<  kdr[i].jenis << endl;
        cout << "\n======================================================================\n"; 
        status = true;
      }
      
    }

    if (status == false)
    {
      cout << "Kendaraan tidak ditemukan, pastikan anda memasukkan plat nomer yang sesuai\n";
    }

    cout << "Apkah anda ingin menggecek kendaraan yang lain? (ya/tidak): ";
    cin >> ulang;

    if (ulang == "ya")
    {
      cekPlat();
    }
    
    menuAdmin();
  }
  
  void CekKarcis()
  {
    string ulang;
    bool status = false;
    cout << "Masukkan Kode Karcis: ";
    cin >> cKode;
    for (int i = 0; i < jumlah; i++)
      {
      if (cKode == kdr[i].kode)
      {
        cout << "\n======================================================================\n"; 
        cout << "Berikut detail kendaraanya, berdasarkan plat nomor: " << cKode << endl;
        cout << "Plat nomor: " <<  kdr[i].platNomor << endl;
        cout << "Kode karcis: " <<  kdr[i].kode << endl;
        cout << "Jenis kendaraan: " <<  kdr[i].jenis << endl;
        cout << "\n======================================================================\n"; 
        status = true;

      }
      
    }
    if (status == false)
    {
      cout << "Kendaraan tidak ditemukan, pastikan anda memasukkan kode karcis yang sesuai\n";
    }
    cout << "Apkah anda ingin menggecek kendaraan yang lain? (ya/tidak): ";
    cin >> ulang;
    if (ulang == "ya")
    {
      CekKarcis();
    }
    
    menuAdmin();
  }
  
  void hilangKarcis()
  {
    cout << "";
  }

  void member()
  {
    cout << "Apakah kendaraan pelanggan memliki member? (y/n)\n";
    
  }
  
  void pembayaran()
  {
    
  }

  void penghapusanData()
  {
    
  } 
  
  void laporanPemasukan()
  {
    
  }

  void menuAdmin()
  {
    int pilihan;
    cout << "\n=== Menu Admin ===\n";
    cout << "1. Cek kendaraan\n";    
    cout << "2. Cek Slot Parkir\n";    
    cout << "3. Hitung transaksi parkir\n";
    cout << "4. Cek laporan pemasukan\n";
    cout << "0. Keluar\n";

    cout << "Masukkan pilihan sesuai nomor yang tertera: ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
      cekKendaraan();
    break;
    case 2:
      slotParkir();
    break;
    case 3:
      pembayaran();   
    break;
    case 4:
      laporanPemasukan();
    break;
    case 0:
      alur();
      break;

    default:
      cout << "Pilihan tidak valid\n";
      break;
    }
    
  }

  void alur()
  {
    int pilihan;
    data();
    cout << "==== MENU LOGIN ====\n";
    cout << "1. Admin\n";
    cout << "0. Keluar\n";
    cout << "Silahkan pilih 1 jika ingin lanjut login, silahkan pilih 0 jika tidak jadi login: ";
    cin >> pilihan;

    if (pilihan == 1)
    {
      login();
      menuAdmin();
    }
    else if (pilihan != 0 && pilihan != 1)
    {
      cout << "Pilihan tidak valid\n";
      alur();
    }
    else 
    {
      cout << "Selesai.....";
      exit(0);
    }
  }
};

int main()
{
  Parkir pkr;
  pkr.alur();


  return 0;
}
