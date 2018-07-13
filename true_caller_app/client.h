#define NAME_SIZE 50
#define ADDRESS_SIZE 100
#define FILE_NAME_SIZE 50

typedef struct query{
	int option = -1;
	long int user_no = -1;
	long int other_no = -1;
	char * filename;
	int balance = -1;
	char *new_name;
	char *new_adress;
	int new_status;
}Query;

char* allocate(char* string, int size)
{
	string = (char*)malloc(sizeof(char)*size);
	return string;
}

char* replace(char* string, char old, char New)
{
	for (int i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == old) string[i] = New;
	}
	return string;
}

int driver(){
	Query query;
	printf("Enter your phone number : ");
	scanf("%ld", &query.user_no);
	while (1){
		printf("Menu :\n\t1. Add contact\n\t2. Report spam\n\t3. Block contact\n\t4. Export contacts\n\t5. Send money\n\t6. Check Balance\n\t7. search\n\t8. update");
		printf("\nEnter your choice : ");
		scanf("%d", &query.option);
		switch (query.option){
		case 1: //Inserting a  single contact
			printf("\nEnter the name : ");
			query.new_name = allocate(query.new_name, NAME_SIZE);
			query.new_adress = allocate(query.new_adress, ADDRESS_SIZE);
			fflush(stdin);
			scanf("%[^\n]s", query.new_name);
			printf("\nEnter the phone number : ");
			scanf("%ld", &query.other_no);
			printf("\nEnter the email : ");
			scanf("%s", query.new_adress);
			//insert_contact(query);						
			break;
		case 2: //report spam
			printf("\nEnter the number to be marked spam : ");
			scanf("%ld", &query.other_no);
			//mark_spam();
			break;
		case 3: //block contact
			printf("\nEnter the number to be blocked : ");
			scanf("%ld", &query.other_no);
			//mark_blocked();
			break;
		case 4: //export contackts
			query.filename = allocate(query.filename, FILE_NAME_SIZE);
			printf("\nEnter The CSV file to be exported : ");
			scanf("%s", query.filename);
			break;
		case 5:// send money
		{printf("\nEnter the recipents's Phone Number : ");
		scanf("%ld", &query.other_no);
		printf("\nEnter the amount to be sent : ");
		scanf("%d", &query.balance);
		int result = -1;//send_money(from,to,amount);
		}
		break;
		case 6: //check Balance
			//check_balance(query.user_no);			
			break;
		case 7:// search
			printf("Options : \n\t1. Search by name\n\t2. Search by number");
			int choice;
			printf("\nEnter your choice");
			scanf("%d", &choice);
			switch (choice){
			case 1: {
				char* name = (char*)malloc(sizeof(char) * 20);
				printf("\nEnter the name of the contact to be searched : ");
				scanf("%s", name);
				query.new_name = allocate(query.new_name, NAME_SIZE);
				char *result = "temp";//search_by_name(query.new_name);
				result = replace(result, ',', '\n');
				printf("%s\n", result); }
					break;
			case 2: {printf("\nEnter the number to be searched : ");
				scanf("%ld", &query.other_no);
				char *name = "temp";
				printf("\nThe number belongs to %s\n", name); }
					break;
			default: printf("wrong choice\n");
			}
			break;
		case 8: //update
		{printf("Options : \n\t1. update Name\n\t2. update address\n\t3. public/private status\n");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		switch (choice){
		case 1: printf("\nEnter the new name : ");
			query.new_name = allocate(query.new_name, NAME_SIZE);
			scanf("%s", query.new_name);
			break;
		case 2: printf("\nEnter the new address : ");
			query.new_adress = allocate(query.new_adress, ADDRESS_SIZE);
			scanf("%s", query.new_adress);
			break;
		case 3: printf("\nDo you want to make your status public (y/n) : ");
			char status;
			fflush(stdin);
			scanf("%c", &status);
			if (status == 'y'){
				query.new_status = 1;
			}
			else{
				query.new_status = 0;
			}
			//
			break;
		}}
		break;
		default: printf("Recheck the query!!\n");
		}
	}
	return 0;
}