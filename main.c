#include<stdio.h>
//encryption given k = 1

char upperCase (char *x, int y); //make all letters in an array upper case
char roEncrypt(char *x, int y, int k, int i); //does rotation encryption with given k where x is the message, y is the size of the message array,
//i is the array number
char roDecrypt(char *x, int y);
char subEncrypt(char *key);





int main(){
    int k = 0, i = 0;
    k = 1; //k is the rotation amount
    char message[] = {"FUCKK YOUUUU"};
    int size = sizeof(message)/sizeof(char) - 1; // create interger 'size' and is the length of the array
    
    upperCase(message, size); //calling function to make all letters upper case
    printf("Original:   %s\n", message); //printing the original message
    
    //Rotation Encryption
    printf("Encrypted:  ");
    for (i = 0; i < size; i++){
    printf("%c", roEncrypt(message, size, k, i));
    }
    //
    //Rotation Decryption Given Key
    printf("\nDecrypted:  ");
    roDecrypt(message, size);
    printf("%s", message);
    
    //Substitution Encryption with key given in function
    printf("\n%s", subDecrypt());
    
    
    return 0;
    }

















//FUNCTION DEFINITIONS
char upperCase (char *x, int y) { //make all letters in an array upper case
    int i;
    for (i = 0; i < y; i++){ //make everything upper case
            if (x[i] >=97 && x[i] <= 122)   {
                x[i] -= 32;
            } 
        }
        return 0;
}

char roEncrypt(char *x, int y, int k, int i) {
    if (x[i] + k > 90){ //if adding k gives a value greater than Z, then minus 26 to make a value between A and Z
        x[i] = x[i] + k - 26;
        return x[i];
        }
    else if (x[i] + k <= 90 && x[i] >64){//if adding k gives value between A and Z, then just leave it at adding k
        x[i] += k;
        return x[i];
        }
    else
        return x[i]; //if it's some other ASCII punctuation, just print it as is
    }
    
char roDecrypt(char *x, int y){
    int i = 0, k = 1;
    for (i = 0, k = 1; i < y; i++){
        if (x[i] <= 90 && x[i] >= 65)
            x[i] = (x[i] - k);
            if (x[i] == 64)
                x[i] += 26;
        else
            x[i] = x[i];
    }
    return *x;
}
    
char subEncrypt(void){   //Substitution Cipher Encryption Given Key
    FILE *fp = fopen("message","r");
    char key[] = {"ZYXWVUTSRQPONMLKJIHGFEDCBA"};
    if (fp = NULL){
        return 0;}
    do
    {
        char c = fgetc(fp); //taking input single character at a time
        if (feof(fp))
            break;
        //make each letter according to key
        else if (c > 64 && c < 91)
            return key[c-65];
        else return c; 
    }
    while(1);
    fclose(fp);
}
