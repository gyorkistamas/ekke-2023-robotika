#include <List.hpp>

class DetectedObject {
  public: 
     int timeToLive;
     int x;
     int y;

    DetectedObject(int number) {
    switch(number) {
      case 0: this->x = 1; this->y = 4; break;
      case 1: this->x = 1; this->y = 5; break;
      case 2: this->x = 1; this->y = 6; break;
      case 3: this->x = 2; this->y = 6; break;
      case 4: this->x = 3; this->y = 6; break;
      case 5: this->x = 4; this->y = 6; break;
      case 7: this->x = 5; this->y = 6; break;
      case 8: this->x = 6; this->y = 6; break;
      case 9: this->x = 6; this->y = 5; break;
      case 10: this->x = 6; this->y = 4; break;
      case 11: this->x = 6; this->y = 3; break;
      case 12: this->x = 6; this->y = 2; break;
      case 13: this->x = 6; this->y = 1; break;
      case 14: this->x = 5; this->y = 1; break;
      case 15: this->x = 4; this->y = 1; break;
      case 16: this->x = 3; this->y = 1; break;
      case 17: this->x = 2; this->y = 1; break;
      case 18: this->x = 1; this->y = 1; break;
      case 19: this->x = 1; this->y = 2; break;
      case 20: this->x = 1; this->y = 3; break;
      
    }
    this->timeToLive = 100;
  }

};

const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;
int dataNumber = 0; 

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

List<DetectedObject> coords;

int hits[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

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
   DetectedObject obj(3);
   coords.add(obj);

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
  for(int i = 0; i < 4; i++) {
    for(int i = 0; i < 10; i++) {
    recvWithEndMarker();
    Display(m1);
    delay(1);
    }

    for(int i = 0; i < 10; i++) {
      recvWithEndMarker();
    Display(m2);
    delay(1);
    }

  for(int i = 0; i < 10; i++) {
    recvWithEndMarker();
    Display(m3);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {recvWithEndMarker();
  recvWithEndMarker();
    Display(m4);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    recvWithEndMarker();
    Display(m5);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    recvWithEndMarker();
    Display(m6);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    recvWithEndMarker();
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


  for (int i = 0; i < 3; i++) {
    Rotate(m1);
    Rotate(m2);
    Rotate(m3);
    Rotate(m4);
    Rotate(m5);
    Rotate(m6);
    Rotate(m7);
  }

  for(int i = 0; i < 4; i++) {
    for(int i = 0; i < 10; i++) {
      recvWithEndMarker();
    Display(m7);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    recvWithEndMarker();
    Display(m6);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    recvWithEndMarker();
    Display(m5);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    recvWithEndMarker();
    Display(m4);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    recvWithEndMarker();
    Display(m3);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    recvWithEndMarker();
    Display(m2);
    delay(1);
  }

  for(int i = 0; i < 10; i++) {
    recvWithEndMarker();
    Display(m1);
    delay(1);
  }

     for (int i = 0; i < 3; i++) {
       Rotate(m1);
      Rotate(m2);
      Rotate(m3);
     Rotate(m4);
     Rotate(m5);
      Rotate(m6);
      Rotate(m7);
   }
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

  if (newData) {
      dataNumber = 0;
      dataNumber = atoi(receivedChars);
     DetectedObject obj(dataNumber);
     coords.add(obj);
     hits[obj.x][obj.y] = 1;
     newData = false;
     Serial.println("Data coming");
  }



  //Ide, ha jön adat logika
  int res[8][8];
  memcpy(res, matri, sizeof res);

  for(int i = 0; i < coords.getSize(); i++) {
   DetectedObject temp = coords[i];
   // if (temp.timeToLive <= 0) {
    //  int x = temp.x;
    //  int y = temp.y;
    //  hits[x][y] = 0;
    //  coords.remove(i);
    //  Serial.println("deleted");
    //}
    Remove(temp, i);
  }

  

  for(int i = 0; i < coords.getSize(); i++) {
    DetectedObject temp = coords[i];
    temp = Decrease(temp);
    coords.remove(i);
    coords.add(temp);

    //coords[i] = temp;
  }


  MergeArrays(res, hits);
  Draw(res);
  
}

DetectedObject Decrease(DetectedObject& obj){
  obj.timeToLive--;
  Serial.println(obj.timeToLive);
  return obj;
}

void Remove(DetectedObject& obj, int i) {
  if (obj.timeToLive <= 0) {
      int x = obj.x;
      int y = obj.y;
      hits[x][y] = 0;
      coords.remove(i);
      Serial.println("deleted");
    }
}

void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;
    
    if (Serial.available() > 0) {
        rc = Serial.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}
