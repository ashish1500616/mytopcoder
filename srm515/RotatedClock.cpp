class RotatedClock{
public:
  string getEarliest(int hh,int mh) {
    string res="";
    for(int mark=0;mark<360;mark+=30)
    {
      int hour=(hh+mark)%360;
      int minute(hour*12)%360;
      if(minute==(mh+mark)%360) {
        hour=hour/30;
        minute=minute/6;
        char tmp[10];
        sprintf(tmp,"%02d:%02d",hour,minute);
        string res=tmp;
        return res;
      }
    }
    return res;
  }
}