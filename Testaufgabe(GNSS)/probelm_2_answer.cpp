//////////////////////////////////////////
// Probelm 2  Implement a word processor
/////////////////////////////////////////
// function reads a c++ file





#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// input args:
//     string file_content: source code for single line 
//     int local_line_length: size of this codeline
// output args: 
//     file_content: source code at this given line after replacing C-style comment by c++ style comment
string word_processor( string file_content, int local_line_length)

    
    {  
        for (int i=0; i<local_line_length;i++)
        

        {

             // distinguish if there is a c style comment in this code line
            if (file_content[i] == '*' )
            {
                // check if this c style comment ends at the end of a line
                if (file_content[local_line_length-1] == '/' || file_content[local_line_length-1] == '*')

                {
                // if c style comment is not end for a line, we replace it by c++ style comment
                   file_content[i] = '/';
                }
               
            }

        }
 
    
    return file_content;
    }
    
  

// main entrance
int main()
{
    //initialize a text string
   string file_contents;
   
    // read the source c++ file 
   ifstream myfile ("sample_source_file.cpp");

   // output source file content
   std::string str;
   cout  << "original source code is: \n";
   while ( getline (myfile,file_contents) )
       {
           //print original file contents 
          cout  << "\n"  << file_contents;
          
       }
     // read the source c++ file again 
   ifstream my_file ("sample_source_file.cpp");
   cout  << "new source code is: \n";
   while (getline (my_file,file_contents))
       {
           //print file contents
         // cout  << "\n"  << file_contents;
         
          //calculate size of string for each line
          int local_line_length = file_contents.size();
          // process for each line with word processor
          string file_content = word_processor(file_contents,local_line_length);
          // append new source code
          str.append(file_content);
           // print the new souce file after replacing c style comments by c++ style comments
          cout  << " \n "  << file_content;
          
       }
   
}