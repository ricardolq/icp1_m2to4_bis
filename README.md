# Assignment: Building and Managing a Library System

## Objective
Implement a library management system that allows users to manage a collection of books. The program should include the following functionalities:
- Creating a new library.
- Loading and saving the library to/from a file.
- Adding, removing, searching, and listing books in the library.

## Description
You are provided with a program outline for a library system that includes function prototypes but lacks the actual implementations. Your assignment is to:

### Define the Book Structure
A `Book` should contain:
- **Title**: A string (up to 50 characters).
- **Author**: A string (up to 50 characters).
- **Publication Year**: An integer.

### Implement the Following Functions
1. **`createEmptyLibrary`**:
    - Create a new library file with an initial empty collection of books.
    - Initialize the library array with a given capacity.

2. **`loadLibrary`**:
    - Load books from a binary file into the library array.
    - Resize the array dynamically if the number of books exceeds the current capacity.

3. **`saveLibrary`**:
    - Save the current state of the library to a binary file.

4. **`searchBook`**:
    - Search for a book by its title.

5. **`addBook`**:
    - Add a new book to the library.
    - Resize the array if the library reaches capacity.

6. **`removeBook`**:
    - Remove a book by its title.

7. **`listBooks`**:
    - List all books in the library with their details (title, author, year).

### Main Function
A menu-driven interface is already provided, allowing users to interact with the library system. The menu includes:
1. Add a book.
2. Remove a book.
3. List all books.
4. Search for a book by title.
5. Exit the program and save the library.

The provided main function also ensures:
- **File Persistence**:
  - If the library file already exists, load its contents when the program starts.
  - If the library file does not exist, create a new library file.

### Testing
- **Google Test Cases**: Provided to help test your program.
- **Manual Testing**: Use the main function to test manually.

## Additional Notes
- Use the provided function prototypes as-is.
- Build and run the program using the `cmake` tool, ideally from Visual Studio Code.
- Use dynamic memory allocation (`malloc`, `realloc`, and `free`) to manage the library’s storage.
- Properly handle file I/O errors and memory allocation failures.

## Expected Deliverables
1. The fully implemented program.
2. The build folder after compiling, building, and testing your program (with the main function or Google Test).
3. The entire Visual Studio project, in a zip file, must be uploaded when submitting the assignment.

## Grading Criteria
- Correct implementation of the required functionalities (tested using Google Test cases provided).
- Effective use of dynamic memory management.
- Proper handling of file I/O operations.
- Code readability, comments, and organization.
