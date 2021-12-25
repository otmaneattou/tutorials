#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_BOOKS = 10;
const int MAX_USERS = 10;

// Methods to manage queries
class Book
{
public:
    int id;
    string name;
    int quantity;
    int total_borrowed;

    // Constructor
    Book()
    {
        quantity = total_borrowed = 0;
        id = -1;
        name = "";
    }

    void read()
    {
        cout << "Enter book info" << endl;
        cout << "id: ";
        cin >> id;
        cout << "name: ";
        cin >> name;
        // std::getline(std::cin, name);
        cout << "total quantity: ";
        cin >> quantity;
        cout << endl;
        total_borrowed = 0;
    }

    bool borrow(int user_id)
    {
        if (quantity - total_borrowed == 0)
            return false;
        ++total_borrowed;
        return true;
    }

    void return_copy()
    {
        if (total_borrowed > 0)
            --total_borrowed;
    }

    bool has_prefix(string prefix)
    {
        if (name.size() < prefix.size())
            return false;

        for (int i{0}; i < (int)prefix.size(); ++i)
        {
            if (prefix[i] != name[i])
                return false;
        }
        return true;
    }

    void print()
    {
        cout << "id = " << id << ",name = " << name
             << ",total quantity " << quantity << ", total borrowed "
             << total_borrowed << endl;
    }
};

bool cmp_book_by_name(Book &a, Book &b)
{
    return a.name < b.name;
}

bool cmp_book_by_id(Book &a, Book &b)
{
    return a.id < b.id;
}

class User
{
public:
    int id;
    string name;
    int borrowed_books_ids[MAX_BOOKS];
    int len;

    // Constructor
    User()
    {
        name = "";
        len = 0;
        id = -1;
    }

    void read()
    {
        cout << "Enter user name and id : ";
        cin >> name >> id;
        /*
        cout << "Enter your id: ";
        cin >> id;
        */
    }

    void borrow(int book_id)
    {
        borrowed_books_ids[len++] = book_id;
    }

    void return_copy(int book_id)
    {
        bool removed = false;
        for (int i{0}; i < len; ++i)
        {
            if (borrowed_books_ids[i] == book_id)
            {
                // Let's shift the array to the right
                // to remove this entry
                for (int j{i + 1}; j < len; ++j)
                    borrowed_books_ids[j - 1] = borrowed_books_ids[j];
                removed = true;
                --len;
                break;
            }
        }
        if (!removed)
            cout << "User " << name << " never borrowed book id"
                 << book_id << endl;
    }

    bool is_borrowed(int book_id)
    {
        for (int i{0}; i < len; ++i)
        {
            if (book_id == borrowed_books_ids[i])
                return true;
        }
        return false;
    }

    void print()
    {
        // sort what he borrowed
        sort(borrowed_books_ids, borrowed_books_ids + len);
        cout << "User: " << name << ", id: " << id << ", borrowed books ids: ";
        for (int i{0}; i < len; ++i)
            cout << borrowed_books_ids[i] << " ";
        cout << endl;
    }
};

class Library_system
{
public:
    int total_books;
    Book books[MAX_BOOKS];
    int total_users;
    User users[MAX_USERS];

    Library_system()
    {
        total_books = total_users = 0;
    }

    void run()
    {
        while (true)
        {
            int choice = menu();
            switch (choice)
            {
            case 1:
                add_book();
                break;
            case 2:
                search_book_by_prefix();
                break;
            case 3:
                print_who_borrowed_book_by_name();
                break;
            case 4:
                print_library_by_id();
                break;
            case 5:
                print_library_by_name();
                break;
            case 6:
                add_user();
                break;
            case 7:
                user_borrow_book();
                break;
            case 8:
                user_return_book();
                break;
            case 9:
                print_users();
                break;
            case 10:
                return;
            }
        }
    }

