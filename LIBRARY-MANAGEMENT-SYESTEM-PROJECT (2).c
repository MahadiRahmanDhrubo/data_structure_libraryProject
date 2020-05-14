#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50


struct book{
    char  name[max];
    char w_name[max];
    char id[max];
    struct book *next;
}*head=NULL;


struct student{
    char name[max];
    char id[max];
    int contact;
    struct student *next;
}*head2=NULL;


struct b_issue{
    char name[max];
    char i_date[max];
    char s_date[max];
    char r_date[max];
    int contact;
    struct b_issue *next;
}*head3=NULL;



void add_book()
{
    if(head==NULL)
        {
        struct book *new_book, *current;
	    int i, number;

        printf("Enter quantity  you want to add: ");
	    scanf("%d", &number);

	for (i = 0; i < number; i++)
        {
		new_book = (struct book*)malloc(sizeof(struct book));
		printf("\n\nEnter info of book no. %d\n\n", i + 1);
        printf("Enter name : ");
        scanf(" %[^\n]", new_book->name);
        printf("Enter w_name : ");
        scanf(" %[^\n]", new_book->w_name);
        printf("Enter id : ");
        scanf(" %[^\n]", new_book->id);
		new_book->next = NULL;
		if (head == NULL)
        {
			head = new_book;
			current = new_book;
		}
		else
		{
			current->next = new_book;
			current = new_book;
		}

	}
	printf("\n%d number of book(s) has been created successfully\n\n", number);
    }
    else
    {
	struct book *new_book,*current;
	int x;
	printf("Enter the number of book you want to add: ");
	scanf("%d", &x);
	for (int i = 0; i < x; i++) {
		new_book = (struct book*)malloc(sizeof(struct book));
		printf("\n\nEnter info of new book no. %d\n\n", i + 1);
		printf("\n\nEnter info of book no. %d\n\n", i);
        printf("Enter name : ");
        scanf(" %[^\n]", new_book->name);
        printf("Enter w_name : ");
        scanf(" %[^\n]", new_book->w_name);
        printf("Enter id: ");
        scanf("%[^\n]", &new_book->id);
		new_book->next = NULL;

		if (i == 0) {
				current = head;
			while (current->next != NULL) {
				current = current->next;
			}
		}
		current->next = new_book;
		current = new_book;
	}
}

}

void display_book() {
	struct book* current;
	int i=1;
	printf("\n>>>Books to display<<<\n\n");
	if (head == NULL) {
		printf("No book has been added\n");
		return;
	}
	else {
		current = head;
		while (current != NULL) {
            printf("\nBook no. %d>>>\n\n",i);
			printf("Name : %s\n", current->name);
			printf("w_name : %s\n", current->w_name);
			printf("id : %s\n", current->id);
			current = current->next;
		i++;
		}
		printf("\n\n");
	}
}

void search_N_book(){
    struct book *current;
    int x=0;
    char name[max];
    printf("Enter Name: ");
    getchar();
    gets(name);
    current=head;
    while(current!=NULL){
        if(strcmp(name,current->name)==0){

			printf("Name : %s\n", current->name);
			printf("w_name : %s\n", current->w_name);
			printf("id : %s\n", current->id);
			x++;
        }
        current=current->next;
    }
    if(x==0){
        printf("\n\n-->No Result<--\n\n");
    }

}

void deletee_book()
{
    struct book *current, *temp;
    int i,count = 0,pos=0;
    char name[max];
    printf("\nEnter name: ");
    scanf(" %[^\n]",name);

        current = head;
        while(current->next!=NULL){
                count++;
                if(strcmp(name,current->name)==0){
                    pos=count;
                    break;
                }
            current=current->next;
        }

        if(current == head)
        {
            head = current->next;

            printf("Contact removed successfully\n");

        }
        else if(current->next == NULL){

            current = head;
            for(i=1;i<=pos-2;i++){
                current = current->next;
            }
            current->next = NULL;

            printf("Contact removed successfully\n");

        }
        else{

            temp = current->next;
            current = head;

            for(i=1;i<=pos-2;i++){
                current = current->next;
            }

            current->next = temp;

            printf("Contact removed successfully\n");

        }
    }




    void add_student() {
    if(head2==NULL){
        struct student *new_student,  *current;
	int i, number;

	printf("Enter quantity of contract you want to add: ");
	scanf("%d", &number);

	for (i = 0; i < number; i++) {
		new_student = (struct student*)malloc(sizeof(struct student));
		printf("\n\nEnter info of student no. %d\n\n", i + 1);
        printf("Enter name : ");
        scanf(" %[^\n]", new_student->name);
         printf("Enter id : ");
        scanf(" %[^\n]", new_student->id);
        printf("Enter contact no: ");
        scanf("%d", &new_student->contact);
		new_student->next = NULL;
		if (head2 == NULL) {
			head2 = new_student;
			current = new_student;
		}
		else {
			current->next = new_student;
			current = new_student;
		}

	}
	printf("\n%d number of student(s) has been created successfully\n\n", number);
    }
    else{
	struct student *new_student,*current;
	int x;
	printf("Enter the number of student you want to add: ");
	scanf("%d", &x);
	for (int i = 0; i < x; i++) {
		new_student = (struct student*)malloc(sizeof(struct student));
		printf("\n\nEnter info of new student no. %d\n\n", i + 1);
		printf("\n\nEnter info of student no. %d\n\n", i);

		 printf("Enter name : ");
        scanf(" %[^\n]", new_student->name);
         printf("Enter id : ");
        scanf(" %[^\n]", new_student->id);
        printf("Enter contact no: ");
        scanf("%d", &new_student->contact);

		new_student->next = NULL;

		if (i == 0) {
				current = head2;
			while (current->next != NULL) {
				current = current->next;
			}
		}
		current->next = new_student;
		current = new_student;
	}
}

}

