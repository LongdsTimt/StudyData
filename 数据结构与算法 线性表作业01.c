#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ShoppingItem {
 char name[50]; // ��Ʒ����
 int quantity; // ��Ʒ����
 struct ShoppingItem* next; // ָ����һ���ڵ��ָ��
};

struct ShoppingItem* shoppingList = NULL; // ��ʼ�������嵥Ϊ��
struct ShoppingItem* z=NULL;
struct ShoppingItem* creatList();
void addItem(char itemName[], int itemQuantity);
void removeItem(char itemName[]);
void displayList();
void updateQuantity(char itemName[], int newItemQuantity);
void clearList();
int totalQuantity();
void findItem(char itemName[]);
void sortList();
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2);
void deleteItem(char itemName[], int deleteAll);
int main(){
	int i;

	printf("1.�����Ʒ�������嵥(��ʽ����Ʒ���� ��Ʒ����)\n");
	printf("2.�ӹ����嵥���Ƴ���Ʒ\n");
	printf("3.�鿴�����嵥\n");
	printf("4.�޸Ĺ����嵥����Ʒ������\n");
	printf("5.��չ����嵥\n");
	printf("6.���㹺���嵥����Ʒ��������\n");
	printf("7.���ҹ����嵥�е���Ʒ\n");
	printf("8.�������嵥\n");
	printf("9.�ϲ������嵥\n");
	printf("0.ɾ�������嵥�е���Ʒ\n");
	//printf("99.�˳�����\n");
	while(1){
	scanf("%d", &i);

	if (i < 0 || i > 9) 
		break;
		
		switch (i)
		{
		case 1: {
			char name[100];
			int sum;
			scanf("%s%d", &name, &sum);
			addItem(name, sum);
			break;
		}
		case 2: {
			char name[100];
			scanf("%s", name);
			removeItem(name);
			break;
		}
		case 3: {
			displayList();
			break;
		}
		case 4:
		{
			char name[100];
			int q;
			scanf("%s %d", name, &q);
			updateQuantity(name, q);
			break; }
		case 5: {
			clearList();
			break;
		}
		case 6: {
			printf("%d\n", totalQuantity());
			break; 
		}
		case 7: {
			char name[100];
			scanf("%s", name);
			findItem(name);
			break; 
		}
		case 8: {
			sortList();
			break; 
		}
		case 9: {
			//List1
			printf("�������һ�������嵥����0�˳�\n");
			struct ShoppingItem* list1;
			list1 = creatList();
			//List2
			printf("������ڶ��������嵥����0�˳�\n");
			struct ShoppingItem* list2;
			list2 = creatList();
			if (list1 != NULL) mergeLists(&list1, &list2);
				shoppingList = list1;

			break;
		}
		case 0 :{
			printf("�����ɾ��ȫ��,����������Ʒ����֮�����0\n");
			char name[100];
			int d;
			scanf("%s %d", name, &d);
			deleteItem(name, d);
			break; 
		}
		//case 99:
			//printf("nice99");
			//break;
		default:break;
		}
		printf("������ɣ������������빦���嵥�������л��������ܻ��߼����ظ��˹��ܣ�"); 
	}
	return 0;
}
struct ShoppingItem* creatList(){
	struct ShoppingItem *s1,*s2,*s3;
	
	s2=(struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	s3=(struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	s3=NULL;
	do{
	s1=(struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	scanf("%s %d",s1->name,&s1->quantity);
	s1->next=NULL;
	if(s3==NULL&&s1->quantity!=0){
	s3=s1;}
	else{
	s2->next=s1;}
	s2=s1;
	}while(s1->quantity!=0);
	
return s3;}

void addItem(char itemName[], int itemQuantity) {
 struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
 strcpy(newItem->name,itemName);
 newItem->quantity=itemQuantity;
 newItem->next=NULL;
 if(shoppingList==NULL) shoppingList=newItem;
 else z->next=newItem;
 z=newItem;

}

void removeItem(char itemName[]) {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* previous = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (previous != NULL) {
 previous->next = current->next;
 } else {
 shoppingList = current->next;
 }
 free(current);
 break;
 }
previous=current;
current=current->next;
 }
}
void displayList() {
 struct ShoppingItem* current = shoppingList;
 printf("�����嵥:\n");
 while (current != NULL) {
 printf("%s - ������%d\n", current->name, current->quantity);
 current=current->next;
 }
}

void updateQuantity(char itemName[], int newItemQuantity) {
 struct ShoppingItem* current = shoppingList;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 current->quantity=newItemQuantity;
 break;
 }
 current = current->next;
 }
}

void clearList() {
	struct ShoppingItem *temp;
	temp= (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
 while (shoppingList != NULL) {
 temp=shoppingList;
 shoppingList=shoppingList->next;
 free(temp);
 }
}

int totalQuantity() {
 struct ShoppingItem* current = shoppingList;
 int total = 0;
 while (current != NULL) {
 total+=current->quantity;
 current=current->next;
 }
 return total;
}

void findItem(char itemName[]) {
 struct ShoppingItem* current = shoppingList;
 printf("������Ʒ \"%s\" ��\n", itemName);
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 printf("%s - ������%d\n", current->name, current->quantity);
 return;
 }
 current=current->next;
 }
 printf("δ�ҵ���Ʒ \"%s\"��\n", itemName);
}

void sortList() {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* nextItem = NULL;
 char tempName[50];
 int tempQuantity;
 while (current != NULL) {
 nextItem = current->next;
 while (nextItem != NULL) {
 if (strcmp(current->name, nextItem->name) > 0) {
 // ������Ʒ��Ϣ
 strcpy(tempName,current->name);
 strcpy(current->name,nextItem->name);
 strcpy(nextItem->name,tempName);
 tempQuantity = current->quantity;
 current->quantity = nextItem->quantity;
 nextItem->quantity = tempQuantity;
 }
 nextItem = nextItem->next;
 }
 current = current->next;
 }
}


void mergeLists(struct ShoppingItem** list1,struct ShoppingItem** list2){
	struct ShoppingItem* current =*list1;
	while(current->next!=NULL)current=current->next;
	current->next=*list2;
	*list2=NULL;
	}



void deleteItem(char itemName[], int deleteAll) {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* prev = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (prev == NULL) {
 // ���Ҫɾ�����ǵ�һ���ڵ�
 struct ShoppingItem* temp = shoppingList;
shoppingList=shoppingList->next;
 free(temp);
 if (!deleteAll) break;
 } else {
 // ���Ҫɾ���Ĳ��ǵ�һ���ڵ�
 prev->next=current->next;
 free(current);
 current = prev->next;
 if (!deleteAll) break;
 }
 } else {
 prev = current;
 current = current->next;
 }
 }
}


