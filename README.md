
A command-line based Image Steganography application developed in C, designed to hide and extract secret data inside images using the Least Significant Bit (LSB) technique. This project demonstrates strong fundamentals in C programming, bitwise operations, and binary file handling.

🚀 Project Description
The LSB Image Steganography application enables users to securely embed secret text data into BMP images and later retrieve it without causing any noticeable change in image quality. By modifying only the least significant bits of image pixels, the application ensures data confidentiality while preserving visual integrity.

This project was developed as part of the C Programming module in the Embedded Systems Professional Course at Emertxe Information Technologies.

🎯 Objective
To implement LSB-based image steganography using C
To understand bit-level manipulation and binary image formats
To apply file handling concepts in a security-related application
To ensure secure data hiding without affecting image quality
✨ Features
Hide secret text data inside BMP images
Extract hidden data accurately from encoded images
Uses Least Significant Bit (LSB) technique
Supports BMP image format
Display all stored contacts
Command-line based and user-friendly interface
Input validation and error handling
🛠️ Technologies & Concepts Used
C Programming
Bitwise Operations
Binary File Handling
File I/O (fopen, fread, fwrite, fseek)
Structures
Pointers and Memory Management
🧠 How the Application Works
Image files are processed in binary mode
Secret data is converted into individual bit
Each bit of secret data is embedded into the LSB of image bytes
Only the least significant bits are modified, preserving image quality
During decoding, LSBs are read back to reconstruct the original data
Encoding and decoding are handled using separate logical modules
📂 Project Structure
LSB-Steganography/
├── encode.c
├── encode.h
├── decode.c
├── decode.h
├── common.c
├── test_encode.c
├── types.h
├── beautiful.bmp
├── secret.txt
└── stego_imag.bmp
▶️ Compilation and Execution
Compile:
gcc *.c -o steganography
Run:
Encode(Hide Secret Data):
./steganography -e source.bmp secret.txt encoded.bmp
└──>Ex:
./steganography -e beautiful.bmp secret.txt stego_imag.bmp
Decode(Extract Secret Data):
./steganography -d encoded.bmp output.txt
└──>Ex:
./steganography -d stego_imag.bmp output.txt
Learning Outcome and Impact
This project strengthened my understanding of bitwise manipulation, binary file processing, and data encoding techniques. It improved my problem-solving approach, debugging skills, and confidence in developing low-level security-oriented applications using C.

Acknowledgment
I would like to sincerely thank Anand Lokhande Sir for his guidance and clear explanation of C programming concepts, which helped me build this project with a strong logical foundation.

GitHub Repository
[https://github.com/Manu-hp1/LSB-Image-Steganography]

About Me
I am an Embedded Systems Trainee at Emertxe Information Technologies, building strong fundamentals in C programming, Linux, and system-level concepts. I am passionate about writing clean code and continuously improving my technical skills.

License
This project is developed for learning and educational purposes.