void display_student() {
	struct student *current;
	int i=1;
	printf("\n>>>students to display<<<\n\n");
	if (head2 == NULL) {
		printf("No student has been added\n");
		return;
	}
	else {
		current = head2;
		while (current != NULL) {
            printf("\nstudent no. %d>>>\n\n",i);
			printf("Name : %s\n", current->name);
			printf("id : %s\n", current->id);
		    printf("Phone Number : %d\n", current->contact);

			current = current->next;
		i++;
		}
		printf("\n\n");
	}
}

void search_N_student(){
    struct student *current;
    int x=0;
    char name[max];
    printf("Enter Name: ");
    getchar();
    gets(name);
    current=head2;
    while(current!=NULL){
        if(strcmp(name,current->name)==0){
            printf("Name : %s\n", current->name);
			printf("id : %s\n", current->id);
			printf("Phone Number : %d\n", current->contact);


			x++;
        }
        current=current->next;
    }
    if(x==0){
        printf("\n\n-->No Result<--\n\n");
    }

}

void deletee_student()
{
    struct student *current, *temp;
    int i,count = 0,pos=0;
    char name[max];
    printf("\nEnter name: ");
    scanf(" %[^\n]",name);

        current = head2;
        while(current->next!=NULL){
                count++;
                if(strcmp(name,current->name)==0){
                    pos=count;
                    break;
                }
            current=current->next;
        }

        if(current == head2)
        {
            head2 = current->next;

            printf("Contact removed successfully\n");

        }
        else if(current->next == NULL){

            current = head2;
            for(i=1;i<=pos-2;i++){
                current = current->next;
            }
            current->next = NULL;

            printf("Contact removed successfully\n");

        }
        else{

            temp = current->next;
            current = head2;

            for(i=1;i<=pos-2;i++){
                current = current->next;
            }

            current->next = temp;

            printf("Contact removed successfully\n");

        }
    }




    void add_b_issue() {
    if(head3==NULL){
        struct b_issue *new_b_issue,  *current;
	int i, number;

	printf("Enter quantity of book issue you want to add: ");
	scanf("%d", &number);

	for (i = 0; i < number; i++) {
		new_b_issue = (struct b_issue*)malloc(sizeof(struct b_issue));
		printf("\n\nEnter info of b_issue no. %d\n\n", i + 1);
		 printf("Enter name : ");
        scanf(" %[^\n]", new_b_issue->name);
        printf("Enter i_date : ");
        scanf(" %[^\n]", new_b_issue->i_date);
         printf("Enter s_date : ");
        scanf(" %[^\n]", new_b_issue->s_date);
        printf("Enter r_date : ");
        scanf(" %[^\n]", new_b_issue->r_date);
        printf("Enter contact no: ");
        scanf("%d", &new_b_issue->contact);
		new_b_issue->next = NULL;
		if (head3 == NULL) {
			head3 = new_b_issue;
			current = new_b_issue;
		}
		else {
			current->next = new_b_issue;
			current = new_b_issue;
		}

	}
	printf("\n%d number of b_issue(s) has been created successfully\n\n", number);
    }
    else{
	struct b_issue *new_b_issue,*current;
	int x;
	printf("Enter the number of b_issue you want to add: ");
	scanf("%d", &x);
	for (int i = 0; i < x; i++) {
		new_b_issue = (struct b_issue*)malloc(sizeof(struct b_issue));
		printf("\n\nEnter info of new b_issue no. %d\n\n", i + 1);
		printf("\n\nEnter info of b_issue no. %d\n\n", i);

		  printf("Enter name : ");
        scanf(" %[^\n]", new_b_issue->name);
		  printf("Enter i_date : ");
        scanf(" %[^\n]", new_b_issue->i_date);
         printf("Enter s_date : ");
        scanf(" %[^\n]", new_b_issue->s_date);
        printf("Enter r_date : ");
        scanf(" %[^\n]", new_b_issue->r_date);
        printf("Enter contact no: ");
        scanf("%d", &new_b_issue->contact);



		new_b_issue->next = NULL;

		if (i == 0) {
				current = head3;
			while (current->next != NULL) {
				current = current->next;
			}
		}
		current->next = new_b_issue;
		current = new_b_issue;
	}
}

}

