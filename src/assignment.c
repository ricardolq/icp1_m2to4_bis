#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the book struct
/**
 * @struct Book
 * @brief Represents a book in a linked list.
 *
 * This structure is used to store information about a book, including its title,
 * author, year of publication, and a pointer to the next book in the list.
 *
 * @var Book::title
 * The title of the book, stored as a character array with a maximum length of 50.
 *
 * @var Book::author
 * The author of the book, stored as a character array with a maximum length of 50.
 *
 * @var Book::year
 * The year the book was published, stored as an integer.
 *
 * @var Book::next
 * A pointer to the next book in the linked list. If this is the last book in the
 * list, the pointer will be NULL.
 */
typedef struct Book {
    char title[50];
    char author[50];
    int year;
    struct Book *next; // Pointer to the next book in the list
} Book;

// Function prototypes
/**
 * @brief Creates an empty library by initializing a linked list of books and saving it to a file.
 * 
 * @param filename The name of the file where the library data will be stored.
 * @param head A pointer to the head of the linked list of books. This will be initialized to NULL.
 * @return int Returns 0 on success, or a non-zero error code on failure.
 */
int createEmptyLibrary(const char *filename, Book **head);

/**
 * @brief Loads a library of books from a file and populates a linked list.
 *
 * This function reads book data from the specified file and creates a linked
 * list of Book structures. The head of the linked list is updated to point
 * to the first book in the list.
 *
 * @param filename The path to the file containing the book data.
 * @param head A pointer to the pointer of the head of the linked list. This
 *             will be updated to point to the first book in the list.
 * @return An integer indicating the success or failure of the operation.
 *         Typically, 0 for success and a non-zero value for failure.
 */
int loadLibrary(const char *filename, Book **head);


/**
 * @brief Saves the library data to a file.
 *
 * This function writes the details of all books in the library to the specified file.
 * The data is saved in a format that can be read back later to restore the library.
 *
 * @param filename The name of the file where the library data will be saved.
 *                 It should be a valid file path.
 * @param head A pointer to the head of the linked list of books.
 *             Each node in the list represents a book in the library.
 *
 * @return An integer indicating the success or failure of the operation.
 *         Returns 0 on success, or a non-zero value if an error occurs
 *         (e.g., file cannot be opened or written to).
 */
int saveLibrary(const char *filename, Book *head);

/**
 * @brief Searches for a book in the library by its title.
 *
 * This function traverses the linked list of books and checks if a book
 * with the specified title exists. If found, it returns a pointer to the
 * corresponding Book structure; otherwise, it returns NULL.
 *
 * @param head A pointer to the head of the linked list of books.
 * @param title The title of the book to search for.
 * @return A pointer to the Book structure if found, or NULL if not found.
 */
Book* searchBook(Book *head, const char *title);

/**
 * @brief Adds a new book to the library.
 *
 * This function creates a new Book structure and adds it to the beginning
 * of the linked list of books. The head pointer is updated to point to the
 * new book.
 *
 * @param head A pointer to the pointer of the head of the linked list.
 * @param newBook The Book structure containing the details of the new book.
 */
void addBook(Book **head, Book newBook);

/**
 * @brief Removes a book from the library by its title.
 *
 * This function searches for a book with the specified title in the linked
 * list and removes it from the list. The head pointer is updated if the
 * removed book was the first in the list.
 *
 * @param head A pointer to the pointer of the head of the linked list.
 * @param title The title of the book to remove.
 * @return An integer indicating success (0) or failure (-1).
 */
int removeBook(Book **head, const char *title);

/**
 * @brief Lists all the books in the linked list.
 * 
 * This function traverses the linked list of books starting from the given head
 * and displays the details of each book in the list.
 * 
 * @param head Pointer to the head of the linked list of books.
 */
void listBooks(Book *head);

/**
 * @brief Frees the memory allocated for the linked list of books.
 *
 * This function traverses the linked list and frees the memory allocated
 * for each Book structure. It is important to call this function to avoid
 * memory leaks when the library is no longer needed.
 *
 * @param head A pointer to the head of the linked list of books.
 */
void freeLibrary(Book *head);

// Function implementations
int createEmptyLibrary(const char *filename, Book **head) {
    FILE *file = fopen(filename, "wb");
    if (!file) return -1;
    int numBooks = 0;
    fwrite(&numBooks, sizeof(int), 1, file);
    fclose(file);
    *head = NULL; // Initialize the linked list as empty
    return 0;
}

int loadLibrary(const char *filename, Book **head) {
    return 0;
}

int saveLibrary(const char *filename, Book *head) {
    return 0;
}

Book* searchBook(Book *head, const char *title) {
    return NULL;
}

void addBook(Book **head, Book newBook) {
    return;
}

int removeBook(Book **head, const char *title) {
    return 0;
}

void listBooks(Book *head) {
    return;
}

void freeLibrary(Book *head) {
    return;
}

#ifdef NDEBUG
int main() {
    Book *library = NULL;
    char title[50];

    if (loadLibrary("library.txt", &library) == -1) {
        printf("Library file not found. Creating a new library.\n");
        if (createEmptyLibrary("library.txt", &library) == -1) {
            printf("Error creating new library.\n");
            return -1;
        }
    }

    Book newBook;
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. List Books\n");
        printf("4. Search Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                scanf("%s", newBook.title);
                printf("Enter book author: ");
                scanf("%s", newBook.author);
                printf("Enter book year: ");
                scanf("%d", &newBook.year);
                addBook(&library, newBook);
                break;
            case 2:
                printf("Enter book title to remove: ");
                scanf("%s", title);
                if (removeBook(&library, title) == -1) {
                    printf("Book not found.\n");
                }
                break;
            case 3:
                listBooks(library);
                break;
            case 4:
                printf("Enter book title to search: ");
                scanf("%s", title);
                Book *foundBook = searchBook(library, title);
                if (foundBook) {
                    printf("Book found: %s by %s, published in %d\n", foundBook->title, foundBook->author, foundBook->year);
                } else {
                    printf("Book not found.\n");
                }
                break;
            case 5:
                saveLibrary("library.txt", library);
                freeLibrary(library);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
#endif
