#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Global variables and function declaration*/
void send_to_file();
void get_form_plaintext();
void get_form_cipher();
int hextoint(char h);
void send_to_Dec(int a);
int bintoint (char arr[],int a , int b);
void keys();
void encryption();
void decryption();
void execution();
char k[10];
char plain_text[8];
char cipher[8];
char key_1[8];
char key_2[8];
char Enc[8];

int main()
{
    execution();
    keys();
    get_form_plaintext();
    get_form_cipher();
    //encryption();
   // decryption();
    return 0;
}
/*%%%%%%%%%%%%%%%%% Creation of Keys %%%%%%%%%%%%%%%%%%%%%%%%%%*/
void keys() {

    char P10[10];
    int p10_format[10] = { 3,5,2,7,4,10,1,9,8,6 };
    for (int i = 0; i < 10; i++)    {
    P10[i] = k[p10_format[i] - 1];
        //printf("%c ", P10[i]);
    }
    char LS1_L[5];
    int LS1L_format[5]={1,2,3,4,0};
    for(int i=0 ; i<5 ; i++){
        LS1_L[i]=P10[LS1L_format[i]];
       // printf("%c ",LS1_L[i]);
    }
    char LS1_R[5];
    int LS1R_format[5]={6,7,8,9,5};
    for(int i=0;i<5;i++){
        LS1_R[i]=P10[LS1R_format[i]];
      //  printf("%c ",LS1_R[i]);
    }
    char LS_1[10];
    int LS_format[10]={1,2,3,4,0,6,7,8,9,5};
    for(int i=0;i<10;i++){
        LS_1[i]=P10[LS_format[i]];
     // printf("%c ",LS_1[i]);
    }
    int SP_8[8]={6,3,7,4,8,5,10,9};
    for(int i=0;i<8;i++){
        key_1[i]=LS_1[SP_8[i]-1];
        //printf("%c ",key_1[i]);
    }
    char LS2_L[5];
    int LS2L_format[5]={2,3,4,0,1};
    for (int i=0;i<5;i++){
        LS2_L[i]=LS1_L[LS2L_format[i]];
       // printf("%c ",LS2_L[i]);
     }
     char LS2_R[5];
    int LS2R_format[5]={2,3,4,0,1};
    for (int i=0;i<5;i++){
        LS2_R[i]=LS1_R[LS2R_format[i]];
      // printf("%c ",LS2_R[i]);
     }
     char LS_2[10];
     int LS2_format[10]={2,3,4,0,1,7,8,9,5,6};
     for(int i=0; i<10;i++){
        LS_2[i]=LS_1[LS2_format[i]];
        //printf("%c ",LS_2[i]);
     }
     for (int i=0;i<8;i++){
        key_2[i]=LS_2[SP_8[i]-1];
       // printf("%c ",key_2[i]);
     }
}

void execution(){

int key;
printf("Please write your text into PlaneText.txt file for Encryption and Decryption \n");
printf("  Please enter the key value from 0 to 1023\n");
scanf("%d",&key);
 if (key >=0 && key<=1023){
    for (int i = 9; i >= 0; i--) {
		k[i] = 	(key % 2)+'0';
		key /= 2;
             }
             printf("Please refer to Cipher.txt file for the Ciphered data and DeCipher.txt for the Deciphered data. \n");
             }else
                {
                 printf("The given key is out of range.\n Please enter a valid key. \n");
             }
  }
