
int n= 14;  //simpang ke-n
int s=200,sl=220,sr=s;// s speed, sl left speed, sr right speed, 
int tsl=130,tsh=250; //tsl turn speed low, tsh high
int ms=1,T=10; //ms 1milisecond,T delay, Ta delay belok tajam

int d0=3,d1=11,d2=9,d3=10  ; // Pin motor
int dl1=12,dl2=13,dfr=2,dbk=5,dml=4,dmr=7,dr1=8,dr2=6; //Pin sensor
int l1,l2,fr,bk=1,ml,mr,r1,r2; //Nilai sensor
int a,b=1,c;//a jgn masuk belok,b counter belok ke brp
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
  //pinMode(d1,OUTPUT);
  pinMode(d2,OUTPUT);
  //pinMode(d3,OUTPUT);
}

void loop() {

  
  a=1;
  ml=digitalRead(dml);
  mr=digitalRead(dmr);
  fr=digitalRead(dfr);
  r1=digitalRead(dr1);
  l1=digitalRead(dl1);
  r2=digitalRead(dr2);
  l2=digitalRead(dl2);
    if(n==1 && ml==1 && mr==1 && r1==1 && l1==1 && r2==1&& l2==1)
    {
        forward();
        delay(300);
    }

    if (ml==0 && mr==0 && fr==0 && n!=10 && n!=9 && n!=12)
      brake(); 
      
    else if(ml==0 && mr==0)
      forward();

    //keep on track belok kanan
    else if (ml==0 && (mr==1 || r1==1) )
    {
        trightban(T,tsh,tsh);
        while(mr==1 || r1==1)
      {

        trightban(T,tsl,tsh);
        mr=digitalRead(dmr); 
        ml=digitalRead(dml);  
        r1=digitalRead(dr1);
        l1=digitalRead(dl1);
        r2=digitalRead(dr2);
        l2=digitalRead(dl2);
        fr=digitalRead(dfr);
        if((r1==1||r2==1)&&(l1==1||l2==1))
          break;
        else if((l2==1||r2==2) && fr==1)
          break;
        else if (mr==1 && (l2==1||r2==1))
          break;        
        else if (n==11 && ml==1 && r1==1)
          break;
      }

    }

    //keep on track belok kiri
    else if ((ml==1||l1==1) && mr==0)
    {
      tleftban(T,tsh,tsh);
      while(ml==1||l1==1)
      {
        tleftban(T,tsl,tsh);
        mr=digitalRead(dmr); 
        ml=digitalRead(dml);       
        r1=digitalRead(dr1);
        l1=digitalRead(dl1);
        r2=digitalRead(dr2);
        l2=digitalRead(dl2);
        fr=digitalRead(dfr);
        if((r1==1||r2==1)&&(l1==1||l2==1))
          break;
        else if((l2==1||r2==1) && fr==1)
          break;
        else if (ml==1 && (l2==1||r2==1))
          break;
        else if (n==11 && ml==1 && r1==1)
          break;
      }      
    }
    ml=digitalRead(dml);
    mr=digitalRead(dmr);
    fr=digitalRead(dfr);
    r1=digitalRead(dr1);
    l1=digitalRead(dl1);
    r2=digitalRead(dr2);
    l2=digitalRead(dl2);
  
    if (n==1 && l1==1  && r2==1 && bk==1 )
      {
        n++;
        trightreverse();
        l2=0;
        while(l2==0)
        {
          forward();
          l2=digitalRead(dl2);
        }
        forward();
        delay(70);
        tleftreverse();
        a=0;
      }
       

    else if ((n==2 || n==4) && (fr==1||ml==1||mr==1) && l2==1  && bk==1)
      { 
        n++;
        
        for(int i=0;i<30;i++)
          brake();
        tleft();
          
          a=0;
      }

     else if(n==15 && (fr==1 || ml==1 || mr==1) && l2==1  && bk==1)
     {
      for(int i=0;i<30;i++)
          brake();
          tleftreverse();
          forward();
          delay(200);

          n++;
     }

    else if ((n==3 || n==5 || n==6 || n==13 || n==14 || n==15 || n==16 || n==17 || n==18) && (fr==1 || mr==1 || ml==1) && r2==1 && bk==1)
      {         
          if(n==13)
          {
            backward();
            delay(150);
            trightbanreverse(100,200,200);
            //tleftban(50,0,250);
            forward();
            delay(350);
            stop();
            delay(500);
            tright();
            /*mr=0;
            while(mr==0)
            {
              analogWrite(d2,0);
              analogWrite(d3,200);
              mr=digitalRead(dmr);
            }*/
            n++;
          } 

          else if(n==14)
          {
            for(int i=0;i<100;i++)
              brake();
            tright();
            n++;
          }

          else if(n==15 || n==16 || n==18)
          {
            for(int i=0;i<100;i++)
              brake();
            tright();
            n++;
          }

          else if(n==17)
          {
            for(int i=0;i<100;i++)
              brake();
            forward();
            delay(25);
            tleft();
            n++;
          }

  
          

          if(n!=14 && n!=13 && n!=15 && n!=16 && n!=17 && n!=18 && n!=19)
          {
            for(int i=0;i<100;i++)
              brake();
            if(n==5)
              tleftban(90,0,100);

            else if(n==6)
              tleftban(100,0,100);

            forward();
            delay(100);            
            a=0;

            n++;
            if(n==7)
              b=1;
          
          }
          
      }

    else if ((n==19 || n==22 || n==23 || n==26 || n==30) && fr==1 && r1==1 && bk==1)
      {for(int i=0;i<100;i++)
          brake();
          
          tright();n++;
          a=0;
      }

    else if ( (n==8 || n==9 || n==10 || n==12) && (l2==1||l1==1) && (r2==1||r1==1) && bk==1)
      {
        
        for(int i=0;i<100;i++)
          brake();

        if(n==8)
        {
           //hexagon
            tleftban(100,0,250);
            while(fr==0)
            {
              fr=digitalRead(dfr);
            forward();
            }
            trightban(440,0,250);
            forward();
            delay(650);
            for(int i=0;i<50;i++)
              brake();

            tleftban(250,0,250);
            forward();
            delay(240);

            trightban(195 , 0 ,250);

            forward();
            delay(100);

            while(fr==0 && (mr==0 || ml==0))
            {
            forward();
             fr=digitalRead(dfr);
             ml=digitalRead(dml);
              mr=digitalRead(dmr);


            }
            
            for(int i=0;i<50;i++)
          brake();

            stop(); 
            delay(500);
            while(fr==0 && (mr==0 || ml==0))
            {
            forward();
             fr=digitalRead(dfr);
             ml=digitalRead(dml);
             mr=digitalRead(dmr);


            }
            
            for(int i=0;i<50;i++)
          brake();
            
      }

        else if(n==9)//diode
        {
          trightban(150,0,250);
          tleftban(370,0,250);
          forward();
          delay(130);
          kot();

        }

        else if(n==10)// resistor
        {
          forward();
          delay(50);
          trightban(450,0,250);
          forward();
          delay(100);
          tleftban(250,0,250);
          trightban(250,0,250);
          tleftban(250,0,250);
          trightban(250,0,250);
          tleftban(50,0,250);

          for(int i=0;i<20;i++)
          brake();
          stop();
          delay(1000);

        }
        
        else if(n==12) //K
        {
          trightban(80,0,250);
          mr=0;
          tright();
          b=1;
        }
        n++;
        a=0;
      }

    else if(n==11 && ml==1 && r1==1) //induktor
    {
          for(int i=0;i<100;i++)
          brake();

          tleftban(50,0,250);
          trightban(20,0,250);
          forward();
          delay(230);
          for(int i=0;i<100;i++)
          brake();
          mr=0;
          tright();
          trightban(50,0,250);
          n++;
        
    }
    

    else if (n==18 && fr==1 && r1==1 && r2==1 && bk==1)
      {for(int i=0;i<100;i++)
          brake();
          
          tright();n++;
          a=0;
      }
        
      if(a==1)
      {
        r2=digitalRead(dr2);
        l2=digitalRead(dl2);

        if(r2==1)
        {
            tright();
            if(n==7)
              b++;
        }
        else if(l2==1)
        {
          if(n==7&&b==3) //transformer
          {

              tleftban(50,0,250);
              forward();
              delay(400);
              l2=0;
              
              while(l2==0)
              {
                tleftban(T,0,200);
                l2=digitalRead(dl2);
              }

              fr=digitalRead(dfr);
              while(fr==0)
              {
              forward();
              fr=digitalRead(dfr);
              }

              for(int i=0;i<100;i++)
              brake();

              tleft();
              kot();
              //tleftban(500,0,250);
              forward();
              delay(470);
              tleftban(500,0,250); //385 270 50%, 392 260 60%, 
              forward();
              delay(120);

              stop();
              delay(1000);

            
            n++;
          }
          else if(n==13)
          {
            forward();
            delay(25);
            tleft();
          }

          else if(n==15)
          {
            for(int i=0;i<50;i++)
            brake();
            tleftban(900,0,250);
            forward();
            delay(80);
           
            
          }

          else if(n==16)
          {
            tleft();
            trightban(100,0,250);
            forward();
            delay(50);
          }
          else
          {
            tleft();
            if(n==7)
              b++;
          }

          
        }
      }
      
}

