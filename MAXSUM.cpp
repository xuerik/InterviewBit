// Erik Xu
// C
// O(n^2) approach
int maxSubArray(const int* A, int n1) {
    int largest = A[0];
    int total;
    int i, j;
    
    for (i = 0; i < n1; i++) {
        total = 0;
        
        for (j = i; j < n1; j++) {
            total =  total + A[j];
            
            if(total > largest) {
                largest = total;
            }
        }
    }
    
    return largest;
}

// C++
// O(n) approach
int Solution::maxSubArray(const vector<int> &A) {
  int currentMax   = 0;
  int maxSum       = 0;
  int allNegatives = 0;
  int actualMax    = -INT_MAX;
  
  // Find the minimum element in the vector
  for (int i = 0; i < A.size(); ++i) {
    if (A[i] > actualMax) {
      actualMax = A[i];
    }
  }
  
  // Flag for whether all input are negatives
  if (actualMax < 0) {
    allNegatives = 1;
  }
  
  
  // Kadane's Algorithm
  for (int i = 0; i < A.size(); ++i) {
    if (allNegatives == 0) {
      currentMax = currentMax + A[i];
          
      if (currentMax < 0) {
        currentMax = 0;
      } else if (currentMax > maxSum) {
         maxSum = currentMax;
      } 
  }
      
    // All negatives
    else {
      maxSum = actualMax;
      break;
    }
  }
  
  return maxSum;
}
