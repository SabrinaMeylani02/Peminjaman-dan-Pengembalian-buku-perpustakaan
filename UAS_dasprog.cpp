#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<string> menus{
  "Peminjaman","Pengembalian", "Keluar",
};

vector<string> books{
  "Akidah Akhlak",
  "Arsitektur & Organisasi Komputer",
  "Bahasa Asing",
  "Dasar Pemrograman",
  "Literasi Digital & Etika Teknologi",
  "Logika Informatika",
  "Pendidikan Pancasila",
  "Pengantar Teknologi Informasi",
};

vector<string> borrowedBooks;

void successMessage(string bookTitle, int numberMenu) {
  cout << "Selamat! Anda telah " << (numberMenu == 1 ? "mengembalikan" : "meminjam") << bookTitle << "\n\n";
}

int main() {
  int numberMenu, numberBook;
  char repeat;

  menu:
    cout << "================ Perpustakaan ================\n";
    cout << "Buku yang dipinjam : " << borrowedBooks.size() << "\n\n";

    for (int i = 0; i < menus.size(); i++) {
      cout << i + 1 << ". " << menus[i] << "\n";
    }

    cout << "\nPilih menu (1 - " << menus.size() << ") : ";
    cin >> numberMenu;

    system("cls");

    switch (numberMenu) {
      case 1:
        returnedBook:
          cout << "======== " << menus[numberMenu - 1] << " Buku ========\n\n";

          for (int i = 0; i < books.size(); i++) {
            cout << i + 1 << ". " << books[i] << "\n";
          }

          cout << "\nPilih buku (1 - " << books.size() << ") : ";
          cin >> numberBook;

          system("cls");

          if (numberBook > 0 && numberBook <= books.size()) {
            borrowedBooks.push_back(books[numberBook - 1]);
            successMessage(books[numberBook - 1], numberMenu);
            books.erase(books.begin() + (numberBook - 1));

            cout << "Apakah ingin meminjam buku yang lain? (y/t) : ";
            cin >> repeat;

            system("cls");

            if (repeat == 'y') goto returnedBook;
            else goto menu;
          } else {
            goto returnedBook;
          }
        break;
      case 2:
        borrowedBook:
          if (borrowedBooks.size() > 0) {
            cout << "======== " << menus[numberMenu - 1] << " Buku ========\n\n";
            for (int i = 0; i < borrowedBooks.size(); i++) {
              cout << i + 1 << ". " << borrowedBooks[i] << "\n";
            }

            cout << "\nPilih buku (1 - " << borrowedBooks.size() << ") : ";
            cin >> numberBook;

            system("cls");

              if (numberBook > 0 && numberBook <= borrowedBooks.size()) {
                books.push_back(borrowedBooks[numberBook - 1]);
                successMessage(borrowedBooks[numberBook - 1], numberMenu);
                borrowedBooks.erase(borrowedBooks.begin() + (numberBook - 1));

                cout << "Apakah ingin mengembalikan buku yang lain? (y/t) : ";
                cin >> repeat;

                system("cls");

                if (repeat == 'y') goto borrowedBook;
                else goto menu;
              } else {
                goto borrowedBook;
              }

            system("cls");
          } else {
            goto menu;
          }
        break;
      case 3:
        abort();
        break;
      default:
        goto menu;
        break;
    }
}
