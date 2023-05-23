#include <List.hpp>

class DetectedObject {
  public: 
     int timeToLive = 200;
     int matrix[8][8] = {
       {0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0},
     };

    DetectedObject(int number) {
    switch(number) {
      case 0: this->matrix[1][4] = 1; break;
      case 1: this->matrix[1][5] = 1; break;
      case 2: this->matrix[1][6] = 1; break;
      case 3: this->matrix[2][6] = 1; break;
      case 4: this->matrix[3][6] = 1; break;
      case 5: this->matrix[4][6] = 1; break;
      case 7: this->matrix[5][6] = 1; break;
      case 8: this->matrix[6][6] = 1; break;
      case 9: this->matrix[6][5] = 1; break;
      case 10: this->matrix[6][4] = 1; break;
      case 11: this->matrix[6][3] = 1; break;
      case 12: this->matrix[6][2] = 1; break;
      case 13: this->matrix[6][1] = 1; break;
      case 14: this->matrix[5][1] = 1; break;
      case 15: this->matrix[4][1] = 1; break;
      case 16: this->matrix[3][1] = 1; break;
      case 17: this->matrix[2][1] = 1; break;
      case 18: this->matrix[1][1] = 1; break;
      case 19: this->matrix[1][2] = 1; break;
      case 20: this->matrix[1][3] = 1; break;
      
    }
    this->timeToLive = 200;
  }

  //Decrease() {
    //this->timeToLive--;
    //Serial.println("Decrease hit");
    //Serial.println(this->timeToLive);
  //}

};


// Mario's Ideas
// Testing all 64 leds in 8x8 LED matrix by lighting  them up one by one

// Raws 
#define C1 9  // 2
#define C2 8  // 3
#define C3 7  // 4
#define C4 6  // 5
#define C5 5  // 6
#define C6 4  // 7
#define C7 3  // 8
#define C8 2  // 9
//Columns
#define R1 10 //10
#define R2 11 //11
#define R3 12 //12
#define R4  13//13
#define R5 A0 //A0
#define R6 A1 //A1
#define R7 A2 //A2
#define R8 A3 //A3

int m1[8][8] = {
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int m2[8][8] = {
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int m3[8][8] = {
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int m4[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 1},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int m5[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int m6[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int m7[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

List<DetectedObject> objs;

void setup() {
  Serial.begin(9600);
   pinMode(R1, OUTPUT);
   pinMode(R2, OUTPUT);
   pinMode(R3, OUTPUT);
   pinMode(R4, OUTPUT);
   pinMode(R5, OUTPUT);
   pinMode(R6, OUTPUT);
   pinMode(R7, OUTPUT);
   pinMode(R8, OUTPUT);
   pinMode(C1, OUTPUT);
   pinMode(C2, OUTPUT);
   pinMode(C3, OUTPUT);
   pinMode(C4, OUTPUT);
   pinMode(C5, OUTPUT);
   pinMode(C6, OUTPUT);
   pinMode(C7, OUTPUT);
   pinMode(C8, OUTPUT);

  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
  digitalWrite(R5,HIGH);
  digitalWrite(R6,HIGH);
  digitalWrite(R7,HIGH);
  digitalWrite(R8,HIGH);
  digitalWrite(C1,LOW);
  digitalWrite(C2,LOW);
  digitalWrite(C3,LOW);
  digitalWrite(C4,LOW);
  digitalWrite(C5,LOW);
  digitalWrite(C6,LOW);
  digitalWrite(C7,LOW);
  digitalWrite(C8,LOW);


   //DetectedObject asd = new DetectedObject(3);
   DetectedObject fasz(3);
   objs.add(fasz);

}



void SelectRow(int row){
  if (row==1)  digitalWrite(R1,LOW); else digitalWrite(R1,HIGH);
  if (row==2) digitalWrite(R2,LOW);  else digitalWrite(R2,HIGH);
  if (row==3) digitalWrite(R3,LOW); else digitalWrite(R3,HIGH);
  if (row==4) digitalWrite(R4,LOW); else digitalWrite(R4,HIGH);
  if (row==5)  digitalWrite(R5,LOW); else digitalWrite(R5,HIGH);
  if (row==6) digitalWrite(R6,LOW);  else digitalWrite(R6,HIGH);
  if (row==7) digitalWrite(R7,LOW); else digitalWrite(R7,HIGH);
  if (row==8) digitalWrite(R8,LOW); else digitalWrite(R8,HIGH);
}

void  Set_LED_in_Active_Row(int column, int state){
  if (column==1) digitalWrite(C1,state);  
  if (column==2) digitalWrite(C2,state); 
  if (column==3) digitalWrite(C3,state);  
  if (column==4) digitalWrite(C4,state); 
  if (column==5) digitalWrite(C5,state);  
  if (column==6) digitalWrite(C6,state); 
  if (column==7) digitalWrite(C7,state);  
  if (column==8) digitalWrite(C8,state); 
}

void loop() {
  for(int i = 0; i < 10; i++) {
    Display(m1);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    Display(m2);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    Display(m3);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    Display(m4);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    Display(m5);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    Display(m6);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    Display(m7);
    delay(1);
  }

  Rotate(m1);
  Rotate(m2);
  Rotate(m3);
  Rotate(m4);
  Rotate(m5);
  Rotate(m6);
  Rotate(m7);
}


void Draw(int picture[8][8]) {
  for (int j=0;j<8;j++){
      SelectRow(j+1);
      for (int i=0;i<8;i++){
        Set_LED_in_Active_Row(i+1, picture[j][i]);
      }
      delay(2);
    }
}

void Rotate(int arr[8][8]) {
  for (int i=0;i<4;i++) 
  { 
    for (int j=i;j<8-i-1;j++) 
    { 
        // Swapping elements after each iteration in Clockwise direction
            int temp=arr[i][j]; 
            arr[i][j]=arr[8-1-j][i]; 
            arr[8-1-j][i]=arr[8-1-i][8-1-j]; 
            arr[8-1-i][8-1-j]=arr[j][8-1-i]; 
            arr[j][8-1-i]=temp; 
    } 
  }
}


void MergeArrays(int arr1[8][8], int arr2[8][8]) {


  for(int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (arr2[i][j] == 1) {
        arr1[i][j] = 1;
      }
    }
  }
}

DetectedObject obj(3);

void Display(int matri[8][8]) {

  int res[8][8];
  memcpy(res, matri, sizeof res);


  //Serial.println(objs[0].matrix[2][6]);
  //for (int i = 0; i < sizeof(arrayTest); i++) {
      //DetectedObject temp = objs.getValue(i);
      if(obj.timeToLive > 0) {
        MergeArrays(res, obj.matrix);
        Decrease(obj);
      }
      //asdika.Decrease();
  //}
  

  //memcpy(res, temp, sizeof temp);

  Draw(res);
  
}

void Decrease(DetectedObject& obj){
  obj.timeToLive--;
}
