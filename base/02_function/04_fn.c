int fn(int n){
  if(n<0){
    printf("can not be negative!\n");
    return 0;
  }

  if(n==0){
   return 1;
  }else{
    return n*fn(n-1);
  }
}
