
//P-6
/*Represent a given graph using adjacency matrix/list to perform DFS and using adjacency 
list to perform BFS. Use the map of the area around the college as the graph. Identify the 
prominent land marks as nodes and perform DFS and BFS on that.*/

#include<iostream>
using namespace std;
class stack{
int arr[10];
int top;
public:
stack(){
top=-1;
}
int isfull(){
if(top==10){
return 1;
}
else
  return 0;
}
int isempty(){
if(top==-1){
return 1;
}
else
  return 0;
}

void push(int temp){
if(isfull()){
cout<<"\nSTACK IS FULL";
}
else{
top++;
arr[top]=temp;
}
}
int pop(){
if(isempty()){
cout<<"STACK IS EMPTY"<<endl;
return -1;
}
else{
int ret=arr[top];
top--;
return ret;
}
}
friend class Graph;

};

class Queue{
int queue[10];
int front,rear;
public:

Queue(){

front=rear=-1;
}


int isEmpty(){
if(front==-1){
return 1;
}
else{
return 0;
}
}

int isFull(){
if(rear>=9){
return 1;
}
return 0;
}

void equeue(int temp){
if(isFull()){
cout<<"\n OVERFLOW ";
return;
}
if(isEmpty()){
front ++;
rear++;
queue[rear]=temp;
}
else{
rear++;
queue[rear]=temp;
}
}

int dequeue(){
if(isEmpty()){
cout<<" underflow ";
return -1;
}
int element=queue[front];
if(front==rear){
front=rear=-1;
}else{
front++;
}
return element;
}
friend class Graph;

};
class Graph{
int array[20][20];
int visit[20];
int weight;
string cities[20];
int no;
public:
Graph(int n);
void create_graph();
void display();
void depth_firstSearch();
void breath_firstSearch();


};
Graph ::Graph(int n){
no=n;
for(int i=0;i<no;i++){
for(int j=0;j<no;j++){
array[i][j]=0;

}
}
for(int i=0;i<no;i++){
visit[i]=0;
}

}
void Graph::display(){
for(int i=0;i<no;i++){
for(int j=0;j<no;j++){
cout<<array[i][j]<<" ";
}
cout<<endl;
}
}
void Graph:: create_graph(){
cout<<"\nENTER CITIES"<<endl;
for(int i=0;i<no;i++){
cin>>cities[i];

}
for(int i=0;i<no;i++){
cout<<" "<<i<<" "<<cities[i]<<endl;

}
for(int i=0;i<no;i++){
for(int j=0;j<no;j++){
if(i<j){

cout<<"\n DO YOU WANT PATH BETWEEN "<<cities[i]<<" and "<<cities[j]<<"(y/n)";
char ch;
cin>>ch;
if(ch=='y'|| ch=='Y'){
cout<<"\n ENTER THE WEIGHT";
cin>>weight;
array[i][j]=array[j][i]=weight;
}

}
}

}
}
void Graph::breath_firstSearch() {

Queue q;
int i;
for ( i = 0; i < no; i++) {
visit[i] = 0;
} cout << "\n Enter node from which you want to start \n";
for (int i = 0; i < no; i++) {

cout << "\nPress " << i << " from " << cities[i] << endl;

}
cin >> i;

q.equeue(i);

while (!q.isEmpty()) {
i = q.dequeue();
  if (visit[i] == 1)
    {
continue; }

cout << " " << cities[i] << " --> ";
visit[i] = 1;
for (int j = 0; j < no; j++) {
if (array[i][j] > 0 && visit[j] == 0)

  q.equeue(j);

}
}
}

void Graph::depth_firstSearch(){
stack obj;
int i;
for(int i=0;i<no;i++){
visit[i]=0;
}
cout << "\n Enter node from which you want to start \n";
    for (int i = 0; i < no; i++) {

         cout << "\nPress " << i << " from " << cities[i] << endl;

       }
    cin >> i;
obj.push(i);
while(!obj.isempty()){
i=obj.pop();
if(visit[i]==1){
continue;
}
cout << " " << cities[i] << " --> ";
        visit[i] = 1;
for (int j = 0; j < no; j++) {
           if (array[i][j] > 0 && visit[j] == 0)

              obj.push(j);
 }

}

}



int main(){
char ch;
int node;
cout<<" \n ENTER NO. OF CITIES : "<<endl;
cin>>node;
Graph gl(node);
gl.create_graph();
gl.display();
int choose;
do{
cout<<"\n TRAVERSAL TECHNIQUES "<<endl;
cout<<"\n 1.DFS ";
cout<<"\n 2.BFS ";
cout<<"\n 3.END PROGRAM";
cin>>choose;
switch(choose){
case 1: gl.depth_firstSearch();
       break;
case 2: gl.breath_firstSearch();
       break;
case 3: exit(0);        
}
}while(ch!=3);
return 0;
}


