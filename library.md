# Library Book Manager

A C program that manages a small library of books using binary file I/O, sorting, and search functionality.

## Overview

This program initializes a collection of 5 books, writes them to a binary file, updates a book's rating, sorts the library alphabetically by title, and lets the user search for books by keyword.

## Features

- Write book records to a binary file (`library.bin`)
- Read and display all records from the file
- Update the rating of a specific book
- Sort books alphabetically by title (bubble sort)
- Search books by title keyword (case-sensitive substring match)

## Data Structure

Each book is stored as a `Book` struct:

| Field    | Type      | Description              |
|----------|-----------|--------------------------|
| `id`     | `int`     | Unique book identifier   |
| `title`  | `char[50]`| Title of the book        |
| `author` | `char[30]`| Author's name            |
| `year`   | `int`     | Publication year         |
| `rating` | `float`   | Book rating (out of 5.0) |

## Default Library

The program starts with these 5 books:

| ID   | Title           | Author           | Year | Rating |
|------|-----------------|------------------|------|--------|
| 1255 | 1984            | George Orwell    | 1949 | 4.8    |
| 1256 | Dune            | Frank Herbert    | 1965 | 4.7    |
| 1257 | The Hobbit      | J.R.R. Tolkien   | 1937 | 4.6    |
| 1258 | Neuromancer     | William Gibson   | 1984 | 4.5    |
| 1259 | Brave New World | Aldous Huxley    | 1932 | 4.4    |

## How It Works

### `main()`
1. Initializes the library array with 5 hardcoded books.
2. Opens `library.bin` in write-binary mode and writes all records.
3. Calls `updateFile()` to update the 3rd book's rating and print all records.
4. Applies the returned rating to `library[2]`.
5. Sorts the array alphabetically by title using bubble sort.
6. Reads a search keyword from the user via `fgets`.
7. Prints all books in sorted order.
8. Prints any books whose title contains the search keyword.

### `updateFile()`
1. Opens `library.bin` in read/write binary mode.
2. Seeks to the 3rd record (index 2) and reads it.
3. Updates its rating to `4.9` and writes it back.
4. Rewinds the file and reads all records one by one, printing each in the format:
   ```
   [YEAR] Title - Author  RATING
   ```
5. Returns the updated rating (`4.9`).

## Usage

### Compile

```bash
gcc -o library main.c
```

### Run

```bash
./library
```

### Example Session

```
Files were created successfully.
Current data at 3: 1257 The Hobbit J.R.R. Tolkien 1937 4.60
Rating will be 4.9.
[1949] 1984 - George Orwell  4.80
[1965] Dune - Frank Herbert  4.70
[1937] The Hobbit - J.R.R. Tolkien  4.90
[1984] Neuromancer - William Gibson  4.50
[1932] Brave New World - Aldous Huxley  4.40
```

After the file listing, enter a search keyword:

```
Hob
```

Output:
```
1255 1984 George Orwell 1949 4.80
1259 Brave New World Aldous Huxley 1932 4.40
1256 Dune Frank Herbert 1965 4.70
1258 Neuromancer William Gibson 1984 4.50
1257 The Hobbit J.R.R. Tolkien 1937 4.90
Book related with word: 1257 The Hobbit J.R.R. Tolkien 1937 4.90
```

## Notes

- The binary file `library.bin` is created in the current working directory.
- The search is **case-sensitive** (uses `strstr`).
- The rating update always targets the **3rd book** (index 2) and sets it to `4.9`.
- The `year` buffer in `updateFile` is only 4 bytes; years with more than 4 digits would overflow. For current use this is safe.
- `s1` (the formatted string buffer) is heap-allocated with `malloc` and properly freed after use.
