#include <stdio.h>
#define TABLE_LIMIT 128
#define NULLP -32625
#define L_VAL 0 
#define R_VAL 1
#define TYPE 2

int magic_table[3][TABLE_LIMIT];


typedef int pointer_t ;

enum Types 
{
	INT,
	ADDR	
};

int genAddr()
{
	static int count =0;
	int base = 111000;
	
	return base + count++;
}

int init_magic_table()
{
	int i;
	for(i=0; i< TABLE_LIMIT; i++)
	{
		magic_table[L_VAL][i] = NULLP;
	 	magic_table[R_VAL][i] = NULLP;
	}  
	
}

void fill_magic_table(int n)
{
    int i;
	for(i=0; i< n; i++)
	{
		
		magic_table[L_VAL][i] = genAddr();	
	    
	}  	
}


int addr_of(int magic_no)
{
	 int i=0;
	for(i=0; i< TABLE_LIMIT; i++)
	  {
	  	 
	  	  if( magic_table[L_VAL][i] == magic_no)
	  	  {
	  	  	 
	  	  	  return i;
		  }
	  	
	  }
	return -1;
}
int assign(pointer_t p,int value,enum Types ty)
{
	int get_addr = addr_of(p);
	magic_table[R_VAL][get_addr] = value;	
	magic_table[TYPE][get_addr] = (int)ty;
}

int deref(int magic_no)
{
	static int deref_level =1;
	int i=0;
	for(i=0; i< TABLE_LIMIT; i++)
	{
		
		  if( magic_no == magic_table[L_VAL][i])
		  { 
		     deref_level++;
		 	 return magic_table[R_VAL][i];
		  }

	}
	
	
}

int main()
{
	 init_magic_table();
	 fill_magic_table(10);
	pointer_t p = 111000;
	assign(p,'c',INT);
	pointer_t z = p+3;
	assign(z,p,ADDR);
	printf("%c\n",deref(deref(z)));
		
}



