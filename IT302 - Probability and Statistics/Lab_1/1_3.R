isPrime<-function(n){
  if(n<=1){
    return(0)
  }
  for(i in 2:sqrt(n)){
    if(n%%i==0){
      return(0)
    }
  }
  return(1)
}

arr<-1:100
primes<-arr[sapply(arr,isPrime)]
prob_prime<-length(primes)/length(arr)
print(prob_prime)
