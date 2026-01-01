/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for(int i=digitsSize-1;i>=0;i--){
        digits[i]++;
        if(digits[i]<10){
            
            *returnSize=digitsSize;
            return digits;
        }
            digits[i]=0;
    }
    int* new_digit = (int*)malloc((digitsSize + 1) * sizeof(int));
    new_digit[0]=1;
    for(int i=0;i<digitsSize;i++){
        new_digit[i+1]=digits[i];
    }
    *returnSize=digitsSize+1;
    return new_digit;

}