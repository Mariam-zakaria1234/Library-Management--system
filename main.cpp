#include <iostream>
#include <string>

using namespace std;

// المخازن (بيانات المكتبة)
string book_names[100];
string book_authors[100];
bool is_available[100];
int total_books = 0;

// فانكشن المساعد: بتدور على مكان الكتاب في الجدول
int find_index(string name) {
    for (int i = 0; i < total_books; i++) {
        if (book_names[i] == name) return i;
    }
    return -1; // لو مش موجود
}

// 1. إضافة كتاب
void add_book() {
    if (total_books >= 100) {
        cout << "Library is full!" << endl;
        return;
    }
    cout << "Enter book title: ";
    getline(cin, book_names[total_books]);
    cout << "Enter author: ";
    getline(cin, book_authors[total_books]);
    is_available[total_books] = true;
    total_books++;
    cout << "Success! Book added." << endl;
}

// 2. البحث عن كتاب
void search_book() {
    string name;
    cout << "Enter book name to search: ";
    getline(cin, name);
    int idx = find_index(name);
    if (idx == -1) {
        cout << "Book not found!" << endl;
    }
    else {
        cout << "Found: " << book_names[idx] << " by " << book_authors[idx];
        cout << (is_available[idx] ? " [Available]" : " [Borrowed]") << endl;
    }
}

// 3. استعارة كتاب
void borrow_book() {
    string name;
    cout << "Enter book name to borrow: ";
    getline(cin, name);
    int idx = find_index(name);
    if (idx == -1) cout << "We don't have this book!" << endl;
    else if (!is_available[idx]) cout << "Sorry, it's already borrowed." << endl;
    else {
        is_available[idx] = false;
        cout << "Done! You can take it now." << endl;
    }
}

// 4. إرجاع كتاب
void return_book() {
    string name;
    cout << "Enter book name to return: ";
    getline(cin, name);
    int idx = find_index(name);
    if (idx == -1) cout << "This book doesn't belong to us!" << endl;
    else {
        is_available[idx] = true;
        cout << "Thank you! The book is back." << endl;
    }
}

// 5. عرض كل الكتب
void show_all() {
    if (total_books == 0) {
        cout << "Library is empty." << endl;
        
    }
    cout << "\n--- Current Books List ---" << endl;
    for (int i = 0; i < total_books; i++) {
        cout << i + 1 << ". " << book_names[i] << " | " << (is_available[i] ? "Available" : "Borrowed") << endl;
    }
}

int main() {
    int user_choice;
    while (true) {
        cout << "\n1.Add | 2.Search | 3.Borrow | 4.Return | 5.Show All | 6.Exit" << endl;
        cout << "Select option: ";
        cin >> user_choice;
        cin.ignore();     

        if (user_choice == 1) add_book();
        else if (user_choice == 2) search_book();
        else if (user_choice == 3) borrow_book();
        else if (user_choice == 4) return_book();
        else if (user_choice == 5) show_all();
        else if (user_choice == 6) {
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid selection!" << endl;
        }
    }
    return 0;
}
