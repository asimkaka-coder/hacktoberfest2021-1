#include <cstdlib>
#include <iostream>
#include <string>
#include "speedTable.h"

using namespace std;

int main()
{

   cout<<"Hash Table"<<endl;
   speedTable students(10);
   student ABDULAHAD("ABDULAHAD",1,"aaa");
student ABDULLAH("ABDULLAH MUGHAL",2,"bbb");
student AHMAD("AHMAD HASSAN",3,"ccc");

   cout <<"\nADDITION OF STUDENTS....";
students.add(ABDULAHAD);
students.add(ABDULLAH);
students.add(AHMAD);

students.dispTable();

cout <<"\nDELETE STUDENT ABDULLAH....";
   students.remove(2);
students.dispTable();

   return 0;
}

Hashtable.h:

#include "studentList.h"


class speedTable
{
private:
studentList * table; //an array of studentLists
int tableSize; //size of the array
   double numItems;

public:
//constructor which will allocate a new array of studentLists of size ‘size’
speedTable(int size){table = new studentList[size];tableSize = size;numItems = 0;};

//be sure to free all dynamically allocated memory!
~speedTable();

//add student s to data structure
void add(student s);

//remove student with given id from data structure
void remove(int id);

//locate and return the student with given id from the data structure
student getStudent(int id);

//Do this method last. Create a new array of size newsize and rehash
//all items in the old table into the new table.
//Free (delete) the old array and point the table
//variable at the new array.
void resize(int newsize);

void dispTable();

};
void speedTable::add(student s)
{
if(numItems/tableSize >= 1)
{
   cout<<"There are "<<numItems<<" items in a size "<<tableSize<<" list"<<endl;
   resize(3*tableSize);
   cout<<"Enlarge from "<<tableSize/3<<" to "<<tableSize<<endl;
}
int place = s.id%tableSize;
//Linear Probing
while(!table[place].empty())
{
   place += 1;
   if(place == tableSize)
       place = 0;
}
table[place].push(s);
numItems++;
}
void speedTable::remove(int id)
{
int place = id%tableSize;
table[place].removeStudent(id);
while(table->getStudent(id).id == id)
{
   table[place+1].removeStudent(id);
}
numItems--;
if((numItems)/tableSize <= 0.25)
{
   cout<<"There are "<<numItems<<" items in a size "<<tableSize<<" list"<<endl;
   resize(tableSize/3);
   cout<<"Cut from "<<tableSize*3<<" to "<<tableSize<<endl;
}
}
student speedTable::getStudent(int id)
{
int place = id%tableSize;
student s = table[place].getStudent(id);
return s;
}
void speedTable::dispTable()
{
for(int i = 0; i < tableSize; i++)
{
cout<<"Table row "<<i<<endl;
table[i].display();
}
cout<<"Table Size: "<<tableSize<<endl;
cout<<"# of students: "<<numItems<<endl;

}
void speedTable::resize(int newsize)
{
studentList * dummy = new studentList[newsize];
student s;
int place;
for(int i = 0; i < tableSize; i++)
{
while(!table[i].empty())
{
s = table[i].pop();
place = s.id%newsize;
       while(!dummy[place].empty())
       {
           place += 1;
           if(place == tableSize)
           {
               place = 0;
           }
       }
dummy[place].push(s);
}
}
table = dummy;
tableSize = newsize;
}
speedTable::~speedTable()
{
for(int i = 0; i < tableSize; i++)
{
table[i].~studentList();
}
}

---------------------------------------------------

StudentData header file

--------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
class student
{
public:
int id; //student ID number
string name; //student’s name
string university; //student’ university
student(){};
   student(string nm, int ID, string univ){name = nm; id = ID; university = univ;};
};

class studentList
{
private:
class node
{
public:
student data;
node * next;
node * prev;
           node(){prev = NULL; next = NULL;};
           node(student s){data = s; prev = NULL; next = NULL;};
};

node * head;


public:
studentList();

//be sure to free all dynamically allocated memory!
~studentList();

//return true if the list is empty, false if not
bool empty();

//insert student s into the front of the linked list
void push(student s);

//remove and return the student at the front of the list
student pop();

//locate and remove the student with given ID number
void removeStudent(int id);

//locate and return a copy of the student with given ID number
student getStudent(int id);


void display();

