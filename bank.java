import java.io.*;
import java.util.*;

class Declare
{
    Vector<Integer> v_accno = new Vector<Integer>();
    Vector<String> v_name = new Vector<String>();
    Vector<Float> v_balance = new Vector<Float>();
}

class login
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String username="admin";
    static String password="1234";
    String user;
    String pass;
    
    void accept()
    {
        try{
            System.out.println("--------------------------------------------------------------------------------");
            System.out.println("\n\t\tWelcome To Bank Management System\n");
            System.out.println("\nEnter The Username : ");
            user = br.readLine();
            System.out.println("Enter The Password : ");
            pass = br.readLine();
        }
        catch(Exception e)
        {}
    }

    void check()
    {
        for(int i = 2; i >= 0 ; i--)
        {
            accept();
            if(username.compareTo(user) == 0 && password.compareTo(pass) == 0)
            {
                System.out.println("\n\n Login Successfull....\n\n");
                bank.mainmenu();
                break;
            }
            else
            {
                System.out.println("\n\n Login Unsuccessfull !!!");
                System.out.println(" The Entered Username Or Password May Be Incorrect !!!");
                if(i > 0)
                    System.out.println(" You Have "+i+" Chance(s) Remaining....\n Please Enter Valid Credentials & Try Logging In Again....\n");
                else
                    System.out.println(" You Have Exhausted All Your Chances To Successfully Login Into The System !!!\n Please Restart The Program....");
            }
        }
    }

}

