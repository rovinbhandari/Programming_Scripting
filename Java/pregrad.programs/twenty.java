/*    PROGRAM TO CALCULATE INCOME TAX FOR THE FINANCIAL YEAR 2005-2006     */


import java.io.*;
class twenty
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println("");
  System.out.println("       PROGRAM TO CALCULATE INCOME TAX FOR THE FINANCIAL YEAR 2005-2006");
  System.out.println("       -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
  System.out.println("");
  System.out.println("INCOME");
  System.out.println("------");
  System.out.println("");
  double inc,a40;
  inc = a40 = 0;
  for(int i=1; ; i++)
  {
   System.out.println("Choose from :");
   System.out.println("# 1 # Monthly salary/income");
   System.out.println("# 2 # Annual salary/income");
   System.out.println("# 3 # <DONE>");
   int a41 = Integer.parseInt(x.readLine());
   if(a41==3)
   {
    break;
   }
   else if(a41!=3 && a41!=2 && a41!=1)
   {
    System.out.println("Wrong entry ! Please Re-Enter...");
   }
   else if(a41==2)
   {
    System.out.println("Enter the amount of annual salary/income :");
    a40 = Double.parseDouble(x.readLine());
   }
   else if(a41==1)
   {
    System.out.println("Enter the amount of monthly salary/income :");
    inc = Double.parseDouble(x.readLine());
   } 
   System.out.println("");
  }
  System.out.println("");
  System.out.println("DONATIONS (under section 80 G)");
  System.out.println("------------------------------");
  System.out.println("");
  double rel = 0;
  double don = 0;
  double rel1 = 0;
  double rel2 = 0;
  for(int i=1; ;i++)
  {
   System.out.println("Choose from :");
   System.out.println("# 1 # Prime Minister\'s Relief Fund");
   System.out.println("# 2 # National Defence Fund");
   System.out.println("# 3 # Prime Minister\'s Drought Relief Fund");
   System.out.println("# 4 # Other");
   System.out.println("# 5 # <DONE>");
   int a1 = Integer.parseInt(x.readLine());
   if(a1==5)
   {
    break;
   } 
   else if(a1!=5 && a1!=4 && a1!=3 && a1!=2 && a1!=1)
   {
    System.out.println("Wrong entry ! Please Re-Enter...");
   } 
   else if(a1==4)
   {
    System.out.println("Enter the amount of donation :");
    don = Double.parseDouble(x.readLine());
    System.out.println("Enter the Relief on the Donation (in percent) :");
    double a2 = Double.parseDouble(x.readLine());
    rel1 = (a2/100.0) * don;
   }
   else if(a1==1 || a1==2 || a1==3)
   {
    System.out.println("Enter the amount of donation :");
    don = Double.parseDouble(x.readLine());
    rel2 = don;
   }
   rel=rel1+rel2;
   System.out.println("");
  }
  System.out.println("");
  System.out.println("EXEMPTIONS/DEDUCTIONS (under section 80 C)");
  System.out.println("------------------------------------------");
  System.out.println("");
  double a3,a4,a5,a6,a7,a8,a9,a10,a11;
  a3=a4=a5=a6=a7=a8=a9=a10=a11=0;
  System.out.println("Money contributed to Provident Fund (P.F.) :");
  a3 = Double.parseDouble(x.readLine());
  System.out.println("Money contributed to Public Provident Fund (P.P.F.) :");
  a4 = Double.parseDouble(x.readLine());
  System.out.println("Money paid to Life Insurance Corporation (L.I.C.) :");
  a5 = Double.parseDouble(x.readLine());
  System.out.println("Investment in National Savings Certificate (N.S.C.) of post office :");
  a6 = Double.parseDouble(x.readLine());
  System.out.println("Investment in United Linked Insurance Plan (U.L.I.P.) of Unit Trust Of India :");
  a7 = Double.parseDouble(x.readLine());
  System.out.println("Investment in National Saving Scheme of post office :");
  a8 = Double.parseDouble(x.readLine());
  System.out.println("Investment in any pension plan :");
  a9 = Double.parseDouble(x.readLine());
  System.out.println("Money paid as principal amount of housing loan :");
  a10 = Double.parseDouble(x.readLine());
  System.out.println("Money paid as tution fees of maximum of two children :");
  a11 = Double.parseDouble(x.readLine());
  double exm = a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11;
  if(exm > 100000.0)
  {
   exm = 100000.0;
  }
  System.out.println("");
  System.out.println("EXEMPTION ON INTEREST ON HOUSING LOAN");
  System.out.println("-------------------------------------");
  System.out.println("");
  double exmp = 0;
  System.out.println("Interest on the loan taken for building own house  or");
  System.out.println("buying house for own use :");
  exmp = Double.parseDouble(x.readLine());
  if(exmp > 150000.0)
  {
   exmp = 150000.0;
  }
  System.out.println("");
  System.out.println("Please enter your name :");
  String name = x.readLine();
  int age = 0;
  for(int i=1; ;i++)
  {
   System.out.println("Choose from :");
   System.out.println("# 1 # Age is below 65 years (during 2005-2006)");
   System.out.println("# 2 # Age is 65 years or above (during 2005-2006)");
   System.out.println("# 3 # <DONE>");
   int a30 = Integer.parseInt(x.readLine());
   if(a30==3)
   {
    break;
   }
   else if(a30!=3 && a30!=2 && a30!=1)
   {
    System.out.println("Wrong entry ! Please Re-Enter...");
   }
   else if(a30==2)
   {
    age = 77;
   }
   else if(a30==1)
   {
    age = 33;
   }
  }
  int sex = 0;
  if(age < 65)
  {
   for(int i=1; ; i++)
   {
    System.out.println("Choose from :");
    System.out.println("# 1 # Male");
    System.out.println("# 2 # Female");
    System.out.println("# 3 # <DONE>");
    int a13 = Integer.parseInt(x.readLine());
    if(a13==1 || a13==2)
    {
     sex = a13;
    }
    else if(a13==3)
    {
     break;
    }
    else
    {
     System.out.println("Wrong entry ! Please Re-Enter...");
    }
   }
  }
  double tax = 0;
  double sal;
  if(a40 > 0)
  {
   sal = a40;
  }
  else 
  {
   sal = 12.0 * inc;
  }
  double tinc = sal - (rel + exm + exmp);
  if(age >= 65)
  {
   if(tinc < 185000.0)
   {
    tax = 0;
   }
   else if(tinc >= 185000.0 && tinc <= 250000.0)
   {
    tax = (20.0/100.0) * (tinc - 185000.0);
   }
   else
   {
    tax = 13000.0 + ((30.0/100.0) * (tinc - 250000));
   }
  }
  else if(age < 65 && sex==2)
  {
   if(tinc < 135000.0)
   {
    tax = 0;
   }
   else if(tinc >= 135000.0 && tinc < 150000.0)
   {
    tax = (10.0/100.0) * (tinc - 135000.0);
   }
   else if(tinc >= 150000.0 && tinc <= 250000.0)
   {
    tax = 1500.0 + ((20.0/100.0) * (tinc - 150000.0));
   }
   else
   {
    tax = 21500 + ((30./100.0) * (tinc - 250000.0));
   }
  }
  else
  {
   if(tinc < 100000.0)
   {
    tax = 0;
   }
   else if(tinc >= 100000.0 && tinc < 150000.0)
   {
    tax = (10.0/100.0) * (tinc - 100000.0);
   }
   else if(tinc >= 150000.0 && tinc <= 250000.0)
   {
    tax = 5000 + ((20.0/100.0) * (tinc - 150000.0));
   }
   else
   {
    tax = 25000 + ((30.0/100.0) * (tinc - 250000.0));
   }
  }
  double sur = 0;
  if(sal > 1000000.0)
  {
   sur = (10.0/100.0) * tax;
  }
  tax = tax + sur;
  double edu = (2.0/100.0) * tax;
  double net = tax + edu;
  System.out.println("");
  System.out.println("TAX DEDUCTION AT SOURCE (T.D.S.)");
  System.out.println("--------------------------------");
  System.out.println("");
  double tds = 0;
  for(int i=1; ;i++)
  {
   System.out.println("T.D.S. paid ?");
   System.out.println("Choose from :");
   System.out.println("# 1 # Yes");
   System.out.println("# 2 # No");
   System.out.println("# 3 # <DONE>");
   int a25 = Integer.parseInt(x.readLine());
   if(a25==3)
   {
    break;
   }
   else if(a25!=3 && a25!=2 && a25!=1)
   {
    System.out.println("Wrong entry ! Please Re-Enter...");
   }
   else if(a25==2)
   {
    break;
   }
   else
   {
    System.out.println("Enter monthly amount paid as T.D.S. :");
    double a14 = Double.parseDouble(x.readLine());
    System.out.println("Enter the number of months for which T.D.S. is paid :");
    int a15 = Integer.parseInt(x.readLine());
    tds = a14 * (double)a15;
   }
  }
  net = net - tds;
  double nett = 0; 
  double ret = 0;
  if(net < 0)
  {
   double a16 = -1.0;
   ret = net * a16;
  }
  else
  {
   nett = net;
  }
  double a17 = nett;
  double a18 = ret;
  a17+=0.5;
  a18+=0.5;
  String a19 = Double.toString(a17);
  int a20 = a19.indexOf('.');
  String a26 = a19.substring(0,a20);
  String a22 = Double.toString(a18);
  int a23 = a22.indexOf('.');
  String a27 = a22.substring(0,a23);
  double it = Double.parseDouble(a26);
  double re = Double.parseDouble(a27);
  System.out.println("");
  System.out.println("RESULT");
  System.out.println("------");
  System.out.println("");
  System.out.println("NAME >>> " + name);
  if(age==33)
  {
   System.out.println("AGE >>> LESS THAN 65 YEARS");
  }
  else
  {
   System.out.println("AGE >>> 65 YEARS OR MORE");
  }
  if(sex > 0)
  {
   if(sex==1)
   {
    System.out.println("SEX >>> MALE");
   }
   else
   {
    System.out.println("SEX >>> FEMALE");
   }
  }
  System.out.println("MONTHLY INCOME/SALARY >>> Rs. " + inc);
  System.out.println("GROSS ANNUAL INCOME >>> Rs. "+ sal);
  if(rel > 0)
  {
   System.out.println("RELIEF ON DONATIONS (under section 80 G) >>> Rs. " + rel);
  }
  if(exm > 0)
  {
   System.out.println("INVESTMENTS (under section 80 C) >>> Rs. " + exm);
  }
  if(exmp > 0)
  {
   System.out.println("HOUSING LOAN EXEMPTION >>>  Rs."+ exmp);
  }
  System.out.println("TAXABLE INCOME >>> Rs. " + tinc);
  System.out.println("EDUCATIONAL CESS >>> Rs. " + edu);
  if(tds > 0)
  {
  System.out.println("TOTAL TAX DEDUCTION AT SOURCE (T.D.S.) >>> Rs. " + tds);
  }
  if(sal > 1000000.0)
  {
   System.out.println("SURCHARGE >>> Rs. " + sur);
  }
  if(it > 0)
  {
   System.out.println("INCOME TAX TO BE PAID AT THE END OF 2005-2006: Rs." + it);
  }
  else if(re > 0)
  {
   System.out.println("AMOUNT REFUNDED AT THE END OF 2005-2006: Rs." + re);
  }
  else
  {
   System.out.println("INCOME TAX TO BE PAID AT THE END OF 2005-2006 >>> NIL");
   System.out.println("AMOUNT REFUNDED AT THE END OF 2005-2006 >>> NIL");
  }
  System.out.println("______________________________________________________________________________");
 }
}

  
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
