#include<stdio.h>
#include<string.h>

  int main()
 {
   int l, i, k=0, p, tc, x;
   char a[14];
   
 scanf("%d", &tc);
 for(x=0; x<tc; x++)
 {

   scanf("%s",a);
   l=strlen(a);
   
   if(a[0]=='0')
   {
         printf("Zero");
   }
 
   i=l-1;
      while(i>=0 && a[0]!='0')    
     {    k=i+1; p=l-i-1;
          if((i+1)%3==0)
          { 
            if(a[p]=='1') {printf("One ");}          if(a[p]=='2') {printf("Two ");}           if(a[p]=='3'){printf("Three ");}
            if(a[p]=='4') {printf("Four ");}         if(a[p]=='5') {printf("Five ");}          if(a[p]=='6'){printf("Six ");}
            if(a[p]=='7') {printf("Seven "); }       if(a[p]=='8') {printf("Eight "); }        if(a[p]=='9') {printf("Nine ");} 
            if(a[p]!='0'){printf("Hundred ");}   i--;  p=l-i-1;
          }

          if((i+2)%3==0)
          {  
             if(a[p]=='1')
             {                                           if(a[p+1]=='0'){printf("Ten ");}
                if(a[p+1]=='1'){printf("Eleven ");}         if(a[p+1]=='2'){printf("Twelve ");}            if(a[p+1]=='3'){printf("Thirteen ");}       
                if(a[p+1]=='4'){printf("Fourteen ");}       if(a[p+1]=='5'){printf("Fifteen ");}           if(a[p+1]=='6'){printf("Sixteen ");}
                if(a[p+1]=='7'){printf("Seventeen ");}      if(a[p+1]=='8'){printf("Eighteen ");}          if(a[p+1]=='9'){printf("Nineteen ");}
                i=i-2;   p=l-i-1;
             }
            
             else
            {
                if(a[p]=='2') {printf("Twenty ");}           if(a[p]=='3'){printf("Thirty ");}           if(a[p]=='4') {printf("Forty ");}
                if(a[p]=='5') {printf("Fifty ");}            if(a[p]=='6'){printf("Sixty ");}              if(a[p]=='7') {printf("Seventy "); } 
                if(a[p]=='8') {printf("Eighty "); }           if(a[p]=='9') {printf("Ninety ");}
                i-=1;    p=l-i-1;
            }
          }
         
          if(i%3==0) 
          {  
             if(a[p]=='1') {printf("One ");   }           if(a[p]=='2') {printf("Two ");   }            if(a[p]=='3') {printf("Three ");   }
             if(a[p]=='4') {printf("Four ");  }           if(a[p]=='5') {printf("Five ");  }            if(a[p]=='6') {printf("Six ");     }
             if(a[p]=='7') {printf("Seven "); }           if(a[p]=='8') {printf("Eight "); }            if(a[p]=='9') {printf("Nine ");    }
                 i-=1;   
          }

       //   printf("%d\n", k);
          
          if(k<=12 && k>=10 && (a[p+2]!='0' || a[p+1]!='0' || a[p]!='0'))
          {
               printf("Billion ");
          }
          if(k<=9 && k>=7 && (a[p+2]!='0' || a[p+1]!='0' || a[p]!='0'))
          {
               printf("Million ");
          }
          if(k<=6 && k>=4 && (a[p+2]!='0' || a[p+1]!='0' || a[p]!='0'))
          {
               printf("Thousand ");
          }          
     }                    
   printf("\n");
  }
   
  return 0;
 }
