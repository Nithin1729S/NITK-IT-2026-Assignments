arr<-array(1:100)
even_arr<-arr[arr%%2==0]
prob_even<-length(even_arr)/length(arr)
print(prob_even)