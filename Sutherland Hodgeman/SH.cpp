#include<stdio.h>
#include<graphics.h>
#include<math.h>

int LeftResultX[30];
int LeftResultY[30];
int TopResultX[30];
int TopResultY[30];
int RightResultX[30];
int RightResultY[30];
int BottomResultX[30];
int BottomResultY[30];

int xmin=20,ymin=40,xmax=100,ymax=100;

int LeftClip(int x[],int y[],int n)
{
    int s=0,j;
    for(int i=0;i<n;i++)
    {
        j=(i+1)%(n);
        if(x[i]<xmin && x[j]>=xmin) //out to in condition
        {
            LeftResultX[s]=xmin;
            LeftResultY[s]=y[i]+(xmin-x[i])*(y[j]-y[i])/(x[j]-x[i]);
            s++;
        }
        else if(x[i]<xmin && x[j]<xmin) //out to out condition
        {
            continue;
        }
        else if(x[i]>=xmin && x[j]<xmin) //in to out condition
        {
            LeftResultX[s]=x[i];
            LeftResultY[s]=y[i];
            s++;
            LeftResultX[s]=xmin;
            LeftResultY[s]=y[j]+(xmin-x[j])*(y[j]-y[i])/(x[j]-x[i]);
            s++;
        }
        else if(x[i]>=xmin && x[j]>=xmin) //in to in condition
        {
            LeftResultX[s]=x[i];
            LeftResultY[s]=y[i];
            s++;
        }
    }
    return s;
}

int TopClip(int x[],int y[],int n)
{
    int s=0,j;
    for(int i=0;i<n;i++)
    {
        j=(i+1)%n;
        if(y[i]>ymax && y[j]<=ymax) //out to in condition
        {
            TopResultX[s]=x[i]+(ymax-y[i])*(x[j]-x[i])/(y[j]-y[i]);
            TopResultY[s]=ymax;
            s++;
        }
        else if(y[i]>ymax && y[j]>ymax) //out to out condition
        {
            continue;
        }
        else if(y[i]<=ymax && y[j]>ymax) //in to out condition
        {
            TopResultX[s]=x[i];
            TopResultY[s]=y[i];
            s++;
            TopResultX[s]=x[j]+(ymax-y[j])*(x[j]-x[i])/(y[j]-y[i]);
            TopResultY[s]=ymax;
            s++;
        }
        else if(y[i]<=ymax && y[j]<=ymax) //in to in condition
        {
            TopResultX[s]=x[i];
            TopResultY[s]=y[i];
            s++;
        }
    }
    return s;
}

int RightClip(int x[],int y[],int n)
{
    int s=0,j;
    for(int i=0;i<n;i++)
    {
        j=(i+1)%(n);
        if(x[i]>xmax && x[j]<=xmax) //out to in condition
        {
            RightResultX[s]=xmax;
            RightResultY[s]=y[i]+(xmax-x[i])*(y[j]-y[i])/(x[j]-x[i]);
            s++;
        }
        else if(x[i]>xmax && x[j]>xmax) //out to out condition
        {
            continue;
        }
        else if(x[i]<=xmax && x[j]>xmax) //in to out condition
        {
            RightResultX[s]=x[i];
            RightResultY[s]=y[i];
            s++;
            RightResultX[s]=xmax;
            RightResultY[s]=y[j]+(xmax-x[j])*(y[j]-y[i])/(x[j]-x[i]);
            s++;
        }
        else if(x[i]<=xmax && x[j]<=xmax) //in to in condition
        {
            RightResultX[s]=x[i];
            RightResultY[s]=y[i];
            s++;
        }
    }
    return s;
}

int BottomClip(int x[],int y[],int n)
{
    int s=0,j;
    for(int i=0;i<n;i++)
    {
        j=(i+1)%n;
        if(y[i]<ymin && y[j]>=ymin) //out to in condition
        {
            BottomResultX[s]=x[i]+(ymin-y[i])*(x[j]-x[i])/(y[j]-y[i]);
            BottomResultY[s]=ymin;
            s++;
        }
        else if(y[i]<ymin && y[j]<ymin) //out to out condition
        {
            continue;
        }
        else if(y[i]>=ymin && y[j]<ymin) //in to out condition
        {
            BottomResultX[s]=x[i];
            BottomResultY[s]=y[i];
            s++;
            BottomResultX[s]=x[j]+(ymin-y[j])*(x[j]-x[i])/(y[j]-y[i]);
            BottomResultY[s]=ymin;
            s++;
        }
        else if(y[i]>=ymin && y[j]>=ymin) //in to in condition
        {
            BottomResultX[s]=x[i];
            BottomResultY[s]=y[i];
            s++;
        }
    }
    return s;
}

void drawwindow()
{
    setcolor(YELLOW);
    line(xmin,ymin,xmax,ymin);
    line(xmax,ymin,xmax,ymax);
    line(xmax,ymax,xmin,ymax);
    line(xmin,ymax,xmin,ymin);
    setcolor(WHITE);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x[]={55,55,15,65,115,75,75};
    int y[]={5,15,15,215,15,15,5};
    int n=7,j;
    drawwindow();
    for(int i=0;i<n;i++)
    {
        j=(i+1)%n;
        line(x[i],y[i],x[j],y[j]);
    }
    getch();
    cleardevice();
    drawwindow();
    int n1=LeftClip(x,y,n);
    for(int i=0;i<n1;i++)
    {
        j=(i+1)%n1;
        line(LeftResultX[i],LeftResultY[i],LeftResultX[j],LeftResultY[j]);
    }
    getch();
    cleardevice();
    drawwindow();
    int n2=TopClip(LeftResultX,LeftResultY,n1);
    for(int i=0;i<n2;i++)
    {
        j=(i+1)%n2;
        line(TopResultX[i],TopResultY[i],TopResultX[j],TopResultY[j]);
    }
    getch();
    cleardevice();
    drawwindow();
    int n3=RightClip(TopResultX,TopResultY,n2);
    for(int i=0;i<n3;i++)
    {
        j=(i+1)%n3;
        line(RightResultX[i],RightResultY[i],RightResultX[j],RightResultY[j]);
    }
    getch();
    cleardevice();
    drawwindow();
    int n4=BottomClip(RightResultX,RightResultY,n3);
    for(int i=0;i<n4;i++)
    {
        j=(i+1)%n4;
        line(BottomResultX[i],BottomResultY[i],BottomResultX[j],BottomResultY[j]);
    }
    getch();
}
