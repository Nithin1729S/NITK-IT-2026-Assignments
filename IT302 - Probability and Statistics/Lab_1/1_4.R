arr<-1:100
req<-arr[(arr%%4==0) & (arr%%6)==0]
prob=length(req)/length(arr)
print(prob)