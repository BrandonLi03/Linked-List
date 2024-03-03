#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
	int age; // contoh data yang ada dalam struct
	
	struct data *next;	// pointer untuk menyambung ke node lainnya
}*head, *tail, *temp, *curr; // pointer yang membantu kita dalam 
							// proses pop(penghapusan data) atau push(penambahan data)

void print(struct data *head){ // untuk print smua node
	temp = head;
	int count = 1;
	
	while(temp != NULL){ // slagi tempnya tidak kososng atau NULL terus ngeprint
		printf("Data ke %d -> %d\n", count, temp -> age);
		temp = temp -> next; // dibuat supaya tempnya trs bergerak ke node selanjutnya
		count++;
	}
}
	
struct data *createNode(int age){ // pembuatan node baru
	struct data *newNode = (struct data*)malloc(sizeof(struct data)); // mengalokasikan data
	
	newNode -> next = NULL; // set awal node baru bahwa node baru ke next akan NULL
	newNode -> age = age; // nilai atau value yang dimasukan di parameter 
						// akan menjadi value variable age di nodenya
	
	return newNode;

}

void pushHead(int age){ // penambahan data di awalan / di urutan atas
	struct data *newNode = createNode(age); // stiap memakai function akan otomatis membuat node baru
	newNode -> next = head; // karena push head node baru punya pointer next akan disambungkan ke head
	head = newNode; // pindahkan head ke node baru karena head menandakan data paling atas.
	
}

void pushTail(int age){ // penambahan data di akhir / di d=urutan terakhir
	struct data *newNode = createNode(age); // otomatis membuat node baru / new node
	temp = head; // pakai pointer temp untuk membantu
	
	if(head == NULL){ // kalau datanya kosong
		head = newNode;
	}else{
		while(temp -> next != NULL){ // slagi temp punya next tidak NULL brati dia bukan data paling akhir
			temp = temp -> next; // bergerak ke node selanjutnya untuk mencari node paling akhir
		}
		temp -> next = newNode; // setelah ketemu lalu akan disambungkan temp punya next ke node baru
	}
	
}

void pushmid(int age){ // penambahan data ditengah tengah / membandingkan nilai
	struct data *newNode = createNode(age); // otomatis membuat node baru
	temp = head; // menggunakan temp untuk membantu
	
	if (head == NULL){ // kalo misalkan kosong maka diakan menjadi head dan tail
		head = tail = newNode;
	} else if (head -> age > newNode -> age){ // dibandingkan terlebih dahulu headnya
		pushHead(age); // jika memenuhi bahwa head punya age lebih besar dri pada new nodenya
					// maka akan di push head
	}
	else {
		while(temp -> next -> age < newNode -> age){ // jika tidak memenuhi maka while disini
													// akan dijalankan. dimana jika temp ke next punya age
													// lebih kecil darpiada new node
			temp = temp -> next; // maka akan terus mencri sampai ketemu yang lebihbsar dri pada age new node
		}
		newNode -> next = temp -> next; // sambungkan newnode punya next ke temp punya next
		temp -> next = newNode; // lalu sambungkan temp ke next dengan new node
	}
	
}

void popHead(){ // penghapusan data di depan
	temp = head; // menggunakan temp untuk membantu proses pop
	head = head -> next; // pindahkan head ke head punya next
	free(temp); // baru kita hapus datanya 
}

void popTail(){ // penghapusan data di belakang
	temp = head; // menggunakan temp dan curr untuk membantu proses pop
	curr = head;
	
	while(curr -> next != NULL){ // selagi curr punya next tidak NULL maka dia bukan data terakhir
		temp = curr; // supaya temp selalu berada di belakang curr
		curr = curr -> next; // memindahkan curr ke node selanjutnya
	}
	
	temp -> next = NULL; /* ketika data paling akhir sudah ketemu maka kita akan lepaskan pointer
						next pada temp menjadi NULL */
	free(curr); // baru hapus curr
}

void popSearch(int age){ // penghapusan data melalui nilai yang di cari / searching
	temp = head; // menggunakan temp dan curr untuk membantu dalam proses pop
	curr = head;
	
	if(head -> age == age){ // disini kalau misalkan data yang dicari adalah data paling atas
		head = head -> next; // maka headnya kita pindahkan head ke head punya next
		free(temp); // baru free temp, karena temp tadi sudah di set sama dengan head
	}else{
		while(curr -> age != age){ // selagi nilai yang di cari tidak sama dengan curr punya nilai age
			temp = curr; // maka temp akan ke tempat curr
			curr = curr -> next; // lalu curr akan ke curr punya next
		}
		temp -> next = temp -> next -> next; // setelah sesuai kita akan menyambungkan temp punya next
											// ke temp punya next next ( atau curr punya next )
		free(curr); // baru free curr
	}
}

int main(){
	
	// contohnya
	pushHead(30);
	pushHead(20);
	pushHead(10);
	pushmid(25);
//	pushTail(40);
	
//	popTail();
//	popHead();
	popSearch(25);
	print(head);

	return 0;
}

