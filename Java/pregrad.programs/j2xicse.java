import java.io.*;
class j2xicse
{
 public static void main(String args[])
 {
  public int l1 = 11;
  public int l2 = 7;
  public final float cons = 1.25f;
  public final String sub1[] = {};
  public final String sub2[] = {};
  public final float rfmin[] = {};
  public final float rfmax[] = {};
  public final float scmin[] = {};
  public final float scmax[] = {};
  public float avg80 = new float[l1];
  public float avg100 = new float[l1];
  public char grd = new char[l2];
  public float svg[] = new float[l2];
  for(int i1 = 0; i1 < l1; i1++)
  {
   avg80[i1] = (rfmin[i1] + rfmax[i1] + scmin[i1] + scmax[i1])/4.0f;
  }
  avg80[7] = avg[7]/cons;
  for(int i2 =0; i2 < l1; i2++)
  {
   avg100[i2] = avg80[i2] * cons;
  }
  avg100[7] = (rfmin[7] + rfmax[7] +scmin[7] + scmax[7])/4.0f;
  svg[0] = (avg100[0] + avg100[1])/2.0f;
  svg[1] = (avg100[2] + avg100[3])/2.0f;
  for(int i3 = 2; i3 < 6; i3++)
  {
   svg[i3] = avg100[i3+2];
  }
  svg[6] = (avg100[8] + avg100[9] + avg100[10])/3.0f;
  for(int i4 = 0; i4 < l2; i4++)
  {
   float t1 = svg[i4];
   if(t1 > 90.0f)
   {
    grd[i4] = 'A';
   }
   else if((t1 > 80.0f) && (t1 < 90.0f))
   {
    grd[i4] = 'B';
   }
   else if((t1 > 70.0f) && (t1 < 80.0f))
   {
    grd[i4] = 'C';
   }
   else if((t1 > 60.0f) && (t1 < 70.0f))
   {
    grd[i4] = 'D';
   }
   else
   {
    grd[i4] = 'f';
   }
  }
  /*    * calc per using avg100[]
        * calc per using svg[]
        * calc avg per of the two
        * calc per using 5-best subjects
        * display details
        * final per = avgper +/- (5-best - avgper)
  */
  float per;
  float s1 = 0.0f;
  for(int i5 = 0; i5 < l1; i5++)
  {
   s1 = s1 + avg100[i5];
  }
  per = s1/11.0f;
  float sper;
  float s2 = 0.0f;
  for(int i6 =0; i6 < l2; i6++)
  {
   s2 = s2 + svg[i6];
  }
  sper = s2/11.0f;
  float aper = (per + sper)/2.0f;
  float b5[] = new float[5];
  float t2;
  for(int i7 = 0; i7 < (l2-1); i7++)
  {
   for(int i8 = (i7+1); i8 < l2; i8++)
   {
    if(svg[i8] > svg[i7])
    {
     t2 = svg[i8];
     svg[i8] = svg[i7];
     svg[i7] =t2;
    }
   }
  }
  for(int i9 = 0; i9 < 5; i9++)
  {
   b5[i9] = svg[i9];
  }
  float s3;
  for(int i10 = 0; i10 < 5;i10++)
  {
   s3 = s3 + b5[i10];
  }
  float per5 = s3/5.0f;
  float permin; 
  float permax; 
  if(per5 > aper)
  {
   permin = per5 - (per5 - aper);
   permax = per5 + (per5 - aper);
  }
  else
  {
   permin = aper - (aper - per5);
   permax = aper + (aper - per5);
  }
 }
}
