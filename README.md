# TreeScan

<p align="center">
  <b>Fast and lightweight filesystem scanner written in modern C++.</b>
</p>

<p align="center">
  C++20 • CMake • Linux
</p>

---

## About

**TreeScan** is a command-line utility for recursively scanning and analyzing directory trees.

The project is being developed as a C++ pet project with a focus on filesystem operations, clean project architecture, STL, multithreading, databases and Linux APIs.

TreeScan currently collects basic information about files and directories and will gradually evolve into a more complete filesystem analysis tool.

## Features

Currently implemented:

- Recursive directory scanning
- File and directory counting
- Total directory size calculation
- File metadata collection
  - file name
  - path
  - extension
  - size
- Permission-denied directory handling
- Command-line interface

Planned:

- File filtering
- Largest file search
- Duplicate file detection
- SHA-256 hashing
- Multithreaded file processing
- SQLite database
- File change monitoring
- Improved CLI
- Tests

## Example

Run TreeScan:

```bash
./build/treescan ~/Downloads
```

Example output:

```text
Scanning: "/home/user/Downloads"

Files:       583
Directories: 71
Total size:  4283748291 bytes

Files:
photo.jpg | .jpg | 4281932 bytes
report.pdf | .pdf | 183452 bytes
main.cpp | .cpp | 2481 bytes
```

## Build

### Requirements

- C++20 compatible compiler
- CMake 3.20+
- Linux

Clone the repository:

```bash
git clone https://github.com/falvah/TreeScan.git
cd TreeScan
```

Configure the project:

```bash
cmake -S . -B build
```

Build:

```bash
cmake --build build
```

Run:

```bash
./build/treescan <directory>
```

For example:

```bash
./build/treescan ~/Documents
```

## Project structure

```text
TreeScan/
├── CMakeLists.txt
├── README.md
│
├── include/
│   └── treescan/
│       ├── FileInfo.hpp
│       └── Scanner.hpp
│
├── src/
│   ├── main.cpp
│   └── Scanner.cpp
│
└── tests/
```

## Architecture

The project separates filesystem scanning from the command-line interface.

```text
                 ┌──────────────┐
                 │     CLI      │
                 │   main.cpp   │
                 └──────┬───────┘
                        │
                        ▼
                 ┌──────────────┐
                 │   Scanner    │
                 └──────┬───────┘
                        │
                        ▼
                 ┌──────────────┐
                 │ std::filesystem
                 └──────┬───────┘
                        │
                        ▼
                   Filesystem
```

Scan results are represented using structures such as:

```cpp
struct FileInfo {
    std::filesystem::path path;
    std::string name;
    std::string extension;
    std::uintmax_t size = 0;
};
```

## Roadmap

### v0.1 — Directory scanning
- [x] Recursive scanning
- [x] Count files
- [x] Count directories
- [x] Calculate total size

### v0.2 — File metadata
- [x] Store file paths
- [x] Store file names
- [x] Store extensions
- [x] Store file sizes

### v0.3 — Search and filtering
- [ ] Filter by extension
- [ ] Filter by size
- [ ] Find largest files

### v0.4 — Duplicate detection
- [ ] Group files by size
- [ ] SHA-256 hashing
- [ ] Detect duplicate files

### v0.5 — Storage
- [ ] SQLite integration
- [ ] Save scan results
- [ ] Load previous scans

### v0.6 — Performance
- [ ] Worker threads
- [ ] File processing queue
- [ ] Parallel hashing

### v0.7 — Monitoring
- [ ] Linux inotify support
- [ ] Detect created files
- [ ] Detect modified files
- [ ] Detect deleted files

## Why TreeScan?

TreeScan is primarily a learning project designed to explore practical modern C++ concepts:

- STL containers and algorithms
- `std::filesystem`
- Object-oriented design
- Error handling
- RAII
- Multithreading
- CMake
- SQLite
- Linux APIs
- Git and GitHub workflow

---

<p align="center">
  <b>TreeScan is currently under development.</b>
</p>
