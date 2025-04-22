#include <stdio.h>
#include <string.h>

int main() {
    int a[10]={[4]=5,[2]=15};
    for(int i=0;i<6;i++) printf("%d ",a[i]);

    return 0;
}