void display_b_issue() {
	struct b_issue *current;
	int i=1;
	printf("\n>>>b_issue to display<<<\n\n");
	if (head3 == NULL) {
		printf("No b_issue has been added\n");
		return;
	}
	else {
		current = head3;
		while (current != NULL) {
            printf("\nb_issue no. %d>>>\n\n",i);
            printf("name : %s\n", current->name);
			printf("i_date : %s\n", current->i_date);
			printf("s_date : %s\n", current->s_date);
			printf("r_date : %s\n", current->r_date);
		    printf("Phone Number : %d\n", current->contact);

			current = current->next;
		i++;
		}
		printf("\n\n");
	}
}

void search_N_b_issue(){
    struct b_issue *current;
    int x=0;
    char name[max];
    printf("Enter Name: ");
    getchar();
    gets(name);
    current=head3;
    while(current!=NULL){
        if(strcmp(name,current->name)==0){
            printf("Name : %s\n", current->name);
			printf("i_date : %s\n", current->i_date);
			printf("s_date : %s\n", current->s_date);
			printf("r_date : %s\n", current->r_date);
			printf("Phone Number : %d\n", current->contact);


			x++;
        }
        current=current->next;
    }
    if(x==0){
        printf("\n\n-->No Result<--\n\n");
    }

}

void deletee_b_issue()
{
    struct b_issue *current, *temp;
    int i,count = 0,pos=0;
    char name[max];
    printf("\nEnter name: ");
    scanf(" %[^\n]",name);

        current = head3;
        while(current->next!=NULL){
                count++;
                if(strcmp(name,current->name)==0){
                    pos=count;
                    break;
                }
            current=current->next;
        }

        if(current == head3)
        {
            head3 = current->next;

            printf("Contact removed successfully\n");

        }
        else if(current->next == NULL){

            current = head3;
            for(i=1;i<=pos-2;i++){
                current = current->next;
            }
            current->next = NULL;

            printf("Contact removed successfully\n");

        }
        else{

            temp = current->next;
            current = head3;

            for(i=1;i<=pos-2;i++){
                current = current->next;
            }

            current->next = temp;

            printf("Contact removed successfully\n");

        }
    }


    void book_manage(){

      int x,y;
    printf("\n\n>>>>>>B O O K<<<<<<\n\n");
    do{
    printf("Enter 1 to ADD\nEnter 2 to DELETE\nEnter 3 to SEARCH\nEnter 4 to VIEW\nEnter 5 to EXIT\n\nYour Choice: ");
    scanf("%d",&x);
    if(x==1){
        add();
        main();
    }
    else if(x==2){
        deletee();
        main();
    }
    else if(x==3){
        search_N();
        main();
    }
    else if(x==4){
        display();
        main();
    }
    else if(x==5){
        y=1;
        break;
    }
    else{
        printf("Wrong input\n");
        main();
    }
    }while(y!=1);



    }



    void student_manage(){

        int x,y;
    printf("\n\n>>>>>>S T U D E N T<<<<<<\n\n");
    do{
    printf("Enter 1 to ADD\nEnter 2 to DELETE\nEnter 3 to SEARCH\nEnter 4 to VIEW\nEnter 5 to EXIT\n\nYour Choice: ");
    scanf("%d",&x);
    if(x==1){
        add();
        main();
    }
    else if(x==2){
        deletee();
        main();
    }
    else if(x==3){
        search_N();
        main();
    }
    else if(x==4){
        display();
        main();
    }
    else if(x==5){
        y=1;
        break;
    }
    else{
        printf("Wrong input\n");
        main();
    }
    }while(y!=1);


    }


    void b_issue_manage(){

        int x,y;
    printf("\n\n>>>>>>B_ISSUE<<<<<<\n\n");
    do{
    printf("Enter 1 to ADD\nEnter 2 to DELETE\nEnter 3 to SEARCH\nEnter 4 to VIEW\nEnter 5 to EXIT\n\nYour Choice: ");
    scanf("%d",&x);
    if(x==1){
        add();
        main();
    }
    else if(x==2){
        deletee();
        main();
    }
    else if(x==3){
        search_N();
        main();
    }
    else if(x==4){
        display();
        main();
    }
    else if(x==5){
        y=1;
        break;
    }
    else{
        printf("Wrong input\n");
        main();
    }
    }while(y!=1);


    }



        void main(){
        printf("\n\n>>>>>>LIBRARY MANAGEMENT SYSTEM<<<<<<\n\n");
        int p,q;
        while(1){
            printf("\n1 for book\n2 for Student\n3 fot b_issue\n4 to exit\n      Choice: ");
            scanf("%d",&p);
            if(p==1){
               book_manage();
            }
            else if(p==2){
               student_manage();
            }
            else if(p==3){
                b_issue_manage();
            }
            else if(p==4){
                break;
            }
            else{
                printf("Wrong Choice\n");
                main();
            }

        }

    }
