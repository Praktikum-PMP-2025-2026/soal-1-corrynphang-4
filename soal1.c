/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 04 - Dynamic Structures
 *   Hari dan Tanggal    : Kamis, 04 Juni 2026
 *   Nama (NIM)          : Beatrice Corryn Pangestu (13224038)
 *   Nama File           : soal1.c
 *   Deskripsi           : Sebuah rangkaian kereta kargo sedang disusun ulang di stasiun bongkar muat. Gerbong dapat 
ditambahkan ke depan, ditambahkan ke belakang, dilepas, atau dicari posisinya di rangkaian. Karena 
susunan gerbong berubah-ubah secara dinamis, struktur data yang digunakan harus mampu 
menangani operasi-operasi tersebut dengan baik. Anda diminta mensimulasikan seluruh rangkaian 
berdasarkan daftar operasi yang diberikan. 
Simulasikan linked list berdasarkan serangkaian operasi. 
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>

 struct gerbong {
    int data;
    int pos;
    struct gerbong* next;
 };

 struct gerbong* head = NULL;

 void push_front(int* data, int pos){
    struct gerbong* newNode = (struct gerbong*)malloc(sizeof(struct gerbong));
    newNode->data = data;
    newNode->pos =pos;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
        return;
    }
    struct gerbong* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
 }

 void delete(int data){
    struct gerbong * temp = head, *prev = NULL;
    if (temp != NULL && temp->data == data){
        head = temp -> next;
        free(temp);
    }
 }

 void list(){
    struct gerbong* temp = head;
    if (temp == NULL){
        printf("LIST EMPTY\n");
        return;
    }

    printf("LIST ");
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next
    }
 }
 