    // For users
    int menu()
    {
        int choice{-1};
        while (choice == -1)
        {
            cout << "Library Menu" << endl;
            cout << "1) Add book" << endl;
            cout << "2) Search books by prefix" << endl;
            cout << "3) Print who borrowed book by name" << endl;
            cout << "4) Print library by id" << endl;
            cout << "5) Print library by name" << endl;
            cout << "6) Add user" << endl;
            cout << "7) User borrow book" << endl;
            cout << "8) User return book" << endl;
            cout << "9) Print users" << endl;
            cout << "10) Exit" << endl
                 << endl;

            cout << "Enter your choice [1-10]: ";
            cin >> choice;
            cout << endl;

            if (!(choice <= 10 && choice >= 1))
            {
                cout << "Invalid choice. Try again" << endl;
                choice = -1;
            }
        }

        return choice;
    }

    void add_book()
    {
        books[total_books++].read();
    }

    void search_book_by_prefix()
    {
        cout << "Enter book name prefix: ";
        string prefix;
        cin >> prefix;

        int cnt{0};
        for (int i{0}; i < total_books; ++i)
        {
            if (books[i].has_prefix(prefix))
            {
                cout << books[i].name << endl;
                ++cnt;
            }
        }

        if (!cnt)
            cout << "No books with such prefix" << endl;
    }

    int find_book_idx_by_name(string name)
    {
        for (int i{0}; i < total_books; ++i)
        {
            if (name == books[i].name)
                return i;
        }
        return -1;
    }

    int find_user_idx_by_name(string name)
    {
        for (int i{0}; i < total_users; ++i)
        {
            if (name == users[i].name)
                return i;
        }
        return -1;
    }

    bool read_user_name_and_book_name(int &user_idx,
                                      int &book_idx,
                                      int trials = 3)
    {
        string user_name;
        string book_name;
        while (trials--)
        {
            cout << "Enter user name: ";
            cin >> user_name;
            cout << endl
                 << "Enter book name: ";
            cin >> book_name;
            cout << endl;

            user_idx = find_user_idx_by_name(user_name);

            if (user_idx == -1)
            {
                cout << "Invalid user name. Try again \n";
                continue;
            }

            book_idx = find_book_idx_by_name(book_name);

            if (book_idx == -1)
            {
                cout << "Invalid book name. Try again \n";
                continue;
            }
            return true;
        }
        cout << "You did several trials! Try later.";
        return false;
    }
    void add_user()
    {
        users[total_users++].read();
    }
    void user_borrow_book()
    {
        int user_idx, book_idx;

        if (!read_user_name_and_book_name(user_idx, book_idx))
            return;

        int user_id = users[user_idx].id;
        int book_id = books[book_idx].id;

        if (!books[book_idx].borrow(user_id))
            cout << "No more copies available right now \n";
        else
            users[user_idx].borrow(book_id);
    }

    void user_return_book()
    {
        int user_idx, book_idx;

        if (!read_user_name_and_book_name(user_idx, book_idx))
            return;

        int book_id = books[book_idx].id;
        books[book_idx].return_copy();
        users[user_idx].return_copy(book_id);
    }

    void print_library_by_id()
    {
        sort(books, books + total_books, cmp_book_by_id);
        cout << endl;
        for (int i{0}; i < total_books; i++)
            books[i].print();
        cout << endl;
    }

    void print_library_by_name()
    {
        sort(books, books + total_books, cmp_book_by_name);
        cout << endl;
        for (int i{0}; i < total_books; ++i)
            books[i].print();
        cout << endl;
    }

    void print_users()
    {
        cout << endl;
        for (int i{0}; i < total_users; ++i)
            users[i].print();
    }

    void print_who_borrowed_book_by_name()
    {
        string book_name;
        cout << "Enter book name: ";
        cin >> book_name;

        int book_idx = find_book_idx_by_name(book_name);

        if (book_idx == -1)
        {
            cout << "Invalid book name." << endl;
            return;
        }
        int book_id = books[book_idx].id;
        if (books[book_idx].total_borrowed == 0)
        {
            cout << "No borowwed copies \n";
            return;
        }

        for (int i{0}; i < total_users; ++i)
        {
            if (users[i].is_borrowed(book_id))
                cout << users[i].name << endl;
        }
    }
};

int main(int argc, const char **argv)
{
    Library_system library;
    library.run();
    return 0;
}