/*%%%%%%%%%%%%% Encryption Function %%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
void encryption(){
    int ip_format[8]={2,6,3,1,4,8,5,7};
    char IP[8];
    for(int i=0;i<8;i++){
            IP[i]=plain_text[ip_format[i]-1];
           // printf("%c ",IP[i]);
    }
    char IP_L[4];
    int IPL_format[4]={0,1,2,3};
    for(int i=0;i<4;i++){
    IP_L[i]=IP[IPL_format[i]];
      // printf("%c ",IP_L[i]);
    }
        char IP_R[4];
        int IPR_format[4]={4,5,6,7};
        for(int i=0;i<4;i++){
        IP_R[i]=IP[IPR_format[i]];
        //printf("%c ",IP_R[i]);
    }
    char EP[8];
    int EP_format[8]={4,1,2,3,2,3,4,1};
    for(int i=0;i<8;i++){
        EP[i]=IP_R[EP_format[i]-1];
       //printf("%c ",EP[i]);
    }
    char EP_K1[8];
    for(int i=0;i<8;i++){
        if(EP[i]==key_1[i]){
            EP_K1[i]='0';
        }
        else{
            EP_K1[i]='1';
        }
          // printf("%c ",EP_K1[i]);
        }
        char XOR1_L[4];
        int XORL_format[4]={0,1,2,3};
        for(int i=0;i<4;i++){
            XOR1_L[i]=EP_K1[XORL_format[i]];
           //printf("%c ",XOR1_L[i]);
        }
        char XOR1_R[4];
        int XORR_format[4]={4,5,6,7};
        for(int i=0;i<4;i++){
            XOR1_R[i]=EP_K1[XORR_format[i]];
           // printf("%c ",XOR1_R[i]);
        }
        int matrix [2][2]={{0,1},{2,3}};
        int col,row,value;
        row=matrix[XOR1_L[0]-'0'][XOR1_L[3]-'0'];
        col=matrix[XOR1_L[1]-'0'][XOR1_L[2]-'0'];
       // printf("row=%d column=%d\n",row,col);
        int S0[4][4] = {
		{1,0,3,2},
		{3,2,1,0},
		{0,2,1,3},
		{3,1,3,2}
	};
        int S1[4][4] = {
		{0,1,2,3},
		{2,0,1,3},
		{3,0,1,0},
		{2,1,0,3}
	};
	char merge[4];
	value= S0[row][col];
	merge[1]=(value % 2)+'0';
	value=value/2;
	merge[0]=(value % 2)+'0';


     row=matrix[XOR1_R[0]-'0'][XOR1_R[3]-'0'];
     col=matrix[XOR1_R[1]-'0'][XOR1_R[2]-'0'];
      // printf("row=%d column=%d\n",row,col);

    value=S1[row][col];
    merge[3]=(value % 2)+'0';
    value=value/2;
    merge[2]=(value % 2)+'0';

    int P4_format[4]={2,4,3,1};
    char P4[4];
    for(int i=0; i<4; i++){
        P4[i]=merge[P4_format[i]-1];
        //printf("%c",P4[i]);
    }
    char P4_XOR[4];

    for(int i=0;i<4;i++){
        if(IP_L[i]==P4[i]){
            P4_XOR[i]='0';
        }
            else{
                 P4_XOR[i]='1';
            }

       //printf("%c", P4_XOR[i]);

    }
    for (int i=0;i<8;i++){
       EP[i]=P4_XOR[EP_format[i]-1];
 //  printf("%c",EP[i]);
    }
        for (int i=0;i<8;i++){
            if(EP[i]==key_2[i]){
                EP_K1[i]='0';
            }
            else{
                EP_K1[i]='1';
            }
          // printf("%c",EP_K1[i]);
        }
        for (int i = 0; i < 4; i++) {
		 XOR1_L[i]=EP_K1[XORL_format[i]];
		//printf("%c",XOR1_L[i]);
        }
        for (int i = 0; i < 4; i++) {
        XOR1_R[i]=EP_K1[XORR_format[i]];
		//printf("%c",XOR1_R[i]);
	}
	row = matrix[XOR1_L[0] - '0'][XOR1_L[3] - '0'];
	col = matrix[XOR1_L[1] - '0'][XOR1_L[2] - '0'];
	//printf("row=%d column=%d\n",row,col);
	value = S0[row][col];

	merge[1] = (value % 2) + '0';
	value = value / 2;
	merge[0] = (value % 2) + '0';

	row = matrix[XOR1_R[0] - '0'][XOR1_R[3] - '0'];
	col = matrix[XOR1_R[1] - '0'][XOR1_R[2] - '0'];
	//printf("row=%d column=%d\n",row,col);

	value = S1[row][col];
	merge[3] = (value % 2) + '0';
	value = value / 2;
	merge[2] = (value % 2) + '0';

	for (int i = 0; i < 4; i++) {
		P4[i] = merge[P4_format[i] - 1];
		//printf("%c", P4[i]);
	}
	char P4_XOR2[4];
	for (int i = 0; i < 4; i++) {
		if (IP_R[i] == P4[i]) {
			P4_XOR2[i] = '0';
		}
		else
		{
			P4_XOR2[i] = '1';
		}
		//printf("%c", P4_XOR[i]);
	}
	char Merg_P4[8];
	for (int i = 0; i < 4; i++) {
		Merg_P4[i] = P4_XOR2[i];
		//printf("%c", Merg_P4[i]);
	}
		for (int i = 4; i < 8; i++) {
		Merg_P4[i] = P4_XOR[i-4];
		//printf("%c", Merg_P4[i]);
		}
		for (int i = 0; i < 8; i++) {
		//printf("%c", Merg_P4[i]);
		}

		int Enc_format[8] = { 4,1,3,5,7,2,8,6 };
        for (int i = 0; i < 8; i++) {
		Enc[i] = Merg_P4[Enc_format[i] - 1];
		//printf("%c", Enc[i]);
	}
}
/*%%%%%%%%%%%%%% Decryption Function %%%%%%%%%%%%%%%%%%%%%%%%%%*/
void decryption(){
    int ip_format[8]={2,6,3,1,4,8,5,7};
    char IP[8];
    for(int i=0;i<8;i++){
            IP[i]=cipher[ip_format[i]-1];
           // printf("%c ",IP[i]);
    }
    char IP_L[4];
    int IPL_format[4]={0,1,2,3};
    for(int i=0;i<4;i++){
    IP_L[i]=IP[IPL_format[i]];
      // printf("%c ",IP_L[i]);
    }
        char IP_R[4];
        int IPR_format[4]={4,5,6,7};
        for(int i=0;i<4;i++){
        IP_R[i]=IP[IPR_format[i]];
        //printf("%c ",IP_R[i]);
    }
    char EP[8];
    int EP_format[8]={4,1,2,3,2,3,4,1};
    for(int i=0;i<8;i++){
        EP[i]=IP_R[EP_format[i]-1];
       //printf("%c ",EP[i]);
    }
    char EP_K1[8];
    for(int i=0;i<8;i++){
        if(EP[i]==key_2[i]){
            EP_K1[i]='0';
        }
        else{
            EP_K1[i]='1';
        }
          // printf("%c ",EP_K1[i]);
        }
        char XOR1_L[4];
        int XORL_format[4]={0,1,2,3};
        for(int i=0;i<4;i++){
            XOR1_L[i]=EP_K1[XORL_format[i]];
           //printf("%c ",XOR1_L[i]);
        }
        char XOR1_R[4];
        int XORR_format[4]={4,5,6,7};
        for(int i=0;i<4;i++){
            XOR1_R[i]=EP_K1[XORR_format[i]];
           // printf("%c ",XOR1_R[i]);
        }
        int matrix [2][2]={{0,1},{2,3}};
        int col,row,value;
        row=matrix[XOR1_L[0]-'0'][XOR1_L[3]-'0'];
        col=matrix[XOR1_L[1]-'0'][XOR1_L[2]-'0'];
       // printf("row=%d column=%d\n",row,col);
        int S0[4][4] = {
		{1,0,3,2},
		{3,2,1,0},
		{0,2,1,3},
		{3,1,3,2}
	};
        int S1[4][4] = {
		{0,1,2,3},
		{2,0,1,3},
		{3,0,1,0},
		{2,1,0,3}
	};
	char merge[4];
	value= S0[row][col];
	merge[1]=(value % 2)+'0';
	value=value/2;
	merge[0]=(value % 2)+'0';


     row=matrix[XOR1_R[0]-'0'][XOR1_R[3]-'0'];
     col=matrix[XOR1_R[1]-'0'][XOR1_R[2]-'0'];
      // printf("row=%d column=%d\n",row,col);

    value=S1[row][col];
    merge[3]=(value % 2)+'0';
    value=value/2;
    merge[2]=(value % 2)+'0';

    int P4_format[4]={2,4,3,1};
    char P4[4];
    for(int i=0; i<4; i++){
        P4[i]=merge[P4_format[i]-1];
        //printf("%c",P4[i]);
    }
    char P4_XOR[4];

    for(int i=0;i<4;i++){
        if(IP_L[i]==P4[i]){
            P4_XOR[i]='0';
        }
            else{
                 P4_XOR[i]='1';
            }

       //printf("%c", P4_XOR[i]);

    }
    for (int i=0;i<8;i++){
       EP[i]=P4_XOR[EP_format[i]-1];
 //  printf("%c",EP[i]);
    }
        for (int i=0;i<8;i++){
            if(EP[i]==key_1[i]){
                EP_K1[i]='0';
            }
            else{
                EP_K1[i]='1';
            }
          // printf("%c",EP_K1[i]);
        }
        for (int i = 0; i < 4; i++) {
		 XOR1_L[i]=EP_K1[XORL_format[i]];
		//printf("%c",XOR1_L[i]);
        }
        for (int i = 0; i < 4; i++) {
        XOR1_R[i]=EP_K1[XORR_format[i]];
		//printf("%c",XOR1_R[i]);
	}
	row = matrix[XOR1_L[0] - '0'][XOR1_L[3] - '0'];
	col = matrix[XOR1_L[1] - '0'][XOR1_L[2] - '0'];
	//printf("row=%d column=%d\n",row,col);
	value = S0[row][col];

	merge[1] = (value % 2) + '0';
	value = value / 2;
	merge[0] = (value % 2) + '0';

	row = matrix[XOR1_R[0] - '0'][XOR1_R[3] - '0'];
	col = matrix[XOR1_R[1] - '0'][XOR1_R[2] - '0'];
	//printf("row=%d column=%d\n",row,col);

	value = S1[row][col];
	merge[3] = (value % 2) + '0';
	value = value / 2;
	merge[2] = (value % 2) + '0';

	for (int i = 0; i < 4; i++) {
		P4[i] = merge[P4_format[i] - 1];
		//printf("%c", P4[i]);
	}
	char P4_XOR2[4];
	for (int i = 0; i < 4; i++) {
		if (IP_R[i] == P4[i]) {
			P4_XOR2[i] = '0';
		}
		else
		{
			P4_XOR2[i] = '1';
		}
		//printf("%c", P4_XOR[i]);
	}
	char Merg_P4[8];
	for (int i = 0; i < 4; i++) {
		Merg_P4[i] = P4_XOR2[i];
		//printf("%c", Merg_P4[i]);
	}
		for (int i = 4; i < 8; i++) {
		Merg_P4[i] = P4_XOR[i-4];
		//printf("%c", Merg_P4[i]);
		}
		for (int i = 0; i < 8; i++) {
		//printf("%c", Merg_P4[i]);
		}
		char Dec[8];
		int Dec_format[8] = { 4,1,3,5,7,2,8,6 };
        for (int i = 0; i < 8; i++) {
		Dec[i] = Merg_P4[Dec_format[i] - 1];
		//printf("%c", Dec[i]);

	}
       send_to_Dec(bintoint (Dec,7, 0));
}
/*%%%%%%%%%Function to decipher the given text %%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
/*convert the given binary to decimal and send to DeCipher.txt file*/
void send_to_Dec(int a){

 FILE *fp;
      fp = fopen("DeCipher.txt", "a");

        fprintf(fp,"%c",a);

    fclose(fp);
}
/*%%%% Function to send ciphered data in hexadecimal to Cipher.txt file  %%%%%%*/
void send_to_file(){

 FILE *fp; /*To open a file you need to use the fopen function, which returns a FILE pointer.*/
      fp = fopen("Cipher.txt", "a");  /* a  mode: open for appending (file need not exist)*/

        fprintf(fp,"%lX",bintoint(Enc,3,0));

        fprintf(fp,"%lX",bintoint(Enc,7,4));
    fclose(fp);
}
/*%%% Read the ciphered data from Cipher.txt and Decrypt using Decryption function  %%%%%*/
void get_form_cipher(){
/*convert the given character data from user to binary*/

     int asc;
     char c ;
    FILE *fp;
      fp = fopen("Cipher.txt", "r"); /*	r mode: Open a file for reading. If a file is in reading mode,
                                                then no data is deleted if a file is already present on a system. */
      while(!feof(fp)){   /*tests the end-of-file indicator for the given stream.*/

        c=fgetc(fp);
        asc = hextoint(c);
        if(asc == -1){
            break;
        }
         for(int j = 3 ; j>=0 ; j--){
               cipher[j] = (asc%2) +'0' ;
               asc /=2 ;
         }
          c=fgetc(fp);
        asc = hextoint(c);
        if(asc == -1){
            break;
        }
         for(int j = 7 ; j>=4 ; j--){
               cipher[j] = (asc%2) +'0' ;
               asc /=2 ;
         }
        decryption();
}}
/*%%% Convert the binary value into integer used in data decryption  %%%%%%%*/
int bintoint (char arr[],int a , int b){

    int decimal=0;
    for(int i=a ; i>=b ; i--){
        decimal += (arr[i]-'0')*pow(2,a-i);
     }
     return decimal;
}
/*%%%%%% Conversion of Hexadecimal into Integer value  %%%%%%%%%%%%%%%%%%%%%%%%%%*/
int hextoint(char h){
/*Declaration and conditions of hexadecimal value*/
    if (h >= '0' && h <='9'){

        return h - '0';

    }else if(h >= 'a' && h <='f' ){

        return h - 'a' + 10;

    }else if (h >= 'A' && h <='F' ){

        return h - 'A' + 10;
    }
}
/*%%%%%%%% Read the file from PlaneText.txt to encrypt the text %%%%%%%%%%%%%%%*/
void get_form_plaintext(){
 int asc;

    FILE *fp;
      fp = fopen("PlaneText.txt", "r");
      while(!feof(fp)){

        asc=fgetc(fp);
        if(asc == -1){
            break;
        }
         for(int j = 7 ; j>=0 ; j--){
               plain_text[j] = (asc%2) +'0' ;
               asc /=2 ;
         }
          encryption();
          send_to_file();
           // printf("\n");

      }
       fclose(fp);
}
