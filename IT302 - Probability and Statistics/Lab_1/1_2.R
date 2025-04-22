arr<-array(1:100)
odd_arr<-arr[arr%%2==1]
prob_odd<-length(odd_arr)/length(arr)
print(prob_odd)