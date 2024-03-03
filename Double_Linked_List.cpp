#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
	int age;
	
	struct data *next;
	struct data *prev;
}*head = NULL, *tail = NULL, *temp;

struct data *createNode(int age){ // pembuatan node baru
	struct data *newNode = (struct data*)malloc(sizeof(struct data)); // mengalokasikan data
	
	newNode -> next = NULL; // set awal node baru bahwa node baru ke next akan NULL
	newNode -> prev = NULL; // selain itu node baru ke prev juga akan NULL;
	newNode -> age = age; // nilai atau value yang dimasukan di parameter 
						// akan menjadi value variable age di nodenya
	
	return newNode;

}

void pushHead(int age){ // penambahan di atas / di awalan
	struct data *newNode = createNode(age); // otomatis membuat node baru atau new node
	
	if(head == NULL){ // kalo kosong dia bakal jadi head dan tailnya
		head = tail = newNode;
	}else{
		head -> prev = newNode; // kalo tidak kosong maka akan disambungkan
		newNode -> next = head;
		head = newNode; // head akan dipindahkan ke node baru supaya head tetap data paling atas
	}
}

void pushTail(int age){ // penambahan data di akhir
	struct data *newNode = createNode(age); // otomatis membuat node baru atau new node
	
	if(head == NULL){ // kalo kosong akan menjadi head dan juga tail secara otomatis
		head = tail = newNode;
	}else{
		tail -> next = newNode; // kalau tidak kosong maka akan disambungkan
		newNode -> prev = tail;
		tail = newNode; // tail akan dipindahkan ke new node supaya tail tetap jadi data paling bawah
	}
}

void pushMid(int age){ // penambahan node ditengah tengah atau dibandingkan
	struct data *newNode = createNode(age); // otomatis akan membuat node baru
	
	if(head == NULL){
		head = tail = newNode; // kalau kosong maka akan menjadi head dan juga tail
	} else if(head -> age > age){
		pushHead(age); // kalau head punya agenya lebih gede maka akan push head
	} else if(tail -> age <= age){
		pushTail(age); // kalau tailnya lebih kecil atau sama dengan age maka akan di push tail
	}else{
		struct data *curr; // menggunakan curr untuk membantu
		curr = head; // c dibuat curr sama dengan head
		while(curr -> next -> age < age){ // jika curr ke next punya age lebih kecil dari pada agenya
			curr = curr -> next; // maka curr akan terus berlanjut atau mencari sampai ada yang lebih besar
		}
		newNode -> next = curr -> next; // jika sudah ketemu maka akan disambungkan dengan node baru
		curr -> next -> prev = newNode;
		newNode -> prev = curr;
		curr -> next = newNode;
	}
}

void popHead(){ // penghapusan node dari depan
	temp = head; // gunakan temp untuk membantu 
	head = head -> next; // pindahkan head ke head ke next
	
	temp -> next = NULL; // lalu lepaskan pointernya
	head -> prev = NULL;
	
	free(temp); // hapus atau free tempnya
}

void popTail(){ // penghapusan node dari belakang
	temp = tail; // gunakan temp untuk membantu
	tail = tail -> prev; // pindahkan tail ke sebelumnya
	
	temp -> prev = NULL; // lalu lepaskan pointernya 
	tail -> next = NULL;
	
	free(temp); // hapus atau free tempnya
}

void popSearch(int age){ // penghapusan node dari pencarian
	
	if(head == tail){ // kalau cuman ada satu node dan sesuai dengan age yang dicari
		head = tail = NULL; // buat mereka jadi null dulu
		free(head);// baru free
		free(tail);
	}else if (head -> age == age){ // kalau headny yang sama dengan yang dicari maka akan pophead
		popHead();
	}else if(tail -> age == age){ // kalau tailnya yang sama dengan yang dicari makan akan poptail
		popTail();
	}else{
		struct data *curr; // membantu dalam proses pop
		curr = head; // buat curr = head
		
		while(curr -> next -> age != age){ // mencari sampai age ny pas
			curr = curr -> next; // untuk memindahkan curr
		}
		
		temp = curr -> next; // temp untuk membantu 
		curr -> next = temp -> next; // menyambungkan pointer
		temp -> next -> curr = curr;
		temp = NULL;
		free(temp); // lalu free temp
	}
}

void print(struct data *head){ // untuk print smua node
	temp = head;
	int count = 1;
	
	while(temp != NULL){ // slagi tempnya tidak kososng atau NULL terus ngeprint
		printf("Data ke %d -> %d\n", count, temp -> age);
		temp = temp -> next; // dibuat supaya tempnya trs bergerak ke node selanjutnya
		count++;
	}
}

int main(){

	pushMid(3);
	pushMid(10);
	pushMid(1);
	pushMid(40);
	pushMid(25);
	
	print(head);
	
	return 0;
}

