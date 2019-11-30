#include <iostream>
#include <windows.h>
#include <fstream>
#include <string.h>
using namespace std;


struct Data_structure
{


public:

   int top, steps;
    int* stackk;

    Data_structure(): top(-1){ stackk = new int[top+1];}
    Data_structure(int y)
    {

        stackk = new int[top+1];

          for(int i=0;i<=top;i++)
          {
            stackk[i] = y;
          }

    }
    ~Data_structure(){delete [] stackk;}




    void Stack_inicialization()
    {
       char a;
        while(1)
        {

        cout<<"Press 1 to input the values via a keyboard"<<endl;
         cout<<"Press 2 to read the values from a file"<<endl;
          cin>>a;

             if(a=='1' || a=='2')
             {
                   break;
             }
                system("CLS");
                 cout<<"Entered value was illogical"<<endl;

        }


             if(a=='1')
             {
                int n = 0;
                 while(1)
                 {

                     cout<<"Enter the size of the Stack: ";
                      cin>>n;

                      if(n>-1)
                      {
                          break;

                      }
                        system("CLS");
                         cout<<"Entered value cannot be negative"<<endl;
                 }

                 while(n>0)
                 {
                    system("CLS");
                     push();
                         n--;
                 }


             }

               else if(a=='2')
               {
                  Stack_inicialization_form_a_text_file_input();

               }



    }




     void Stack_inicialization_form_a_text_file_input()
    {
         char str1[] = ".txt", str2[50], str3[55];

        while(1)
        {

                cout<<"Enter the name of a file with your data: "; //without .txt
                     cin>>str2;
                          strcpy(str3, (strcat(str2, str1)));

              ifstream duom;
                duom.open(str3);

            if(duom.fail())
                {
                    cout<<"The file with this name doesn't exist in the current directory"<<endl;
                      system("pause");
                        system("CLS");
                }

                   else if (is_empty(duom))
                   {
                        cout<<"The file with this name doesn't have any values, choose a file with values"<<endl;
                          system("pause");
                            system("CLS");
                    }

              else
               {
                  system("CLS");
                     int q = 0;
                         while(!duom.eof())
                         {

                            display();
                              duom>>q;
                               push_auto(q);
                                cout<<"The pushed value was: "<<q<<endl;
                                  display();
                                     system("pause");
                                      system("CLS");


                         }

                              duom.close();

                                    system("CLS");

                                            break;

                }


         }
    }



    bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

 void push_auto(int x)
            {

                   top++;
                     stackk[top] = x;
            }



 //-----------------------------------------------------------------------


    void display()
    {

        if(top>=0)
        {

         cout<<"The Stack: ";
           for(int i=0; i<=top ;i++)
           {
               cout<<stackk[i]<<" ";

           }

                  cout<<endl;
        }

        else
        {
               cout<<"The Stack is empty"<<endl;

        }


     }










     void push()
     {

           int x = 0, st=0;

             display();

              cout<<"Enter the element to be pushed: ";
               cin>>x;
                   top++;
                     stackk[top] = x;
                        display();

                             system("pause");

      }



      void pop()
      {
          if(top<=-1)
          {
            cout<<"Stack Underflow"<<endl;
          }

            else
            {
                int matrix[top-1];

                display();

                 cout<<"The popped element was: "<< stackk[top] <<endl;
                 top--;

                  for(int i=0; i<=top; i++)
                  {
                      matrix[i]=stackk[i];

                  }

                    delete [] stackk;

                             for(int i=0; i<=top; i++)
                             {
                                       stackk[i]=matrix[i];
                            }
                                 delete [] matrix;



                                  display();

                               system("pause");


            }



      }




      void show_top()
      {

          display();
           cout<<"The top element is: "<<stackk[top]<<endl;


                       system("CLS");



      }



      void check_if_empty()
      {
          if(top<0)
          {
              cout<<"The Stack is empty "<<endl;
               system("pause");
          }

            else
            {
                cout<<"The Stack is not empty "<<endl;
                  system("pause");
            }

      }



      void show_Stack_size()
      {


           cout<<"The current size of this Stack is: "<<top+1<<endl;

            system("pause");
      }




    void save_Stack(int g)
    {

        char str3 [55];
          create_a_file_name(str3);
             ofstream duom;
                 duom.open(str3);

        if(g==1)
        {
            duom<<stackk[top];
        }


             else
             {

                     for(int i=0; i<=top-1 ;i++)
                     {
                      duom<<stackk[i]<<" ";
                     }
                        duom<<stackk[top];
              }



                   duom.close();
                       cout<<"Data inserted to a "<<str3<<" file"<<endl;
                         system("pause");
    }



    void create_a_file_name(char* str3)
{

     char str1[] = ".txt", str2[50];

                cout<<"Enter the name of a file you would like to insert the data into ( up to 50 charachters): "; //without .txt
                     cin>>str2;
                          strcpy(str3, (strcat(str2, str1)));
}



      int options()
      {
         int a;

          cout<<"-------------------------------------------------------"<<endl;
          cout<<"| Operations:                                         |"<<endl;
          cout<<"| Press 1 to remove an item from the top of the Stack |"<<endl;
          cout<<"| Press 2 to add an item on top of the Stack          |"<<endl;
          cout<<"| Press 3 to view the top item of the Stack           |"<<endl;
          cout<<"| Press 4 to check if the Stack is empty              |"<<endl;
          cout<<"| Press 5 to view the size of the Stack               |"<<endl;
          cout<<"| Press 6 to view the Stack (on the screan)           |"<<endl;
          cout<<"| Press 7 to save the Stack in a file                 |"<<endl;
          cout<<"| Press 8 to create a new Stack                       |"<<endl;
          cout<<"| Press 9 exit                                        |"<<endl;
          cout<<"-------------------------------------------------------"<<endl;

          cin>>a;



          return a;

      }


      void empty_Stack()
      {
          while(top > -1)
          {
              stackk[top--];
          }

      }
}data;

int main()
{


      data.Stack_inicialization();


      while(1)
      {
        system("CLS");
          switch(data.options())
          {

                  case 1:
                    data.pop();
                      break;


                      case 2:
                       data.push();
                        break;


                          case 3:
                           data.show_top();
                            break;


                                 case 4:
                                  data.check_if_empty();
                                    break;


                                      case 5:
                                       data.show_Stack_size();
                                          break;


                                            case 6:
                                             data.display();
                                              system("pause");
                                               break;


                                                 case 7:
                                                   data.save_Stack(0);
                                                     break;


                                                    case 8:
                                                      data.empty_Stack();
                                                       data.Stack_inicialization();
                                                       break;


                                                        case 9:
                                                           return 0;



                                                            default:
                                                                 break;


          }

      }


}
