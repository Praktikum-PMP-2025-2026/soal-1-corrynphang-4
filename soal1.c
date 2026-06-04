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
#include <stdbool.h>
 struct gerbong {
    int data;
    int pos;
    struct gerbong* next;
 };

 struct gerbong* head = NULL;

 void push(struct gerbong** head_ref, int new_data)
{
    struct gerbong* new_node = (struct gerbong*) malloc(sizeof(struct gerbong));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void append(struct gerbong** head_ref, int new_data)
{
    struct gerbong* new_node = (struct gerbong*) malloc(sizeof(struct gerbong));
    struct gerbong *last = *head_ref;  
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL){
        last = last->next;
    }
        
    last->next = new_node;
    return;
}

void delete(struct gerbong** head_ref, int key)
{
    struct gerbong *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp); 
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp); 
}

bool search(struct gerbong* head, int x)
{
    struct gerbong* current = head;  
    int loc=1;
    while (current != NULL)
    {
        if (current->data == x){
            return true;
        }else{
            loc++;
        }
        current = current->next;
    }
}

 void list(struct gerbong* node){
    struct gerbong* temp = head;
    if (temp == NULL){
        printf("LIST EMPTY\n");
        return;
    }
    printf("LIST ");
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
 }

int main(){
    struct gerbong *head = NULL;

    int data,pos,q;
    scanf("%d ", &q);
    while (q !=1){
        scanf("%d %d ",&pos,&data);
        if(pos == 1){
            push(&head,data);
        }else if (pos ==2){
            append(&head,data);
        }else if (pos == 3){
            delete(&head,data);
        }
        q--;
    }
    
    list(head);
}