   void idsort();
   void namesort();
   void remove(node *s);
   student findSmallestID();
   student findAlpha();
};
studentList::studentList()
{
head = NULL;
}
studentList::~studentList()
{
while(!empty())
{
node* temp = head;
head=head->next;
delete temp;
}
}
bool studentList::empty()
{
if(head == NULL)
{
return true;
}
return false;
}
student studentList::findSmallestID()
{
   node *search = head;
   node *temp = head;
   while(search != NULL)
   {
       if(search->data.id < temp->data.id)
       {
           temp = search;
       }
       search = search->next;
   }

   return temp->data;
}
student studentList::findAlpha()
{
   node *search = head;
   node *temp = head;
   while(search != NULL)
   {
       if(search->data.name < temp->data.name)
       {
           temp = search;
       }
       search = search->next;
   }

   return temp->data;
}
void studentList::idsort()
{
   node *temp = NULL; // temporary storage for nodes
   node *search = head; // for searching through list
   node *temphead = NULL;
   student small;

   while(!empty())
   {
       small = findSmallestID();

       if(temphead == NULL)
       {
           temp = new node(small);
           temphead = temp;
       }
       else
       {
           temp->next = new node(small);
           temp->next->prev = temp;
           temp = temp->next;
       }
       removeStudent(small.id);
   }
   head = temphead;
   cout<<"A sorted list by ID!!!"<<endl<<endl;
}
void studentList::namesort()
{
   node *temp = NULL; // temporary storage for nodes
   node *search = head; // for searching through list
   node *temphead = NULL;
   student small;

   while(!empty())
   {
       small = findAlpha();

       if(temphead == NULL)
       {
           temp = new node(small);
           temphead = temp;
       }
       else
       {
           temp->next = new node(small);
           temp->next->prev = temp;
           temp = temp->next;
       }
       removeStudent(small.id);
   }
   head = temphead;
   cout<<"A sorted list by names!!!"<<endl<<endl;
}
void studentList::sort(string field)
{
   if(field == "id" || field == "ID")
   {
       idsort();
   }
   else if(field == "name" || field == "NAME")
   {
       namesort();
   }

}
student studentList::getStudent(int id)
{
   //cout<<"Searching for student . . ."<<endl;
   node *search = head;
   student wanted("No Student",00,"No School");
   while(search != NULL)
   {
       if(search->data.id == id)
       {
           wanted = search->data;
       }
       search = search->next;
   }
   return wanted;
}
void studentList::push(student s)
{
if(head == NULL)
{
node *temp = new node(s);
head = temp;
}
else
{
node *dummy = new node(s);
dummy->next = head;
head->prev = dummy;
head = dummy;
}
}
student studentList::pop()
{
   node *temp = head;
   if(head == NULL)
   {
       cout<<"No students anymore."<<endl;
       student s("None",0,"None");
       return s;
   }
   if(head->next != NULL)
   {
       head->next->prev = NULL;
   }
   head = temp->next;
   //cout<<"POP!!!"<<endl<<endl;
   return temp->data;
}
void studentList::remove(node *s)
{
   if(s->prev == NULL && s->next == NULL)
   {
       head = NULL;
       return;
   }
   if(s == head)
   {
       head = head->next;
       head->prev = NULL;
   }
   node *temp1 = s->prev;
   node *temp2 = s->next;
   if(s->prev != NULL)
   {
       temp1->next = temp2;
   }
   if(s->next != NULL)
   {
       temp2->prev = temp1;
   }
}
void studentList::removeStudent(int id)
{
   node *search = head;
   if(head == NULL || empty())
   {
           cout<<"No students anymore."<<endl;
           return;
   }
   while(search != NULL)
   {
       if(search->data.id == id)
       {
           remove(search);
       }
       search = search->next;
   }
}
void studentList::display()
{
if(head != NULL)
{
node *current = head;
while(current != NULL)
{
cout<<current->data.name<<" "<<current->data.id<<" "<<current->data.university<<endl;
       current = current->next;
}
   cout<<endl<<endl;
}
}
