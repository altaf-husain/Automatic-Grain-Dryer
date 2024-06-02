## Pengering-Gabah
Proyek Akhir Mata Kuliah Instrumentasi dan Kontrol
pengering ini menggunakan sensor load cell dan lampu sebagai alat pengeringnya yang dikontrol menggunakan arduino
Konsepnya adalah ketika gabah dimasukan maka load cell akan menyimpan nilai awal kemudian lampu otomatis menyala lama kelamaan gabah akan mengering dan berat gabah semakin berkurang karena kadar air berkurang setelah berat gabah berkurang sebesar 30% maka lampu akan otomatis mati untuk menghentikan proses pengeringan gabah 

projek ini bertujuan untuk mengatasi proses pengeringan gabah yang masih konvensional dengan cara di jemur menggunakan panas sinar matahari yang bergantung pada kondisi cuaca dan mudah terkena debu

## Prinsip Kerja
1. **Memasukkan Gabah Basah**: Gabah basah dimasukkan ke dalam alat.
2. **Pengukuran Berat Awal**: Sensor load cell akan mengukur dan menyimpan nilai berat awal gabah.
3. **Proses Pengeringan**: Lampu pijar menyala dan memulai proses pengeringan.
4. **Pengurangan Berat 56%**: Berdasarkan penelitian, ketika berat gabah berkurang sebesar 56%, lampu pijar akan otomatis mati dan proses pengeringan dihentikan.
5. **Pemantauan Suhu**: Layar LCD digunakan untuk memonitor suhu selama proses pengeringan.

## Komponen yang Digunakan
- **Arduino Uno**: Sebagai mikrocontroller utama untuk mengendalikan seluruh proses.
- **Sensor Load Cell**: Untuk mengukur berat awal dan mengawasi pengurangan berat gabah.
- **Lampu Pijar**: Sebagai sumber panas untuk mengeringkan gabah.
- **Relay**: Untuk mengendalikan nyala/matinya lampu pijar berdasarkan input dari Arduino.
- **Layar LCD**: Untuk menampilkan informasi suhu dan status pengeringan.
