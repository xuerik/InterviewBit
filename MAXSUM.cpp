/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
 
// O(n^2) approach
int maxSubArray(const int* A, int n1) {
    int largest = A[0];
    int total;
    int i, j;
    
    for(i = 0; i < n1; i++) {
        total = 0;
        
        for(j = i; j < n1; j++) {
            total =  total + A[j];
            
            if(total > largest) {
                largest = total;
            }
        }
    }
    
    return largest;

    
    
}