class bank
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static Declare d = new Declare();
    public static void main(String args[])
    {
        login lg = new login();
        lg.check();
    }

    static void mainmenu()
    {
        try{
            int choice = -1;
            do{
                System.out.println("-------------------------------------------------------------------------------");
                System.out.println("\t\t\tBank Management System");
                System.out.println("-------------------------------------------------------------------------------\n\n");
                System.out.println("\t1. Add Account");
                System.out.println("\t2. Deposit");
                System.out.println("\t3. Withdraw");
                System.out.println("\t4. Display All Accounts");
                System.out.println("\t5. Remove Account");
                System.out.println("\t6. Search Account");
                System.out.println("\t7. Transfer Money");
                System.out.println("\t8. Exit");
                System.out.println("\n\n\tEnter Your Choice : ");
                choice = Integer.parseInt(br.readLine());
                System.out.println("--------------------------------------------------------------------------------");
                switch(choice)
                {
                    case 1 : addAccount();
                    break;
                    case 2 : deposit();
                    break;
                    case 3 : withdraw();
                    break;
                    case 4 : displayAllAccounts();
                    break;
                    case 5 : removeAccount();
                    break;
                    case 6 : searchAccount();
                    break;
                    case 7 : transfer();
                    break;
                    case 8 : System.out.println("Are You Sure (y/n) : ");
                             if(br.readLine().equalsIgnoreCase("y"))
                                choice = -1;
                    break;
                    default : System.out.println("INVALID CHOICE !!!");
                    break;
                }
            } while(choice != -1);
        }
        catch (Exception e)
        {}
    }

    static void addAccount()
    {
        try{
            System.out.println("Enter The Account Number : ");
            Integer accno = new Integer(br.readLine());
            if(d.v_accno.contains(accno))
            {
                System.out.println("Account Already Exists !!!");
            }
            else
            {
                System.out.println("Enter The Account Holder Name : ");
                String name = br.readLine();
                d.v_accno.addElement(accno);
                d.v_name.addElement(name);
                d.v_balance.addElement(new Float(0));
                System.out.println("\n\n Account Added Successfully....\n\n");
                System.out.println("\n\n|------------------------------------------------------------------------------|");
                System.out.println("| NOTE : Balance Is Rs.0.00 For New Accounts Until Some Amount Is Deposited... |");
                System.out.println("|------------------------------------------------------------------------------|\n");
                System.out.println(" Account Details Are As Follows : \n");
                display(d.v_accno.indexOf(accno));
            }
        }
        catch(Exception e)
        {}
    }

    static void displayAllAccounts()
    {
        System.out.println("      Account No.       |       Account Holder Name       |       Balance");
        System.out.println("-------------------------------------------------------------------------------");
        if(d.v_accno.size()>0)
        {
            for(int i=0;i<d.v_accno.size();i++)
            {
                System.out.printf("      %-17d |       %-25s |       %.2f",d.v_accno.elementAt(i),d.v_name.elementAt(i),d.v_balance.elementAt(i));
                System.out.println();
            }
        }
        else
        {
            System.out.println("\n\n\n\t\t  No Accounts To Display !!!\n\n\n");
        }
    }

    static int searchAccount()
    {
        int accno;
        System.out.println("Enter The Account Number To Search : ");
        try{
            accno=Integer.parseInt(br.readLine());
            if (d.v_accno.contains(new Integer(accno)))
            {
                int index = d.v_accno.indexOf(new Integer(accno));
                display(index);
                return index;
            }
            else
                System.out.println("Account Does Not Exists !!!");
        }catch(Exception e)
        {}
        return -1;
    }

    static void deposit()
    {
        int index=searchAccount();
        if(index>=0)
        {
            try{
                float balance = (float)(Float)d.v_balance.elementAt(index);
                System.out.println("\nEnter The Amount To Deposit : ");
                float amount=Float.parseFloat(br.readLine());
                balance += amount;
                d.v_balance.set(index,new Float(balance));
                System.out.println("\n\n Amount Deposited Successfully....");
                System.out.println("\n\n Current Balance Is : Rs."+balance);
            }
            catch(Exception e)
            {}
        }
    }

    static void withdraw()
    {
        int index=searchAccount();
        if(index>=0)
        {
            try{
                float balance = (float)(Float)d.v_balance.elementAt(index);
                if(balance <= 0)
                {
                    System.out.println("Account Does Not Have Sufficient Balance !!!\nPlease Deposit Some Amount First...");
                }
                else
                {
                    System.out.println("\nEnter The Amount To Withdraw : ");
                    float amount=Float.parseFloat(br.readLine());
                    if(balance <= amount)
                    {
                        System.out.println("Insufficient Balance !!!");
                    }
                    else
                    {
                        balance -= amount;
                        d.v_balance.set(index,new Float(balance));
                        System.out.println("\n\n Amount Withdrawn Successfully....");
                        System.out.println("\n\n Current Balance Is : Rs."+balance);
                    }
                }
            }
            catch(Exception e)
            {}
        }
    }

    static void removeAccount()
    {
        int index=searchAccount();
        if(index > 0)
        {
            d.v_accno.removeElementAt(index);
            d.v_name.removeElementAt(index);
            d.v_balance.removeElementAt(index);
            System.out.println("\n\n Account Deleted Successfully....");
        }
        else if(d.v_accno.size() == 0)
        {
            System.out.println("Account Cannot Be Deleted As Only One Account Is Present In System...");
        }
    }

    static void display(int index)
    {
        System.out.println("Account Number : "+d.v_accno.elementAt(index));
        System.out.println("Account Holder Name : "+d.v_name.elementAt(index));
        System.out.println("Available Balance : "+d.v_balance.elementAt(index));
    }

    
    static void transfer()
    {
        try{
            System.out.println("Enter The Account Number Of Sender : ");
            int sno = Integer.parseInt(br.readLine());
            if (d.v_accno.contains(new Integer(sno)))
            {
                float sbal = (float)(Float)d.v_balance.elementAt(d.v_accno.indexOf(new Integer(sno)));
                if(sbal > 0)
                { 
                    System.out.println("Enter The Account Number Of Reciever : ");
                    int dno = Integer.parseInt(br.readLine());
                    if (d.v_accno.contains(new Integer(dno)))
                    {
                        System.out.println("Enter The Amount To Be Transferred : ");
                        float amount = Float.parseFloat(br.readLine());
                        if(sbal <= amount)
                        {
                            System.out.println("Insufficient Balance !!!");
                        }
                        else
                        {
                            float dbal = (float)(Float)d.v_balance.elementAt(d.v_accno.indexOf(new Integer(dno)));
                            sbal -= amount;
                            dbal += amount;
                            d.v_balance.set(d.v_accno.indexOf(new Integer(sno)),new Float(sbal));
                            d.v_balance.set(d.v_accno.indexOf(new Integer(dno)),new Float(dbal));
                            System.out.println("\n\n Amount Has Been Transferred From A/c No. : "+sno+" To A/c No. : "+dno+" Successfully....");
                        }
                    }
                    else
                    {
                        System.out.println("Account Does Not Exist !!!");
                    }
                }
                else
                {
                    System.out.println("Insufficient Balance !!!");
                }
            }
            else
            {
                System.out.println("Account Does not Exist !!!");
            }
        }
        catch(Exception e)
        {}
    }
}