//
//  string.h
//  DataStructure
//
//  Created by SUMIT_THAKUR on 20/10/16.
//  Copyright © 2016 Sumit. All rights reserved.
//

int strlenn(int start,int end)
{
    int count=1;
    while(1)
    {
        if(start==end)
            break;
        ++count;
        ++start;
    }
    return count;
    
}

int strcmpp(char a[],char b[])
{
    int x[26]={0};
    int y[26]={0};
    int i=0;
    while(1)
    {
        if(a[i]=='\0' && b[i]=='\0')
            break;
        x[a[i]-97]++;
        y[b[i]-97]++;
        i++;
    }
    for(i=0;i<26;i++)
    {
        if(x[i]!=y[i])
            return 0;
        
    }
    return 1;
}

int *charocc(char a[])
{
    
    int *ptr= new int[26]();
    int i=0;
    while(1)
    {
        if(a[i]=='\0')
            break;
        ptr[a[i]-'a']++;
        ++i;
    }
    return ptr;
}

int strlenn(char a[])
{
    int c;
    if(*a=='\0')
    {
        return 0;
    }
    else
    {
        c=1+strlenn(&a[1]);
        return c;
    }
}

int remove_spaces(int start,int end,char *a)
{
   // cout<<start<<" "<<end<<endl;
    int Null=end-start;
    if(Null==1)
        return start+1;
    --Null;
    int l=strlenn(a);
    int s=start+1;
    if(start==0)
    {
        while(a[end]!='\0')
        {
            a[start]=a[end];
            start++;
            end++;
        }
        a[l-Null]='\0';
        return 1;
    }
    else
    {
        while(a[end]!='\0')
        {
            a[start+1]=a[end];
            start++;
            end++;
        }
        a[l-Null]='\0';
        return s;
    }
}
void strspace(char a[])
{
    int i=0;
    int flag=0;
    int start=0;
    int end=0;
    while(a[i]!='\0')
    {
        if(a[i]==' ' && flag==0)
        {
            start=i;
            flag=1;
        }
        else
            if(a[i]!=' ' && flag==1)
            {
                end=i;
                i=remove_spaces(start, end, a);
                flag=0;
            }
        i++;
    }
    
}

