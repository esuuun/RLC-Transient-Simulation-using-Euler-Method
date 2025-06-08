# RLC Transient Simulation using Euler Method

Nama: M. Ikhsan Kurniawan  
NPM: 2306210784

## 🧾 Deskripsi Program

Program ini mensimulasikan respons arus dan muatan listrik \( q(t) \) pada rangkaian RLC seri yang diberi eksitasi tegangan sinusoidal. Penyelesaian dilakukan dengan metode numerik **Euler**, dan hasilnya dibandingkan dengan **solusi analitik** yang tersedia dalam buku _Chapman_ (Persamaan 28.11). Perbandingan antara kedua solusi ditampilkan dalam bentuk tabel untuk menilai akurasi numerik.

Program ditulis menggunakan bahasa **C** dan menghasilkan output berupa:

- Nilai waktu \( t \)
- Nilai muatan hasil RK4
- Nilai muatan hasil analitiks
- Selisih (error) antara keduanya
