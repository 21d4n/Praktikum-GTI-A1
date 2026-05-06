# Cara Kerja Kode Lengan
## •	Struktur Umum
  Kode ini adalah program OpenGL/GLUT yang mensimulasikan lengan robot 2 segmen (bahu + siku) yang bisa digerakkan lewat keyboard.
  Program ini terdiri dari 5 fungsi utama: init, display, reshape, keyboard, dan main.
## •	Penjelasan Per Fungsi
  ### 1.	init()
      Setup awal sederhana:
      a)	glClearColor(0,0,0,0) → latar belakang hitam
      b)	glShadeModel(GL_FLAT) → pewarnaan flat (tidak ada gradasi cahaya)
  
  ### 2.	display()
      Fungsi display() menggambar seluruh objek lengan robot ke layar menggunakan transformasi translasi, rotasi, dan skala.
      Alur kerja fungsi:
      a)	glClear(GL_COLOR_BUFFER_BIT)
          Membersihkan layar sebelum objek digambar ulang agar tampilan tidak menumpuk.
      b)	glPushMatrix()
          Menyimpan matriks transformasi awal supaya perubahan transformasi tidak mempengaruhi objek lain.
      c)	glTranslatef(-1.0, 0.0, 0.0)
          Memindahkan posisi objek ke kiri pada sumbu x.
      d)	glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0)
          Memutar lengan atas berdasarkan nilai variabel shoulder terhadap sumbu z.
      e)	glTranslatef(1.0, 0.0, 0.0)
          Memindahkan titik pusat transformasi ke ujung lengan atas.
      f)	glPushMatrix()
          Menyimpan transformasi sementara sebelum membuat lengan atas.
      g)	glScalef(2.0, 0.4, 1.0)
          Mengubah ukuran kubus menjadi bentuk persegi panjang agar menyerupai lengan.
      h)	glutWireCube(1.0)
          Menggambar kubus berbentuk wireframe sebagai lengan atas.
      i)	glPopMatrix()
          Mengembalikan matriks transformasi sebelumnya agar skala tidak mempengaruhi objek lain.
      j)	glTranslatef(1.0, 0.0, 0.0)
          Memindahkan posisi ke ujung lengan atas sebagai titik siku.
      k)	glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0)
          Memutar lengan bawah berdasarkan nilai variabel elbow.
      l)	glTranslatef(1.0, 0.0, 0.0)
          Memindahkan posisi ke tengah lengan bawah.
      m)	glPushMatrix()
          Menyimpan transformasi sebelum membuat lengan bawah.
      n)	glScalef(2.0, 0.4, 1.0)
    	    Mengubah ukuran kubus agar menyerupai lengan bawah.
      o)	glutWireCube(1.0)
          Menggambar kubus wireframe sebagai lengan bawah.
      p)	glPopMatrix()
          Mengembalikan matriks transformasi sebelumnya.
      q)	glPopMatrix()
          Mengembalikan matriks awal sebelum seluruh transformasi dilakukan.
      r)	glutSwapBuffers()
          Menukar buffer belakang dengan buffer depan agar hasil render tampil ke layar secara halus tanpa flicker.
  
  ### 4.	reshape(w,h)
      Dipanggil saat ukuran jendela berubah. Mengatur:
      a)	Viewport sesuai ukuran jendela baru.
      b)	Proyeksi perspektif dengan FOV 65°.
      c)	Kamera digeser mundur 5 unit (glTranslatef(0,0,-5)) agar objek terlihat.
  
  ### 5.	keyboard()
      Mengontrol rotasi lengan robot:
      Tombol          -->	Efek
      s	Bahu berputar --> +5°
      S	Bahu berputar --> -5°
      e	Siku berputar --> +5°
      E	Siku berputar --> -5°Keluar program
      Esc	            --> Keluar program
      Nilai disimpan di variabel global shoulder dan elbow, lalu glutPostRedisplay() memicu render ulang.
  
  ### 6.	main()
      Fungsi utama program yang menjalankan seluruh sistem OpenGL/GLUT.
      Tahapan kerjanya:
      a)	glutInit(&argc, argv)
          Digunakan untuk menginisialisasi GLUT sebelum program dijalankan.
      b)	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB)
          Mengatur mode tampilan:
          •	GLUT_DOUBLE → menggunakan double buffering agar animasi halus 
          •	GLUT_RGB → menggunakan mode warna RGB
      c)	glutInitWindowSize(700,600)
          Menentukan ukuran window sebesar 700 × 600 pixel.
      d)	glutInitWindowPosition(100,100)
          Menentukan posisi awal window pada layar.
      e)	glutCreateWindow(argv[0])
          Membuat window OpenGL.
      f)	init()
          Memanggil fungsi inisialisasi awal program.
      g)	glutDisplayFunc(display)
          Menentukan fungsi display() sebagai fungsi untuk menggambar objek.
      h)	glutReshapeFunc(reshape)
          Menentukan fungsi reshape() untuk menangani perubahan ukuran window.
      i)	glutKeyboardFunc(keyboard)
          Menghubungkan input keyboard dengan fungsi keyboard().
      j)	glutMainLoop()
          Menjalankan loop utama GLUT secara terus menerus sampai program ditutup.
