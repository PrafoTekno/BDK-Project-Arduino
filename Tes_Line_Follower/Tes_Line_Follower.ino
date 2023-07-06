
int n= 1;  //simpang ke-n
int s=200,sl=227.5,sr=s;// s speed, sl left speed, sr right speed, 
int tsl=130,tsh=250; //tsl turn speed low, tsh high
int ms=1,T=10; //ms 1milisecond,T delay, Ta delay belok tajam

int d0=5,d1=6,d2=9,d3=10  ; // Pin motor
int dl1=12,dl2=13,dfr=2,dbk=3,dml=4,dmr=7,dr1=8,dr2=11; //Pin sensor
int l1,l2,fr,bk=1,ml,mr,r1,r2; //Nilai sensor
int a=0,b,c;//a setiap n-ms belok

void setup() 
{
  Serial.begin(9600);
  
  pinMode(dl2,INPUT);
  pinMode(dl1,INPUT);
  pinMode(dfr,INPUT);
  pinMode(dbk,INPUT);
  pinMode(dml,INPUT);
  pinMode(dmr,INPUT);
  pinMode(dr1,INPUT);
  pinMode(dr2,INPUT);

  pinMode(d0,OUTPUT);
  pinMode(d2,OUTPUT);
  pinMode (d1, OUTPUT);
  pinMode (d3, OUTPUT);
  
}


void loop() {
  
  ml=digitalRead(dml);
  mr=digitalRead(dmr);
  fr=digitalRead(dfr);
  r1=digitalRead(dr1);
  l1=digitalRead(dl1);
  r2=digitalRead(dr2);
  l2=digitalRead(dl2);

  if (n==1 && l1==1  && r2==1 && bk==1 )
      {tright();n++;}    

    else if ((n==2 || n==4 || n==20) && fr==1 && l1==1  && bk==1)
      {tleft();n++;}

    else if ((n==3 || n==5 || n==6 || n==21 || n==25) && fr==1 && r1==1 && bk==1)
      {forward();n++;}

    else if ((n==7 || n==19 || n==22 || n==23 || n==26 || n==30) && fr==1 && r1==1 && bk==1)
      {tright();n++;}

    else if ((n==8 || n==9 || n==10 || n==11 || n==13 || n==14 || n==15 || n==17 || n==24 || n==27 || n==28 || n==29) && l1==1 && r1==1 && bk==1)
      {tright();n++;}

    else if (n==16 && l1==1 && r1==1 && bk==1)
      {tleft();n++;}

    else if (n==18 && fr==1 && r1==1 && r2==1 && bk==1)
      {tright();n++;}


    if (ml==0 && mr==0 && fr==0)
      brake(); 
      
    else if(ml==0 && mr==0)
      forward();
      
    
    //keep on track belok kanan
    else if (ml==0 && (mr==1 || r1==1) )
    {
        while(mr==1 || r1==1)
      {
        trightban(T,tsl,tsh);
        mr=digitalRead(dmr);    
        r1=digitalRead(dr1);
      }

    }

    //keep on track belok kiri
    else if ( (ml==1||l1==1) && mr==0)
    {
         while(ml==1||l1==1)
      {
        tleftban(T,tsl,tsh);
        ml=digitalRead(dml);
        l1=digitalRead(dl1);
      }
      
    }

    r2=digitalRead(dr2);
    l2=digitalRead(dl2);

    if(r2==1)
    {
      tright();
    }
    else if(l2==1)
    {
      tleft();
    }

    
}
void forward()
{
      analogWrite(d0,sl);
      analogWrite(d1,0);
      analogWrite(d2,sr);
      analogWrite(d3,0);
      delay(10);
}
void tleftban(int time,int low, int high)
{
      analogWrite(d0,low);
      analogWrite(d1,0);
      analogWrite(d2,high);
      analogWrite(d3,0);
      delay(time);
}
void trightban(int time,int low, int high)
{
      analogWrite(d0,high);
      analogWrite(d1,0);
      analogWrite(d2,low);
      analogWrite(d3,0);
      delay(time);
}

void tright()
{
  trightban(100,0,s);
      r2=0;
      while(r2==0)
      {
        trightban(T,0,100); 
        r2=digitalRead(dr2);
      }
      while(mr!=1)
      {
        delay(1);
        mr=digitalRead(dmr);
      }
      tleftban(50,0,255);
        
}

void tleft()
{
  tleftban(100,0,s); 
      l2=0;
      while(l2==0)
      {
        tleftban(T,0,100); 
        l2=digitalRead(dl2);
      }
      while(ml!=1)
      {
        delay(1);
        ml=digitalRead(dml);
      }
      trightban(50,0,255);
}

void brake()
{
      analogWrite(d0,0);
      analogWrite(d1,195);
      analogWrite(d2,0);
      analogWrite(d3,195);
      delay(2);
      analogWrite(d0,0);
      analogWrite(d1,0);
      analogWrite(d2,0);
      analogWrite(d3,0);
      delay(1);

}
void brake1(int x,int y)
{
      analogWrite(x,0);
      analogWrite(y,250);
      delay(10);
      analogWrite(x,0);
      analogWrite(y,0);
      delay(5);

}

void tleft90(int time,int low, int high)
{
      delay(30);
      analogWrite(d0,0);
      analogWrite(d1,200);
      analogWrite(d2,0);
      analogWrite(d3,200);
      delay(30);
      analogWrite(d0,0);
      analogWrite(d1,low);
      analogWrite(d2,high);
      analogWrite(d3,0);
      delay(time);
}
void tright90(int time,int low, int high)
{
      delay(30);
      analogWrite(d0,0);
      analogWrite(d1,200);
      analogWrite(d2,0);
      analogWrite(d3,200);
      delay(30);
      analogWrite(d0,high);
      analogWrite(d1,0);
      analogWrite(d2,0);
      analogWrite(d3,low);
      delay(time);
}

void stop()
{
  analogWrite(d0,0);
  analogWrite(d1,0);
  analogWrite(d2,0);
  analogWrite(d3,0);
  delay(ms);
}
