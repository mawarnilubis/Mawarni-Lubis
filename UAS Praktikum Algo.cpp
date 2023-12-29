/*  Nama     : Mawarni Lubis
    NIM      : 23343009
    Matkul   : Praktikum Algoritma  */

#include <iostream>
#include <string>

using namespace std;

class ATM {
private:
    float saldo;
    string pin;

public:
    ATM() : saldo(100000.00), pin("1234") {}

    void cekSaldo() {
        cout << "Saldo Anda : Rp." << saldo << endl;
    }

    void tarikUang() {
        float jumlah;
        cout << "Masukkan jumlah yang ingin ditarik : Rp.";
        cin >> jumlah;

        if (jumlah > saldo) {
            cout << "Saldo anda tidak mencukupi.\n";
        } else {
            saldo -= jumlah;
            cout << "Penarikan sukses! Saldo anda sekarang : Rp." << saldo << endl;
        }
    }

    void setorUang() {
        float jumlah;
        cout << "Masukkan jumlah yang ingin disetor : Rp.";
        cin >> jumlah;

        saldo += jumlah;
        cout << "Penyetoran sukses! Saldo anda sekarang : Rp." << saldo << endl;
    }

    void transferUang() {
        float jumlah;
        string rekTujuan;

        cout << "Masukkan nomor rekening tujuan : ";
        cin >> rekTujuan;

        cout << "Masukkan jumlah yang ingin ditransfer : Rp.";
        cin >> jumlah;

        if (jumlah > saldo) {
            cout << "Saldo anda tidak mencukupi.\n";
        } else {
            saldo -= jumlah;
            cout << "Transfer sukses ke rekening " << rekTujuan << "! Saldo anda sekarang : Rp." << saldo << endl;
        }
    }

    bool cekPin(string inputPin) {
        return pin == inputPin;
    }
};

int main() {
    ATM atm;
    string pin;
    int pilihan;

    do {
        cout << "Selamat datang di mesin ATM!\n";
        cout << "Masukkan PIN anda : ";
        cin >> pin;

        if (!atm.cekPin(pin)) {
            cout << "PIN yang anda masukkan salah. Silahkan coba lagi.\n" << endl;
        }

    } while (!atm.cekPin(pin));

    do {
        cout << "\n===== Menu =====\n";
        cout << "1. Cek Saldo\n";
        cout << "2. Tarik Uang\n";
        cout << "3. Setor Uang\n";
        cout << "4. Transfer Uang\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                atm.cekSaldo();
                break;
            case 2:
                atm.tarikUang();
                break;
            case 3:
                atm.setorUang();
                break;
            case 4:
                atm.transferUang();
                break;
            case 5:
                cout << "Terimakasih telah menggunakan mesin ATM ini. Selamat tinggal!\n";
                break;
            default:
                cout << "Pilihan anda tidak Valid.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}
