.data
prompt_mahasiswa1: .asciiz "\nNama: - \nNIM : -\n"
prompt_mahasiswa2: .asciiz "\nNama: - \nNIM : -\n"
prompt_mahasiswa3: .asciiz "\nNama: - \nNIM : -\n"
prompt_mahasiswa4: .asciiz "\nNama: - \nNIM : -\n"
prompt_mahasiswa5: .asciiz "\nNama: - \nNIM : -\n"
prompt_sisi1: .asciiz "\nMasukkan sisi 1: "
prompt_sisi2: .asciiz "Masukkan sisi 2: "
prompt_invalid: .asciiz "\nInputan harus sama dan bilangan positif.\n"
prompt_result: .asciiz "\nLuas bujur sangkar: "
prompt_kategori_kecil: .asciiz "\nKategori: Bujur Sangkar Kecil\n"
prompt_kategori_sedang: .asciiz "\nKategori: Bujur Sangkar Sedang\n"
prompt_kategori_besar: .asciiz "\nKategori: Bujur Sangkar Besar\n"
prompt_exit: .asciiz "\nExit Program.\n"
prompt_exit_hint: .asciiz "\nType 1501 for exit\n"

.text
.globl main

main:
    # Menampilkan Nama dan NIM setiap anggota
    li $v0, 4
    la $a0, prompt_mahasiswa1
    syscall

    li $v0, 4
    la $a0, prompt_mahasiswa2
    syscall

    li $v0, 4
    la $a0, prompt_mahasiswa3
    syscall

    li $v0, 4
    la $a0, prompt_mahasiswa4
    syscall

    li $v0, 4
    la $a0, prompt_mahasiswa5
    syscall
    
    # Menampilkan Petunjuk Exit
    li $v0, 4
    la $a0, prompt_exit_hint
    syscall

    # Prosedur MASUKAN
masukan:
    li $v0, 4
    la $a0, prompt_sisi1
    syscall

    li $v0, 5
    syscall
    move $t0, $v0  # Sisi 1

    # Cek exit jika Sisi 1 = 1501
    li $t1, 1501
    beq $t0, $t1, exit_program

    li $v0, 4
    la $a0, prompt_sisi2
    syscall

    li $v0, 5
    syscall
    move $t1, $v0  # Sisi 2

    # Input Validation
    blez $t0, invalid_input
    blez $t1, invalid_input
    bne $t0, $t1, invalid_input

    # Prosedur HITUNG
hitung:
    move $t2, $t0  # Sisi 1
    move $t3, $t1  # Sisi 2
    li $t4, 0       # Luas = 0

loop_multiplication:
    beqz $t3, selesai_hitung
    add $t4, $t4, $t2
    sub $t3, $t3, 1
    j loop_multiplication

selesai_hitung:
    # Prosedur KELUARAN
keluaran:
    li $v0, 4
    la $a0, prompt_result
    syscall

    li $v0, 1
    move $a0, $t4
    syscall

    # Tentukan kategori
    blt $t4, 500, kategori_kecil
    blt $t4, 1000, kategori_sedang
    j kategori_besar

kategori_kecil:
    li $v0, 4
    la $a0, prompt_kategori_kecil
    syscall
    j masukan

kategori_sedang:
    li $v0, 4
    la $a0, prompt_kategori_sedang
    syscall
    j masukan

kategori_besar:
    li $v0, 4
    la $a0, prompt_kategori_besar
    syscall
    j masukan

invalid_input:
    li $v0, 4
    la $a0, prompt_invalid
    syscall
    j masukan

exit_program:
    li $v0, 4
    la $a0, prompt_exit
    syscall

    li $v0, 10  # Exit program
    syscall
