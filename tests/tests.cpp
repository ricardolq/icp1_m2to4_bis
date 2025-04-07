#include "gtest/gtest.h"

extern "C" {
    #include "../src/assignment.c"
}

// Test fixture for setting up and tearing down test environment
class LibraryTest : public ::testing::Test {
protected:
    Book *library;

    void SetUp() override {
        library = nullptr; // Initialize the linked list as empty
    }

    void TearDown() override {
        freeLibrary(library); // Free the linked list
    }
};

// Test for loadLibrary function
TEST_F(LibraryTest, LoadLibrary) {
    createEmptyLibrary("test_library.txt", &library);
    addBook(&library, (Book){"Title1", "Author1", 2001});
    addBook(&library, (Book){"Title2", "Author2", 2002});
    saveLibrary("test_library.txt", library);
    freeLibrary(library);
    library = nullptr;

    EXPECT_EQ(loadLibrary("test_library.txt", &library), 0);
    EXPECT_NE(searchBook(library, "Title1"), nullptr);
    EXPECT_NE(searchBook(library, "Title2"), nullptr);
}

// Test for createEmptyLibrary function
TEST_F(LibraryTest, CreateEmptyLibrary) {
    EXPECT_EQ(createEmptyLibrary("test_empty_library.txt", &library), 0);
    EXPECT_EQ(library, nullptr);
    FILE *file = fopen("test_empty_library.txt", "rb");
    ASSERT_NE(file, nullptr);
    int numBooks;
    fread(&numBooks, sizeof(int), 1, file);
    EXPECT_EQ(numBooks, 0);
    fclose(file);
}

// Test for saveLibrary function
TEST_F(LibraryTest, SaveLibrary) {
    addBook(&library, (Book){"Title1", "Author1", 2001});
    addBook(&library, (Book){"Title2", "Author2", 2002});
    EXPECT_EQ(saveLibrary("test_library_save.txt", library), 0);
    freeLibrary(library);
    library = nullptr;

    EXPECT_EQ(loadLibrary("test_library_save.txt", &library), 0);
    EXPECT_NE(searchBook(library, "Title1"), nullptr);
    EXPECT_NE(searchBook(library, "Title2"), nullptr);
}

// Test for searchBook function
TEST_F(LibraryTest, SearchBook) {
    addBook(&library, (Book){"Title1", "Author1", 2001});
    Book *foundBook = searchBook(library, "Title1");
    ASSERT_NE(foundBook, nullptr);
    EXPECT_STREQ(foundBook->title, "Title1");
}

// Test for addBook function
TEST_F(LibraryTest, AddBook) {
    addBook(&library, (Book){"Title1", "Author1", 2001});
    EXPECT_NE(searchBook(library, "Title1"), nullptr);
}

// Test for removeBook function
TEST_F(LibraryTest, RemoveBook) {
    addBook(&library, (Book){"Title1", "Author1", 2001});
    EXPECT_EQ(removeBook(&library, "Title1"), 0);
    EXPECT_EQ(searchBook(library, "Title1"), nullptr);
}

// Test for listBooks function
TEST_F(LibraryTest, ListBooks) {
    addBook(&library, (Book){"Title1", "Author1", 2001});
    addBook(&library, (Book){"Title2", "Author2", 2002});
    testing::internal::CaptureStdout();
    listBooks(library);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Title1"), std::string::npos);
    EXPECT_NE(output.find("Title2"), std::string::npos);
}

// Test for listBooks function in an empty library
TEST_F(LibraryTest, ListBooksEmptyLibrary) {
    testing::internal::CaptureStdout();
    listBooks(library);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, ""); // Expect no output for an empty library
}

// Test for adding a book with an empty title
TEST_F(LibraryTest, AddBookEmptyTitle) {
    addBook(&library, (Book){"", "Author1", 2001});
    EXPECT_NE(searchBook(library, ""), nullptr);
}

// Test for adding a book with an empty author
TEST_F(LibraryTest, AddBookEmptyAuthor) {
    addBook(&library, (Book){"Title1", "", 2001});
    EXPECT_NE(searchBook(library, "Title1"), nullptr);
}

// Test for adding a book with a future year
TEST_F(LibraryTest, AddBookFutureYear) {
    addBook(&library, (Book){"Title1", "Author1", 3000});
    Book *foundBook = searchBook(library, "Title1");
    ASSERT_NE(foundBook, nullptr);
    EXPECT_EQ(foundBook->year, 3000);
}

// Test for saving and loading an empty library
TEST_F(LibraryTest, SaveLoadEmptyLibrary) {
    EXPECT_EQ(saveLibrary("test_empty_library_save.txt", library), 0);
    EXPECT_EQ(loadLibrary("test_empty_library_save.txt", &library), 0);
    EXPECT_EQ(library, nullptr);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}