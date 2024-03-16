# Analisis Performa Algoritma Pengurutan

Repositori ini menyediakan kode sumber dalam bahasa C yang bertujuan untuk melakukan analisis performa atas tiga metode pengurutan yang berbeda: Bubble Sort, Selection Sort, dan Insertion Sort. Kode ini bekerja dengan cara menghasilkan nilai-nilai acak, lalu mengurutkannya memanfaatkan masing-masing metode tersebut, menghitung durasi waktu eksekusi, dan akhirnya mencatat hasilnya ke dalam sebuah file teks.

## Instruksi Eksekusi

Untuk dapat menjalankan kode ini, Anda diharuskan memiliki compiler bahasa C terinstal pada sistem Anda.

1. Silakan lakukan clone pada repositori ini atau unduh berkas `2208107010074_Simple_Sorting.c`.
2. Untuk mengkompilasi kode, gunakan perintah berikut ini:
   ```bash
   gcc 2208107010074_Simple_Sorting.c -o algoritma_pengurutan
   ```
3. Eksekusi file yang telah terkompilasi:
   ```bash
   ./algoritma_pengurutan
   ```

## Deskripsi Fungsi

### hasilkanAngkaAcak
Fungsi ini bertugas mengisi suatu array dengan nilai-nilai acak yang dihasilkan oleh fungsi `rand()`.

**Parameter:**

- `array`: Array yang akan diisi nilai acak.
- `size`: Besaran ukuran array yang akan diisi.

### bubbleSort
Fungsi ini menjalankan proses pengurutan array menggunakan metode Bubble Sort.

**Parameter:**

- `array`: Array yang akan diurutkan.
- `size`: Ukuran dari array tersebut.

### selectionSort
Fungsi ini mengaplikasikan algoritma Selection Sort untuk mengurutkan array.

**Parameter:**

- `array`: Array sasaran pengurutan.
- `size`: Dimensi array.

### insertionSort
Menggunakan algoritma Insertion Sort, fungsi ini mengatur ulang elemen-elemen dalam array.

**Parameter:**

- `array`: Array target.
- `size`: Kapasitas array.

### simpanKeFile
Fungsi ini berfungsi menyimpan array ke dalam sebuah dokumen teks.

**Parameter:**

- `filename`: Nama berkas output.
- `array`: Array yang akan dicatat.
- `size`: Ukuran array.

### waktuPengurutan
Mengukur waktu yang dibutuhkan oleh fungsi pengurutan untuk menjalankan tugasnya dalam satuan milidetik.

**Parameter:**

- `sortFunction`: Pointer ke fungsi pengurutan.
- `array`: Array untuk diurutkan.
- `size`: Ukuran dari array.

### copyArray
Menggandakan isi dari satu array ke array lain.

**Parameter:**

- `source`: Array sumber.
- `tujuan`: Array tujuan.
- `size`: Besar ukuran array.

## Fungsi Utama

Melalui fungsi `main`, kode ini melakukan uji coba terhadap efisiensi waktu eksekusi dari masing-masing algoritma pengurutan, dimulai dari ukuran array 100,000 hingga mencapai 1,000,000 dengan penambahan interval sebesar 100,000.

## Lisensi

Kode yang terdapat dalam repositori ini tersedia di bawah Lisensi MIT.
