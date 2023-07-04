){
  int end = start;
  int curr_petrol = 0;
  while(true){
   curr_petrol += (petrol[end] - dist[end]);
   if(curr_petrol < 0){