//class

void forward()
{
      analogWrite(d0,sl);
      analogWrite(d1,0);
      analogWrite(d2,sr);
      analogWrite(d3,0);
      delay(ms);
}
void tleftban(int time,int low, int high)
{
      analogWrite(d0,low);
      analogWrite(d1,0);
      analogWrite(d2,high);
      analogWrite(d3,0);
      delay(time);
}
void tleftbanreverse(int time,int low, int high)
{
      analogWrite(d0,0);
      analogWrite(d1,low);
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
void trightbanreverse(int time,int low, int high)
{
      analogWrite(d0,high);
      analogWrite(d1,0);
      analogWrite(d2,0);
      analogWrite(d3,low);
      delay(time);
}

void tright()
{
  trightban(50,0,255);
      r2=0;
      while(r2==0)
      {
        trightban(T,0,100); 
        r2=digitalRead(dr2);
      }
      mr=0;
      while(mr!=1)
      {
        delay(1);
        mr=digitalRead(dmr);
      }
      tleftban(50,0,255);
        
}
void trightreverse()
{
  for(int i=0;i<50;i++)
  brake();

   trightbanreverse(20,250,250);
   r2=0;
   while(r2==0)
  {
    trightbanreverse(T,100,100); 
    r2=digitalRead(dr2);
  }
  while(mr!=1)
  {
    if(n==13)
      brake1(d0 , d1);
    else 
    {
      delay(1);
      mr=digitalRead(dmr);
    }
  }
  if(n==13)
    tleftban(25,0,255);
  else
    tleftban(50,0,255);
}

void tleft()
{
  tleftban(50,0,255); 
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

void tleftreverse()
{
  for(int i=0;i<50;i++)
  brake();

   tleftbanreverse(20,250,250);
   l2=0;
   while(l2==0)
  {
    tleftbanreverse(T,100,100); 
    l2=digitalRead(dl2);
  }
  while(ml!=1)
  {
    if (n==2)
      brake1(d2 , d3);
   else
      delay(1);
    ml=digitalRead(dml);
  }
  if (n==2)
    trightban(25,0,255);
  else
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
      delay(2);
      analogWrite(x,0);
      analogWrite(y,0);
      delay(1);

}

void stop()
{
  analogWrite(d0,0);
  analogWrite(d1,0);
  analogWrite(d2,0);
  analogWrite(d3,0);
  delay(ms);
}
void kot()
{
  //keep on track belok kiri
  if (ml==0 && (mr==1 || r1==1) )
    {
        while(mr==1 || r1==1)
      {
        trightban(T,tsl,tsh);
        mr=digitalRead(dmr); 
        ml=digitalRead(dml);  
        r1=digitalRead(dr1);
        l1=digitalRead(dl1);
        r2=digitalRead(dr2);
        l2=digitalRead(dl2);
        fr=digitalRead(dfr);
        if((r1==1||r2==1)&&(l1==1||l2==1))
          break;
        else if((l1==1||r1==1) && fr==1)
          break;
          else if (mr==1 && (l2==1||r2==1))
          break;        
        else if (n==11 && ml==1 && r1==1)
          break;
        
      }

    }

    //keep on track belok kiri
    else if ((ml==1||l1==1) && mr==0)
    {
      while(ml==1||l1==1)
      {
        tleftban(T,tsl,tsh);
        mr=digitalRead(dmr); 
        ml=digitalRead(dml);       
        r1=digitalRead(dr1);
        l1=digitalRead(dl1);
        r2=digitalRead(dr2);
        l2=digitalRead(dl2);
        fr=digitalRead(dfr);
        if((r1==1||r2==1)&&(l1==1||l2==1))
          break;
        else if((l1==1||r1==1) && fr==1)
          break;
          else if (mr==1 && (l2==1||r2==1))
          break;        
        else if (n==11 && ml==1 && r1==1)
          break;
 
      }      
    }
}

void backward()
{
      analogWrite(d0,0);
      analogWrite(d1,sl);
      analogWrite(d2,0);
      analogWrite(d3,sr);
      delay(ms);
}
