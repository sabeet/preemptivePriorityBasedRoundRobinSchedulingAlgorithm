#include <iostream>
#include <string>
#include<sstream>
#include<fstream>
#include<cstdlib>

using namespace std;

//contructed the process class

class process{
  private:
    int p_num; //process number
    int priority;
    int burst;
    int arrival;
    bool isLocalProcessRunning = false; //is process running

    //wait time
    //turnaround time

    static int numOfProcess;

  public:
  //getters and setters
    int get_pNum(){return p_num;}
    void set_pNum(int p_num){this->p_num=p_num;}
    int getPriority(){return priority;}
    void setPriority(int priority){this->priority = priority;}
    int getBurst(){return burst;}
    void setBurst(int burst){this-> burst= burst;}
    int getArrival(){return arrival;}
    void setArrival(int arrival){this->arrival = arrival;}
    bool getIsLocalProcessRunning(){return isLocalProcessRunning;}
    void setIsLocalProcessRunning(bool isLocalProcessRunning){this->isLocalProcessRunning = isLocalProcessRunning;}

    void setAll(int p_num, int priority, int burst, int arrival);
    process(int p_num, int priority, int burst, int arrival);
    process(){}
    static int getNumOfProcess(){return numOfProcess;}
    void ToString();
};

int process::numOfProcess = 0;
void process::setAll(int p_num,int priority,int burst,int arrival){
  this-> p_num = p_num;
  this-> priority = priority;
  this-> burst = burst;
  this-> arrival = arrival;
  process::numOfProcess++;
}

process::process(int p_num, int priority, int burst, int arrival){
  this-> p_num = 0;
  this-> priority = 0;
  this-> burst = 0;
  this-> arrival = 0;
  process::numOfProcess++;
}

void process::ToString(){
  cout 
  << this -> p_num 
  << "\t" << this -> priority 
  << "\t" << this -> burst 
  << "\t" << this -> arrival << "\n";
}


struct NODE { 
    process data; 
    NODE* next; 
    NODE(process d) 
    { 
        data = d; 
        next = NULL; 
    } 
}; 
  
struct queue { 
    NODE *front, *rear; 
    queue() 
    { 
        front = rear = NULL; 
    } 
  
    void enqueue(process x) 
    { 

        NODE* temp = new NODE(x); 

        if (rear == NULL) { 
            front = temp; 
            rear = front;  // if isssues change to f = r = t;
            return; 
        } 

        rear->next = temp; 
        rear = temp; 
    } 
  
    void dequeue() 
    { 
 
        if (front == NULL) 
            return; 

        NODE* temp = front; 
        front = front->next; 

        if (front == NULL) 
            rear = NULL; 
  
        delete (temp); 
    } 
};

//reads the priority collumns
string readPriorityFromText(int i){
  ifstream file("Book1.txt");
  string w,x,y,z;
  string line;
  for(int lineNum = 0; getline(file, line) && lineNum < i; lineNum++){
  file >> w >> x >> y >> z;
    //return w;
  }
  return x;

};

//reads the Burst collumn
string readBurstFromText(int i){
  ifstream file("Book1.txt");
  string w,x,y,z;
  string line;
  for(int lineNum = 0; getline(file, line) && lineNum < i; lineNum++){
  file >> w >> x >> y >> z;
    //return w;
  }
  return y;

};

//reads the arrival collumn
string readArrivalFromText(int i){
  ifstream file("Book1.txt");
  string w,x,y,z;
  string line;
  for(int lineNum = 0; getline(file, line) && lineNum < i; lineNum++){
  file >> w >> x >> y >> z;
    //return w;
  }
  return z;

};

//used to check true of false for priority comparison
bool comparisonPriority(process x, process y){
    if(x.getPriority() == y.getPriority()){

    }

    return ( x.getPriority() > y.getPriority());
};

//used to check true of false for arrival comparison
bool comparisonArrivalCheck(process x, process y){
  if(x.getArrival() == y.getArrival()){
    return (x.getPriority() < y.getPriority());
  }

  else{
    return (x.getArrival() < y.getArrival());
  }

};

int main() {

    //process handling
    queue readyQ;
    int time_quantum = 10;
    int check = 0;
    bool isGlobalProcessRunning = false;
    int time_t = 0;
    process x[6]; // initiating our processes

    cout << "Text table to console check" << endl;
  
    // set the values from the text file to each process
    for(int i=1; i <= 6; i++){

    x[i].set_pNum(i);
    cout << "P" << x[i].get_pNum() << " | \t";

    string s = readBurstFromText(i);
    stringstream ss(s);
    int o = 0;
    ss >> o;
    x[i].setBurst(o);
     cout << "burst : " << x[i].getBurst() << " | \t";

    string s2 = readArrivalFromText(i);
    stringstream ss2(s2);
    int p = 0;
    ss2 >> p;
    x[i].setArrival(p);
     cout << "arrival : " << x[i].getArrival() << " | \t";

    string s3 = readPriorityFromText(i);
    stringstream ss3(s3);
    int q = 0;
    ss3 >> q;
    x[i].setPriority(q); 
     cout << "priority : " << x[i].getPriority() << " | \n";
    }

    //all string converted to int

    cout << "\n";

    for(int i = 0; i<96; i++){ // simulate time from 0 to 96
      for(int j = 1; j<=6; j++){
      if(x[j].getArrival() == i && x[j].getArrival() !=  x[j+1].getArrival()){ // arrival time check
        cout << "Arrival time for P" << j <<  " is " << x[j].getArrival() << endl;
          readyQ.enqueue(x[j]);
          if(x[j].getIsLocalProcessRunning() == false){ //if process is not running
            readyQ.dequeue();
            x[j].setIsLocalProcessRunning(true); // set process to run state
            time_t += x[j].getBurst(); 
            cout << "Runtime for P" << x[j].get_pNum() << " is " << time_t << "\n"; 

          }
          else if(x[j].getArrival() ==  x[j+1].getArrival()){ //else if process has higher priority than following process
              x[j].setIsLocalProcessRunning(true);
              readyQ.dequeue(); //new process
              time_t += time_quantum;
              x[j+1].setIsLocalProcessRunning(true);
              readyQ.enqueue(x[j]);
              cout << "Runtime for P" << x[j].get_pNum() << " is " << time_t  << "\n"; 
          } 
        }  
      }
    }

  return 0;
}