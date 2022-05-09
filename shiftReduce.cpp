#include<stdio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10]; void check();
int main()
{
puts("GRAMMAR is \n E->E+E \n E->E*E \n E->(E) \n E->id"); puts("Enter input string ");
gets(a); c=strlen(a);
strcpy(act,"SHIFT->");
puts("STACK \t INPUT \tCOMMENT");
//puts("$ \t");
//puts(a);
printf("$ \t%s$\n",a);
for(k=0,i=0; j<c; k++,i++,j++)
{
if(a[j]=='i' && a[j+1]=='d')
{
stk[i]=a[j];
stk[i+1]=a[j+1];
stk[i+2]='\0';
a[j]=' ';
a[j+1]=' ';
//printf("$ \t%s$\n",a); printf("\n$%s\t%s$\t%sid",stk,a,act); check();
}
else
{
stk[i]=a[j];
stk[i+1]='\0';
a[j]=' ';
printf("\n$%s\t%s$\t%ssymbols",stk,a,act); check();
}
}
}
void check()
{
strcpy(ac,"REDUCE TO E"); for(z=0; z<c; z++)
if(stk[z]=='i' && stk[z+1]=='d')
{
stk[z]='E';
stk[z+1]='\0'; printf("\n$%s\t%s$\t%s",stk,a,ac); j++;
}
for(z=0; z<c; z++)
if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E')
{
stk[z]='E';
stk[z+1]='\0';
stk[z+2]='\0'; printf("\n$%s\t%s$\t%s",stk,a,ac); i=i-2;
}
for(z=0; z<c; z++)
if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E')
{
stk[z]='E';
stk[z+1]='\0';
stk[z+1]='\0'; printf("\n$%s\t%s$\t%s",stk,a,ac); i=i-2;
}
for(z=0; z<c; z++)
if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')')
{
stk[z]='E';
stk[z+1]='\0';
stk[z+1]='\0'; printf("\n$%s\t%s$\t%s",stk,a,ac); i=i-2;
}
}

/* 1. Start the Process.
2. Symbols from the input are shifted onto stack until a handle appears on top of the stack.
3. The Symbols that are the handle on top of the stack are then replaces by the left-hand side of the production (reduced).
4. If this result in another handle on top of the stack, then another reduction is done, otherwise we go back to shifting.
5. This combination of shifting input symbols onto the stack and reducing productions when handles appear on the top of the stack continues until all of the input is consumed and the goal symbol is the only thing on the stack - the input is then accepted.
6. If we reach the end of the input and cannot reduce the stack to the goal symbol, the input is rejected.
7. Stop the process. */