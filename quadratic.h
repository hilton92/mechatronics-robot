/* 
 * File:   quadratic.h
 * Author: Justin
 *
 * Created on April 7, 2016, 8:46 PM
 */

#ifndef QUADRATIC_H
#define	QUADRATIC_H

//#include<stdio.h>
//#include<math.h>

void gatherData();
void regression(int);

float IRdata[300];
float second;
float first;
float zeroth;

void findDispenser()
{
    float degree = 360;
    toggleMotorsOff();
    
    //set motor direction
    setMotorDirection(LEFT,BACKWARD);
    setMotorDirection(RIGHT,FORWARD); 
    
     //set motor speeds
//    setMotorSpeed(LEFT,MOTORLOWSPEED);
//    setMotorSpeed(RIGHT, MOTORLOWSPEED);  
    setBothMotorSpeeds(MOTORLOWSPEED);
    
    //turn on motors
//    toggleMotors(LEFT,ON);
//    toggleMotors(RIGHT,ON); 
    toggleMotorsOn();
    
    //clearEventInfo(PERIODCOUNTRIGHT);
    setLow(&motorPeriodCount);
    //PR4 = MOTORLOWSPEED;
    
    //convert degree to counts
    int count = QUARTERTURNCOUNT/90.0 * degree;
    
    //read in a value every tenth time
    int spread = 100;
    int track = 0;
    int n = 0;
    
    while(motorPeriodCount < count)
    {
        if(track == spread)
        {
            float sum = 0;
            int count = 0;

            while (count < 70)
            {
                sum = sum + readAD(15);
                count++;
            }
                      
            IRdata[n] =  sum / 70.0;
            n++;
            track = 0;                        
        }
        track++;
    }
    
    toggleMotorsOff();
    n--;
    
    
    
    regression(n);
    
    float m = 2 * second;
    float b = first;
    
    int zero = (int)(-b / m);
    
    
    //convert the zero to be 0 thru 360;
    int position = (int)(zero/n *360);
    
    degree = position;
    //get back to square one
    toggleMotorsOff();
    
    //set motor direction
    setMotorDirection(LEFT,BACKWARD);
    setMotorDirection(RIGHT,FORWARD); 
    
     //set motor speeds
//    setMotorSpeed(LEFT,MOTORLOWSPEED);
//    setMotorSpeed(RIGHT, MOTORLOWSPEED);  
    setBothMotorSpeeds(MOTORLOWSPEED);
    
    //turn on motors
//    toggleMotors(LEFT,ON);
//    toggleMotors(RIGHT,ON); 
    toggleMotorsOn();
    
    //clearEventInfo(PERIODCOUNTRIGHT);
    setLow(&motorPeriodCount);
    //PR4 = MOTORLOWSPEED;
    
    //convert degree to counts
    count = QUARTERTURNCOUNT/90.0 * degree;
    
    while(motorPeriodCount < count)
    {          
    }
    
    toggleMotorsOff();
    
    
}

void regression(int n1)
{
    int n, i, j, k;
    float sumx, sumxsq, sumy, sumxy;
    float sumx3, sumx4, sumxsqy, a[20][20], u=0.0, b[20];
    //Printf(?\n Enter the n value?);
    //Scanf(?%d?, &n);
    n = n1;
    sumx = 0;
    sumxsq = 0;
    sumy = 0;
    sumxy = 0;
    sumx3 = 0;
    sumx4 = 0;
    sumxsqy = 0;
    for(i=0; i<n; i++)
    {
         //scanf(?%f %f?, &x, &y);
         sumx += i;
         sumxsq += i * i;//pow(x,2);
         sumx3 += i * i * i; //pow(x,3);
         sumx4 += i * i * i * i; //pow(x,4);
         sumy += IRdata[i];
         sumxy += i * IRdata[i];
         sumxsqy += i * i * IRdata[i]; //pow(x,2) *y;
    }
    a[0][0] = n;
    a[0][1] = sumx;
    a[0][2] = sumxsq;
    a[0][3] = sumy;
    a[1][0] = sumx;
    a[1][1] = sumxsq;
    a[1][2] = sumx3;
    a[1][3] = sumxy;
    a[2][0] = sumxsq;
    a[2][1] = sumx3;
    a[2][2] = sumx4;
    a[2][3] = sumxsqy;
    for(i=0;  i<3; i++)
    { 
        for(j=0;  j<=3; j++)
        {
           //printf(?%10.2f?,a[i][j]);
           //Printf(?\n?);
        }
        for(k=0;  k<=2; k++)
        {
             for(i=0;i<=2;i++)
             {
                      if(i!=k)
                      {
                         u=a[i][k]/a[k][k];
                      }
                      for(j = k; j<=3; j++)
                      {
                          a[i][j]=a[i][j] - u * a[k][j];              
                      }
             }
          }

     for(i=0;i<3;i++)
     {
            b[i] = a[i][3]/a[i][i];
            //Printf(?\nx[%d] = %f?, I, b[i]);
     }
        //  Printf(?\n?);
        // Printf(?y= %10.4fx +10.4 fx +%10.4f?,b[2],b[i],b[0]);
        second = b[2];
        first = b[1];
        zeroth = b[0];
    }
}

#endif	/* QUADRATIC_H */

