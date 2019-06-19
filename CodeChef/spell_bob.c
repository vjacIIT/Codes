#include<stdio.h>


int main()
{
		int i, j, k, tc, w, flag, b, o;
	 	char str1[5], str2[5];
		char com_str[5];
		scanf("%d", &tc);

		while(tc--)
		{ 
				flag=0; b=0; o=0;
				scanf("%s%s", str1,str2);
				for(i=0; i<2; i++)
				{
						for(j=0; j<2; j++)
						{
								for(k=0; k<2; k++)
								{		
										b=0; o=0;
										if(i==0)
	      								com_str[0] = str1[0];
										else if(i==1)
											com_str[0] = str2[0];
	      							if(j==0)
	      								com_str[1] = str1[1];
										else if(j==1)
											com_str[1] = str2[1];
										if(k==0)
	      								com_str[2] = str1[2];
										else if(k==1)
											com_str[2] = str2[2];
										for(w=0; w<3; w++)
										{		
												if(com_str[w]=='b')
												   b++;
												else if(com_str[w]=='o')
													o++;													
										}
										
										if(b==2 && o==1 && flag==0)
										{
												printf("yes\n"); 		flag=1;
										}
								}
							if(flag)	
							break;
						}
					if(flag)
					break;
				}
			if(flag==0)
				printf("no\n");
 		}             
	return 0;
}




