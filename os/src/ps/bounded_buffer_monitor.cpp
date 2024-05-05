monitor mp{
  condition notfull, notempty;  
  int count=0,nextin=0,nextout=0;
  void append (char x){
    if (count == N) notfull.wait(); 
    buffer[nextin] = x;
    nextin=(nextin+1)%N;
    count++; 
    notempty.signal(); 
  }
  char take (void){
    if (count == 0) notempty.wait(); 
    char x=buffer[nextout];
    nextout=(nextout+1)%N);
    count--; 
    notfull.signal(); 
    return x
  }
};
void producer(void){
  char x;
  do{ 
    x = produce();  
    mp.append(x);
  }while(1);
}
void consume(void){
  char x;
  do{ 
    x = mp.take();  
    consume(x); 
  } while(1);
}